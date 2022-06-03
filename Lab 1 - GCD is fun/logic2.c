//using euclidean algorithm
#include<stdio.h>
int gcditterative(int a,int b);
int gcdrecursion(int a,int b);
int main()
{
	int a,b;
	printf("Enter two numbers\n");
	scanf("%d %d",&a,&b);
	printf("GCD of given two numbers using itterative method is :");
	int gcd,gd;
	
	if(a>=0 && b>=0)
	{	
		a = a;
		b = b;
	}
	else if(a<0 && b>=0)
	{	
		a = -a;
		b = b;
	}
	else if(a>=0 && b<0)
	{	
		a = a;
		b = -b;
	}
	else
	{	
		a = -a;
		b = -b;
	}
	
	gcd = gcditterative(a,b);

	printf("%d\n",gcd);
	
	gd = gcdrecursion(a,b);
	printf("GCD of given two numbers using recursive method is :");
	printf("%d\n",gd);
	return 0;
}

int gcditterative(int a,int b)
{
	while(a!=0)
	{
		int d = a;
		a = b%a;
		b = d;
	}
	return b;
}


int gcdrecursion(int a,int b)
{
	if(a==0)
		return b;
	else
		return gcdrecursion(b%a,a);
}
	
