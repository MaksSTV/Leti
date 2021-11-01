#define DOWN 0x06

#include <conio.h>
#include <dos.h>

void scroll(int lines, char attr){
union REGS r;
r.h.ah = DOWN;
r.h.al = lines;
r.h.cl = 14;
r.h.ch = 14;
r.h.dl = 64;
r.h.dh = 19;
r.h.bh = attr;
int86(0x10,&r,&r);

}

int main(){
	union REGS r;
	int lines;
	int i, j;
	lines = 2;

	clrscr();
	window(15,15,65,20);

	for (i = 0; i < 15 - 5 + 1; i++) cprintf("\n");
	for(i=0;i<16;i++){
	   for(j=0;j<8;j++){
	     textcolor(i);
	     switch(j){
	     case 0:{ textbackground(BLACK); if (!(i == 0 && j == 0)) cprintf("\r\n");
			  cprintf("%s%i","Black background and color number ",i);break;}
	     case 1:{ textbackground(BLUE);  if (!(i == 0 && j == 0)) cprintf("\r\n");
			 cprintf("%s%i","Blue background and color number ", i);  break;}
	     case 2:{ textbackground(GREEN); if (!(i == 0 && j == 0)) cprintf("\r\n");
			 cprintf("%s%i","Green background and color number ", i);  break;}
	     case 3:{ textbackground(CYAN); if (!(i == 0 && j == 0)) cprintf("\r\n");
			 cprintf("%s%i","Cyan background and color number ",i); break;}
	     case 4:{ textbackground(RED); if (!(i == 0 && j == 0)) cprintf("\r\n");
			 cprintf("%s%i","Red background and color number ",i);break;}
	     case 5:{ textbackground(MAGENTA); if (!(i == 0 && j == 0)) cprintf("\r\n");
			 cprintf("%s%i","Magenta background and color number ",i);break;}
	     case 6:{ textbackground(BROWN);  if (!(i == 0 && j == 0)) cprintf("\r\n");
			 cprintf("%s%i","Brown background and color number ",i); break;}
	     case 7:{ textbackground(LIGHTGRAY); if (!(i == 0 && j == 0)) cprintf("\r\n");
			 cprintf("%s%i","Lightgray background and color number ",i); break;}
	     }



	     clreol();
		 cprintf("\r\n");
	     scroll(lines-1,j*17);
	     /*cprintf("\r\n");*/

	     delay(800);

	   }

	 }

	 getch();



return 0;
}