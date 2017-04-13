#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

COORD coord = {0,0};

void gotoxy(int x,int y);
void rect();
void add();
void adminpage();
int login();
void fpage();
void search(char name[20]);


struct DOB{
	int day;
	int month;
	int year;
};
struct nam{
		char fname[10];
		char lname[20];
	};
struct student {
	int id;
	struct nam name;
	char regi[20];
	int roll;
	char address[30];
	char phone[12];
	int year;
	char sem[10];
	struct DOB date;

};



	
int main(){
	system("CLS");
	rect();
	fpage();
}


void gotoxy(int x,int y){
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void rect(){
	int i;
	//Top line
	for(i=10;i<106;i++){
		gotoxy(i,9);
		printf("%c",257);
	}
	
	gotoxy(55,10);
	printf("SIM");
	gotoxy(45,11);
	printf("Student Information Manager");
	

	//2nd Top line
	for(i=10;i<106;i++){
		gotoxy(i,12);
		printf("%c",257);
	}
	
	//right line
	for(i=8;i<35;i++){
		gotoxy(105,1+i);
		printf("%c\n",257);
	}
	
	//Left line
	for(i=8;i<35;i++){
	gotoxy(10,1+i);
	printf("%c",257);
	}
		//Bottom line
	for(i=10;i<106;i++){
		gotoxy(i,35);
		printf("%c",257);
	}
}

void add(){
	rect();
	FILE *fptr;
	struct student record;
	static int i=0,id;
	char cont;

	id = i +1;
	gotoxy(90,14);
	printf("Id : %d",id);
	
	fptr=fopen("E:/SIMs/ff.txt","a+b");
	if (fptr==NULL){
		printf("FILE CANNOT BE CREATED\n");
		exit(0);
	}
	
	//print
	gotoxy(13,14);
	printf("Registration No.: ");
	gotoxy(13,16);
	printf("First name : ");
	gotoxy(47,16);
	printf("Last name : ");
	gotoxy(85,16);
	printf("Roll No. : ");
	gotoxy(13,18);
	printf("Address : ");
	gotoxy(47,18);
	printf("Phone No.: ");
	gotoxy(13,20);
	printf("Year: ");
	gotoxy(47,20);
	printf("Semester: ");
	gotoxy(13,22);
	printf("Date OF Birth (dd mm yyy): ");
	
	// scan
	gotoxy(31,14);
	scanf("%s",&record.regi);
	gotoxy(26,16);
	scanf("%s",&record.name.fname);
	gotoxy(59,16);
	scanf("%s",&record.name.lname);
	gotoxy(96,16);
	scanf("%d",&record.roll);
	gotoxy(23,18);
	scanf("%s",&record.address);
	gotoxy(58,18);
	scanf("%s",&record.phone);
	gotoxy(19,20);
	scanf("%d",&record.year);
	gotoxy(57,20);
	scanf("%s",&record.sem);
	gotoxy(40,22);
	scanf("%d %d %d",&record.date.day,&record.date.month,&record.date.year);
	
	fprintf(fptr,"\nRegistration No.:%s\t\t\tid=%d\nName: %s %s\t\troll no.: %d\naddress: %s\t\t\t\tphone no:%s\nyear: %d\t\t\t\t\t\nsemester:%s\nDOB:%d-%d-%d",record.regi,id,record.name.fname,record.name.lname,record.roll,record.address,record.phone,record.year,record.sem,record.date.day,record.date.month,record.date.year);
	fclose(fptr);
	gotoxy(13,24);
	printf("Add ? if yes press 'y': ");
	scanf(" %c",&cont);
	i++;
	printf("\n");
	
	if(cont == 'y'){
		system("CLS");
		add();
	}
	
	
	
}

void adminpage(){
	rect();
	int cho;
	gotoxy(47,15);
	printf("1. ADD");
	gotoxy(47,20);
	printf("2. Modify");
	gotoxy(47,25);
	printf("3. Delete");
	cho = getch();
	
	switch (cho){
		case '1':
			system("CLS");
			add();
			break;
		case '2':
			printf("modify");
			break;
		case '3':
			printf("Delete");
			break;
		default:
			adminpage();
	}
}

int login(){
	rect();
	char pasword[10],usrname[10], ch;
	int i=0;
	
	
	char stdpas[10] = "admin";
	char stdusn[10] = "admin";
	
	
	gotoxy(47,20);
	printf("user name: ");
	gotoxy(47,23);
	printf("Password: ");
	gotoxy(60,20);
	gets(usrname);
	gotoxy(60,23);
	
	
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
		gotoxy(47,26);
		printf("Access Granted");
		getch();
		system("CLS");
		adminpage();
	}

	else{
		gotoxy(47,26);
		printf("Incorrect Password or username");
		getch();
		system("CLS");
	}
}

void fpage(){
	rect();
	char swt;
	char sea[100];
	gotoxy(47,20);
	printf("1. Search");
	gotoxy(47,25);
	printf("2. Admin");
	swt = getch();
	
	switch (swt){
		case '1':
			gotoxy(70,22);
			printf("0");
			gotoxy(71,23);
			printf("\\");
			gotoxy(47,22);
			scanf("%s",sea);
			search(sea);
			break;
		case '2':
			system("CLS");
			login();
			break;
		default:
			fpage();
	}
}

void search(char name[20]){
	FILE *fp;
	int dataFound = 0;
	struct student record;	
	fp=fopen("ff.txt","a+");
	if(fp== NULL){
		printf("FILE NOT FOUND");
		exit(0);
	}
	else{
		while(fread(&record,sizeof(record),3,fp)==1){
			if ( strcmp(record.name.fname,name)==0){
				dataFound = 1;
			gotoxy(31,14);
			printf("Registration No.: %s",&record.regi);
			gotoxy(26,16);
			printf("%s",&record.name.fname);
			gotoxy(59,16);
			printf("%s",&record.name.lname);
			gotoxy(96,16);
			printf("%d",&record.roll);
			gotoxy(23,18);
			printf("%s",&record.address);
			gotoxy(58,18);
			printf("%s",&record.phone);
			gotoxy(19,20);
			printf("%d",&record.year);
			gotoxy(57,20);
			printf("%s",&record.sem);
			gotoxy(40,22);
			printf("%d %d %d",&record.date.day,&record.date.month,&record.date.year);
			}
			if (dataFound == 0){
			printf("Matching Document Not found");
			}
		
		}
	}
}