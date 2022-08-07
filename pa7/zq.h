//
//  zq.h
//  pa7
//
//  Created by Rahel Gerson on 7/13/22.
//

#ifndef zq_h
#define zq_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* A ZQDecisionTreeNode represents one question or group of answers. */
typedef struct ZQDecisionTreeNode{
    char text[50];
    int num_answers;
    char** answers;
    struct ZQDecisionTreeNode* yes;
    struct ZQDecisionTreeNode* no;
}ZQDecisionTreeNode;

typedef struct ZQDecisionTree{
    ZQDecisionTreeNode* root;
}ZQDecisionTree;


/* UTILS  */
int len_int(int arr[]);
int len_long(long arr[]);
int len_double(double arr[]);
int len_char(char arr[]);

void reset_char_arr(char arr[], int start, int end);
void reset_int_arr( int arr[], int start, int end, int val);
void reset_long_arr(long arr[], int start, int end, int val);
void reset_float_arr(float arr[], int start, int end, int val);
void reset_double_arr(double arr[], int start, int end, int val);

void strcpy_(char dst[], char src[], int out_start, int in_start, int in_end);
bool is_char(char c);
bool is_digit(char c);
int char2num(char Input);
void print_int_arr(int arr[]);

void intcpy_(int dst[], int src[], int out_start, int in_start, int in_end);
void floatcpy_(float dst[], float src[], int out_start, int in_start, int in_end);
void doublecpy_(double dst[], double src[], int out_start, int in_start, int in_end);
void longcpy_(long dst[], long src[], int out_start, int in_start, int in_end);

void str2long_list(char input[], long output[]);
void str2int_list(char input[], int output[]);
int expandList(char input[], int output[]);
int expandListLong(char input[], long output[]);
int checkCharLoc(char input[],char b);
int combineElements(char arr[], int cc);
void get_separation_locs(char input[], char delim, int startLoc, int endLoc, int output[]);
int find_substr(char input[], char search[], int ind);
int count_substr(char base[], char to_search[]);
int count_char(char input[], char search);
int index_(char base[], char to_search[]);
void delimit(char line[], char delim, char* output[]);
void str_append(char** base, char* to_append);
void print_spaces(int num_spaces);
/* file IO helper funcs */
int count_num_lines(char* path, int buff_size);
int get_max_line_len(char* path);
//char* read_line(char* path, int buff_size, char* out_line);
int* line_lengths(char* path, int buff_size);
//char** read_(char* path, int buff_size);
void read_(char* path, int buff_size, char* arr[]);

/* END UTILS*/


/* functions*/
//void process(char** data, char delim, int num_lines, int line_len, char* col1[], char* col2[]);
void process(char** data, char delim, int num_lines, int line_len, char* col1[], char* col2[]);

//void read_(FILE* data , int indices[], char* file_data[], int* num_lines);
char* read_line(char* curr_buff, char** next_buff, char* temp, int* num_buffs );
void parse_line(char* line, char delim, char** out1, char** out2);



void ZQ_print_tree(ZQDecisionTree* root);
void ZQ_print_tree_helper(ZQDecisionTreeNode* curr, int level);
ZQDecisionTree* ZQ_build_tree(char* file_name);
void ZQ_populate_tree(ZQDecisionTree* tree, char* file_name);
void ZQ_free_tree(ZQDecisionTree* tree);
void ZQ_free_tree_helper(ZQDecisionTreeNode* cur, int level);
ZQDecisionTreeNode* ZQ_build_tree_helper(char* fields[], int curr_level, int num_levels, int num_poss_answers);

//void ZQ_populate_tree_helper(ZQDecisionTreeNode* tree, ZQDecisionTreeNode node, char* field, int* map, int num_levels, int curr_level);

//void ZQ_populate_tree_helper(ZQDecisionTreeNode* node, char* field, int* map, int num_levels, int curr_level);
void ZQ_populate_tree_helper(ZQDecisionTreeNode* node, char* field, int* map, int curr_lvl, int num_lvls);

void ZQ_print_node_info(ZQDecisionTreeNode* node);
void ZQ_db_print_tree_helper(ZQDecisionTreeNode* cur, int level);
void ZQ_db_print_tree(ZQDecisionTree* tree);

#endif /* zq_h */
