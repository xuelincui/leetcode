#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

bool isValid(string s)
{
    bool ret = false;
    vector<char> stack;

    for ( const char &c:s)
    {
        if (c == '[' || c == '(' || c == '{' )
        {
            stack.push_back(c);
        }
        else if  (c == ']' && !stack.empty() && stack.back() == '[' )
        {
            stack.pop_back();
        }
        else if  (c == ')' && !stack.empty() && stack.back() == '(' )
        {
            stack.pop_back();
        }
        else if  (c == '}' && !stack.empty() && stack.back() == '{' )
        {
            stack.pop_back();
        }
        else
        {
            stack.push_back(c);
        }
    }

    if (stack.empty())
        ret = true;

    return ret;

}

int main()
{
    string s = "]";
    bool ret = isValid(s);

    std::cout << std::boolalpha<< ret  << std::endl;
    return 0;
}