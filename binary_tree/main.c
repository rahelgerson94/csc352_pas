//
//  main.c
//  binary_tree
//
//  Created by Rahel Gerson on 8/10/22.
//

#include <stdio.h>
#include "binary_tree.h"
#define num_words 4
int main(int argc, const char * argv[]) {
    // insert code here...
   
    char* words[num_words] = {"intel", "rust", "camel", "elk"};
    
    BinaryTree* bt = BT_create();
    
    for (int i = 0; i < num_words; i++){
        BT_insert(bt, words[i]);
    }
    //BT_print(bt);
    
    NumTreeNode* root = NTN_create();
    uint32_t nums[6] = {1,4,5,6,8,3};
    for (int i = 0; i < 6; i++){
        NTN_insert(root, nums[i]);
    }
    NTN_print(root);
    return 0;
}
