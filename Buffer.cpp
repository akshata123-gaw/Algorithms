#include<iostream>
using namespace std;
void merge(int A[], int n, int B[], int m)
{
    int i,j;
    i=n-1;
    j=m-1;
    int lastindex=n+m-1;

    while(j>=0)
    {
        if(i>=0 and A[i]>B[j])
        {
            A[lastindex]=A[i];
            i--;
            lastindex--;
        }
        else
        {
            A[lastindex]=B[j];
            j--;
            lastindex--;
        }
    }
}

int main()
{
    int A[]={2,3,7,13,67,-1,-1,-1,-1,-1};
    int n=5;
    int B[]={6,11,23,35,66};
    int m=5;
    cout<<"A: ";
    for(int i: A)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    merge(A,n,B,m);
cout<<"After Merged: ";
for(int i: A)
{
    cout<<i<<" ";
}
cout<<endl;
}
