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

}


void mergeSort(int arr[],int l,int r)
{
	if(l<r)
	{
		int mid= (l+r)/2;

		mergeSort(arr,l,mid);
		
		mergeSort(arr,mid+1,r);

		merge(arr,l,mid,r);
	}
}




void main()
{
	
	int n;

	printf("Print size:-");
	scanf("%d",&n);

	int ar[n];

	int i=0;
	while(i!=n)
	{
		printf("Enter Elements:-");
		scanf("%d",&ar[i++]);
	}

	mergeSort(ar,0,n-1);

	for(i=0;i<n;i++)
	{
		printf("%d ",ar[i]);
	}

	printf("\n");

}