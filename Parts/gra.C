#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
COORD cord={0,0};
void gotoxy(int x, int y){
	cord.X=x;
	cord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cord);
}
int rect(){
	int i;
		gotoxy(10,1);
		printf("%c",177);
	for(i=10;i<75;i++){	//for horizontal first side of rectangle.
		gotoxy(i,1);
		printf("%c",177);
	}
	gotoxy(75,1);
	printf("%c",177);
	for(i=1;i<35;i++){
		gotoxy(75,1+i);	//for vertical second side of rectangle.
		printf("%c\n",177);
	}
	for(i=1;i<35;i++){	//for vertical first side of rectangle.
	gotoxy(10,1+i);
	printf("%c",177);
	}
	for(i=10;i<75;i++){	//for horizontal second side of rectangle.
		gotoxy(i,35);
		printf("%c",177);
	}
}

int main(){
	
	char pasword[10],usrname[10], ch,a;
    int i,count=0,k;
    char stdpas[10] = "admin";
    char stdusn[10] = "admin";
    loop:
	system("cls");
	rect();
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
        //ch = '*' ;
        //printf("%c",ch);
        i++;
        }
    }
    pasword[i] = '\0';
	system("cls");
	rect();
	
    if (strcmp(stdpas,pasword) == 0 && strcmp(stdusn,usrname)==0){
        gotoxy(32,14);
        printf("Access Granted");
		gotoxy(32,15);
		printf("Press Enter To Continue:");
		
    }

        else{
        gotoxy(27,14);
        printf("Incorrect Password or username.");
		if(count==2){
			system("cls");
			gotoxy(27,16);
			printf("PROGRAM TERMINATED");
			k=getch();
			if(k== '\r'){
			exit(0);
		}
		}
		gotoxy(35,16);
		printf("%d Trial left",2-count);
		gotoxy(29,18);
		printf("PRESS ENTER TO TRY AGAIN");
		a=getch();
		
		
		if(a== '\r'){
			count++;
			goto loop;
		}
		else{
			exit(0);
		}
    }
	
	return 0;
}