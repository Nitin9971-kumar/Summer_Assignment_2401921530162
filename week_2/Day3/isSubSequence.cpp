#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {

    int i = 0;
    int j = 0;

    while (i < s.length() && j < t.length()) {

        if (s[i] == t[j]) {
            i++;
        }

        j++;
    }

    return i == s.length();
}

int main() {

    string s = "abc";
    string t = "ahbgdc";

    if (isSubsequence(s, t))
        cout << "True";
    else
        cout << "False";

    return 0;
}
