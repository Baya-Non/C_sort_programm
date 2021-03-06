/****binary search****/

#include <stdio.h>
#include <stdlib.h>
int *num;

int BSearch(int Number,int low,int max)
{
	int out;
	if(Number==num[low+max/2]){
		return(low+max)/2;
	}
	if(low==max){
		return -1;
	}	else if(Number<num[(low+max)]/2){
		out = BSearch(Number,low,(low+max)/2-1);
	}	else if(Number>num[(low+max)/2]){
		out = BSearch(Number,(low+max)/2+1,max);
	}
	
	return out;
}

int main()
{
	FILE *fp;
	int i=0;
	int x;
	
	if((fp=fopen("sorted.dat","r"))==NULL){
		printf("cant open file \n");
	}
	
	while((fscanf(fp,"%d",num[i]))==1) i++;
	printf("探索するプログラムを入力＞＞");
	scanf("%d",&i);
	x=BSearch(i,0,9999999);
	if(x<0){
		printf("%dは該当なし\n",i);
	}	else	{
		printf("%dは%d番目\n",i,x);
	}
	
	return 0;
	
}


