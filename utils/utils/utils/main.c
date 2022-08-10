//
//  main.c
//  utils
//
//  Created by Rahel Gerson on 7/22/22.
//

#include <stdio.h>
#include "utils.h"
int main(int argc, const char * argv[]) {
    //char path[200] = "/Users/rahelmizrahi/Library/Mobile_Documents/com~apple~CloudDocs/csc352/cs352_pas/pa5/data.txt";
    char path[300] ;
    int buff_size = 10;
    strcpy(path, argv[1]);
    int num_lines = count_num_lines(path, buff_size);
    char* file_data[num_lines];
    read_( path, buff_size, file_data);
    printf("\nmain()\n");
    for (int i = 0; i < num_lines; i++){
        printf("%d. >%s<\n", i, file_data[i]);
    }
    free_data(file_data, num_lines);
//    for (int i = 0; i < num_lines; i++)
//        free(file_data[i]);
    return 0;
}
