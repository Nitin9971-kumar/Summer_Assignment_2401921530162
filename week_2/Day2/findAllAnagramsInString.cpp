#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findAnagrams(string s, string p) {

    vector<int> ans;

    if (p.length() > s.length())
        return ans;

    vector<int> freqP(26, 0);
    vector<int> freqS(26, 0);

    // Frequency of pattern
    for (char ch : p)
        freqP[ch - 'a']++;

    int windowSize = p.length();

    // First Window
    for (int i = 0; i < windowSize; i++)
        freqS[s[i] - 'a']++;

    if (freqP == freqS)
        ans.push_back(0);

    // Sliding Window
    for (int i = windowSize; i < s.length(); i++) {

        // Add new character
        freqS[s[i] - 'a']++;

        // Remove old character
        freqS[s[i - windowSize] - 'a']--;

        if (freqP == freqS)
            ans.push_back(i - windowSize + 1);
    }

    return ans;
}

int main() {

    string s = "cbaebabacd";
    string p = "abc";

    vector<int> ans = findAnagrams(s, p);

    for (int index : ans)
        cout << index << " ";

    return 0;
}
