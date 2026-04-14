//
// Created by xuelin on 4/14/25.
//

#include "bst.h"

bst::bst()
{
    root = nullptr;
}


bst::node* bst::CreateLeaf(int key)
{
    node* n = new node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;

    return n;
}


void bst::AddLeafImpl(int key, node* n)
{

}

void bst::AddLeaf(int key)
{
    AddLeafImpl( key, root);

}