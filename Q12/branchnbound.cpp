#include<stdio.h>
 
int dist[10][10],completed[10],n,cost=0;
 
int least(int c)
{
  int i,nc=999;
  int min=999,kmin;
 
  for(i=0;i < n;i++)
  {
    if((dist[c][i]!=0)&&(completed[i]==0))
         if(dist[c][i]+dist[i][c] < min)
           {
               min=dist[i][0]+dist[c][i];
               kmin=dist[c][i];
               nc=i;
           }
  }
 
if(min!=999)
cost+=kmin;
 
return nc;
}
 
void mincost(int city)
{
  int i,ncity;
 
  completed[city]=1;
 
  printf("%d--->",city+1);
  ncity=least(city);
 
  if(ncity==999)
  {
     ncity=0;
     printf("%d",ncity+1);
     cost+=dist[city][ncity];
 
     return;
  }
 
  mincost(ncity);
}
 

int main()
{
   int i,j;

   printf("Enter the number of cities: ");
   scanf("%d",&n);
 
   printf("\nEnter the Cost/Distance Matrix\n");
 
   for(i=0;i < n;i++)
   {
      for( j=0;j < n;j++)
         scanf("%d",&dist[i][j]);
      completed[i]=0;
   }
 
   printf("\n\nThe Path is:\n");
   mincost(0); //passing 0 because starting vertex
 
   printf("\n\nMinimum cost is %d\n ",cost);
 
   return 0;
}