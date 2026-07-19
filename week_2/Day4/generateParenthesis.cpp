#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(int open, int close, int n, string current,
           vector<string> &result) {

    // Base Case
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    // Add '(' if available
    if (open < n) {
        solve(open + 1, close, n, current + "(", result);
    }

    // Add ')' only if it won't make the string invalid
    if (close < open) {
        solve(open, close + 1, n, current + ")", result);
    }
}

vector<string> generateParenthesis(int n) {

    vector<string> result;

    solve(0, 0, n, "", result);

    return result;
}

int main() {

    int n = 3;

    vector<string> ans = generateParenthesis(n);

    for (string str : ans) {
        cout << str << endl;
    }

    return 0;
}
