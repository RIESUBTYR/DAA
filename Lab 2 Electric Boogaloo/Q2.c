#include<stdio.h>
#include<time.h>

int arr[10000];

clock_t start,stop;

double time_taken;



/*FIRST LOGIC:- LINEAR SEARCH/LINEAR PROBING

	IF element isnt -1
		next position=pos+1;

	Until position == n

	or element -1 has been found
*/
void logic1()
{
	start=clock();
	int i=0;

	while(arr[i]!=-1)
	{
		i++;
	}
	if(i<10000)
	printf("Position=%d",i+1);
	else
	printf("Position not found");

	stop=clock();

	time_taken=(double)((stop-start)/CLOCKS_PER_SEC);

	printf("Time Taken by logic1 :-%lf",time_taken);

}

/* SECOND LOGIC-QUADRATIC PROBING
----------------------------------
   IF ELEMENT ISNT -1
   		NEXT POSITION=POS+i*i;

*/



void logic2()
{
	start=clock();

	int i=0;
	int quad=1;
	while(arr[i]!=-1)
	{
		i=i+(quad*quad);
		quad++;
	}

	while(arr[i-1]==-1)
	{
			i--;
	}
	if(arr[i]==-1)
	printf("Position:%d",i-1);
	else
	printf("Position not found");

	stop=clock();

	time_taken=(double)((stop-start)/CLOCKS_PER_SEC);

	printf("Time Taken by logic1 :-%lf",time_taken);

}

/*LOGIC -*/


void logic3()
{
	start=clock();


	int beg=0;
	int mid;
	int end=10000;
	int flag=0;
	while(beg<=end)
	{
		mid=(end+beg)/2;
		if(arr[mid]==-1)
		{
			if(arr[mid-1]==-1)
			{
			 	end=mid-1;
			}
			else
			{
				flag=1;
				printf("Position:%d",mid+1);
				break;
			}

		}
		else if(arr[mid]>arr[mid-1])
		{
			beg=mid+1;
		}
	}

	if(flag==0)
	{
		printf("Position not found");
	}


	stop=clock();

	time_taken=(double)((stop-start)/CLOCKS_PER_SEC);

	printf("Time Taken by logic1 :-%lf",time_taken);


}




void main()
{
int i=0;

do
{
	printf("Enter Element:-\n");
	scanf("%d",&arr[i]);
	i=i+1;
}while(arr[i-1]!=-1);

int j=i+1;

while(j<10000)
{
	arr[j++]=-1;
}

printf("\n\nLogic 1:\n\n");
logic1();
printf("\n\nLogic 2:\n\n");
logic2();
printf("\n\nLogic 3:\n\n");
logic3();

printf("\n\n");

}