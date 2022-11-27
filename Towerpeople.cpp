#include<bits/stdc++.h>
using namespace std;
bool Compare(vector<int>v1,vector<int>v2)
{
    if(v1[0]<v2[0])
    {
        return true;
    }
    if(v1[0]>v2[0])
    {
        return false;
    }
    return v2[0]>=v1[0];
}

int getPerson(vector<vector<int>>&info)
{
    int count=1;
    
    sort(info.begin(),info.end(),Compare);
    for(int i=1;i<info.size();i++)
    {
        if(info[i][0] > info[i-1][0] and info[i][1] > info[i-1][1])
        {
            count++;
        }
    }
    return count;
}

int main(){

    vector<vector<int>>info{{65, 100}, {70, 105}, {56, 90}, {75,190}, {60, 95}, {68, 110}};
    cout<<"The number of possible person: "<<getPerson(info);
     
    return 0;
}
