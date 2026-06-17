#include <iostream>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                ans[i] = arr[j];
                break;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};

    vector<int> ans = nextGreaterElement(arr);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
