#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s)
{
    int end = s.length()-1;
    while (end > 0 && s[end] == ' ')    // remove all space at the end
    {
        end--;
    }

    if (end < 0)
        return 0;

    int start = end;
    while (start >= 0 && s[start] != ' ')   // looping over local string
    {
        start--;
    }

    return end -start;
}

int main()
{
    string s = "h";
    int l = lengthOfLastWord( s);

    std::cout << l << std::endl;
    return 0;
}