#include<stdio.h>
#include<stdlib.h>

void prims(int g[20][20], int n)
{
	int vt[20],e[20],min,u1,v1;
	int ne,i,j,cost=0;
	//source is take as vertex 0
         
	for (i=0;i<n;i++)  //  initialization all vertices not in min spanning tree
	{
		vt[i]=0;     
	}
       	
                     // Remove source vertex 0 from vr and source vertex is inculded in spanning tree vertex set vt   
        vt[0]=1;
  
	printf("Minimum spanning tree edges:\n");
        // Select  n-1 edges of spanning tree
         ne=1;
	while (ne<n)
	{
		min=999; //infinity
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				if (g[i][j]<min)
				{
					if (i!=j && vt[i]==1 && vt[j]!=1)  // selecting edge from i to j such that i is in 
                                                                           // spanning tree and j is not in spanning tree
					{
						min=g[i][j];
						u1=i;
						v1=j;
					}
				}
			}
		}
		cost+=min;
		vt[v1]=1;
		
		ne++;
		printf("Edge from vertex %d to %d\n",u1+1,v1+1);
		
	}
	printf("The weight of the minimum spanning tree is %d",cost);
}
int main()
{
	int n,g[20][20],i,j;
	printf("Enter the no. of vertices:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	prims(g,n);
}
