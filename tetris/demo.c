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




void draw_s_1(sprite_t* sp)		//画闪电1,这是打算写在一个函数里
{	
  int x,y,w,c,t;

  x = ((int*)sp->data)[0];
  y = ((int*)sp->data)[1];
  w = ((int*)sp->data)[2];
  c = ((int*)sp->data)[3];
  t = ((int*)sp->data)[4];

  if (t == 0)
  {
      draw_rect(x,y,w,w,c);
      draw_rect(x,y+w,w,w,c);
      draw_rect(x+w,y+w,w,w,c);
      draw_rect(x+w,y+w+w,w,w,c);
  }
  else
  {
      draw_rect(x+w,y,w,w,c);
      draw_rect(x+w+w,y,w,w,c);
      draw_rect(x,y+w,w,w,c);
      draw_rect(x+w,y+w,w,w,c);
  }
}

void draw_s_2(sprite_t* sp)		//画闪电2
{	
  int x,y,w,c;

  x = ((int*)sp->data)[0];
  y = ((int*)sp->data)[1];
  w = ((int*)sp->data)[2];
  c = ((int*)sp->data)[3];

  draw_rect(x+w,y,w,w,c);
  draw_rect(x+w+w,y,w,w,c);
  draw_rect(x,y+w,w,w,c);
  draw_rect(x+w,y+w,w,w,c);
}

void draw_s_a(sprite_t* sp)		//画闪电a
{	
  int x,y,w,c;

  x = ((int*)sp->data)[0];
  y = ((int*)sp->data)[1];
  w = ((int*)sp->data)[2];
  c = ((int*)sp->data)[3];

  draw_rect(x+w,y,w,w,c);
  draw_rect(x,y+w,w,w,c);
  draw_rect(x+w,y+w,w,w,c);
  draw_rect(x,y+w+w,w,w,c);
}

void draw_s_b(sprite_t* sp)		//画闪电b
{	
  int x,y,w,c;

  x = ((int*)sp->data)[0];
  y = ((int*)sp->data)[1];
  w = ((int*)sp->data)[2];
  c = ((int*)sp->data)[3];

  draw_rect(x,y,w,w,c);
  draw_rect(x+w,y,w,w,c);
  draw_rect(x+w,y+w,w,w,c);
  draw_rect(x+w+w,y+w,w,w,c);
}



void draw_l_1(sprite_t* sp)	//画L字1
{
	int x,y,w,c;

	x = ((int*)sp->data)[0];
	y = ((int*)sp->data)[1];
	w = ((int*)sp->data)[2];
	c = ((int*)sp->data)[3];
	
	draw_rect(x,y,w,w,c);
	draw_rect(x,y+w,w,w,c);
	draw_rect(x+w,y+w,w,w,c);
	draw_rect(x+w+w,y+w,w,w,c);
}
void draw_l_2(sprite_t* sp)	//画L字1
{
	int x,y,w,c;

	x = ((int*)sp->data)[0];
	y = ((int*)sp->data)[1];
	w = ((int*)sp->data)[2];
	c = ((int*)sp->data)[3];
	
	draw_rect(x,y,w,w,c);
	draw_rect(x,y+w,w,w,c);
	draw_rect(x+w,y,w,w,c);
	draw_rect(x,y+w+w,w,w,c);
}

void draw_l_a(sprite_t* sp)	//画L字a
{
	int x,y,w,c;

	x = ((int*)sp->data)[0];
	y = ((int*)sp->data)[1];
	w = ((int*)sp->data)[2];
	c = ((int*)sp->data)[3];
	
	draw_rect(x,y,w,w,c);
	draw_rect(x+w,y,w,w,c);
	draw_rect(x+w+w,y,w,w,c);
	draw_rect(x+w+w,y+w,w,w,c);
}

void draw_l_b(sprite_t* sp)	//画L字b
{
	int x,y,w,c;

	x = ((int*)sp->data)[0];
	y = ((int*)sp->data)[1];
	w = ((int*)sp->data)[2];
	c = ((int*)sp->data)[3];
	
	draw_rect(x+w,y,w,w,c);
	draw_rect(x+w,y+w,w,w,c);
	draw_rect(x+w,y+w+w,w,w,c);
	draw_rect(x,y+w+w,w,w,c);
}

void one_draw(sprite_t* sp)	//画长1字
{
	int x,y,w,c;

	x = ((int*)sp->data)[0];
	y = ((int*)sp->data)[1];
	w = ((int*)sp->data)[2];
	c = ((int*)sp->data)[3];
	
	draw_rect(x,y,w,w,c);
	draw_rect(x,y+w,w,w,c);
	draw_rect(x,y+w+w,w,w,c);
	draw_rect(x,y+w+w+w,w,w,c);
}

void sq_draw(sprite_t* sp){		//画田字矩形
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

void hjkl_tick(sprite_t* s){
  int key = get_lastkey();

  int w = ((int*)s->data)[2];
  switch(key){
    case VKEY_DOWN:
      ((int*)s->data)[1] += w;
      break;
    case VKEY_UP:
      ((int*)s->data)[1] -= w;
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
  
  l1 = mk_sprite(50,0,10,0x20,0);
  l2 = mk_sprite(50,50,10,0x20,0);
  la = mk_sprite(50,100,10,0x20,1);
  lb = mk_sprite(50,150,10,0x20,1);
  
  l1->d = draw_s_1;
  l1->t = hjkl_tick;
  
  l2->d = draw_l_2;
  l2->t = hjkl_tick;
  
  la->d = draw_s_1;
  la->t = hjkl_tick;
  
  lb->d = draw_l_b;
  lb->t = hjkl_tick;
  
  s1->d = draw_s_1;
  s1->t = hjkl_tick;
  
  s2->d = draw_s_2;
  s2->t = hjkl_tick;
  
  sa->d = draw_s_a;
  sa->t = hjkl_tick;
  
  sb->d = draw_s_b;
  sb->t = hjkl_tick;
  //add_sprite(s1,0);
  //add_sprite(s2,0);
 // add_sprite(sa,0);
  //add_sprite(sb,0);
  add_sprite(l1,0);
  add_sprite(l2,0);
  add_sprite(la,0);
  add_sprite(lb,0);
  
}

void main_p(){
  
}
