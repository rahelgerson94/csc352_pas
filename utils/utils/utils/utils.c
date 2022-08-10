#include "utils.h"
/* *************** DEBUG FUNCTIONS ****************/
#define db_mode
#ifdef db_mode
    #define DB_PRINT_NUM(NUM)\
        printf("%d\n", NUM);
    
    #define DB_PRINT_FCT(FCT_NAME)\
        printf("--------------------- %s ---------------------\n",FCT_NAME );

    #define DB_PRINT_STRING(STRING)\
        printf("%s\n",STRING );
#else
    #define DB_PRINT_NUM(NUM)
    #define DB_PRINT_FCT(FCT_NAME)
    #define DB_PRINT_STRING(STRING)
#endif


#define debug
/* *************** ARRAY: LENGTH ****************/
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
            i++;
        }
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

void print_spaces(int num_spaces){
    for (int i = 0; i < num_spaces; i++){
        printf(" ");
    }
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
void print_int_ptr_arr(int* arr[], int length)
{
    printf("{ ");
    for (int i = 0; i < length; i++)
    {
        if (i == length - 1)
        {
            printf("%d }\n", *arr[i]);
            return;
        }
        else
        {
            printf("%d, ", *arr[i]);
        }
    }
}
/* *************** ARRAY: COPY ****************/
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

/* *************** ARRAY: CONVERT STRING TO NUMERICAL ****************/

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

/* atoi: only does single chars*/
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
/* converts (char)25 into int(25) */
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

/* *************** DATA: PROCESSING ****************/

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

void delimit(char line[], char delim, char* output[]){
/*
 inputs: a delim-delimited string,
     delim: the delimiter
        eg: line = "dog, fish, girl"
            delim = ','
 outtputs: [dog,  fish, girl]
 REMEBER TO FREE AT THE END!!! */
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

int count_num_lines(char* path, int buff_size){
/* count the number of lines in a file
 buff_size : max bytes/chars to read (for fgets) */
    FILE* data = fopen(path, "r");
    char curr_data[buff_size];
    int num_lines = 0;
    while(fgets(curr_data, buff_size, data) != NULL){
        num_lines+=count_char(curr_data, '\n');
    }
    fclose(data);
    return num_lines+1;
}

int get_max_line_len(char* path){
/* given a path to a file, finds the longest line in the file
 returns the length of the longest line in a file.
 length excludes newline char */
    FILE* data = fopen(path, "r");
    char curr_data[2];
    int num_lines = 0;
    int max_num_char = 0;
    int curr_num_char = 0;
//    printf("<\n");
    while(fgets(curr_data, 2, data) != NULL){
//        printf(">%s<\n",curr_data);
        if (strcmp(curr_data,"\n") == 0 || strcmp(curr_data,"\0") == 0){
            num_lines++;
            if (curr_num_char > max_num_char) max_num_char = curr_num_char;
            curr_num_char = 0;
        }else{
            curr_num_char++;
        }
    }
    fclose(data);
//    printf(">");
    return max_num_char;
}

void read_(char* path, int buff_size, char* arr[]){
/* populate arr w/ contents of file_data.
 buff_size: number of bytes fgets() will read.
 arr is an out param */

    int max_len = get_max_line_len(path);
    int cur_len;
    FILE* in = fopen(path, "r");
    char curr_in[max_len+1];
    reset_char_arr(curr_in, 0, max_len);
    int i = 0;
    while(fgets(curr_in, max_len+1, in) != NULL){ //+1 for new line
        cur_len = len_char(curr_in);
        curr_in[cur_len] = '\0';
        
        if (cur_len == 0){
            printf("%d\t NULL\n", cur_len); //debug
            continue;
        }
        else{
            printf("%d\t", cur_len);
            arr[i] = malloc(sizeof(char)*(cur_len+1)); //+1 for null char,
            strcpy(arr[i], curr_in);
            arr[i][cur_len]  = '\0';
            printf(">%s<\n", arr[i]);
            reset_char_arr(curr_in, 0, max_len);
            i++;
        }
        
    }
    fclose(in);
}

/* *************** STRING OPERATIONS ****************/

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
    while(input[ind] != '\0' ){
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


void str_append(char** base, char* to_append){
/* copies to_append into base, without deleting to_append */

    int base_data_len,  to_append_data_len;
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



/* unsure if this works*/
int* line_lengths(char* path, int buff_size){
    int num_lines = count_num_lines(path, buff_size);
    int* out = malloc(num_lines*sizeof(int)  + 1);
    out[num_lines+1] = -1;
    
    FILE* in = fopen(path, "r");
    char curr_data[buff_size]; reset_char_arr(curr_data, 0, buff_size);
    int num_buffs = 0;
    int len = buff_size;
    int l = 0;
    bool first_time = true;
    while(fgets(curr_data, buff_size, in) != NULL){
        printf(">%s<\n", curr_data);
        if (count_char(curr_data, '\n') > 0){
            int new_line_idx = checkCharLoc(curr_data, '\n');
            switch(first_time){
                case true:
                    out[l]=(new_line_idx);
                    break;
                case false:
                    out[l]=len+(new_line_idx)-1;
                    break;
            }
            
            first_time = true;
            l++;
            num_buffs = 0;
            len = buff_size;
        }
        else{
            num_buffs = num_buffs+1;
            len = buff_size*num_buffs;
            first_time = false;
        }
    }//end while
    return out;
}

/* BIT-LEVEL FUNCTIONS */
void print_bits(void * loc, int num_bytes){
    /*
     loc: the address of a number, it's not an array!
     size: number of bytes in loc*/
    uint8_t* data = (uint8_t*) loc;
    uint8_t temp;
    for (int byte = 0; byte < num_bytes; byte++){ //for each byte in data
        for (int bit = 0; bit < 8; bit++){ //for each bit in byte
            temp = data[byte] << (7- bit); //shift the bit-th LSB bit to MSB loc. (bit 0)
            temp = temp >> 7; //shift the MSB to the LSB loc, zero out all other bits.
            if (temp == 1)
                printf("1");
            else if (temp == 0)
                printf("0");
//            else
//                printf("%hhu", temp);
            
        }
        printf(" "); //space between each byte
    }
    printf("\n");
}

int get_last_digit(uint16_t num){
    uint16_t first = num;
    /* Remove last digit from number till only one digit is left */
    while(first >= 10)
        first = first / 10;
    return  first;
}


uint64_t convert_to_base(uint64_t num, uint8_t base){
    uint64_t new_base_num = 0;
    int i = 1;
    int remainder;
    while(num != 0){
        remainder = num % base;
        num = num / base;
        new_base_num = new_base_num + (remainder * i);
        i = i * 10;
    }
    return new_base_num;
}

/* frees the data structure created by read_( )*/
void free_data(char* data[], int num_lines){
    for (int i = 0; i < num_lines; i++)
        free(data[i]);
    
}

