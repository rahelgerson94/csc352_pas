//
//  binary_tree.h
//  binary_tree
//
//  Created by Rahel Gerson on 8/10/22.
//

#ifndef binary_tree_h
#define binary_tree_h

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utils.h"

typedef struct BinaryTreeNode{
    char* value;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

typedef struct BinaryTree{
    int node_count;
    struct BinaryTreeNode* root;
} BinaryTree;

typedef struct NumTreeNode {
       uint32_t value;
       struct NumTreeNode* left;
       struct NumTreeNode* right;
} NumTreeNode;

BinaryTree* BT_create();
void BT_insert(BinaryTree* bt, char* val);
BinaryTreeNode* BT_insert_helper(BinaryTreeNode* cur, char* val);
void BT_print(BinaryTree* bt);
void BT_print_helper(BinaryTreeNode* cur, int level);

NumTreeNode* NTN_create();
void NTN_insert(NumTreeNode* root, uint32_t val);
NumTreeNode* NTN_insert_helper(NumTreeNode* cur, uint32_t val);
void NTN_print(NumTreeNode* root);
void NTN_print_helper(NumTreeNode* cur, int level);

#endif /* binary_tree_h */
