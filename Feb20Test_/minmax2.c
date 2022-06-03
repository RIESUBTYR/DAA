#include<stdio.h>
#include<time.h>

void main()
{
	clock_t start,end;
	double time_taken;
	
	int i;
	int n;
	printf("Number of ELements:-\n");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter %d Elements:-\n",n );
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	int min,max;

	start=clock();
	
	if(n%2==0)
	{
		if(a[0]>a[1])
		{
			min=a[1];
			max=a[0];
		}
		else
		{
			min=a[0];
			max=a[1];
		}
		i=2;
	}
	else
	{
		min=a[0];
		max=a[0];
		i=1;
	}

	while(i<n-1)
		{
			if(a[i]>a[i+1])
			{
				if(a[i]>max)
					max=a[i];
				if (a[i+1]<min)
					min=a[i+1];
			}
			else
			{
				if(a[i+1]>max)
					max=a[i+1];
				if(a[i]<min)
					min=a[i];
			}

			i+=2;
		}
	
	end=clock();

	printf("Max value:-%d \nMin Value:-%d\n\n",max,min);

	time_taken=(double)(end-start)/CLOCKS_PER_SEC;
	printf("time:-%lf\n\n",time_taken);

}