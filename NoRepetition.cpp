#include<iostream>
using namespace std;

int partition(int *list, int left, int right)
{
    int pivot=list[left];
    int i=left;
    int j=right;
    while(i<j)
    {
        do
        {
            i++;
        }while(list[i] <= pivot);

        do
        {
            j--;
        } while(list[j] > pivot);

        if(i < j)
        {
            swap(list[i], list[j]);
        } 
    }
    swap(list[left], list[right]);
    return j;
}

void QuickSort(int *list, int left, int right)
{
    if(left < right)
    {
        int j=partition(list, left, right);
        QuickSort(list,left,j);
        QuickSort(list,j+1,right);
    }
}

bool isRepeated(int *list, int n)
{
    QuickSort(list, 0, n);

    for(int i=1;i<n;i++)
    {
        if(list[i-1]==list[i])
        {
            return true;
        }
    }
    return false;
}

int main(){
    int list[]={10, 4, 8, 1, 2, 3};
    int n=sizeof(list)/sizeof(list[0]);

    if(isRepeated(list, n))
    {
        cout<<"Duplicate elements present"<<endl;
    }
    else{
        cout<<"No Duplicate elements present"<<endl;
    }
    
    return 0;
}
