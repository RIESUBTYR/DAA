#include<iostream>

using namespace std;

void sort(int a[], int r[], int n1, int n2);

int main()
{
	int a[100][100];
	int k,n;
	cin >> k;
	
	int size[100];

	for(int i=0; i<k; i++)
	{
		cin >> size[i];
		for(int j=0; j<size[i]; j++)
		{
			cin >> a[i][j];
		}
	}
	
	int b[100];
	int total_size =0;
	
	for(int i=0; i<k; i++)
	{
		sort(b, a[i],total_size, size[i]);
		total_size += size[i];
	}
	
	for(int i=0; i<total_size ;i++)
	{
		cout << b[i] <<" ";
	}

return 0;
}

void sort(int a[], int r[], int n1, int n2)
{
	int l[n1];
	
	for(int i=0; i<n1; i++)
		l[i] = a[i];
		
	int k=0, k1=0, k2=0;
	
	while(k1<n1 && k2<n2)
	{
		if(l[k1] < r[k2])
		{
			a[k] = l[k1++];
		}
		else
		{
			a[k] = r[k2++];
		}
		k++;
	}
	
	while(k1<n1)
	{
		a[k++] = l[k1++];
	}
	
	while(k2<n2)
	{
		a[k++] = r[k2++];
	}
	
	
}
