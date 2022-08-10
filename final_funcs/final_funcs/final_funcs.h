

#ifndef final_funcs_h
#define final_funcs_h

#include <stdio.h>
#include <string.h>

#include "utils.h"

typedef struct StringLLNode {
    char* string;
    struct StringLLNode* next;
  } StringLLNode;

void reverse_words(char line[]);
void reverse_word(char word[]);
void StringLLNode_sort();
void quicksort_strs(char const *args[], unsigned int len);
void swap_str_ptrs(char const **arg1, char const **arg2);
int count_ones(unsigned long num);

#endif /* final_funcs_h */
