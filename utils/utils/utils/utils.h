
#ifndef utils_h
#define utils_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <stdbool.h>
#include <string.h>

/* array lengths*/
int len_int(int arr[]);
int len_long(long arr[]);
int len_double(double arr[]);
int len_char(char arr[]);
//array: reset
void reset_char_arr(char arr[], int start, int end);
void reset_int_arr( int arr[], int start, int end, int val);
void reset_long_arr(long arr[], int start, int end, int val);
void reset_float_arr(float arr[], int start, int end, int val);
void reset_double_arr(double arr[], int start, int end, int val);

//array: copy
void strcpy_(char dst[], char src[], int out_start, int in_start, int in_end);
void intcpy_(int dst[], int src[], int out_start, int in_start, int in_end);
void floatcpy_(float dst[], float src[], int out_start, int in_start, int in_end);
void doublecpy_(double dst[], double src[], int out_start, int in_start, int in_end);
void longcpy_(long dst[], long src[], int out_start, int in_start, int in_end);

bool is_char(char c);
bool is_digit(char c);
int char2num(char Input);

/* print funcs*/
void print_int_arr(int arr[]);
void print_int_ptr_arr(int* arr[], int length);
void print_spaces(int num_spaces);

void str2long_list(char input[], long output[]);
void str2int_list(char input[], int output[]);

int expandList(char input[], int output[]);
int expandListLong(char input[], long output[]);
int checkCharLoc(char input[],char b);
int combineElements(char arr[], int cc);

/* string-related operations*/
void get_separation_locs(char input[], char delim, int startLoc, int endLoc, int output[]);
int find_substr(char input[], char search[], int ind);
int count_substr(char base[], char to_search[]);
int count_char(char input[], char search);
int index_(char base[], char to_search[]);
void delimit(char line[], char delim, char* output[]); //alloc'd
void str_append(char** base, char* to_append); //alloc'd

/* file IO helper funcs */
int count_num_lines(char* path, int buff_size);
int get_max_line_len(char* path);
//char* read_line(char* path, int buff_size, char* out_line);
int* line_lengths(char* path, int buff_size); //alloc'd, but not sure if works
//char** read_(char* path, int buff_size);
void read_(char* path, int buff_size, char* arr[]);
void free_data(char* data[], int num_lines);
/* BIT-LEVEL FUNCTIONS */
void print_bits(void* loc, int size);
int get_last_digit(uint16_t num);
uint64_t convert_to_base(uint64_t num, uint8_t base);
#endif /* utils_h */
