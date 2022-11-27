#include<bits/stdc++.h>
using namespace std;

int partition(int *list, int left, int right)
{
    int pivot=list[left];
    int i=left;
    int j=right;

    while(i<j)
    {
        do{
            i++;
        }while(list[i]<=pivot);
        do
        {
            j--;
        } while(list[i]>pivot);
        if(i<j)
        {
            swap(list[i], list[j]);
        }
    }
    swap(list[left], list[j]);
    return j;
}

void QuickSort(int *list, int left, int right)
{
    if(left<right)
    {
        int j=partition(list, left, right);
        QuickSort(list, left, j);
        QuickSort(list, j+1, right);
    }
}

bool isSum(int *a1, int n, int *a2, int m, int key)
{
    QuickSort(a1, 0, n);
    for(int i=0;i<m;i++)
    {
        int sum=key-a2[i];
        int j=0, k=m-1;
        while(j <= k)
        {
            int mid=(j+k)/2;
            if(a1[mid] == sum)
                return true;
            else if(a1[mid] < sum)
                j=mid+1;
            else
                k=mid-1; 
            
        }
    }
    return false;
}
int main(){

    int a1[]={2, 0, 7, 5, 3, 8, 1};
    int a2[]={9, 11, 0, 6, 4, 10};

    int n=sizeof(a1)/sizeof(a1[0]);
    int m=sizeof(a2)/sizeof(a2[0]);

    int key=13;

    if(isSum(a1, n, a2, m, key))
    {
        cout<<"Given sum is present"<<endl;
    }
    else
    {
        cout<<"Sum is not present"<<endl;
    }
    return 0;
}
