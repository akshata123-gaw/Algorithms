#include <bits/stdc++.h>
using namespace std;
int main()
{ //
    // {profit,weight}
    vector<pair<int, int>> v = {{25, 18}, {24, 15}, {15, 10}};
    int capacity = 20;
    float ans = 0;
    // Sort according to decreasing order of profit sort(v.begin(),v.end(),greater<>());
    int i = 0;
    while (capacity != 0)
    {
        // if capacity of knapsack is more than or equal
        // to current weight then add it in knapsack
        if (capacity >= v[i].second)
        {
            ans += v[i].first;
            cout<<"ans:"<<ans<<endl;
            capacity -= v[i].second;
            cout<<"capacity:"<<capacity<<endl;
        }
        else
        { // take the fractional part of it float
           float x = (float)v[i].first / v[i].second;
           cout<<x<<endl;
            float y = x * capacity;
            cout<<y<<endl;
            ans += y;
            cout<<"ans:"<<ans<<endl;
            capacity -= x;
            cout<<"capacity:"<<capacity<<endl;
        }
        i++;
    }
    cout << "The maximum profit is " << ans << endl;
}