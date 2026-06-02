#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main(){
    int n,data;
    vector<int>arr;
    int sum = 0,maxi = INT_MIN;

    cout << "Enter no.of elements  : " << endl;
    cin >> n;

    cout << "Enter array elements  : " << endl;
    for(int i=0;i<n;i++){
        cin >> data;
        arr.push_back(data);
    }

    for(int i=0;i<n;i++){
        // add element to sum 
        sum = sum + arr[i];

        // update maxi
        if(sum > maxi)
            maxi = sum;

        // reset
        if(sum < 0)
            sum = 0;
    }

    cout << "Maximum subarray sum is : " << maxi << endl;

    return 0;
}