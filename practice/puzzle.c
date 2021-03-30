#include <stdio.h>
#include <stdlib.h>
#include <termio.h>
#include <string.h>
#include <time.h>
int getch(void) {
    int ch;
    struct termios buf;
    struct termios save;
    tcgetattr(0, &save);
    buf = save;
    buf.c_lflag &= ~(ICANON | ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch=getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}
void prt_pz(int a[4][4]);
int cmp_pz(int arr[4][4]);
void mix_pz(int arr[4][4]);
int mv_pz(int* x, int* y, int arr[4][4]);
int main(int argc, char *argv[]){
	int a,b=1,c=1;
	int x=3,y=3;
	a= (int) *argv[1] -'0';
	int puz[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
 	switch(a){
	case 1 :
	system("clear");
	prt_pz(puz);
	break;
	case 2 :
	system("clear");
	mix_pz(puz);
	prt_pz(puz);
	break;
	default :
	return 0;
	}
	while(b){
	c= mv_pz(&x,&y,puz);
	if(c==0)
	return 0; 
	system("clear");
	prt_pz(puz);
	b= cmp_pz(puz);
	}

printf("축하합니다");
sleep(3);
return 0;
}
void prt_pz(int arr[4][4]){
printf("\n\n\n\n\n\n\n\n");
    for (int i = 0; i < 4; i++) {
        printf("\t\t\t\t");
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] == 0)
                printf("  ");
            else
                printf(" %3d ", arr[i][j]);
        }
        printf("\n");
    }

return;
}


int cmp_pz(int arr[4][4]){
int sol[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
int k=0;
for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] == sol[i][j])
                k++;
      	}}
if (k==16)
	return 0;     
else
	return 1;
}
void mix_pz(int arr[4][4]) {
    int list[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    int p;
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 3 && j == 3)
                break;
            p = rand() % (15 - (4 * i) -j);
            arr[i][j] = list[p];
            for (int k = p; k < 14 - (4 * i) -j; k++) {
                list[k] = list[k + 1];
            }
        }
    }
return ;	
}

int mv_pz(int *x, int *y, int arr[4][4]){
char ch;
int temp;
ch= getch();
switch(ch){
	case (27) :
	return 0;
	case 'j' :
		if((*y)==0){
		printf("다시 입력해 주세요");
		return 1;}	
	temp=arr[*x][*(y)-1];
	arr[*x][*(y)-1]=arr[*x][*y];
	arr[*x][*y]=temp;
	(*y)--;
	return 1;
	case 'k' :
		if((*x)==3){
		printf("다시 입력해 주세요");
		return 1;}	
	temp=arr[(*x)+1][*y];
	arr[*(x)+1][*y]=arr[*x][*y];
	arr[*x][*y]=temp;
	(*x)++;
	return 1;
	case 'l' :
	if((*y)==3){
		printf("다시 입력해 주세요");
		return 1;}	
	temp=arr[*x][(*y)+1];
	arr[*x][(*y)+1]=arr[*x][*y];
	arr[*x][*y]=temp;
	(*y)++;
	return 1;
	case 'i' :
	if((*x)==0){
		printf("다시 입력해 주세요");
		return 1;}	
	temp=arr[(*x)-1][*y];
	arr[(*x)-1][*y]=arr[*x][*y];
	arr[*x][*y]=temp;
	(*x)--;
	return 1;
	}
}





