#include <iostream>
#include <string>

using namespace std;

// ret is a bool flag indicating whether x is a palidrone num or not
// ret->true->x is palidrone; ret->false->x is not a palidrone
bool isPalindrome(int x)
{
    std::string s = std::to_string(x);

    int l = 0;
    int r = s.length() - 1;

    while (r >= l)
    {
        if (s[l] == s[r])
        {
            l = l + 1;  // move l pointer to the right by 1 digit
            r = r - 1;  // move r pointer to the left by 1 digit
        }
        else
        {
            return false;
        }
    }

    return true;
}


int main()
{
    int x = 12345431;

    bool f = isPalindrome( x);

    std::cout << f << std::endl;

    return 0;
}