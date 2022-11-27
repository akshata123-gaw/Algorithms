#include<iostream>
using namespace std;

int colour=0;

void placeTiles(int arr[8][8],int x1, int y1, int x2, int y2, int x3, int y3)
{
    colour+=1;

    arr[x1][y1]=colour;
    arr[x2][y2]=colour;
    arr[x3][y3]=colour;
}
int arrangeTiles(int arr[8][8], int n, int x, int y)
{
    if(n==2)
    {
        colour+=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[x+i][y+j]==0)
                {
                    arr[x+i][y+j]=colour;
                }
            }
        }
        return 0;
    }

    int tx,ty;
    for(int i=x;i<x+n;i++)
    {
        for(int j=y;j<y+n;j++)
        {
            if(arr[i][j]!=0)
            {
                tx=i;
                ty=j;
            }
        }
    }
    int Xmid=x+n/2;
    int Ymid=y+n/2;

    if(tx < Xmid and ty < Ymid)
    {
        placeTiles(arr,x+n/2,y-1+n/2,x+n/2,y+n/2,x-1+n/2,y+n/2);
    }
    if(tx < Xmid and ty >= Ymid)
    {
        placeTiles(arr,x+n/2,y-1+n/2,x+n/2,y+n/2,x-1+n/2,y-1+n/2);
    }
    if(tx >= Xmid and ty < Ymid)
    {
        placeTiles(arr,x-1+n/2,y+n/2,x+n/2,y+n/2,x-1+n/2,y-1+n/2);
    }
    if(tx>= Xmid and ty>=Ymid)
    {
        placeTiles(arr,x+n/2,y-1+n/2,x-1+n/2,y-1+n/2,x-1+n/2,y+n/2);
    }

    arrangeTiles(arr,n/2,x,y+n/2);
    arrangeTiles(arr,n/2,x,y);
    arrangeTiles(arr,n/2,x+n/2,y);
    arrangeTiles(arr,n/2,x+n/2,y+n/2);
    return 0;

}
int main(){
    int arr[8][8]={0};
    arr[0][0]=-1;
    int n=8;
    arrangeTiles(arr,n,0,0);

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
