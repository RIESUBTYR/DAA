#include<stdio.h>
#include<time.h>

int binaryAddition(int binary1,int binary2)
{
 
    int i=0,remainder = 0,sum[20];
 
    int binarySum=0;
 
    while(binary1!=0||binary2!=0)
 
{
 
         sum[i++] =  (binary1 %10 + binary2 %10 + remainder ) % 2;
 
         remainder = (binary1 %10 + binary2 %10 + remainder ) / 2;
 
         binary1 = binary1/10;
 
         binary2 = binary2/10;
 
    }
 
    if(remainder!=0)
 
         sum[i++] = remainder;
 
    --i;
 
    while(i>=0)
 
         binarySum = binarySum*10 + sum[i--];
 
    return binarySum;
 
}




void main()
{
	int digit;

	int n;
	scanf("%d",&n);

	int binary1=0;
	int binary2;

	long multiply;

	int factor=1;

	while(n!=0)
	{
		binary1=binary1+(factor*(n%2));
		factor*=10;
		n=n/2;
	}

	binary2=binary1;

	factor=1;

	long binary=binary1;

    while (binary2 != 0)
    {

        digit =  binary2 % 10;

        if (digit == 1)
        {

            binary1 = binary1 * factor;

            multiply = binaryAddition(binary1, multiply);

        }

        else
            binary1 = binary1 * factor;

        binary2 = binary2 / 10;

        factor = 10;
    }
    printf("Product of two binary numbers: %ld", multiply);

    printf("Product :-%ld",binary*binary);
}