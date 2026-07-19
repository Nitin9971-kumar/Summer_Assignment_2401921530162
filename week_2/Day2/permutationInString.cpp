#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkInclusion(string s1, string s2) {

    if (s1.length() > s2.length())
        return false;

    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);

    // Frequency of s1
    for (char ch : s1)
        freq1[ch - 'a']++;

    int windowSize = s1.length();

    // First Window
    for (int i = 0; i < windowSize; i++)
        freq2[s2[i] - 'a']++;

    if (freq1 == freq2)
        return true;

    // Sliding Window
    for (int i = windowSize; i < s2.length(); i++) {

        // Add new character
        freq2[s2[i] - 'a']++;

        // Remove old character
        freq2[s2[i - windowSize] - 'a']--;

        if (freq1 == freq2)
            return true;
    }

    return false;
}

int main() {

    string s1 = "ab";
    string s2 = "eidbaooo";

    if (checkInclusion(s1, s2))
        cout << "True";
    else
        cout << "False";

    return 0;
}
