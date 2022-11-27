#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int par[1000005];
// function to find parent
int find(int i)
{
    if(par[i] == i) return i;
    return par[i] = find(par[i]);
}
// merge two segments
void merge(int a,int b)
{
    a = find(a);
    b = find(b);
    par[b] = a;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=0;i<=n;i++) par[i] = i;
    vector<pair<int,int>> v;

    for(int i=0;i<n;i++)
    {
        int deadline,profit;
        cin >> deadline >> profit;
        v.push_back({profit,deadline});
    }

    sort(v.begin(),v.end(),greater<pair<int,int>>());

    int profitSum = 0;

    for(int i=0;i<n;i++)
    {
        int deadline = v[i].second;
        int profit = v[i].first;
        // finding the latest available day for a deadline(before)
        int last_available_day = find(deadline);

        // Check whether any day is avaible
        if(last_available_day > 0)
        {
            profitSum += profit;

            // merging day and day-1 so that next time day-1 will be latest availble day
            merge(last_available_day-1,last_available_day);
        }
    }
    
    cout << profitSum;
    
    

    return 0;
}
