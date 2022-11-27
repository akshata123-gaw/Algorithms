#include <bits/stdc++.h>

using namespace std;

//structure to store cooardinates of starting and ending of building
struct buildingCoordinates{
    int x;
    int y;
    bool isStart;
};

// sorting the vector of buildingCoordinates using this comapre function
bool compare(buildingCoordinates &b1, buildingCoordinates &b2){
    // if x coordinate is small return true
    if(b1.x < b2.x)
        return 1;
    //if x coordinate is small return true
    if(b1.x > b2.x)
        return 0;
    // if x is equal and both are starting coordinates
    if(b1.isStart and b2.isStart)
        return b1.y > b2.y;
    // if x is equal and both are ending coordinates
    if(!b1.isStart and !b2.isStart)
        return b1.y < b2.y;
    //if first is starting coordinate
    if(b1.isStart)
        return 1;

    return 0;

}
// function to get coordinates of skyline
vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings){
    vector<buildingCoordinates> points;// store end and start points
    vector<pair<int, int>> skyline; //store ans

    //convert given data to start and end coo
    for(vector<int> building: buildings){
        points.push_back({building[0], building[2], true});

        points.push_back({building[1], building[2], false});
    }
    //sort points vector using the compare function
    sort(points.begin(), points.end(), compare);
    //multiset to hold starting points
    multiset<int> heights={0};
    int prevMax = 0;
    for(buildingCoordinates point: points){
        // if it is starting point insert it into the set
        if(point.isStart){
            heights.insert(point.y);
        }
        // if it is end point then remove it
        else{
            heights.erase(heights.find(point.y));
        }

        int currMax = *heights.rbegin(); // get max from the set
        if(prevMax != currMax){ //if max and prevMax are not same then push the x and currmax to ans vector
            prevMax = currMax;
            skyline.push_back({point.x, currMax});
        }
    }
    return skyline;
}

int main()
{
    vector<vector<int>> buildings{
        {2,9,10},
        {3,7,15},
        {5,12,12},
        {15,20,10},
        {19,24,8}
    };
    vector<pair<int, int>> ans = getSkyline(buildings);
    //printing skline coordinates
    for(auto i: ans){
        cout << i.first << " " << i.second << endl;
    }

}
