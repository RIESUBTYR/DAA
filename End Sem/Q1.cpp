/* Hrishikesh Rajesh Menon -  COE18B024

    Logic:- Keep dividing the array 3 ways with the termination conditions as :-
        1.Division only has 1 element
        2.Division only has 2 elements
        (The division can only end with these as if its 2 it will just subdivide into 1+1 and thats a waste of computation)
    
    Checking for perfect square - Take the number and root it while type casting it to int(if it isnt a perfect square the root when type casting will not give the same number)

    set a static count variable,
    check if it reaches the termination condition and count up based on the check of the number/pair of numbers
    */

#include<iostream>
#include<cmath>
using namespace std;

static int count=0;

bool isPerfectSquare(int num)
{
    int root= int(sqrt(num));

    if(root*root == num) return true;
    else return false;
}


void numperfectsq(int arr[],int l,int r)
{
	int m=l+(r-l)/3;
	int n=l+(2*(r-l))/3;
	if(l==r)
    {
        if(isPerfectSquare(arr[l]))
        count++;
    }
    else if(l-r==2)
    {
        if(isPerfectSquare(arr[l]))
        count++;

        if(isPerfectSquare(arr[r-1]))
        count++;
    }
    else
    {
    numperfectsq(arr,l,m);
    if(m+1<=n)
	numperfectsq(arr,m+1,n);
	numperfectsq(arr,n+1,r);
    }	
}



int main()
{
    /*
    int x;
    cin>>x;
    if(isPerfectSquare(x))
    cout<<"It is a perfect square"<<endl;
    else
    cout<<"It is not a perfect square"<<endl;
    */
   int n;
   cout<<"How many integers to accept:";
   cin>>n;

   int ar[n];
    cout<<"Enter elements:-"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    numperfectsq(ar,0,n-1);

    cout<<"Enter number of perfect squares:-"<<count<<endl;

    return 0;

}