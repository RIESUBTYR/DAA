  #include<stdio.h>
  
  int main()
  {
  	int n;
  	printf("Enter the number of rounds you will run extra on the given day :-\n ");
  	scanf("%d",&n);
  	int a[n];
  	
  	int i;
  	
  	for(i=1;i<=n;i++)
	{
		a[i] = i;
	}
	
	printf("The schedule of person till that day is \n");
	
	int end = n;
	int j = 2;
	int day=0;
	while(end>1)
	{
		while(j<=end)
		{
			printf("%d " , j);
			j = j*2;
		}
		printf("\n");
		end = end/2;
		j=2;
		++day;
	}
	printf("It is a %d day program.\n\n",day);
	return 0;
}
