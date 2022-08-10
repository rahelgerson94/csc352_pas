//
//  final_funcs.c
//  final_funcs
//
//  Created by Rahel Gerson on 8/9/22.
//

#include "final_funcs.h"
///* line will be modified in place, so it is passed by reference*/
//void reverse_words(char* line[]){
//    int num_lines = count_char(*line, ' ')+1;
//    char* output[num_lines];
//    delimit(*line, ' ', output); //alloc'd
//    //reset_char_arr(*line, 0, (int)strlen(*line));
//
//    int out_start=0;
//    for (int i = 0; i < num_lines; i++){
//        int cur_word_len = (int)strlen(output[i]);
//        char cur_word[cur_word_len+1];
//        strcpy(cur_word, output[i]);
//        reverse_word(&cur_word);
//        strcpy_(*line, cur_word, out_start, 0, cur_word_len);
//        *line[cur_word_len] = ' ';
//        out_start = out_start + cur_word_len+ 1;
//    }
//    for (int i = 0; i < num_lines; i++){
//        free(output[i]);
//    }
//
//}

/* line will be modified in place, so it is passed by reference*/
//                1  1 1
//0     6| 8      5| 7 9
//cheetah| elephant| cat
void reverse_words(char line[]){
    int num_lines = count_char(line, ' ')+1;
    char* output[num_lines];
    delimit(line, ' ', output); //alloc'd
   
    int out_start=0;
    for (int i = 0; i < num_lines; i++){
        int cur_word_len = (int)strlen(output[i]);
        char cur_word[cur_word_len+1]; reset_char_arr(cur_word, 0, cur_word_len+1);
        cur_word[cur_word_len]='\0';
        strcpy(cur_word, output[i]);
        //printf(">%s<\n", cur_word);
        reverse_word(cur_word);
        strcpy_(line, cur_word, out_start, 0, cur_word_len);
        
        line[out_start + cur_word_len] = ' ';
        //printf(">%s<\n", line);
        out_start = out_start + cur_word_len+ 1;
    }
    for (int i = 0; i < num_lines; i++){
        free(output[i]);
    }
}

void reverse_word(char word[]){
    int len = (int)strlen(word);
    char temp[len+1];
    temp[len+1]='\0';

    int out_i =0;
    for (int in_i = len-1; in_i >= 0; in_i--){
        temp[out_i]= word[in_i];
        out_i++;
    }
    strcpy(word, temp);
}

void quicksort_strs(char const *args[], unsigned int len){
    unsigned int i, pvt=0;

    if (len <= 1)
        return;

    // swap a randomly selected value to the last node
    swap_str_ptrs(args+((unsigned int)rand() % len), args+len-1);

    // reset the pivot index to zero, then scan
    for (i=0;i<len-1;++i)
    {
        if (strcmp(args[i], args[len-1]) < 0)
            swap_str_ptrs(args+i, args+pvt++);
    }

    // move the pivot value into its place
    swap_str_ptrs(args+pvt, args+len-1);

    // and invoke on the subsequences. does NOT include the pivot-slot
    quicksort_strs(args, pvt++);
    quicksort_strs(args+pvt, len - pvt);
}
void swap_str_ptrs(char const **arg1, char const **arg2)
{
    const char *tmp = *arg1;
    *arg1 = *arg2;
    *arg2 = tmp;
}

int count_ones(unsigned long num){
    int ones=0;
    const unsigned long num_cpy = num;
    unsigned long temp = num;
    int max = (sizeof(num)*8) - 1;
    for (int i = max; i >=0; i--){
        temp = num_cpy;
        temp = temp << i;
        temp = temp >> max;
        if (temp == 1 )
            ones++;
    }
    return ones;
}
