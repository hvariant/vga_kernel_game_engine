#ifndef _TETRIS_GRAPHICS_H_
#define _TETRIS_GRAPHICS_H_

void draw_rect(int x,int y,int w,int h,int c);

void* alloc_mem(int size);
void  free_mem(void*);

struct _sprite;

typedef void (*sp_draw)(struct _sprite*);
typedef void (*sp_tick)(struct _sprite*);

#define MAX_SPRITE_Z 10
#define MEM_SIZE 1024

typedef struct mem_entry{
  int size;
  struct mem_entry* next;
  struct mem_entry* prev;
  void* ptr;
} mem_t;

struct _sprite;

typedef struct sp_entry{
  struct _sprite* sp;
  int used;
} sp_entry;

typedef struct _sprite{
  sp_draw d;
  sp_tick t;
  void* data;
  int z;

  void* reserved;
} sprite_t;

void add_sprite(sprite_t*,int z);
void remove_sprite(sprite_t*);

void init_p(void);
void main_p(void);

int get_lastkey();

#endif
