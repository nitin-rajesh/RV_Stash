#include<stdio.h>
#include<stdlib.h>

int place(int p,int x[])
{
	int i;
	for (i=1;i<=(p-1);i++)
		if ((x[i]==x[p])||(abs(x[i]-x[p])==(abs(i-p))))
			return 0;
		return 1;
}

int main()
{
	int i,j,k,n,count=1,x[1500],flag =0;
	printf("Enter the number of queens:");
	scanf("%d",&n);
	
		
		x[1]=0;    //x[k] column no, k is row number
                k=1;
		while (k)
		{
			x[k]=x[k]+1;   
			while (x[k]<=n && !place(k,x))
				x[k]=x[k]+1;
			if (x[k]<=n)
			{
				if (k==n) // nth queen
				{
					printf("Solution %d\n",count++);
					 flag =1;
					for (i=1;i<=n;i++)   
					{
						for (j=1;j<x[i];j++)       
							printf("* ");
						printf("Q ");
						for (j=x[i]+1;j<=n;j++)
							printf("* ");
						printf("\n");
					}
				}
				else
				{
					k+=1;
					x[k]=0;
				}
			}
			else  
				k-=1;
		}
		if (flag ==0)
		    printf("No solution!!");
	
}
