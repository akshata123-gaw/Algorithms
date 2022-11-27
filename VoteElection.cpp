#include<iostream>
using namespace std;
int voteCount(int arr[],int n){
    int max=arr[0];
    for(int j=1;j<n;j++)
    {
        if(max<arr[j])
        {
            max=arr[j];
        }
    }
    int freq[max]={0};
    for(int i=0;i<n;i++){
        int k=arr[i];
        freq[k]++;
    }
    int u=freq[0];
    int c=0;
    for(int g=1;g<max;g++)
    {
        if(freq[g]>u)
        {
            u=freq[g];
            c=g;
        }
    }
    return c;
}
int main(){
    int arr[]={4,5,3,2,7,2,2,2};
    int n=sizeof(arr)/sizeof(int);
    int y=voteCount(arr,n);
    cout<<y;
    return 0;
}
