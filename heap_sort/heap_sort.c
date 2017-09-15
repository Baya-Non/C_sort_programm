/****heap_sort****/
#include <stdio.h>
#include <stdlib.h>



/* n 個のデータを表示する */
void ShowData(int x[],int n)
{
	int	i;
	for (i = 0; i < n ; i++){
		printf("%d  \n", x[i]);
	}
	printf("\n");
}

void sort(int d[],int i,int j)
{
	int num;
	num = d[i];
	d[i] = d[j];
	d[j] = num;
	
}


void heap( int d[], int n, int idx )
{
	int m,l,tmp;
	
	if(idx*2+1>n-1){
		return;
	}
	if(idx*2+2>n-1){
		if(d[idx]<d[2*idx+1]){
			sort(d,idx,2*idx+1);
		}
	}	else {
		if(d[idx]<d[2*idx+1]){
			sort(d,idx,2*idx+1);
		}
		
		if(d[idx]<d[2*idx+2]){
			sort(d,idx,2*idx+2);
		}
		
		if(2*(2*idx+2)+2<=n-1){
			if(d[2*idx+2]<d[2*(2*idx+2)+2] || d[2*idx+2]<d[2*(2*idx+2)+1]){
				heap(d,n,2*idx+2);
			}
		}
		
		else if(2*(2*idx+2)+1<=n-1){
			if(d[2*idx+2]<d[2*(2*idx+2)+1]){
				heap(d,n,2*idx+2);
			}
		}
		
		if(2*(2*idx+1)+2<=n-1){
			if(d[2*idx+1]<d[2*(2*idx+1)+2] || d[2*idx+1]<d[2*(2*idx+1)+1]){
				heap(d,n,2*idx+1);
			}
		}else if(2*(2*idx+1)+1<=n-1){
			if(d[2*idx+1]<d[2*(2*idx+1)+1]){
				heap(d,n,2*idx+1);
			}
			
		}
	}
}

int main()
{
	int i;
	int k,n=0,tmp,n1;
	
	FILE *fp;
	int d[1000000];
	
	fp=fopen("kadai_05_sample1.txt","r");
	
	while(fscanf(fp,"%d",&d[n])==1){
		n++;
	}
	n1=n;
	printf("ソート前\n");
	for(i=0;i<n;i++){
		printf("%d\n",d[i]);
	}
	printf("ソート中\n");
	for(k=n-1;k>=0;k--){
		heap(d,n,k);
	}
	
	while( n > 1 ) {
		tmp = d[0];
		d[0] = d[n-1];
		d[n-1] = tmp;
		n-- ;
		heap( d, n, 0 ) ;
	}
	printf("ソート後\n");
	
	for(i=0;i<n1;i++){
		printf("%d\n",d[i]);
	}


}