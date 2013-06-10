#include "graphics.h"
#include "const.h"
#include "stdio.h"


#define MAX_WIDTH 150
#define MAX_HEIGHT 200
#define MIN_WIDTH 0
#define MIN_HEIGHT 0

#define START_X 50
#define START_Y 0

typedef struct
{
	int x[4];
	int y[4];
	
} point_t;

int road[32][20];

sprite_t* mk_sprite(int x,int y,int w,int c,int t){
  sprite_t* sp = alloc_mem(sizeof(sprite_t) + sizeof(int)*5 + sizeof(point_t) );
  sp->data = (char*)sp+ sizeof(sprite_t);

  sp->reserved = NULL;
  ((int*)sp->data)[0] = x;
  ((int*)sp->data)[1] = y;
  ((int*)sp->data)[2] = w;
  ((int*)sp->data)[3] = c;
  ((int*)sp->data)[4] = t;

  return sp;
}


int states[8] = {11,21,31,41,51,61,71};

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
  point_t* ps = (point_t*)((char*)sp->data + sizeof(sprite_t) + sizeof(int)*5);
  //int diamX[4];
  //int diamY[4];
  if (t == 11)
  {
	  ps->x[0] = x;
	  ps->y[0] = y;
	  ps->x[1] = x;
	  ps->y[1] = y + w;
	  ps->x[2] = x + w;
	  ps->y[2] = y + w;
	  ps->x[3] = x + w + w;
	  ps->y[3] = y + w;
      
  }
  else if (t == 12)
  {
	  ps->x[0] = x;
	  ps->y[0] = y;
	  ps->x[1] = x;
	  ps->y[1] = y + w;
	  ps->x[2] = x + w;
	  ps->y[2] = y;
	  ps->x[3] = x;
	  ps->y[3] = y + w + w;
  }
  else if (t == 13)
  {
	  ps->x[0] = x;
	  ps->y[0] = y;
	  ps->x[1] = x + w;
	  ps->y[1] = y;
	  ps->x[2] = x + w + w;
	  ps->y[2] = y;
	  ps->x[3] = x + w + w;
	  ps->y[3] = y + w;
  }
  else if (t == 14)
  {
	  ps->x[0] = x + w;
	  ps->y[0] = y;
	  ps->x[1] = x + w;
	  ps->y[1] = y + w;
	  ps->x[2] = x + w;
	  ps->y[2] = y + w + w;
	  ps->x[3] = x;
	  ps->y[3] = y + w + w;
  }
  else if (t == 21)
  {
	  ps->x[0] = x + w + w ;
	  ps->y[0] = y;
	  ps->x[1] = x + w + w ;
	  ps->y[1] = y + w;
	  ps->x[2] = x + w;
	  ps->y[2] = y + w;
	  ps->x[3] = x;
	  ps->y[3] = y + w;
  }
  else if (t == 22)
  {
	  ps->x[0] = x;
	  ps->y[0] = y;
	  ps->x[1] = x;
	  ps->y[1] = y + w;
	  ps->x[2] = x;
	  ps->y[2] = y + w + w ;
	  ps->x[3] = x + w;
	  ps->y[3] = y + w + w;
  }
  else if (t == 23)
  {
	  ps->x[0] = x;
	  ps->y[0] = y;
	  ps->x[1] = x;
	  ps->y[1] = y + w;
	  ps->x[2] = x + w;
	  ps->y[2] = y;
	  ps->x[3] = x + w + w ;
	  ps->y[3] = y;
  }
  else if (t == 24)
  {
	  ps->x[0] = x;
	  ps->y[0] = y;
	  ps->x[1] = x + w;
	  ps->y[1] = y;
	  ps->x[2] = x + w;
	  ps->y[2] = y + w;
	  ps->x[3] = x + w;
	  ps->y[3] = y + w + w;
  }
  else if (t == 31)
  {
	  ps->x[0] = x;
	  ps->y[0] = y;
	  ps->x[1] = x + w;
	  ps->y[1] = y;
	  ps->x[2] = x + w;
	  ps->y[2] = y + w;
	  ps->x[3] = x + w + w ;
	  ps->y[3] = y + w;
  }
  else if (t == 32)
  {
	  ps->x[0] = x + w;
	  ps->y[0] = y;
	  ps->x[1] = x;
	  ps->y[1] = y + w;
	  ps->x[2] = x + w;
	  ps->y[2] = y + w;
	  ps->x[3] = x;
	  ps->y[3] = y + w + w;
  }
  else if (t == 41)
  {
	  ps->x[0] = x + w;
	  ps->y[0] = y;
	  ps->x[1] = x + w + w;
	  ps->y[1] = y;
	  ps->x[2] = x;
	  ps->y[2] = y + w;
	  ps->x[3] = x + w;
	  ps->y[3] = y + w;
  }
  else if (t == 42)
  {
	  ps->x[0] = x;
	  ps->y[0] = y;
	  ps->x[1] = x;
	  ps->y[1] = y + w;
	  ps->x[2] = x + w;
	  ps->y[2] = y + w;
	  ps->x[3] = x + w;
	  ps->y[3] = y + w + w;
  }
  else if (t == 51)
  {
	  ps->x[0] = x;
	  ps->y[0] = y;
	  ps->x[1] = x + w;
	  ps->y[1] = y;
	  ps->x[2] = x + w;
	  ps->y[2] = y + w;
	  ps->x[3] = x;
	  ps->y[3] = y + w;	
  }
  else if (t == 61)
  {
	  ps->x[0] = x + w;
	  ps->y[0] = y;
	  ps->x[1] = x;
	  ps->y[1] = y + w;
	  ps->x[2] = x + w;
	  ps->y[2] = y + w;
	  ps->x[3] = x + w + w ;
	  ps->y[3] = y + w;
  }
  else if (t == 62)
  {
	  ps->x[0] = x;
	  ps->y[0] = y;
	  ps->x[1] = x;
	  ps->y[1] = y + w;
	  ps->x[2] = x + w;
	  ps->y[2] = y + w;
	  ps->x[3] = x;
	  ps->y[3] = y + w + w;
  }
  else if (t == 63)
  {
	  ps->x[0] = x;
	  ps->y[0] = y;
	  ps->x[1] = x + w;
	  ps->y[1] = y;
	  ps->x[2] = x + w + w;
	  ps->y[2] = y;
	  ps->x[3] = x + w;
	  ps->y[3] = y + w;
  }
  else if (t == 64)
  {
	  ps->x[0] = x + w;
	  ps->y[0] = y;
	  ps->x[1] = x;
	  ps->y[1] = y + w;
	  ps->x[2] = x + w;
	  ps->y[2] = y + w;
	  ps->x[3] = x + w;
	  ps->y[3] = y + w + w;
  }
  else if (t == 71)
  {
	  ps->x[0] = x;
	  ps->y[0] = y;
	  ps->x[1] = x;
	  ps->y[1] = y + w;
	  ps->x[2] = x;
	  ps->y[2] = y + w + w;
	  ps->x[3] = x;
	  ps->y[3] = y + w + w + w;
  }
  else if (t == 72)
  {
	  ps->x[0] = x;
	  ps->y[0] = y;
	  ps->x[1] = x + w;
	  ps->y[1] = y;
	  ps->x[2] = x + w + w;
	  ps->y[2] = y;
	  ps->x[3] = x + w + w + w ;
	  ps->y[3] = y;
  }
  int i;
  for (i = 0 ; i < 4 ; i++)
  {
		draw_rect(ps->x[i],ps->y[i],w,w,c);
  }
}

void draw_brick(sprite_t* sp)
{
	int x,y,w,c,t;
    x = ((int*)sp->data)[0];
    y = ((int*)sp->data)[1];
    w = ((int*)sp->data)[2];
    c = ((int*)sp->data)[3];
    t = ((int*)sp->data)[4];
	int i,k;
	for (i = 0 ; i < 32; i ++)
		for (k = 0 ; k < 20 ; k ++)
		{
			if (road[i][k] == 1)
				draw_rect(i * 10,k * 10,w,w,c);
		}
    for (i =0 ; i < 20 ; i ++)
    {
	draw_rect(150,i * 10,3,3,0x40);
    }
}


void noop_tick(sprite_t* s){
  //noop
}

void hjkl_tick(sprite_t* s){
  int key = get_lastkey();

  int i,j;
  
  int x = ((int*)s->data)[0];
  int y = ((int*)s->data)[1];
  int w = ((int*)s->data)[2];
  int type = ((int*)s->data)[4];
  int diamX[4];
  int diamY[4];
  point_t*  ps = (point_t*)((char*)s->data + sizeof(sprite_t) + sizeof(int)*5);
  int ok = 1;
  for (i = 0 ; i < 4 ; i ++)
  {
	diamX[i] = ps->x[i];
	diamY[i] = ps->y[i];
  }

  for (i = 0 ; i < 4 ; i ++)
  {
    if (diamY[i] + w >= MAX_HEIGHT || road[diamX[i] / 10][(diamY[i] + w) / 10] == 1)
    {
      for (j = 0 ; j < 4 ; j ++)
        road[ps->x[j] / 10][ps->y[j] / 10] = 1;
      ok = 0;
      ((int*)s->data)[0] = START_X;
      ((int*)s->data)[1] = START_Y;
      ((int*)s->data)[4] = states[rand()%8];
      break;
    }
  }
  if (ok)
    ((int*)s->data)[1] += w;

  switch(key){
    case VKEY_DOWN:
	
		//clean();
			/*
	  if (y + w + w >= MAX_HEIGHT)
	  {

		//road[5][5] = 1;	
		for (i = 0 ; i < 4 ; i ++)
			road[ps->x[i] / 10][ps->y[i] / 10] = 1;
		((int*)s->data)[0] = 50;
		((int*)s->data)[1] = 0;
		((int*)s->data)[4] = 61;
	  }
	  
	  else
		((int*)s->data)[1] += w;
		*/
      break;
    case VKEY_UP:
      if (type == 11)
	  {
	     if(road[(x + w) / 10][(y+w) / 10] == 1 || road[x/10][(y+w+w+w)/10] == 1)
		 {((int*)s->data)[4] = 11; }
		 else ((int*)s->data)[4] = 12;
	  }
	  else if(type == 12)
	  {
	     if(road[(x+w+w)/10][(y+w)/10] == 1 || road[(x+w+w)/10][(y+w+w)/10] == 1)
		 {((int*)s->data)[4] = 12;}
		 else ((int*)s->data)[4] = 13;
	  }
	  else if(type == 13)
	  {
	     if(road[(x+w)/10][(y+w+w)/10] == 1 || road[(x+w)/10][(y+w+w+w)/10] == 1)
		 {((int*)s->data)[4] = 13;}
		 else ((int*)s->data)[4] = 14;
	  }
	  else if(type == 14)
	  {
	     if(road[x/10][(y+w)/10] == 1 || road[x/10][(y+w+w)/10] == 1)
		 {((int*)s->data)[4] = 14;}
		 else ((int*)s->data)[4] = 11;
	  }
	//  if (type >= 11 && type <=14)
	 // {
	//	((int*)s->data)[4] = (type + 1 > 14) ? (type + 1 - 4) : (type + 1);
	 // }
	  else if(type == 21)
	  {
	     if(road[x/10][(y+w)/10] == 1 || road[x/10][(y+w+w+w)/10] == 1 || road[(x+w)/10][(y+w+w+w)/10] == 1)
		 {((int*)s->data)[4] = 21;}
		 else ((int*)s->data)[4] = 22;
	  }
	  else if(type == 22)
	  {
	     if(road[(x+w)/10][(y+w)/10] == 1 || road[(x+w+w)/10][(y+w)/10] == 1)
		 {((int*)s->data)[4] = 22;}
		 else ((int*)s->data)[4] = 23;
	  }
	  else if(type == 23)
	  {
	     if(road[(x+w)/10][(y+w+w)/10] == 1 || road[(x+w)/10][(y+w+w+w)/10] == 1)
		 {((int*)s->data)[4] = 23;}
		 else ((int*)s->data)[4] = 24;
	  }
	  else if(type == 24)
	  {
	     if(road[(x+w+w)/10][(y+w)/10] == 1 || road[(x+w+w)/10][(y+w+w)/10] == 1 || road[x/10][(y+w+w)/10] == 1)
		 {((int*)s->data)[4] = 24;}
		 else ((int*)s->data)[4] = 21;
	  }	  
	/*  else if (type >= 21 && type <=24)
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
	  */
	  else if(type == 31)
	  {
	     if(road[x/10][(y+w+w)/10] == 1 || road[x/10][(y+w+w+w)/10] == 1)
		 {((int*)s->data)[4] = 31;}
		 else ((int*)s->data)[4] = 32;
	  }
	  else if(type == 32)
	  {
	     if(road[x/10][(y+w)/10] == 1 || road[(x+w+w)/10][(y+w+w)/10] == 1)
		 {((int*)s->data)[4] = 32;}
		 else ((int*)s->data)[4] = 31;
	  }
	  else if(type == 41)
	  {
	     if(road[x/10][(y+w)/10] == 1 || road[(x+w)/10][(y+w+w+w)/10] == 1)
		 {((int*)s->data)[4] = 41;}
		 else ((int*)s->data)[4] = 42;
	  }
	  else if(type == 42)
	  {
	     if(road[(x+w)/10][(y+w)/10] == 1 || road[(x+w+w)/10][(y+w)/10] == 1)
		 {((int*)s->data)[4] = 42;}
		 else ((int*)s->data)[4] = 41;
	  }	  
	  else if (type == 51)
	  {
		
	  }
	  
	 /* else if (type >= 61 && type <=64)
	  {
		((int*)s->data)[4] = (type + 1 > 64) ? (type + 1 - 4) : (type + 1);
	  }
	  else if (type >= 71 && type <=72)
	  {
		((int*)s->data)[4] = (type + 1 > 72) ? (type + 1 - 2) : (type + 1);
	  }*/
	  else if(type == 61)
	  {
	     if(road[x/10][(y+w)/10] == 1 || road[x/10][(y+w+w+w)/10] == 1)
		 {((int*)s->data)[4] = 61;}
		 else ((int*)s->data)[4] = 62;
	  }
	  else if(type == 62)
	  {
	     if(road[(x+w)/10][(y+w)/10] == 1 || road[(x+w+w)/10][(y+w)/10] == 1)
		 {((int*)s->data)[4] = 62;}
		 else ((int*)s->data)[4] = 63;
	  }
	  else if(type == 63)
	  {
	     if(road[x/10][(y+w+w)/10] == 1 || road[(x+w)/10][(y+w+w+w)/10] == 1)
		 {((int*)s->data)[4] = 63;}
		 else ((int*)s->data)[4] = 64;
	  }
	  else if(type == 64)
	  {
	     if( road[(x+w+w)/10][(y+w+w)/10] == 1 )
		 {((int*)s->data)[4] = 64;}
		 else ((int*)s->data)[4] = 61;
	  }

	  else if(type == 71)
	  {
	     if(road[(x+w)/10][(y+w)/10] == 1 || road[(x+w+w)/10][(y+w)/10] == 1 || road[(x+w+w+w)/10][(y+w)/10] == 1)
		 {((int*)s->data)[4] = 71;}
		 else ((int*)s->data)[4] = 72;
	  }
	  else if(type == 72)
	  {
	     if(road[x/10][(y+w+w)/10] == 1 || road[x/10][(y+w+w+w)/10] == 1 || road[x/10][(y+w+w+w+w)/10] == 1)
		 {((int*)s->data)[4] = 72;}
		 else ((int*)s->data)[4] = 71;
	  }
	  
	  
      break;
    case VKEY_LEFT:
	for (i = 0 ; i < 4 ; i ++)
		{
			if (diamX[i] - w < MIN_WIDTH || road[(diamX[i] - w) / 10][diamY[i] / 10] == 1)
			{
				if (diamY[i] + w >= MAX_HEIGHT || road[diamX[i] / 10][(diamY[i] + w) / 10] == 1)
				{
					for (i = 0 ; i < 4 ; i ++)
						road[ps->x[i] / 10][ps->y[i] / 10] = 1;
					
					((int*)s->data)[0] = START_X;
					((int*)s->data)[1] = START_Y;
					((int*)s->data)[4] = 61;
					
				}
				ok = 0;
				break;
			}
		}
		if (ok)
			((int*)s->data)[0] -= w;
      break;
    case VKEY_RIGHT:
		for (i = 0 ; i < 4 ; i ++)
		{
			if (diamX[i] + w >= MAX_WIDTH || road[(diamX[i] + w) / 10][diamY[i] / 10] == 1)
			{
				
				if (diamY[i] + w >= MAX_HEIGHT || road[diamX[i] / 10][(diamY[i] + w) / 10] == 1)
				{
					for (i = 0 ; i < 4 ; i ++)
						road[ps->x[i] / 10][ps->y[i] / 10] = 1;
					
					((int*)s->data)[0] = START_X;
					((int*)s->data)[1] = START_Y;
					((int*)s->data)[4] = 61;
					
				}
				ok = 0;
				break;
			}
		}
		if (ok)
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
  
  sprite_t *brick;
  
  //s1 = mk_sprite(0,0,10,0x20);
  //s2 = mk_sprite(0,50,10,0x20);
  //sa = mk_sprite(0,100,10,0x20);
  //sb = mk_sprite(0,150,10,0x20);
  
  brick = mk_sprite(0,0,10,0x30,0);
  l1 = mk_sprite(50,0,10,0x20 ,11);
  l2 = mk_sprite(60,50,10,0x20,31);
  la = mk_sprite(70,100,10,0x20,42);
  lb = mk_sprite(80,150,10,0x20,64);
  
  
  l1->d = draw_diam;
  l1->t = hjkl_tick;
  
  l2->d = draw_diam;
  l2->t = hjkl_tick;
  
  la->d = draw_diam;
  la->t = hjkl_tick;
  
  lb->d = draw_diam;
  lb->t = hjkl_tick;
  
  brick->d = draw_brick;
  brick->t = noop_tick;
  add_sprite(l1,0);
  add_sprite(brick,1);
  //add_sprite(l2,0);
  //add_sprite(la,0);
  //add_sprite(lb,0);
  

  srand(tick);
}

void main_p(){
  int i,j;
  int num_row = 0;
  int arr_row[MAX_HEIGHT];
  memset(arr_row,0,sizeof(arr_row));
  for (i = 0 ; i < MAX_HEIGHT / 10; i ++)
  {
	int count = 0;
	for (j = 0 ; j < MAX_WIDTH / 10 ; j ++)
	{
		if (road[j][i] == 1)
			count++;
	}
	if (count == MAX_WIDTH / 10)
	{
		arr_row[i] = 1;
		num_row++;
	}
  }
  int k;
  for (i = 0 ; i < MAX_HEIGHT / 10 ; i ++)
  {
	if (arr_row[i] == 1)
	{
		for (k = i ; k > 0 ; k --)
		{
			for (j = 0 ; j < MAX_WIDTH / 10 ; j ++ )
			{
				road[j][k] = road[j][k - 1];
			}
		}
	}
  }
}
