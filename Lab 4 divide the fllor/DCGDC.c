#include<stdio.h>
#include<time.h>


int gcd(int a ,int b)
{
	if(a==0)
		return b;
	else
		return gcd(b%a,a);
}
int lcm(int a,int b)
{
	return (a*b)/gcd(a,b);
}

int dc(int arr[],int beg,int end)
{
	if(beg-end==1)
	{
		return gcd(arr[beg],arr[end]);
	}
	if(beg-end==0)
	{
	return arr[beg];
	}
	else
	{
	int a=dc(arr,beg,(beg+end)/2);
	
	int b=dc(arr,(beg+end)/2+1,end);

	return gcd(a,b);
	}	
}

int dclcm(int arr[],int beg,int end)
{
	if(beg-end==1)
	{
		return	lcm(arr[beg],arr[end]);
	}
	if(beg-end==0)
	{
		return arr[beg];
	}
	int a=dclcm(arr,beg,(beg+end)/2);

	int b=dclcm(arr,(beg+end)/2+1,end);

	return lcm(a,b);
}
	



void main()
{
	clock_t start,end;

	double time_taken;


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


	start=clock();

  	printf("Gcd of these numbers is :-%d",dc(ar,0,n-1));
	printf("LCM of these numbers is :-%d\n",dclcm(ar,0,n-1));

	end=clock();


	time_taken=(double)(end-start);
}