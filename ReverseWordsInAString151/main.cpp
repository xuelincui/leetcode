#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

string reverseWords(string s)
{
    stringstream ss(s);
    string reversed = "";

    vector<string> vec_words;

    // split word from s
    string word;
    while (ss >> word)
    {
        vec_words.push_back(word);
    }

    // reverse words
    int l = 0;
    int r = vec_words.size() - 1;

    while ( l <= r )
    {
        string temp = vec_words[l];
        vec_words[l] = vec_words[r];
        vec_words[r] = temp;

        l++;
        r--;
    }

    // put reversed words in a string
    int n = 0;
    for (const auto& str : vec_words)
    {
        reversed += str;

        if (n < vec_words.size() - 1)
        {
            reversed += ' ';
        }

        n++;
    }

    return reversed;
}


// Example 1:
//
// Input: s = "the sky is blue"
// Output: "blue is sky the"

int main()
{
    string s = "the sky is blue";
    string ret_s = reverseWords( s);

    std::cout <<ret_s << std::endl;
    return 0;
}