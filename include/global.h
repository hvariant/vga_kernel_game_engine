
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            global.h
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/* EXTERN is defined as extern except in global.c */
#ifdef	GLOBAL_VARIABLES_HERE
#undef	EXTERN
#define	EXTERN
#endif

EXTERN	int		disp_pos;
EXTERN	u8		gdt_ptr[6];	// 0~15:Limit  16~47:Base
EXTERN	DESCRIPTOR	gdt[GDT_SIZE];
EXTERN	u8		idt_ptr[6];	// 0~15:Limit  16~47:Base
EXTERN	GATE	idt[IDT_SIZE];

EXTERN	u32		k_reenter;

EXTERN	TSS		tss;
EXTERN	PROCESS*	p_proc_ready;

EXTERN  char      double_buf[320*200+10];

EXTERN  volatile int     tick;

EXTERN  volatile int     keys_len;
EXTERN  volatile int     keys[KEY_BUFFER_SIZE];

extern	PROCESS		proc_table[];
extern	char		task_stack[];
extern  TASK        task_table[];
extern	irq_handler	irq_table[];


