//
//  binary_tree.c
//  binary_tree
//
//  Created by Rahel Gerson on 8/10/22.
//

#include "binary_tree.h"

BinaryTree* BT_create(){
    BinaryTree* bt = malloc(sizeof(BinaryTree));
    bt->node_count = 0;
    bt->root = NULL;
    return bt;
}
void BT_insert(BinaryTree* bt, char* val){
    bt->root = BT_insert_helper(bt->root, val);
}

BinaryTreeNode* BT_insert_helper(BinaryTreeNode* cur, char* val){
    if (cur == NULL){
        BinaryTreeNode* node = malloc(sizeof(BinaryTreeNode));
        node->value = malloc(sizeof(char)*(strlen(val)+1));
        strcpy(node->value, val);
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    int res = strcmp( val, cur->value);
    //neg : go left
    //pos: go right
    // 0 : already exists
    if (res < 0){ //go left
        cur->left = BT_insert_helper(cur->left, val);
    }
    else if (res > 0 ){ //go right
        cur->right = BT_insert_helper(cur->right, val);
    }
    return cur;
}

void BT_print(BinaryTree* bt){
    BT_print_helper(bt->root, 0);
}
void BT_print_helper(BinaryTreeNode* cur, int level){
    if (cur == NULL){
        return;
    }
    else{
        print_spaces(level);
        printf("[cur: %p  left: %p  right: %p  value: %s]\n",
               cur, cur->left, cur->right, cur->value);
        BT_print_helper(cur->left, level+1);
        BT_print_helper(cur->right, level+1);
    }
}

NumTreeNode* NTN_create(){
    NumTreeNode* node = malloc(sizeof(NumTreeNode));
    node->left= NULL;
    node->right= NULL;
    return node;
}
void NTN_insert(NumTreeNode* root, uint32_t val){
    root = NTN_insert_helper(root, val);
}

NumTreeNode* NTN_insert_helper(NumTreeNode* cur, uint32_t val){
    if (cur == NULL){
        NumTreeNode* node = malloc(sizeof(NumTreeNode));
        node->value = val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    if (val < cur->value){ //go left
        cur->left = NTN_insert_helper(cur->left, val);
    }
    else if (val > cur->value)
        cur->right = NTN_insert_helper(cur->right, val);
    return cur;
}
void NTN_print(NumTreeNode* node){
    NTN_print_helper(node, 0);
}
void NTN_print_helper(NumTreeNode* cur, int level){
        if (cur == NULL){
            return;
        }
        else{
            print_spaces(level);
            printf("[cur: %p  left: %p  right: %p  value: %d]\n",
                   cur, cur->left, cur->right, cur->value);
            NTN_print_helper(cur->left, level+1);
            NTN_print_helper(cur->right, level+1);
        }
}


