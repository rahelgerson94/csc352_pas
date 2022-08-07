//
//  game.c
//  pa7
//
//  Created by Rahel Gerson on 7/22/22.
//
#include "zq.h"
#include <stdio.h>
void play(ZQDecisionTreeNode* cur);
int main(int argc, const char * argv[]) {
    //questions = calloc(BUFFSIZE+1, sizeof(char));
    char* path = calloc(strlen(argv[1])+1, sizeof(char));
    //char* path = (char*)argv[1];
    strcpy(path, argv[1]);
    ZQDecisionTree* tree = ZQ_build_tree(path);
    //ZQ_print_tree(tree);
    ZQ_populate_tree(tree, path);
    //ZQ_print_tree(tree);
    play(tree->root);
    ZQ_free_tree(tree);
    free(path);
    return 0;
}

void play(ZQDecisionTreeNode* cur){
    char ans;
    if (cur->num_answers >=0){
        for (int i = 0; i < cur->num_answers; i++){
            printf("is it %s?\n", cur->answers[i]);
            scanf(" %c", &ans );
            if (ans == 'y'){
                printf("I guessed it!");
                return;
            }
        }
        printf("You got me :)\n");
    } //end base case
    else{ //begin recurrence
        printf("does it have %s?\n", cur->text);
        scanf(" %c", &ans);
        switch(ans){
            case 'y':
                play(cur->yes);
            break;
            case 'n':
                play(cur->no);
            break;
        }//switch
    }//end recurrence
}//end play()

 
