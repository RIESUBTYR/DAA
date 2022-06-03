#include<stdio.h>
#include<time.h>


double time_taken;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  


void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
   		 for (j = 0; j < n-i-1; j++)  
        	if (arr[j] > arr[j+1])  
            	 swap(&arr[j], &arr[j+1]); 
}  


int BinarySearch(int arr[],int n,int s)
{
	int beg=0;
	int end=n-1;
	int mid;

	while(beg<=end)
	{
		mid=(beg+end)/2;

		if(arr[mid]==s)
			return 1;
		else if(arr[mid]<s)
			beg=mid+1;
		else
			end=mid-1;
	}

	return 0;
}




int LinearSearch(int arr[],int n,int s)
{
	int flag=0;

	for(int i=0;i<n;i++)
	{
		if(arr[i]==s)
			flag=1;
	}

	if(flag)
		return 1;
	else
		return 0;

}

void logic2(int arr[],int n,int p)
{
	clock_t start,end;

	start=clock();

	bubbleSort(arr,n);  

	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}	
    printf("\n");
	int flag=0;
	int r;
	for(int i=0;i<n;i++)
	{
		 r=arr[i];

		if(BinarySearch(arr,n,(p-r)))
		{
			flag=1;
			printf("Ans:-%d+%d=%d\n",r,(p-r),p);
			break;
		}
	}

	
	if(flag==0)
		printf("R and Q dosent exist\n");

	end=clock();
	time_taken=((double)(end-start))/CLOCKS_PER_SEC;

	printf("TIME TAKEN=%lf",time_taken);
}

void logic1(int arr[],int n,int p)
{
	clock_t start,end;

	start=clock();

	int r;
	int flag=0;

	for(int i=0;i<n;i++)
	{
		 r=arr[i];

		if(LinearSearch(arr,n,(p-r)))
		{
			flag=1;
			printf("Ans:-%d+%d=%d\n",r,(p-r),p);
			break;
		}
	}


	if(flag==0)
		printf("R and Q dosent exist\n");

	end=clock();
	time_taken=((double)(end-start))/CLOCKS_PER_SEC;

	printf("TIME TAKEN=%lf",time_taken);
}



void logic3(int arr[],int n,int p)
{
	clock_t start,end;

	start=clock();

	bubbleSort(arr,n); 

	int pos1=0;
	int pos2=n-1;
	int flag=0;
	while(pos1<=pos2)
	{
		int sum=arr[pos1]+arr[pos2];

			if(sum==p)
			{
				flag=1;
				printf("Ans:-%d+%d=%d\n",arr[pos1],arr[pos2],p);
				break;
			}
			else if (sum<p)
			{
				pos1++;
			}
			else
				pos2--;
	}

	if(flag==0)
		printf("R and Q dosent exist\n");

	end=clock();
	time_taken=((double)(end-start))/CLOCKS_PER_SEC;

	printf("TIME TAKEN=%lf",time_taken);
}

void main()
{
	clock_t start,end;
	
	int n;

	printf("Enter Array size:-");
	scanf("%d",&n);

	int arr[n];

	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}	

	int p;

	printf("Enter a number:-");
	scanf("%d",&p);

	start=clock();

	printf("Logic1:\n\n");
	logic1(arr,n,p);
	printf("\n\nLogic2:\n\n");
	logic2(arr,n,p);
	printf("\n\nLogic3:\n\n");
	logic3(arr,n,p);

	end=clock();
	time_taken=((double)(end-start))/CLOCKS_PER_SEC;

	printf("\n\nTOTAL TIME TAKEN=%lf",time_taken);
}