
/***quicksort***/
/* ex) 4,6,2,7,10,35,2,1,8 */
#include <stdio.h>

  /* n 個のデータを表示する */
void ShowData(int x[ ], int n)
{
    int i;

    for (i = 0; i < n ; i++)
        printf("%d  \n", x[i]);
    printf("\n");
}

void quicksort(int d[],int a,int b)
{
	
	
	int left = a;
	int right = b;
	
	int pivot = d[(a+b)/2];
	int num;
	while(1){
	
		while(d[left]<pivot) left++;
		while(d[right]>pivot) right--;
		
		if(left>=right){
			break;
		}
		
		num = d[left];
		d[left] = d[right];
		d[right] = num;
		
		left++;
		right--;
	
	}
	
	if(a<left-1)quicksort(d,a,left-1);
	if(right+1<b)quicksort(d,right+1,b);
	
}

int main()
{
	FILE *fp;
	int data[1000000];
	int n=0,i;
	fp=fopen("kadai_05_sample1.txt","r");
	
	while(fscanf(fp,"%d",&data[n])==1){
		n++;
	}
	fclose(fp);
	quicksort(data,0,n-1);
	
	ShowData(data,n);

}


/**************** 実行結果 *****************


*******************************************/
