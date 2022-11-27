#include<bits/stdc++.h>
using namespace std;
int findString(vector<string> str, string key, int left,int right){
    int low=0;
    int high=str.size()-1;

    while(low<=high){
        int mid=(low+high)/2;
        int left=mid ;
        int right=mid;
        if(str[mid]==key)
           return mid;
        while(left>=low and str[left]==""){
            left--;
        }
        while (right<=high and str[right]=="")
        {
            right++;
        }
        if(left>=low and str[left]==key)
        return left;
        if(right<=high and str[right]==key)
        return right;
        if(left>=low and str[left]<key)
        low=right+1;
        if(right<=high and str[right]>key) 
        high=left-1;
    }
}
int main(){
    vector<string> str{"at","","","ball","","","car","","","dad","",""};
    string key = "ball";
    cout << "Given string present at index " << findString(str,key, 0, str.size() - 1) << endl;

    return 0;
}
