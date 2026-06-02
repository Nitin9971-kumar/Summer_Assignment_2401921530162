#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void  containsDuplicate(vector<int>&ans){
    unordered_map<int,int>mp;

    for(int i=0;i<ans.size();i++){
        if(mp[ans[i]] > 0){
            cout << "true";
            return;
        }
        mp[ans[i]]++;
    }
    cout << "false";
}

int main(){
    int n,data,flag=0;
    vector<int>arr;
    unordered_map<int,int>mp;

    cout << "Enter no.of elements : " << endl;
    cin >> n;

    cout << "Enter array elements : " << endl;
    for(int i=0;i<n;i++){
        cin >> data;
        arr.push_back(data);
    }

    containsDuplicate(arr);
    return 0;
}