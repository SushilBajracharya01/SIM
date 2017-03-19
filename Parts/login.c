#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

COORD coord = {0,0};

void gotoxy(int x,int y){
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
	char pasword[10],usrname[10], ch;
	int i;
	char stdpas[10] = "admin";
	char stdusn[10] = "admin";
	gotoxy(32,10);
	printf("user name: ");
	gets(usrname);
	gotoxy(32,12);
	printf("Password: ");

	i=0;
	while(1){
		ch = getch();
		if(ch == '\r'){
			break;
		}
		else if(ch==8)
    	{     if(i!=0) /*this is for avoiding the ENTER instructions getting deleted */
    		{
     			printf("\b");  /*printing backspace to move cursor 1 pos back*/
    			printf("%c",32);/*making the char invisible which is already on console*/
    			printf("\b"); /*printing backspace to move cursor 1 pos back*/
    			i--;
    			pasword[i]='\0';
    		}
    		else
    		continue;
    	}
		
		else{
		pasword[i] = ch;
		putchar('*');
		i++;
		}
	}
	pasword[i] = '\0';

	if (strcmp(stdpas,pasword) == 0 && strcmp(stdusn,usrname)==0){
		gotoxy(32,14);
		printf("Access Granted");
	}

		else{
		gotoxy(27,14);
		printf("Incorrect Password or username");
	}
  return 0;
}
