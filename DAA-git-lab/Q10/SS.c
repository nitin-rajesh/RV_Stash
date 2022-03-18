#include<stdio.h>
#define max 10
int d,s[max],x[max],flag=0,n,count =0;
void subsetsum(int p,int k,int r)
{
        
        int i;
        if( k > n)
            return ;
        if( p + s[k] > d )
            return ;
        if (p + r < d)   
            return ;
        // with kth element
        if(p+s[k]==d)
        {
                 x[k]=1;
                printf("\n Subset %d { ",++count);
                for(i=1;i<=k;i++)
                {
                        if(x[i]==1)
                                printf("%d\t",s[i]);
                }
                printf("}\n");
                flag=1;
        }
        x[k]=1;
        subsetsum(p+s[k],k+1,r-s[k]);
        // with out kth element
        x[k]=0;
        subsetsum(p,k+1,r-s[k]); 
       
}

void main()
{
        int i,sum=0;
        printf("Enter no of elements\n");
	scanf("%d",&n);
        printf("Enter elements in ascending order\n");
        for(i=1;i<=n;i++)
        {
                scanf("%d",&s[i]);
                sum+=s[i];
        }

        printf("\n Enter max subset value");
        scanf("%d",&d);
        
        subsetsum(0,1,sum);                 
        if(flag ==0)
                printf("\n No Solution");
}

