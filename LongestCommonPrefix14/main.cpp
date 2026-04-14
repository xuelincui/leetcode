#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    string s_ret;

    int min_len = 1000;

    for (const string& str : strs)
    {
        if (str.size() < min_len)
        {
            min_len = static_cast<int>(str.size());
        }
    }

    int n = 0;

    while (n < min_len)
    {
        for (const string &str : strs)
        {
            if (str[n] != strs[0][n])
            {
                s_ret = str.substr(0, n);
                return s_ret;
            }
        }

        n++;
    }

    s_ret = strs[0].substr(0, n);
    return s_ret;
}

int main() {
    std::vector<std::string> strs = {"ab", "a"};

    string fl = longestCommonPrefix(strs);

    std::cout << fl << std::endl;
    return 0;
}