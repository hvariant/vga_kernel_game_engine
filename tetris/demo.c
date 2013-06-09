#include "graphics.h"
#include "const.h"

sprite_t* mk_sprite(int x,int y,int w,int c,int t){
  sprite_t* sp = alloc_mem(sizeof(sprite_t) + sizeof(int)*5);
  sp->data = (char*)sp+ sizeof(sprite_t);
  sp->reserved = NULL;
  ((int*)sp->data)[0] = x;
  ((int*)sp->data)[1] = y;
  ((int*)sp->data)[2] = w;
  ((int*)sp->data)[3] = c;
  ((int*)sp->data)[4] = t;

  return sp;
}




void draw_diam(sprite_t* sp)		//画各种形状,这是打算写在一个函数里，由参数data确定
								//用两位十进制编码各种形状，11-14代表反L，21-24代表正L，
								//31-32代表正Z，41-42代表反Z，51代表田字，61-64土字，71-72代表长条
{	
  int x,y,w,c,t;

  x = ((int*)sp->data)[0];
  y = ((int*)sp->data)[1];
  w = ((int*)sp->data)[2];
  c = ((int*)sp->data)[3];
  t = ((int*)sp->data)[4];

  if (t == 11)
  {
      draw_rect(x,y,w,w,c);
	  draw_rect(x,y+w,w,w,c);
	  draw_rect(x+w,y+w,w,w,c);
	  draw_rect(x+w+w,y+w,w,w,c);
  }
  else if (t == 12)
  {
      draw_rect(x,y,w,w,c);
	  draw_rect(x,y+w,w,w,c);
	  draw_rect(x+w,y,w,w,c);
	  draw_rect(x,y+w+w,w,w,c);
  }
  else if (t == 13)
  {
      draw_rect(x,y,w,w,c);
	  draw_rect(x+w,y,w,w,c);
	  draw_rect(x+w+w,y,w,w,c);
	  draw_rect(x+w+w,y+w,w,w,c);
  }
  else if (t == 14)
  {
      draw_rect(x+w,y,w,w,c);
	  draw_rect(x+w,y+w,w,w,c);
	  draw_rect(x+w,y+w+w,w,w,c);
	  draw_rect(x,y+w+w,w,w,c);
  }
  else if (t == 21)
  {
      draw_rect(x+w+w,y,w,w,c);
      draw_rect(x+w+w,y+w,w,w,c);
      draw_rect(x+w,y+w,w,w,c);
      draw_rect(x,y+w,w,w,c);
  }
  else if (t == 22)
  {
      draw_rect(x,y,w,w,c);
      draw_rect(x,y+w,w,w,c);
      draw_rect(x,y+w+w,w,w,c);
      draw_rect(x+w,y+w+w,w,w,c);
  }
  else if (t == 23)
  {
      draw_rect(x,y,w,w,c);
      draw_rect(x,y+w,w,w,c);
      draw_rect(x+w,y,w,w,c);
      draw_rect(x+w+w,y,w,w,c);
  }
  else if (t == 24)
  {
      draw_rect(x,y,w,w,c);
      draw_rect(x+w,y,w,w,c);
      draw_rect(x+w,y+w,w,w,c);
      draw_rect(x+w,y+w+w,w,w,c);
  }
  else if (t == 31)
  {
      draw_rect(x,y,w,w,c);
      draw_rect(x+w,y,w,w,c);
      draw_rect(x+w,y+w,w,w,c);
      draw_rect(x+w+w,y+w,w,w,c);
  }
  else if (t == 32)
  {
      draw_rect(x+w,y,w,w,c);
      draw_rect(x,y+w,w,w,c);
      draw_rect(x+w,y+w,w,w,c);
      draw_rect(x,y+w+w,w,w,c);
  }
  else if (t == 41)
  {
      draw_rect(x+w,y,w,w,c);
      draw_rect(x+w+w,y,w,w,c);
      draw_rect(x,y+w,w,w,c);
      draw_rect(x+w,y+w,w,w,c);
  }
  else if (t == 42)
  {
      draw_rect(x,y,w,w,c);
      draw_rect(x,y+w,w,w,c);
      draw_rect(x+w,y+w,w,w,c);
      draw_rect(x+w,y+w+w,w,w,c);
  }
  else if (t == 51)
  {
      draw_rect(x,y,w,w,c);
      draw_rect(x+w,y,w,w,c);
      draw_rect(x+w,y+w,w,w,c);
      draw_rect(x,y+w,w,w,c);
  }
  else if (t == 61)
  {
      draw_rect(x+w,y,w,w,c);
      draw_rect(x,y+w,w,w,c);
      draw_rect(x+w,y+w,w,w,c);
      draw_rect(x+w+w,y+w,w,w,c);
  }
  else if (t == 62)
  {
      draw_rect(x,y,w,w,c);
      draw_rect(x,y+w,w,w,c);
      draw_rect(x+w,y+w,w,w,c);
      draw_rect(x,y+w+w,w,w,c);
  }
  else if (t == 63)
  {
      draw_rect(x,y,w,w,c);
      draw_rect(x+w,y,w,w,c);
      draw_rect(x+w+w,y,w,w,c);
      draw_rect(x+w,y+w,w,w,c);
  }
  else if (t == 64)
  {
      draw_rect(x+w,y,w,w,c);
      draw_rect(x,y+w,w,w,c);
      draw_rect(x+w,y+w,w,w,c);
      draw_rect(x+w,y+w+w,w,w,c);
  }
  else if (t == 71)
  {
      draw_rect(x,y,w,w,c);
      draw_rect(x,y+w,w,w,c);
      draw_rect(x,y+w+w,w,w,c);
      draw_rect(x,y+w+w+w,w,w,c);
  }
  else if (t == 72)
  {
      draw_rect(x,y,w,w,c);
      draw_rect(x+w,y,w,w,c);
      draw_rect(x+w+w,y,w,w,c);
      draw_rect(x+w+w+w,y,w,w,c);
  }
}


void noop_tick(sprite_t* s){
  //noop
}

void hjkl_tick(sprite_t* s){
  int key = get_lastkey();

  int w = ((int*)s->data)[2];
  int type = ((int*)s->data)[4];
  switch(key){
    case VKEY_DOWN:
      ((int*)s->data)[1] += w;
      break;
    case VKEY_UP:
      //((int*)s->data)[1] -= w;
	  //int type = ((int*)s->data)[4];
	  if (type >= 11 && type <=14)
	  {
		((int*)s->data)[4] = (type + 1 > 14) ? (type + 1 - 4) : (type + 1);
	  }
	  else if (type >= 21 && type <=24)
	  {
		((int*)s->data)[4] = (type + 1 > 24) ? (type + 1 - 4) : (type + 1);
	  }
	  else if (type >= 31 && type <=32)
	  {
		((int*)s->data)[4] = (type + 1 > 32) ? (type + 1 - 2) : (type + 1);
	  }
	  else if (type >= 41 && type <=42)
	  {
		((int*)s->data)[4] = (type + 1 > 42) ? (type + 1 - 2) : (type + 1);
	  }
	  else if (type == 51)
	  {
		
	  }
	  else if (type >= 61 && type <=64)
	  {
		((int*)s->data)[4] = (type + 1 > 64) ? (type + 1 - 4) : (type + 1);
	  }
	  else if (type >= 71 && type <=72)
	  {
		((int*)s->data)[4] = (type + 1 > 72) ? (type + 1 - 4) : (type + 1);
	  }
	  
      break;
    case VKEY_LEFT:
      ((int*)s->data)[0] -= w;
      break;
    case VKEY_RIGHT:
      ((int*)s->data)[0] += w;
      break;
  }
}

void init_p(){
  sprite_t *s1;
  sprite_t *s2;
  sprite_t *sa;
  sprite_t *sb;
  
  sprite_t *l1;
  sprite_t *l2;
  sprite_t *la;
  sprite_t *lb;
  
  //s1 = mk_sprite(0,0,10,0x20);
  //s2 = mk_sprite(0,50,10,0x20);
  //sa = mk_sprite(0,100,10,0x20);
  //sb = mk_sprite(0,150,10,0x20);
  
  l1 = mk_sprite(50,0,10,0x20 ,21);
  l2 = mk_sprite(50,50,10,0x20,31);
  la = mk_sprite(50,100,10,0x20,42);
  lb = mk_sprite(50,150,10,0x20,64);
  
  l1->d = draw_diam;
  l1->t = hjkl_tick;
  
  l2->d = draw_diam;
  l2->t = hjkl_tick;
  
  la->d = draw_diam;
  la->t = hjkl_tick;
  
  lb->d = draw_diam;
  lb->t = hjkl_tick;
  
  add_sprite(l1,0);
  add_sprite(l2,0);
  add_sprite(la,0);
  add_sprite(lb,0);
  
}

void main_p(){
  //road[0][0] = 1;
}
