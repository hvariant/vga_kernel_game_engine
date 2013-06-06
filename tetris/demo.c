#include "graphics.h"
#include "const.h"

sprite_t* mk_sprite(int x,int y,int w,int c){
  sprite_t* sp = alloc_mem(sizeof(sprite_t) + sizeof(int)*4);
  sp->data = (char*)sp+ sizeof(sprite_t);
  sp->reserved = NULL;
  ((int*)sp->data)[0] = x;
  ((int*)sp->data)[1] = y;
  ((int*)sp->data)[2] = w;
  ((int*)sp->data)[3] = c;

  return sp;
}

void zig_draw(sprite_t* sp){
  int x,y,w,c;

  x = ((int*)sp->data)[0];
  y = ((int*)sp->data)[1];
  w = ((int*)sp->data)[2];
  c = ((int*)sp->data)[3];

  draw_rect(x,y,w,w,c);
  draw_rect(x,y+w,w,w,c);
  draw_rect(x+w,y+w,w,w,c);
  draw_rect(x+w,y+w+w,w,w,c);
}

void sq_draw(sprite_t* sp){
  int x,y,w,c;

  x = ((int*)sp->data)[0];
  y = ((int*)sp->data)[1];
  w = ((int*)sp->data)[2];
  c = ((int*)sp->data)[3];

  draw_rect(x,y,w,w,c);
  draw_rect(x+w,y,w,w,c);
  draw_rect(x,y+w,w,w,c);
  draw_rect(x+w,y+w,w,w,c);
}

void noop_tick(sprite_t* s){
  //noop
}

void init_p(){
  sprite_t *z1,*z2;
  sprite_t *s1,*s2;

  z1 = mk_sprite(0,0,10,0x20);
  z2 = mk_sprite(20,140,10,0x30);
  s1 = mk_sprite(240,40,5,0x40);
  s2 = mk_sprite(250,130,5,0x50);
  z1->d = z2->d = zig_draw;
  s1->d = s2->d = sq_draw;
  z1->t = z2->t = s1->t = s2->t = noop_tick;

  add_sprite(z1,0);
  add_sprite(z2,1);
  add_sprite(s1,2);
  add_sprite(s2,3);
}
