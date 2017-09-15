/****merge_sort****/
#include <stdio.h>
#include <stdlib.h>
int tmp[1000000];

void msort();

void msort( int data[], int left, int right )
{
	
	int i,j,k,m;
	if(left >= right){
		return;
	}
	m=(left+right)/2;
	
	msort(data,left,m);
	msort(data,m+1,right);
	
	for(i=left;i<=m;i++){
		tmp[i]=data[i];
	}
	for(i=m+1,j=right;i <= right;i++,j--){
		tmp[i]=data[j];
	}
	i=left;
	j=right;
	
	for(k=left;k<=right;k++){
		if(tmp[i]<=tmp[j]){
			data[k] = tmp[i++];
		} else {
			data[k] = tmp[j--];
		}
	}
	
	
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
	
	
	 
	printf("ソート前\n");
    	for (i=0;i<n;i++){
        	printf("%d\n", data[i]);
	}
    	msort(data,0,n-1);

	printf("ソート後\n");
   	for (i=0;i<n;i++){
        	printf("%d\n", data[i]);
	}

}
