#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "graphics.h"

extern volatile int tick;
extern volatile int keys_len;
extern volatile int keys[KEY_BUFFER_SIZE];

void draw_rect(int x,int y,int w,int h,int c){
  int i;

  for(i=y;i<y+h;i++){
    int s = x + i*320;
    put_pixel(s,w,c);
  }
}

char mem[MEM_SIZE];
mem_t* head;

sp_entry sp_list[4][MAX_SPRITE_Z];

void init_mem(){
  head = (mem_t*)mem;
  head->prev = head->next = head;
  head->size = 0;
  head->ptr = (char*)head+sizeof(mem_t);
}

void* alloc_mem(int size){
  mem_t* m = head;
  int freesize;

  while(m->next != head){
    freesize = (((char*)m->next) - ((char*)m->ptr)) - m->size;

    if(freesize - (int)sizeof(mem_t) >= size){
      mem_t* ret = m->ptr + m->size;
      ret->prev = m;
      ret->next = m->next;
      m->next->prev = ret;
      m->next = ret;

      ret->ptr = ((char*)ret) + sizeof(mem_t);
      ret->size = size;

      return ret->ptr;
    }

    m = m->next;
  }

  freesize = MEM_SIZE + mem - ((char*)m->ptr + m->size);
  if(freesize - (int)sizeof(mem_t) >= size){
    mem_t* ret = m->ptr + m->size;
    ret->prev = m;
    ret->next = m->next;
    m->next->prev = ret;
    m->next = ret;

    ret->ptr = (char*)ret + sizeof(mem_t);
    ret->size = size;

    return ret->ptr;
  }

  return NULL;
}

void free_mem(void* v){
  mem_t* m = (mem_t*)((char*)v - sizeof(mem_t));
  m->prev->next = m->next;
  m->next->prev = m->prev;
}

void engine()
{
  int i,j;
  int bg = 0;
  static int lasttick = 0;

  for(i=0;i<4;i++)
    for(j=0;j<MAX_SPRITE_Z;j++){
      sp_list[i][j].used = 0;
    }

  init_mem();
  init_p();
  i = 0;
  while(1){
    while(tick - lasttick < 100);
    lasttick = tick;

    disable_irq(CLOCK_IRQ);
    disable_irq(KEYBOARD_IRQ);

    bg = 0;
    for(i=0;i<keys_len;i++){
      if(keys[i] == VKEY_UP){
        bg = 0x20;
      } else if(keys[i] == VKEY_DOWN){
        bg = 0x30;
      } else if(keys[i] == VKEY_LEFT){
        bg = 0x40;
      } else {
        bg = 0x50;
      }
    }
    draw_rect(0,0,320,200,bg);
    keys_len = 0;
    enable_irq(KEYBOARD_IRQ);

    for(i=0;i<4;i++)
      for(j=0;j<MAX_SPRITE_Z;j++){
        if(sp_list[i][j].used == 1){
          sp_list[i][j].sp->d(sp_list[i][j].sp);
          sp_list[i][j].sp->t(sp_list[i][j].sp);
        }
      }

    enable_irq(CLOCK_IRQ);
  }
}

void add_sprite(sprite_t* s,int z){
  int j;

  for(j=0;j<MAX_SPRITE_Z;j++){
    if(sp_list[z][j].used == 0){
      sp_list[z][j].used = 1;
      sp_list[z][j].sp = s;
      s->reserved = &sp_list[z][j];

      return;
    }
  }
}

void remove_sprite(sprite_t* s){
  sp_entry* e = s->reserved;
  if(e != NULL)
    e->used = 0;
}
