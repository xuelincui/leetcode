#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int l = 0;
    std::unordered_set<char> longestSubstring = {};
    int len = 0;

    for (int r = 0; r < s.length(); r++)
    {
        while (longestSubstring.find(s[r]) != longestSubstring.end())
        {
            longestSubstring.erase(s[l]);
            l++;
        }

        longestSubstring.insert(s[r]);

        len = r-l+1;
    }

    return len;
}

// Example 1:
//
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

int main()
{
    string s = "pwwkew";

    int l = lengthOfLongestSubstring( s);

    std::cout <<l << std::endl;
    return 0;
}