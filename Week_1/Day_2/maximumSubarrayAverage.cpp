#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
    int n,data;
    vector<int>arr;
    cout << "Enter no.of elements : " << endl;
    cin >> n;

    cout << "Enter data elements : " << endl;
    for(int i=0;i<n;i++){
        cin >> data;
        arr.push_back(data);
    }

    double avg = 0;
    double maxi = INT_MIN;
    int sum = 0;

    int k;
    cout << "Enter size of window : " << endl;
    cin >> k;

    if(k > n){
        cout << "Invalid window size : " << endl;
        return 0;
    }

    int l = 0,r=k-1;
    for(int i=0;i<=r;i++){
        sum = sum + arr[i];
    }

    avg = (double)sum / k;
    maxi = avg;

    while(r < n-1){
        sum = sum - arr[l];
        l++;
        r++;
        sum = sum + arr[r];

        avg = (double)sum / k;
        maxi = max(avg,maxi);
    }

    cout << "Maximum average of subarray is : " << maxi << endl;
    return 0;
}