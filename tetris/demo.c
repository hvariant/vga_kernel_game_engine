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

typedef struct Diam
{
  int x[500];
  int y[500];
} diam;

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
      //((int*)s->data)[0] -= (x - w >= 0) ? w : 0;
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
		/*
	   if (type == 11 || type == 13 || type == 21 || type == 23 
	  || type == 31 || type == 41 || type == 61 || type == 63)
	  {
		((int*)s->data)[0] = ((int*)s->data)[0] += (x + w + w + w + w <= MAX_WIDTH) ? w : 0;
	  }
	  else if (type == 12 || type == 14 || type == 22 ||
	  type == 24 || type == 32 || type == 42 || type == 51 || type == 62 || type == 64)
	  {
		((int*)s->data)[0] += (x + w + w + w <= MAX_WIDTH) ? w : 0;
	  }
	  if (type == 72)
	  {
		((int*)s->data)[0] += (x + w + w + w + w + w <= MAX_WIDTH) ? w : 0;
	  }
	  if (type == 71)
	  {
		((int*)s->data)[0] += (x + w +w <= MAX_WIDTH) ? w : 0;
	  }
      */
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

void clean()
{
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
	if (count == MAX_WIDTH / 10 - 1)
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
		for (k = 1 ; k < MAX_HEIGHT / 10 ; k ++)
		{
			for (j = 0 ; j < MAX_WIDTH / 10 ; j ++ )
			{
				road[j][k] = road[j][k - 1];
			}
		}
	}
  }
}

void main_p(){
  road[0][0] = 1;
  road[0][1] = 1;
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
