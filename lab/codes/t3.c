#include <stdio.h>
#include<string.h>

void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
	}
	
int main(){
	int n;
	int pt=0;
	int bt[50],at[50],remBt[50],wt[50],tt[50],c[50];
	printf("Enter total number of Process: ");
	scanf("%d",&n);
	int priority[n];
	char process[n][n],t[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter the Process names arrival time,brust time and priority: \n");//input format= p1 0 5 2
		scanf(" %s %d %d %d",process[i],&at[i],&bt[i],&priority[i]);
		remBt[i]=bt[i];
	}
	//printf("ss");
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if (at[j]<at[i]){
				swap(&priority[i],&priority[j]);
				swap(&at[i],&at[j]);
				swap(&bt[i],&bt[j]);
				swap(&remBt[i],&remBt[j]);
				strcpy(t,process[i]);
				strcpy(process[i],process[j]);
				strcpy(process[j],t);
			}
		}
	}
	
	priority[100]=9999;
	int count=0,c1=0, c2=0;
	while(count<n){
		int minIndex=100;
		pt++;
		c2=0;
		while (c2<n){
			if (at[c2]<=c1 && priority[c2]<priority[minIndex] && remBt[c2]>0){
				minIndex=c2;
			}
			c2++;
		}
		remBt[minIndex]=remBt[minIndex]-1;
		if (remBt[minIndex]==0){
			count++;
			tt[minIndex]=pt-at[minIndex];
			wt[minIndex]=tt[minIndex]-bt[minIndex];
			c[minIndex]=pt;
		}
		c1++;
	}
	printf("\nPName CT TT WT\n");
	for(int i=0;i<n;i++){
		printf("%s %d %d %d\n",process[i],c[i],tt[i],wt[i]);
	}
}
	
