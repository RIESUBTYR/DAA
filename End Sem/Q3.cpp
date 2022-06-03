/*Hrishikesh Rajesh Menon-COE18B024
	Logic-Taking each element from the matrix(aka every relation) you print with(include) and without(exclude) that pair continously until youve done all 
	n^2 pairs and through recursion you will go through every possible relation.

	Suggestion:-Inputs of more than 10 are not to be advised(Huge computation time :- 2^(2^10) = 2^100 = 1.26* e^30 different combinations!!)
*/
#include<iostream>
#include<cmath>
using namespace std;

    long maximum;
	int n;
	int relnno;
	int *arr;
	int **reln;

void constructor(int num)
{
	relnno = 0;

	n=num;
	

	reln = (int**)malloc(n*sizeof(int*));
	arr = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
	{
		arr[i] = i;
		reln[i] = (int*)malloc(n*sizeof(int));
	}
	return;
}

void print()
{
	relnno++;
	cout<<"Relation "<<relnno<<":"<<endl;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			if(reln[i][j] == 1)
				cout << "(" << arr[i] << "," << arr[j] << "),";
			if(relnno==maximum && i==n-1 && j==i) 
				cout<<"NULL";//To Print NULL which is the last relation 
		}
	cout<<"\n\n";
	return;
}

void listRelations(int i, int j)
{
	for(int l=1; l>=0; l--)
	{
		reln[i][j] = l;
		if( i == n-1 && j == n-1)
			print();
		else if( j == n-1)
			listRelations(i+1,0);//To go to the next row
		else 
			listRelations(i,j+1);//To go along the row
	}
	return;
}

int main()
{	
	int num;
	cout<<"Enter the number of elements";
	cin >> num;
	constructor(num);
	maximum=long(pow(2,pow(n,2)));
	listRelations(0 , 0);
	return 0;
}