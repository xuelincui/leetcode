//
// Created by xuelin on 4/14/25.
//

#ifndef BST_H
#define BST_H
#include <oneapi/tbb/partitioner.h>

#endif //BST_H


class bst
{
private:
    struct node
    {
        int key;
        node *left;
        node *right;
    };

    node* root;

    void AddLeafImpl(int key, node *node);

public:
    bst();

    node* CreateLeaf(int key);
    void AddLeaf(int key);
};
