#include <iostream>

using namespace std;

int getSubstringCount(string s)
{
    // count of binary substrings
    int count = 0;

    int prev_group_len = 0;      // length of previous group of identical letters
    int curr_group_len = 1;      // length of currnt group of identical letters

    for (int n = 1; n < s.length(); n++)
    {
        if (s[n-1] != s[n] )
        {
            count += min(prev_group_len, curr_group_len);
            prev_group_len = curr_group_len;
            curr_group_len = 1;
        }
        else
        {
            curr_group_len++;
        }
    }

    return count + min(prev_group_len, curr_group_len);
}


int main()
{
    string s = "";

    int n = getSubstringCount(s);
    std::cout << n<< std::endl;
    return 0;
}