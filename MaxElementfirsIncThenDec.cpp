#include<bits/stdc++.h>
using namespace std;

int findElement(vector<int> arr, int left, int right)
{
   if(left==right)
   {
        return arr[left];
   } 
   if((left+1 == right) and arr[left]>= arr[right])
   {
        return arr[left];
   }
   if((left+1 == right) and arr[left]<=arr[right])
   {
        return arr[right];
   }
   int mid=(left+right)/2;

   if(arr[mid-1]<arr[mid] and arr[mid]>arr[mid+1])
   {
        return arr[mid];
   }

   if(arr[mid-1] > arr[mid] and arr[mid] > arr[mid+1])
   {
        return findElement(arr, left, mid-1);
   }
   else
   {
       return findElement(arr, mid+1, right);
   }
}
int main(){
    vector<int> arr{9,14,22,87,90,56,45};
    int n=arr.size()-1;
    cout<<"Element founded is: "<<findElement(arr,0,n)<<endl;
    return 0;
}
