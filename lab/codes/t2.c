#include<stdio.h>
#include<string.h>
int main()
{
	int n,q,pt=0,count=0;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int bt[50],com[50],wt[50],tt[50],remBt[50];
	int counted[n];
	char process[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter the Brust Time for processes serially" );
		process[i]=i;
		scanf("%d",&bt[i]);
		remBt[i]=bt[i];
	}
	for (int i=0;i<n;i++){
		counted[i]=0;
	}
	printf("Enter Quantum time: ");
	scanf("%d",&q);
	while(1)
	{
		int c1=0;
		while(c1<n)
		{
			if (remBt[c1]==0 ){
				if (counted[c1]==0){
					counted[c1]=1;
					count++;
					if(count==n){
						break;
					}
				}
			}
			else if(remBt[c1]<=q ){
				if(remBt[c1]>0){
					pt+=remBt[c1];
					remBt[c1]=0;
					com[c1]=pt;
					tt[c1]=pt;
				}
			}
			else {
				pt+=q;
				remBt[c1]=remBt[c1]-q;
				tt[c1]=pt;
				com[c1]=pt;
			}
			c1++;
		}
		if(count==n){
		break;
		}
	}
	for(int i=0;i<n;i++)
	{
		wt[i]=tt[i]-bt[i];
	}
	printf("\nProcess CT TT WT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d %d %d %d\n",process[i]+1,com[i],tt[i],wt[i]);
	}
}
