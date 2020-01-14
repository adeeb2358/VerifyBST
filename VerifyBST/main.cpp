//
//  main.cpp
//  VerifyBST
//
//  Created by adeeb mohammed on 13/01/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//
// this is a program to validate BST using recursion
// the basic condition of a bst is that the left node must be less than the root
// node and right node must be greater than the parent node
// we need to find the left and right value ie min and max value of each
// node such that checking the properties will return whether the tree
// satisfies the tree property



#include <iostream>
#include <climits>

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool validateBSTHelper(BST *tree,int minVal,int maxVal){
    if(tree->value < minVal || tree->value >= maxVal){
        return false;
    }
    if(tree->left != NULL && !(validateBSTHelper(tree->left, minVal, tree->value))){
        return false;
    }
    if(tree->right != NULL && !(validateBSTHelper(tree->right, tree->value, maxVal))){
        return false;
    }
    return true;
}

// O(n) time n-> no of nodes in the tree | O(d) space d->depth of the tree
bool validateBst(BST *tree) {
    return validateBSTHelper(tree,INT_MIN,INT_MAX);
}


int main(int argc, const char * argv[]) {
    std::cout <<  "Validating BST";
    std::cout<< INT_MIN ;
    return 0;
}
