#include<bits/stdc++.h>
using namespace std;
vector<string> getAnagrams(vector<string> input)
{
    unordered_map<string,vector<string>> anagrams;

    vector<string> answer;
    for(string s:input)
    {
        string temp=s;
        sort(temp.begin(),temp.end());
        anagrams[temp].push_back(s);
    }
    for(auto it: anagrams ){
        for(string e:it.second){
        answer.push_back(e);
        }
    }
    return answer;
}
int main(){
    vector<string> input;
    input.push_back("tap");
    input.push_back("pat");
    input.push_back("apt");
    input.push_back("rat");
    input.push_back("act");
    input.push_back("tan");
    input.push_back("art");

    cout<<"Bafore sorting :"<<endl;
    for(string q:input){
        cout<<q<< " ";
    }
    cout<<"\n\n";
    vector<string> answer=getAnagrams(input);
    cout<<"After sorting :"<<endl;
    for(string a:answer){
        cout<<a<<" ";
    }
    cout<<"\n\n";

    return 0;
}
