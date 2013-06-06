
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                               clock.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "string.h"
#include "proc.h"
#include "global.h"


/*======================================================================*
                           clock_handler
 *======================================================================*/
PUBLIC void clock_handler(int irq)
{
	//disp_str("#");

	if (k_reenter != 0) { /* �ж����� */
		//disp_str("!");
	//	return; /* ��ʾ!��ֱ�ӷ��� */
  	 draw_rect(0,0,320,200,0x80);
	}
	/* ���ж�����ʱ�л�����һ��PCB */
	p_proc_ready++;
	if (p_proc_ready >= proc_table + NR_TASKS) {
		p_proc_ready = proc_table;
	}

  tick++;
}
