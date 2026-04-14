#include <iostream>
#include <vector>

struct TreeNode
{
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> BST2Vector(TreeNode* root)
{
    std::vector<int> v;

    if (root != nullptr)
    {

    }
    else
    {
     // empty tree
    }

    return v;
}

int kthSmallest(TreeNode* root, int k)
{
    std::vector<int> v = BST2Vector( root);
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}