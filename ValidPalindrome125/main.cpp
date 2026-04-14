#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s)
{
    int l = 0;
    int r = s.length() - 1;

    while (l < r)
    {
        // Skip non-alphanumeric characters from left
        while (l < r && !isalnum(s[l]))
        {
            l++;
        }

        // Skip non-alphanumeric characters from left
        while (l < r && !isalnum(s[r]))
        {
            r--;
        }

        // convert to lower case
        if (tolower(s[l]) != tolower(s[r]))
            return false;

        l++;
        r--;
    }

    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    s = "0P";
    bool ret = isPalindrome( s);
    std::cout << ret <<std::boolalpha << std::endl;
    return 0;
}