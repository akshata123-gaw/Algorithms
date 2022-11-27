#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> Hull;

int FindSide(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3)
{
     int side=(p3.second-p1.second)*(p2.first-p1.first)-(p3.first-p1.first)*(p2.second-p1.second);
     if(side<0)
        return -1;
     if(side>0)
        return 1;
     return 0;
}

int FindDist(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3)
{
    return abs((p3.second-p1.second)*(p2.first-p1.first)-(p3.first-p1.first)*(p2.second-p1.second));
}

void QuickHull(pair<int,int> a[],int n , pair<int,int> min_point, pair<int,int> max_point,int side)
{
    int ind=-1;
    int max_dist=0,i=0;
    int dist;
    while(i<n)
    {
        dist=FindDist(min_point,max_point,a[i]);
        if(dist>max_dist && FindSide(min_point,max_point,a[i])==side)
        {
            max_dist=dist;
ind=i;
        }
        i++;
    }

    if(ind==-1)
    {
        Hull.insert(min_point);
        Hull.insert(max_point);
        return;
    }

    QuickHull(a,n,a[ind],min_point,-1*FindSide(min_point,max_point,a[ind]));
    QuickHull(a,n,a[ind],max_point,-1*FindSide(max_point,min_point,a[ind]));
}

void SolveHull(pair<int,int> array[], int n)
{
    if(n<3)
    {
        cout<<"hull is not possible";
        return;
    }
    int i=1;
    int minx=0,maxx=0;
    while(i<n)
    {
        if(array[i].first<array[minx].first)
            minx=i;
        if(array[i].first>array[maxx].first)
            maxx=i;
        i++;
    }

    QuickHull(array,n,array[minx],array[maxx],1);
    QuickHull(array,n,array[minx],array[maxx],-1);

    cout << "\n\nThe points in Convex Hull are:\n";
while (!Hull.empty())
    {
        cout << "(" <<( *Hull.begin()).first << ", "
             << (*Hull.begin()).second << ") ";
        Hull.erase(Hull.begin());
    }

}

int main()
{
    int n;
    cout<<"Enter the No of Points: ";
    cin>>n;
    pair<int,int> array[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Point "<<i+1<<" ->";
        cin>>array[i].first>>array[i].second;
    }

    SolveHull(array,n);
    return 0;
}