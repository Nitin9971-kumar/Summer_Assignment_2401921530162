#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    int index = haystack.find(needle);

    if (index != string::npos)
        return index;

    return -1;
}

int main() {
    string haystack, needle;

    cout << "Enter haystack: ";
    cin >> haystack;

    cout << "Enter needle: ";
    cin >> needle;

    cout << strStr(haystack, needle);

    return 0;
}
