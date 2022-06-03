#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int size1=m-l+1;
	int size2=r-m;

	int L[size1],R[size2];

	for(i=0;i<size1;i++)
		L[i] =arr[l+i];

	for(j=0;j<size2;j++)
		R[j] =arr[m+1+j];


	i=0;
	j=0;
	k=l;

	while(i<size1 && j<size2)
	{

		if(L[i] <= R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}

	while(i<size1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}

	while(j<size2)
	{
		arr[k]=R[j];
		k++;
		j++;
	}

    printf("\nStep:-\n");
    for(i=0;i<k;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
}

void main()
{
    int k;
    printf("Enter no of arrays:-");
    scanf("%d",&k);    
    int arr[k][100];
    int n[k];

    int size=0;


    for(int i=0;i<k;i++)
    {
        printf("Enter size of array %d:-",i+1);
        scanf("%d",&n[i]);
        size+=n[i];
        for(int j=0;j<n[i];j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

     for(int i=0;i<k;i++)
    {
       for(int j=0;j<n[i];j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    int Output[size];

    int p=0;

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n[i];j++)
        {
            Output[p++]=arr[i][j];
        }
    }

    p=2;
    int mid=n[0]-1;
    int r=n[0]+n[1]-1;

    printf("\n\nUnsorted:-\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ", Output[i]);
    }

    printf("\n");
    
    int count=0;
    
    do
    {

        merge(Output,0,mid,r);
        
        mid=r;
        
        r+=n[p++];

    }while(p<=k);
    
    printf("\nSorted:-\n");
    
    for(int i=0;i<size;i++)
    {
        printf("%d ", Output[i]);
    }
}