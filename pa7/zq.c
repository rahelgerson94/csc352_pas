//#define db_preproc
//#define db_build
//#define db_pop
//#define db_pop2
//#define db_print
#define BUFFSIZE 3
#include "zq.h"
//#define db_free


/* UTILS */
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
        printf("    ");
    }
}


void str_append(char** base, char* to_append){
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

int checkCharLoc(char input[],char b){
    int ii = 0;
    while(input[ii] != '\0'){
        if (input[ii] == b) return ii;
        ii++;
    }
    return -1;
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
void str2long_list(char input[], long output[]){
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
void delimit(char line[], char delim, char* output[]){
    int num_lines = count_char(line, delim)+1;
    int start, end;
    
    int delim_locs[num_lines];reset_int_arr(delim_locs, 0, num_lines, -1);
    get_separation_locs(line, delim, 0, strlen(line), delim_locs);
#ifdef db_preproc
    printf("delimit()\n");
    print_int_arr(delim_locs);
    printf("\n");
#endif
    start = 0;
    end = delim_locs[0];
    int curr_size = end - start + 1; //includes space for null char
    output[0] = calloc(curr_size, sizeof(char));
    strcpy_(output[0], line, 0, start, end );
    
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

/* END UTILS*/
void ZQ_print_tree(ZQDecisionTree* tree){
#ifdef debug_print
    printf("\nZQ_print_tree\n");
#endif
    /* print out a text representation of a decision tree. */
    //printf("[%s]\n",tree->root->text);
    ZQ_print_tree_helper(tree->root, 0);
}

void ZQ_print_tree_helper(ZQDecisionTreeNode* cur, int level){
    /* print out a text representation of a decision tree. */
    //print_spaces(level);
    if (cur->num_answers >= 0){ //we are at answers.
        //printf(" | ");
        for (int i = 0; i < cur->num_answers; i++){
            if (i == 0)
                printf("| %s | ",cur->answers[i]);
            else{
                printf("%s | ",cur->answers[i]);
            }
            //printf("$");
        }
        printf("\n");
    return;
    } //end if cur->num_answers >= 0
    else{
        printf("[%s]\n", cur->text);
        print_spaces(level);  printf("-y-> ");
        ZQ_print_tree_helper(cur->yes, level+1);
        print_spaces(level);printf("-n-> ");
        ZQ_print_tree_helper(cur->no, level+1);
    return;
    }
}

void ZQ_db_print_tree(ZQDecisionTree* tree){
    /* print out a text representation of a decision tree. */
    printf("[%s]\n",tree->root->text);
    ZQ_db_print_tree_helper(tree->root, 0);
}

/*
 
 */

void ZQ_db_print_tree_helper(ZQDecisionTreeNode* cur, int level){
    print_spaces(level);
    /* print out a text representation of a decision tree. */
    if (cur->num_answers >= 0){ //we are at answers.
        for (int i = 0; i < cur->num_answers; i++)
            printf(" > %s < ",cur->answers[i]);
    return;
    } //end if cur->num_answers >= 0
    else{
        //if (cur->yes == NULL) {printf("-y->\n");  printf("num_answers = %d\n", cur->yes->num_answers);}
        //else printf("-y-> [%s] num_answers = %d\n",cur->yes->text, cur->yes->num_answers);
        printf("-y-> [%s] num_answers = %d\n",cur->yes->text, cur->yes->num_answers);
        ZQ_db_print_tree_helper(cur->yes, level+1);
//        if (cur->no == NULL) {printf("-n->\n"); printf("num_answers = %d\n", cur->no->num_answers);}
//        else printf("-n-> [%s] num_answers = %d\n",cur->no->text, cur->no->num_answers);
        printf("-n-> [%s] num_answers = %d\n",cur->no->text, cur->no->num_answers);
        ZQ_db_print_tree_helper(cur->no, level+1);
        //print_spaces(level);
    return;
    }
}


void ZQ_print_node_info(ZQDecisionTreeNode* node){
    printf("question: %s\t", node->text);
    printf("num_answers: %d\n", node->num_answers);
    if (node->answers != NULL){
        for (int i = 0; node->answers[i] != NULL; i++)
            printf("\t%s\t",node->answers[i]);
    }
    printf("\n");
}

ZQDecisionTree* ZQ_build_tree(char* file_name){
/*
 inputs: a char* which represents the name of the file to load the data from.
 returns: a ZQDecisionTree that has been populated with all of the questions.
 this function opens up the file, iterate through the data within, creating an
 intermediate data structure to store it in) and populate a decision tree.
 During this process, the answers should not be added to the tree, just the question structure and
 leaf nodes with no questions or answers are added to the tree. Every level of this
 totally-full tree should have the same question.*/
    //FILE* data = fopen(file_name, "r");
    int buff_size = 100;
    
    
    
    //int indices[1]  = {0};
    //data = fopen(file_name, "r");
    //int dummy;
    //read_(data, indices, file_data, &dummy);
    
    int num_lines = count_num_lines(file_name, buff_size);
    int num_objs = num_lines - 2;
    char* file_data[num_lines];
    read_( file_name, buff_size, file_data);
    
#ifdef  db_build
    printf("\nZQ_build_tree()\n"); fflush(stdout);
    for (int i = 0; i < num_lines; i++){
        printf("%s\n", *(file_data+i)); fflush(stdout);
    }
    printf("ZQ_build_tree(): about to call delimit() \n"); fflush(stdout);
#endif
    char* questions = file_data[1];
    int num_levels = count_char(questions, '?');
    
    char* qs_list[num_objs];
    delimit(questions, ',', qs_list);
    ZQDecisionTree* tree = malloc(sizeof(tree));
#ifdef db_build
    printf("ZQ_build_tree(): output of delimit()\n");
    fflush(stdout);
    for (int i = 0; i < num_levels; i++){
        printf("%s\n", qs_list[i]);
        fflush(stdout);
    }
    printf("ZQ_build_tree(): about to call build_tree_helper()\n");
    fflush(stdout);
#endif
    
    tree->root = ZQ_build_tree_helper(qs_list, 0,  num_levels, num_objs);
 /* ***************************  CLEANUP ******************************************* */
#ifdef db_build
    printf("ZQ_build_tree(): about to free file_data and qs_list\n");
    fflush(stdout);
#endif

    
    for (int i = 0; i < num_lines; i++){
        //printf("\t%s\n", *(file_data+ i)); fflush(stdout); //debug
        free(*(file_data+ i));
    }
    //free(file_data);
    for (int i = 0; i < num_levels; i++){
        //printf("\t%s\n", *(qs_list+ i)); fflush(stdout);//debug
        free(*(qs_list+ i));
    }
#ifdef db_build
    printf(" build_tree(): about to exit\n"); fflush(stdout);//debug
#endif
    return tree;
}

ZQDecisionTreeNode* ZQ_build_tree_helper(char* questions[],  int curr_lvl, int num_levels, int num_poss ){
    ZQDecisionTreeNode* node = calloc(sizeof(ZQDecisionTreeNode),1);
    if (curr_lvl == num_levels){ //answer nodes (don't pop. q field)
        node->yes = NULL;
        node->no = NULL;
        node->num_answers = 0;
        node->answers = calloc(sizeof(char*), num_poss );
        //node->answers = calloc(sizeof(char*), num_poss );
    }
    else{
#ifdef db_build
        if (curr_lvl==0){
            for (int i = 0; i < num_levels; i++){
            printf(">%s<\n",questions[i] );
            fflush(stdout);
            }
        }

#endif
            strcpy(node->text,  questions[curr_lvl]);
            node->yes = NULL;
            node->no = NULL;
            node->answers = NULL;
            node->num_answers = -1;
        //}
        //else{
            node->yes = ZQ_build_tree_helper(questions, curr_lvl+1, num_levels, num_poss);
            node->no = ZQ_build_tree_helper(questions,  curr_lvl+1, num_levels, num_poss);
        //}
   // }
#ifdef db_build
    print_spaces(curr_lvl); fflush(stdout);
        //printf("%s\n", *(questions+curr_lvl));
    printf("about to segfault\n");fflush(stdout);
    printf("curr lvl: %d\n", curr_lvl);fflush(stdout);
    printf(">%s\n<",questions[curr_lvl] );fflush(stdout);
    printf("[%s]\n", node->text);
    printf("ZQ_build_tree_helper(): about to exit\n");
       fflush(stdout);
#endif
}//end question nodes block
    return node;
}


void ZQ_populate_tree(ZQDecisionTree* tree, char* file_name){
    
    int buff_size = 100;
    int num_lines = count_num_lines(file_name, buff_size);
    char* file_data[num_lines];
    read_( file_name, buff_size, file_data);
    int num_objs = atoi(file_data[0]);
    /*
     FILE* data = fopen(file_name, "r");
     int num_lines;
     char temp_int[10];
     fgets(temp_int, BUFFSIZE, data);
     fclose(data);
     data = fopen(file_name, "r");
     num_lines = atoi(temp_int);
     char* file_data[num_lines+1];
     
     int dummy;
     int indices[1]  = {0};
     read_(data, indices, file_data, &dummy);
     
     */
    
    
    int num_lvls = count_char(*(file_data+1), '?');
    int line_len = get_max_line_len(file_name);
#ifdef  db_preproc
    printf("\nZQ_populate_tree()\n");
    fflush(stdout);
    for (int i = 0; i < num_lines; i++){
        printf("%s\n", *(file_data+i));
        fflush(stdout);
    }
#endif
    char* objects[num_objs]; char* answers_temp[num_objs];
    process(file_data, ',', num_objs, line_len+1, objects, answers_temp); //populate the answers and objects fields
   
#ifdef  db_preproc
    printf("\nZQ_populate_tree(): output of process()\n");
    for (int i = 0; i < num_objs; i++){
        printf("%d. %s\t", i, objects[i]); fflush(stdout);
        printf("%s\n", answers_temp[i]); fflush(stdout);
    }
    printf("\n");
#endif
    int answers[num_lvls+1]; reset_int_arr(answers, 0, num_lvls+1, -1); //add a -1 at the end
    
    for (int i = 0; i < num_objs; i++){
        str2int_list(answers_temp[i], answers);
#ifdef  db_preproc
    print_int_arr(answers);
    printf("poulate_tree(): about to call pop_tree_helper()\n");
        fflush(stdout);
#endif
        ZQ_populate_tree_helper(tree->root, objects[i], answers, 0 , num_lvls); //num_lvls+1 for the answer nodes
    } //end for
#ifdef  db_pop
    printf("poulate_tree(): about to free stuff\n"); fflush(stdout);//debug
#endif
 /* ***************************  CLEANUP ******************************************* */
    for (int i = 0; i < num_objs; i++)
        free(*(objects+ i));
#ifdef  db_pop
    printf("poulate_tree(): freed objects\n"); fflush(stdout);//debug
#endif
    for (int i = 0; i < num_objs; i++)
        free(*(answers_temp+ i));
#ifdef  db_pop
    printf("poulate_tree(): freed answers_temp\n"); fflush(stdout);//debug
#endif
    for (int i = 0; i < num_lines; i++)
        free(*(file_data+ i));
#ifdef  db_pop
    printf("poulate_tree(): freed file_data\n"); fflush(stdout);//debug
#endif
    //free(file_data);
#ifdef  db_pop
    printf("poulate_tree(): about to exit\n"); fflush(stdout);//debug
#endif
/*
 This takes a previously-built tree and a char* with the name of the data file.
 The function populates the tree with the answers within the correct leaf nodes based on the data
 from the file, following the correct yes/no paths through the tree.
 */
}

void ZQ_populate_tree_helper(ZQDecisionTreeNode* curr, char* field, int* map, int curr_lvl, int num_lvls){
    int idx;
    if (curr_lvl == num_lvls-1) { //we are one level before the answer node level
        switch(*(map+curr_lvl)){
            case 1:
                idx = curr->yes->num_answers;
                //curr->yes->answers = realloc(curr->yes->answers, sizeof(char*)*(idx+1)); //add a new elem to list
                curr->yes->answers[idx] = calloc(strlen(field)+1, sizeof(char));
                strcpy(curr->yes->answers[idx], field);
                
                curr->yes->num_answers++;
            break;
            case 0:
                idx = curr->no->num_answers;
                curr->no->answers[idx] = calloc(strlen(field)+1, sizeof(char));
                strcpy(curr->no->answers[idx], field);
                curr->no->num_answers++;

            break;
        }
        return;
    }
    else{
        switch(*(map+curr_lvl)){
            case 0:
                ZQ_populate_tree_helper(curr->no, field, map, curr_lvl+1, num_lvls);
            break;
            case 1:
                ZQ_populate_tree_helper(curr->yes, field, map, curr_lvl+1, num_lvls);
            break;
        }
    }
}//end ZQ_populate_tree_helper

void ZQ_free_tree(ZQDecisionTree* tree){
    /* free all memory associated with tree.*/
    ZQ_free_tree_helper(tree->root, 0);
    free(tree);
}

void ZQ_free_tree_helper(ZQDecisionTreeNode* cur, int lvl){
    /* free all memory associated with tree.*/
    
    if (cur->yes == NULL && cur->no == NULL){
#ifdef db_free
        print_spaces(lvl); printf("freeing the answers\n");
#endif
        for (int i = 0; i < cur->num_answers ; i++){
            free(cur->answers[i]);
        }
        free(cur->answers);
        free(cur);
        return;
    }
    else{
#ifdef db_free
        print_spaces(lvl); printf("%s\n", cur->text);
#endif
        ZQ_free_tree_helper(cur->yes, lvl+1);
        ZQ_free_tree_helper(cur->no,lvl+1);
        free(cur);
        return;
    }
}

/* helper functions */

/* this function splits the data contained in data and places it into col1 and col2, based on a delimter.
 the data before the first occurence of delim will be in col1, and all data after that first delim
 will be in col2.
 col1 and col2 are outparams */
void process(char** data, char delim, int num_lines, int line_len, char* col1[], char* col2[]){
    //int num_qs = count(*data, "?");
    //int num_qs = count_char(data[1], '?');
    int col2_elems = line_len; //col2 elems are always 1 digit, and look like 0,1,... and we know how many 0's and 1s there are (there are num_qs of them)
    
    /* allocate  space for col2*/
    for (int l = 0; l < num_lines; l ++){
        col2[l] = calloc(col2_elems, sizeof(char)); // allocate space for each row in col2//*col2[l] this did not work
    }
    
#ifdef  db_build
    printf("process()\n");
    for (int i = 0; i < num_lines; i++){
        printf("%s\n", *(data+i+2)); fflush(stdout);
    }
    printf("\n"); fflush(stdout);
#endif
    //populate col1, col2
    for (int l = 0; l < num_lines; l++){
        int col1_elems = line_len;
        col1[l] = calloc(col1_elems, sizeof(char));
        parse_line(*(data+l+2), ',', &(col1[l]), &(col2[l]));
#ifdef  db_build
        printf("process(): output of parse_line()\n"); fflush(stdout);
        printf("%d. %s\t", l, col1[l]); fflush(stdout);
        printf("%s\n", col2[l]); fflush(stdout);
        printf("process(): exiting...\n"); fflush(stdout);
#endif
    }
}


void parse_line(char* line, char delim, char** out1, char** out2){
    int c = 0;
    while (line[c] != delim){
        *(*out1+c) = line[c];
        c++;
    }
    *(*out1+c) = '\0';
    int out2_i = 0;
    c = c+1;
    while (line[c] != '\0'){
        *(*out2+out2_i) = line[c];
        c++;
        out2_i++;
    }
    *(*out2+out2_i) = '\0';
}

char* read_line(char* curr_buff, char** prev_buff, char* line, int* num_buffs){
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


/* this function stores the info contained in a file in a variable, file_data
 the first line must contain the number of lines in the file
 file_data,then   stores all lines except the first */
//void read_(FILE* data , int indices[], char* file_data[], int* num_lines){
//    /*
//     indices: the lines that are to be treated as special
//     */
//    char* curr_data = calloc(BUFFSIZE+1, sizeof(char));
//    char* prev_data = calloc(BUFFSIZE+1, sizeof(char));
//    char* line = calloc(BUFFSIZE+1, sizeof(char));
//    int l = 0;
//    int data_i=0;
//    int num_buffs=1;
//    while(fgets(curr_data, BUFFSIZE, data) != NULL){
//        data_i = l-1;
//        if (l == indices[0]){ //number of qs
//            *num_lines = atoi(curr_data);
//           // file_data = calloc(1 + *num_lines, sizeof(char*));
//            l++;
//            num_buffs = 1; //rst  num_buffs for next code block;
//            continue;
//        }
//        else{  //the questions
//            if ( data_i < *num_lines ){
//                //if (count(curr_data, "\n" ) <= 0 ){ //if curr_data does not contain a newline char
//                if (count_char(curr_data, '\n' ) <= 0 ){ //if curr_data does not contain a newline char
//                    line = read_line(curr_data, &prev_data, line, &num_buffs);
//                    //questions = read_line(curr_data, &prev_data, questions, &num_buffs);
//                    //read_line(curr_data, &prev_data, &temp, &num_buffs);
//                }
//                else { //the possible objects and their clues
//                    char temp_[BUFFSIZE*num_buffs]; memset(temp_, '\0', BUFFSIZE*num_buffs);
//                    strcpy_(temp_, curr_data, 0, 0, BUFFSIZE*num_buffs);
//                    line = read_line(temp_, &prev_data, line, &num_buffs);
//                    file_data[data_i] = calloc(1+len_char(line), sizeof(char));
//                    strcpy_(file_data[data_i], line, 0, 0, len_char(line));
//
//                    free(line);
//                    free(prev_data);
//                    line = calloc(1+BUFFSIZE, sizeof(char));
//                    prev_data = calloc(1+BUFFSIZE, sizeof(char));
//                    num_buffs = 1;
//                    l++;
//                    continue;
//                }
//            }//end l < num_lines - 1
//            else{
//                line = read_line(curr_data, &prev_data, line, &num_buffs);
//                //*(*file_data+ data_i) = calloc(1+ len_char(line), sizeof(char));
//                //strcpy_(*(*file_data+ data_i), line, 0, 0, len_char(line));
//                file_data[data_i] = calloc(1+ len_char(line), sizeof(char));
//                strcpy_(file_data[data_i], line, 0, 0, len_char(line));
////    #ifdef debug
//
//#ifdef db_preproc
//                printf("%s\n", file_data[data_i]);
//#endif
//#ifdef db_pop2
//        printf("\t");  printf("[pop_helper()] data_i = %d\n", data_i);
//#endif
//        }//end NOT(data_i == num_lines -1)
//            }//end l ≠ 0
//        }//end while
//    /*CLEANUP*/
//    fclose(data);
//    /*freeing data*/
//    free(curr_data);
//    free(prev_data);
//    free(line);
//}
/* count the number of lines in a file */
int count_num_lines(char* path, int buff_size){
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
    /* returns the length of the longest line in a file
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
     arr is an out param */
    
    //int num_lines = count_num_lines(path, buff_size);
    int max_len = get_max_line_len(path);
    int cur_len;
    FILE* in = fopen(path, "r");
    char curr_in[max_len+1];
    reset_char_arr(curr_in, 0, max_len);
    int i = 0;
    while(fgets(curr_in, max_len+1, in)){ //+1 for new line
        cur_len = len_char(curr_in);
        curr_in[cur_len] = '\0';
        //printf("%d\t", cur_len);
        if (cur_len == 0)
            continue;
        else{
            arr[i] = malloc(sizeof(char)*(cur_len+1)); //+1 for null char,
            strcpy(arr[i], curr_in);
            arr[i][cur_len]  = '\0';
            //printf(">%s<\n", arr[i]);
            reset_char_arr(curr_in, 0, max_len);
            i++;
        }
        
    }
    fclose(in);
}
