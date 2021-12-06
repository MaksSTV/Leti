	#include "stdio.h"
	#include "conio.h"
	#include "math.h"
	#include "dos.h"

	#define SPACE 32
	#define DOWN 72
	#define UP 80
	#define ESC 27

	
	int x1 = 0, y1 = 0,x2 = 0,x3=0,y3=0;
	int y2 = 0, over = 1, down = 0;
	float del = 0;
	int score = 0;
	int scry = 0;
	int live = 0;
	int cord, x = 7, y = 6, j;

	int getchar1(){
	    union REGS reg;
	    reg.h.ah = 0x08;
	    int86(0x21,&reg,&reg);
	    return reg.h.al;
	}
	
	void generate_new_x1(){
	    if (x1 == 1) {
	        x1 = 49;
			y1 = rand() % 10;
	        gotoxy(x1, y1);
	    }
	    
	}

	void generate_new_x2(){
	    if (x2 == 1) {
	        x2 = 49;
			y2 = rand() % 10;
	        gotoxy(x2, y2);
	    } 
	}

	void generate_bullet() {
		if (cord == SPACE) {
			x3 = x;
			y3 = y;
			gotoxy(x3, y3);
		}
	}

	void move() {
		if ((cord == UP) || (cord == DOWN)) {
			if (cord == DOWN)
				if (y > 1) y--;
			if (cord == UP)
				if (y <= 10) y++;
		}
	}
	
	main() {
	
	    textbackground(0);
	    clrscr();
	    window(15, 5, 65, 15);

	    textbackground(15);
	    clrscr();
	    textcolor(0);

	    x2 = x1 + 15;
	    del = 70;
	    y1 = y;
	    over = 4;
	    scry = 2;
	    live = 1;

	    while (live != 0) {
	        y = y1;
	        y2 = y1;
	        x1 = x + 15;
	        x2 = x1 + rand() % 30 + 4;
	        down = 0;
	        score = 0;
	        while (1) {
	            cord = 0;
	            if ((kbhit()) && (down == 0))
	                cord = getch();
				if (cord == ESC) { live--; break; }
				gotoxy(x, y);
				cprintf(">");
	            gotoxy(x1, y1);
	            generate_new_x1();
				gotoxy(x2, y2);
	            generate_new_x2();
				
	            cprintf("*");
	            x1--;
	            x2--;
				
				move();
				
				gotoxy(x3, y3);
				cprintf("-");
				generate_bullet();
				x3++;
	            delay(del);
				if (((x3 == x2) && (y3 == y2)) || ((x3 == x1) && (y3 == y1))) {
					if ((x3 == x2) && (y3 == y2)) {
						x2 = 1;
						y2 = 1;
					}
					else if((x3 == x1) && (y3 == y1)){
						x1 = 1;
						y1 = 1;
					}
				}
	            clrscr();
	        }
	    }
}