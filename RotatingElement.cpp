#include<bits/stdc++.h>
using namespace std;

int findPivot(int arr[], int left, int right)
{
    if(left==right)
       return left;
    if(left > right)
    return -1;

    int mid=(left+right)/2;

    if(mid<right and arr[mid]>arr[mid+1])
    {
        return mid;
    }
    if(left<mid and arr[mid-1]>arr[mid])
    {
        return mid-1;
    }
    if(arr[left] >= arr[mid])
        return findPivot(arr, left, mid-1);
    
    return findPivot(arr, mid+1,right);

}

int BinarySearch(int arr[], int left, int right, int key)
{
    if(left==right)
    {
        return left;
    }
    if(left>right)
    {
        return -1;
    }
    int mid=(left+right)/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    if(arr[mid] > key)
    {
        return BinarySearch(arr,left, mid-1,key);
    }
    else
    {
        return BinarySearch(arr,mid+1,right,key);
    }
}

int HelperFunc(int arr[], int n, int target)
{
    int pivot=findPivot(arr, 0, n-1);

    if(pivot==-1)
    {
        return BinarySearch(arr,0,n-1,target);
    }
    if(arr[pivot]==target)
    {
        return pivot;
    }
    if(arr[0]<=target)
        return BinarySearch(arr,0,pivot-1,target);
    return BinarySearch(arr,pivot+1,n-1,target);
}

int main()
{
    int arr[]={15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=5;
    cout<<key<<" is present at index: "<<HelperFunc(arr, n, key)<<endl;
    return 0;
}
