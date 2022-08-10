//
//  main.c
//  final_funcs
//
//  Created by Rahel Gerson on 8/9/22.
//
#define BUFFSIZE 256
#include <stdio.h>
#include "final_funcs.h"

void prob7(){
    char words[] = "cheetah elephant cat";
    reverse_words(words);
    printf("%s\n", words);
    
    char w[] = "cat";
    reverse_word(w);
    printf("%s\n", w);
}
void prob2(){
    /* test quicksort_strs */
    char* pathname="/Users/rahelmizrahi/Library/Mobile_Documents/com~apple~CloudDocs/csc352/csc352_codes/final_funcs/prob2_words.txt";
    int num_lines=count_num_lines(pathname, BUFFSIZE);
    char* data[num_lines];
    read_(pathname, BUFFSIZE, data);
    quicksort_strs(data, num_lines);
    free_data(data, num_lines);
}
/* count the # of 1's in the binary rep. of num*/
void prob4(){
    unsigned long num = 7;

    printf("count_ones(%lu) = %d\n", num, count_ones(num) );
}

int main(int argc, const char * argv[]) {
    prob4();
    return 0;
}

