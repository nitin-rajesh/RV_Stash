#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int table[1000];
void ShiftTableComputation(char p[])
{
    int m,i,j;
	m=strlen(p);
        for (i=0;i<1000;i++)
	    table[i]=m;
	for (j=0;j<=m-2;j++)
	   table[p[j]]=m-1-j;
}
	

int HPoolStringMatching(char p[],char t[])
{

    int m,n,i,j,k;
    //Shift Table Computation
	ShiftTableComputation(p);

	m=strlen(p);
	n=strlen(t);

	i=m-1;  // i ndex for text and j index for pattern
	while (i<=n-1)
	{
		k=0;
		while ((k<=m-1) && t[i-k]==p[m-1-k])
			k++;
		if (k==m)
			return i-m+1;
		else
			i=i+table[t[i]];
	}
	return -1;
}

int main()
{
    char str[100],ptr[100];
    int res;
	printf("Enter the text:");
	scanf("%[^\n]",str);
	printf("Enter pattern:");
	scanf("%s",ptr);
	res=HPoolStringMatching(ptr,str);
	if (res==-1)
		printf("Not found\n");
	else
		printf("Pattern found at position %d\n",res+1);
}
