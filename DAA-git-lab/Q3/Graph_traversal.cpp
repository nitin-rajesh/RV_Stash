#include<stdio.h>

int stack[100];
int top = -1;
void dfs(int a[10][10],int n,int visited[10],int current)
{
	int j, v;
	stack[++top] = current;
	visited[current]=1;
	//printf("%d ",current);     
	for (j=0;j<n;j++)
	{
		if (a[current][j]==1 && visited[j]==0)      //current to j and j is not yet visited
		{
			dfs(a,n,visited,j);
		}
	}
	v = stack[top--];
	printf("%d  ", v);
}
void DFS(int a[10][10],int n)
{
  int visited[10],comp=0;

      for (int i=0;i<n;i++)
      {
	    visited[i]=0;
      }
	
	//To find DFS traversal 
	printf("DFS order:\n");
			
	for (int i=0;i<n;i++)
	{
		if (visited[i]==0)
		{
				dfs(a,n,visited,i);
				comp++;
		 }			
	}

    if (comp > 1)
	{
              printf("\nThe graph is disconnected \n");
              printf("\nThe no. of components are:%d\n",comp);
        }
	else
	{
		printf("\nGraph is connected.\n");
	}

}

void bfs(int a[10][10],int n,int visited[10],int current)
{

	int j,m;
        int queue[10],r=-1,f=0;//queue declaration and initialization

	queue[++r]=current; // insert and mark the vertex as visited
	visited[current]=1;

	while (   !(f> r)  )   // while queue not empty
	{
		
		m=queue[f++];
		printf("%d ",m);
		for (j=0;j<n;j++)
		{
			if (a[m][j]==1 && visited[j]==0)   
			{
				queue[++r]=j;   // insert and mark the vertex as visited
				visited[j]=1;
			}
		}
	}
}

void BFS(int a[10][10],int n) // to visit all the components of the graph
{
  int visited[10],comp=0;

      for (int i=0; i < n; i++)
      {
	    visited[i]=0;
      }
	
	//To find DFS traversal 
	printf("BFS order:\n");
			
	for (int i = 0; i < n; i++)
	{
	         if (visited[i]==0)
		 {
				bfs(a,n,visited,i);
				comp++;
		 }
	 
				
	}

        if (comp > 1)
	{
              printf("\nThe graph is disconnected \n");
              printf("\nThe no. of components are:%d\n",comp);
        }
	else
	{
		printf("\nGraph is connected.\n");
	}

}

int main()
{
	int a[10][10],n,i,j,comp=0;
	printf("Enter the no. of vertices:");
	scanf("%d",&n);
	
	//Accepting input matrix   for undirected  & 0,1 matrix
	printf("Enter the adjacency matrix:\n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	//Converting to undirected graph
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (a[j][i]==1)
			{
				a[i][j]=1;
			}
		}
	}
	
	DFS(a, n);
	BFS(a, n);


	return 0;
}
