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

	int minindex=0;
	int maxindex=0;
	start=clock();
	
	for(i=1;i<n;i++)
	{
		if(a[i]<a[minindex])
		{
			minindex=i;
		}
		if(a[i]>a[maxindex])
		{
			maxindex=i;
		}
	}
	end=clock();

	printf("Max value:-%d \nMin Value:-%d\n\n",a[maxindex],a[minindex]);
	time_taken=(double)(end-start)/CLOCKS_PER_SEC;
	printf("time:-%lf\n\n",time_taken);

}