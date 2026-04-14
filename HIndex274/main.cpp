#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int hIndex(vector<int>& citations)
{
    int h_idx = 0;

    std::vector<int> accumulate_paper_counts(citations.size()+1, 0);

    for (int n = 0; n <citations.size(); n++)
    {
        int num_citations = citations[n];

        if (num_citations > citations.size())
        {
            num_citations = citations.size();
        }

        accumulate_paper_counts[num_citations]++;
    }

    int n = citations.size();
    int total_citation = 0;     // total num of citation that >= a citation num
    while (n > 0)
    {
        total_citation += accumulate_paper_counts[n];
        if (total_citation >= n && n >= h_idx)
        {
            h_idx = n;
        }

        n--;
    }

    return h_idx;
}
int main()
{
    std::vector<int> citations = {3,0,6,1,5};

    int h_idx = hIndex( citations);

    std::cout << h_idx<< std::endl;
    return 0;
}