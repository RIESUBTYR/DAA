#include<stdio.h>
	
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

	void printArrayWithSum (int arr[],int n)
    {
        int sum1 = 0;
        for (int i=0; i<n; i++)
        {
            sum1 += arr[i];
            printf("%d,",arr[i]);
        }
        printf("=%d\n\n",sum1);
    }
 
    void divideInEqualSums(int arr[],int n, int set1[], int set2[],int setSize) 
    {
        bubbleSort(arr,n);
        
        int pos1=0;
        int pos2=0;
        
        int i=n-1;
        
        int sum1 = 0;
        int sum2 = 0;


        while (pos1 < setSize && pos2 < setSize)
        {
            if (sum1 < sum2)
            {
                set1[pos1] = arr[i];
                pos1++;
                sum1 += arr[i];
            }
            else
            {
                set2[pos2] = arr[i];
                pos2++;
                sum2 += arr[i];
            }
            i--;
        }
        
        while (i>=0)
        {
            if (pos1 < setSize)
                set1[pos1++] = arr[i];
            else
                set2[pos2++] = arr[i];
            i--;
        }
/*
        int point1=0;
        int point2=0;

        while(point1!=setSize || point2!=setSize)
       	{
       		int temp_sum1=sum1;
       		int temp_sum2=sum2;
       		int diff=sum1-sum2;
       		int difference=set1[point1]-set2[point2];
       		if(difference<0)
       		{
       			temp_sum1 -= difference;
       			temp_sum2 += difference;
       		}
       		else
       		{
       			temp_sum2 -= difference;
       			temp_sum1 += difference;
       		}

       		int new_diff=temp_sum1-temp_sum2;

       		if(new_diff<diff)
       		{
       			if(diff>0)
       			swap(&set1[point1],&set2[point2]);
       			else
       			swap(&set1[point1],&set2[point2]);
       		}

       		diff=sum1-sum2;
       		
        }
*/

        printArrayWithSum(arr,n);
        printArrayWithSum(set1,setSize);
        printArrayWithSum(set2,setSize);
    }
    
    void main ()
    {
    	int n;

    	printf("Size of array:-");
    	scanf("%d",&n);
    	int arr[n];
    	printf("Enter elements:-\n");
    	for(int i=0;i<n;i++)
    	{
    		scanf("%d",&arr[i]);
    	}

    	int setSize=(1+n)/2;
        int set1[(1+n)/2];
        int set2[(1+n)/2];
        
        divideInEqualSums (arr,n,set1,set2,setSize);
    }
    