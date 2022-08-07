#include "utils.h"
#define debug
int len_int(int arr[]){
    int i = 0;
    int len = 0;
    while (arr[i] >= 0){ //!= -1){
        //printf("%d ",arr[i] ) ;
        len++;
        i++;
    }
    return len;
}
int len_long(long arr[]){
    int i = 0;
    int len = 0;
    while (arr[i] >= 0){ //!= -1){
        //printf("%d ",arr[i] ) ;
        len++;
        i++;
    }
    return len;
}
int len_double(double arr[]){
    int i = 0;
    int len = 0;
    while (arr[i] >= 0){ //!= -1){
        //printf("%d ",arr[i] ) ;
        len++;
        i++;
    }
    return len;
}

int len_char(char arr[]){
    int i = 0;
    int len = 0;
    while (arr[i] != '\0'){
        if (arr[i] == '\n')
            break;
        else{
            len++;
        }
        i++;
    }
    return len;
}


void reset_char_arr(char arr[], int start, int end){
    for (int i = start; i < end; i++)
    {
        arr[i] = '\0';
    }
}
void reset_int_arr(int arr[], int start, int end, int val)
{
    for (int i = start; i < end; i++)
    {
        arr[i] = val;
    }
}
void reset_long_arr(long arr[], int start, int end, int val)
{
    for (int i = start; i < end; i++)
    {
        arr[i] = val;
    }
}


void reset_float_arr(float arr[], int start, int end, int val)
{
    for (int i = start; i < end; i++)
    {
        arr[i] = val;
    }
}
void reset_double_arr(double arr[], int start, int end, int val)
{
    for (int i = start; i < end; i++)
    {
        arr[i] = val;
    }
}
void strcpy_(char dst[], char src[], int out_start, int in_start, int in_end){
    int len = in_end - in_start;
    int in_i = in_start;
    int out_i ;
    for ( out_i = out_start; out_i < out_start + len; out_i++)
    {
        if (src[in_i]== '\n') break;
        dst[out_i] = src[in_i];
        in_i++;
    }
    dst[out_i] = '\0';
}

bool is_char(char c){
    bool is_char = false;
    bool upper = false;  bool lower = false;
    
    if ((int)c >= 97 && (int)c <= 122) lower = true;
    if ((int)c >= 65 && (int)c <= 90) upper = true;
    if (upper || lower ) is_char = true;
    return is_char;
}
bool is_digit(char c){
    //[48-57]
    if ((int)c >= 48 && (int)c <= 57) return true;
    else return false;
}


void print_int_arr(int arr[])
{
    printf("{ ");
    int length = len_int(arr);

    for (int i = 0; i < length; i++)
    {
        if (i == length - 1)
        {
            printf("%d }\n", arr[i]);
            return;
        }
        else
        {
            printf("%d, ", arr[i]);
        }
    }
}


void intcpy_(int dst[], int src[], int out_start, int in_start, int in_end)
{
    int len = in_end - in_start;
    int in_i = in_start;
    for (int out_i = out_start; out_i < out_start + len; out_i++)
    {
        dst[out_i] = src[in_i];
        in_i++;
    }
}

void floatcpy_(float dst[], float src[], int out_start, int in_start, int in_end)
{
    int len = in_end - in_start;
    int in_i = in_start;
    for (int out_i = out_start; out_i < out_start + len; out_i++)
    {
        dst[out_i] = src[in_i];
        in_i++;
    }
}
void doublecpy_(double dst[], double src[], int out_start, int in_start, int in_end)
{
    int len = in_end - in_start;
    int in_i = in_start;
    for (int out_i = out_start; out_i < out_start + len; out_i++)
    {
        dst[out_i] = src[in_i];
        in_i++;
    }
}
void longcpy_(long dst[], long src[], int out_start, int in_start, int in_end)
{
    int len = in_end - in_start;
    int in_i = in_start;
    for (int out_i = out_start; out_i < out_start + len; out_i++)
    {
        dst[out_i] = src[in_i];
        in_i++;
    }
}

void str2long_list(char input[], long output[]){
    int Start = 0;
    // int End = 0;
    int ii = 0;
    int extra = 0;
    int commas[100] = {0};
    // int num;
    get_separation_locs(input, 'c', 0, -1, commas);
    while (commas[ii] > 0)
    {
        char dst[100] = {'\0'};
        reset_char_arr(dst, 0,100);
        strcpy_(dst, input, 0, Start, commas[ii]);
        if (checkCharLoc(dst, '-') >= 0){
            long expandedList[100] = {-1};
            reset_long_arr(expandedList, 0,100, -1);
            int len = expandListLong(dst, expandedList);
            longcpy_(output, expandedList, ii + extra, 0, len);
            extra += (len -1);
            Start = commas[ii] + 1;
            ii++;
        }else{
        int num = combineElements(dst, commas[ii] - Start);
        output[ii] = num;
        Start = commas[ii] + 1;
        ii++;
        }
    }
}

void str2int_list(char input[], int output[]){
    int Start = 0;
    // int End = 0;
    int ii = 0;
    int extra = 0;
    int commas[100] = {0};
    // int num;
    get_separation_locs(input, ',', 0, -1, commas);
    while (commas[ii] > 0)
    {
        char dst[100] = {'\0'};
        reset_char_arr(dst, 0,100);
        strcpy_(dst, input, 0, Start, commas[ii]);
        if (checkCharLoc(dst, '-') >= 0){
            int expandedList[100] = {-1};
            reset_int_arr(expandedList, 0,100, -1);
            int len = expandList(dst, expandedList);
            intcpy_(output, expandedList, ii + extra, 0, len);
            extra += (len -1);
            Start = commas[ii] + 1;
            ii++;
        }else{
        int num = combineElements(dst, commas[ii] - Start);
        output[ii] = num;
        Start = commas[ii] + 1;
        ii++;
        }
    }
}

int expandList(char input[], int output[]){
    int check = checkCharLoc(input,'-');
    if(check < 0) return -1;
    output[0] = combineElements(input, check);
    int ll = 1;
    while (input[ll] >=0){
        int jj = ll;
        char dst[100] = {'\0'};
        int Size = len_char(input);
        strcpy_(dst, input, 0, check + 1, Size);
        int num2go2 = combineElements(dst, Size - check - 1);
        int Add = 1;
        while (output[jj - 1] != num2go2)
        {
            output[jj++] = output[ll - 1] + Add++;
        }
        return jj;
        ll = jj + 1;
    }
    ll++;
    return ll;
}
int expandListLong(char input[], long output[]){
    int check = checkCharLoc(input,'-');
    if(check < 0) return -1;
    output[0] = combineElements(input, check);
    int ll = 1;
    while (input[ll] >=0){
        int jj = ll;
        char dst[100] = {'\0'};
        int Size = len_char(input);
        strcpy_(dst, input, 0, check + 1, Size);
        int num2go2 = combineElements(dst, Size - check - 1);
        int Add = 1;
        while (output[jj - 1] != num2go2)
        {
            output[jj++] = output[ll - 1] + Add++;
        }
        return jj;
        ll = jj + 1;
    }
    ll++;
    return ll;
}

int char2num(char Input)
{
    int out = Input - '0';
    if (out > 9 || out < 0)
    {
        return -1;
    }
    return out;
}

int checkCharLoc(char input[],char b){
    int ii = 0;
    while(input[ii] != '\0'){
        if (input[ii] == b) return ii;
        ii++;
    }
    return -1;
}

int combineElements(char arr[], int cc){
    int nums[100] = {-1};

    for (int ll = 0; ll < cc; ll++)
    {

        int temp = char2num(arr[ll]);
        // TODO : fix the zero problem
        if (temp >= 0)
            nums[ll] = temp;
        else
        {
            char dst[100] = {'\0'};
            int expandedList[100] = {-1};
            reset_int_arr(expandedList, 0,100, -1);
            int Size = len_char(arr);
            strcpy_(dst, arr, 0, ll + 1, Size);
            expandList(dst, expandedList);
        }
    }
    int out = 0;
    int mult = 1;
    for (int ii = cc - 1; ii >= 0; ii--)
    {
        out += nums[ii] * mult;
        mult = mult * 10;
    }
    return out;
}

void get_separation_locs(char input[], char delim, int startLoc, int endLoc, int output[]){
    if (endLoc == -1)
    {
        endLoc = 100;
    }
    int ll = 0;
    for (int ii = startLoc; ii < endLoc; ii++)
    {
        if (input[ii] == delim || input[ii] == '\n')
        {
            output[ll++] = ii;
        }
        else if (input[ii] == '\0')
        {
            output[ll++] = ii;
            break;
        }
    }
}

int find_substr(char input[], char search[], int ind){
    /* return the index in input where search appears
     ex: if input = blafishes, search = fis,
     out should be 3
     */
    int ll = 0; //iterator for the search term
    int out = ind;
    bool first_match = true;
    
    while(input[ind] != '\0'){
        if(input[ind] == search[ll]){
            if (first_match) {
                out = ind;
                first_match = false;
            }
            ll++;
            if (search[ll] == '\0')
                return  out;
        }
        else{
            first_match = true;
            ll=0;
        }
        ind++;
    }
    return -1;
}
/* return the number of times search appears in input*/
int count_char(char input[], char search){
    int ind = 0;
    int count = 0;
    while(input[ind] != '\0'){
        if(input[ind] == search){
            count++;
        }
        ind++;
    }
    return count;
}

int count_substr(char base[], char to_search[]){
    /*
    count how many times to_search appears within base.
    return 0 if no match is found.
     */
//#ifdef debug
//    printf("count()\n");
//#endif
    
    int count = 0;
    int bi = 0;
    while (base[bi] != '\0'){
        bi = find_substr(base, to_search, bi);
        if  (bi==-1) return count;
//#ifdef debug
//        printf("\tbi=%d\n", bi);
//#endif
        if (bi != -1) {
            count++;
            bi++;
        }
    }return count;
}



//int         (char input[], char search[], int ind){
int index_(char base[], char to_search[]){
    /* return the index in base where search appears
     ex: if base = blafishes, to_search = fis,
     out should be 3
     */
    int ind = 0;
    int ll = 0; //iterator for the search term
    int out = ind;
    bool first_match = true;
    
    while(base[ind] != '\0'){
        if(base[ind] == to_search[ll]){
            if (first_match) {
                out = ind;
                first_match = false;
            }
            ll++;
            if (to_search[ll] == '\0')
                return  out;
        }
        else{
            first_match = true;
            ll=0;
        }
        ind++;
    }
    return -1;
}
void print_spaces(int num_spaces){
    for (int i = 0; i < num_spaces; i++){
        printf(" ");
    }
}
void delimit(char line[], char delim, char* output[]){
    int num_lines = count_char(line, delim)+1;
    int start, end;
    
    int delim_locs[num_lines];reset_int_arr(delim_locs, 0, num_lines, -1);
    get_separation_locs(line, delim, 0, strlen(line), delim_locs);
    
    start = 0;
    end = delim_locs[0];
    int curr_size = end - start + 1; //includes space for null char
    output[0] = calloc(curr_size, sizeof(char));
    strcpy_(output[0], line, 0, start, end );
    printf("%s\n", output[0]);
    
    for (int l = 1; l < num_lines; l++){
        if (l == num_lines-1){
            start = delim_locs[l-1]+1;
            end = strlen(line);
        }
        else{
            end = delim_locs[l];
            start = delim_locs[l-1]+1;
        }
        curr_size = end - start + 1;
        output[l] = calloc(curr_size, sizeof(char));
        strcpy_(output[l], line, 0, start, end);
        //printf("%s\n", output[l]);
    }
}

void str_append(char** base, char* to_append){
    int base_data_len,  to_append_data_len;
    int base_tot, to_append_tot;
    base_data_len = len_char(*base);
    to_append_data_len = len_char(to_append);
    /*combine the data fields*/
    //char new_str[base_data_len+to_append_data_len+1];
    char* new_str = calloc(base_data_len+to_append_data_len+1, sizeof(char));
    //char* new_data = NULL;
    strcpy_(new_str, *base, 0, 0, base_data_len);
    strcpy_(new_str, to_append, base_data_len, 0, to_append_data_len);
#ifdef debug
    printf("str_append()\n", new_str);
    printf("\t%s\n", new_str);
#endif
    free(*base);
    *base = new_str;
}

/* count the number of lines in a file */
int num_lines(char* path, int buff_size){
    FILE* data = fopen(path, "r");
    char curr_data[buff_size];
    int num_lines = 0;
    while(fgets(curr_data, buff_size, data) != NULL){
        num_lines+=count_char(curr_data);
    }
    fclose(data);
    return num_lines;
}
/*this function reads a single line of input from a file */
 char* read_line(char* path, int buff_size, char* out_line){
    free(line);
    line =  calloc(BUFFSIZE*(*num_buffs)+1, sizeof(char));
    //strcpy_(line, *prev_buff, 0, 0, BUFFSIZE*(*num_buffs));
    strcpy(line, *prev_buff);
    strcat(line, curr_buff);
    free(*prev_buff);
    *prev_buff = calloc(BUFFSIZE*(*num_buffs), sizeof(char));
    strcpy(*prev_buff, line);
    (*num_buffs)++;
    return line;
}
/* return the number of times search appears in input*/
int count_char(char input[], char search){
    int ind = 0;
    int count = 0;
    while(input[ind] != '\0'){
        if(input[ind] == search){
            count++;
        }
        ind++;
    }
    return count;
}
void read_(char* path, int buff_size){
    FILE* data = fopen(path, "r");
    while(fgets(curr_data, buff_size, data) != NULL){
        if ((count_char(curr_data, '\n' ) <= 0 ) { //check  if its the end of the line
            
        }//end check of EOL
    }//while
    fclose(data);
}//end read_

void free_string_arr(){
}


int num_lines(char* path, int buff_size){
    FILE* data = fopen(path, "r");
    char curr_data[buff_size];
    int num_lines = 0;
    while(fgets(curr_data, buff_size, data) != NULL){
        num_lines+=count_char(curr_data);
    }
    fclose(data);
    return num_lines;
}
