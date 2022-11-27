#include<bits/stdc++.h>
using namespace std;
pair<int,int> findElement(vector<vector<int>>matrix,int key){
    int row=0;
    int col=matrix.size()-1;
    while(row<matrix.size() and col>=0)
    {
        if(matrix[row][col]==key)
        return {row,col};
        if(matrix[row][col]>key)
        col--;
        if(matrix[row][col]<key)
        row++;
    }
    return {-1,-1};
}
int main(){
    vector<vector<int>> matrix={
        {4, 5, 6, 7},
        {8, 9, 10,11},
        {12,13,14,15},
        {16,17,18,19}
    };
    int key=13;
    pair<int,int> ans=findElement(matrix,key);
    cout<<"The "<<key<<" is at index: "<<ans.first<<","<<ans.second;
    return 0;
}
