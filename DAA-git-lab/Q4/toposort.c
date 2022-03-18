#include<stdio.h>
#include<stdlib.h>

int TopoSort(int n, int a[10][10],int indegree[10],int output[10])
{
	int i, j, k = 0;
        
        i = 0;
	while (i < n) // repeatedly find the source vertex
	{   
	    
	    
		   if (indegree[i]==0)// find a source vertex : vertex with 0 indegree
		   {
			indegree[i]=-1;  // deleting the vertex indicated by -1 indegere array(0-1= -1)
			output[k++]= i;    // copy the verex i to the output array

          		for (j=0;j<n;j++) // delete all outgoing edgees from i  to j 
			{
				if (indegree[j] != -1 && indegree[j]!= 0  &&   a[i][j] == 1  ) 
				{
					indegree[j]--;
				}
			}
			i=0;//each time start from beginning
		   }
                   else
                     i++;
	}
	return k;
}

int main()
{
	int i,j,adj[10][10],m,n,b[10],indegree[10];
	printf("Enter no. of vertices:");
	scanf("%d",&n);
        // indegree is set to zero for all vertices: initialization
        for (i=0;i<n;i++)
	{
		indegree[i]=0;
	}
        
	printf("Enter adjacency matrix:\n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
			if (adj[i][j]==1) // update the indegree of vertex j because there is an edge from i to j
				indegree[j]++;
		}
	}
        
	m=TopoSort(n,adj,indegree,b);
	if (m!=n) // some vertices could not be deleted
	{
		printf("\nCycle Detected. Topological sort not possible");
	}
	else
	{
		printf("\nTopological ordering is:");
		for (i=0;i<n;i++)
		{
			printf("%d ",b[i]);
		}
	}
	return 0;
}
