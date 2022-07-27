//
//  3d.c
//  pa8
//
//  Created by Rahel Gerson on 7/25/22.
//
#include "3d.h"
#include <errno.h>
//#define db0 //db for basis funcs
//#define db_pyramid
//#define db_quad
//#define db_o_append
//#define db_o_destroy
//#define db_s_destroy
//#define db_s_append
#define write_gradescope
/*
 * This function allocates space for a new Scene3D object on the heap,
 * initializes the values to defaults as necessary, and returns a pointer to
 * the object in memory.
 */
Scene3D* Scene3D_create(){
    Scene3D* scene = malloc(sizeof(Scene3D)*1);
    *scene = (Scene3D) {0,0,NULL};
    return scene;
}

/*
 * Frees the memory on the heap for the Scene3D itself, as well as the Object3D
 * and Triangle3DNode's within it.
 *   Parameters:
 *     scene: The scene to destroy
 */
void Scene3D_destroy(Scene3D* scene){
#ifdef db_s_destroy
    print_db_fct("Scene3D_destroy");
#endif
    for (int i = 0; i < scene->count; i++){
        #ifdef db_s_destroy
            printf("Scene3D_destroy(): about to destroy scene->object[%d], address: %p\n", i, scene->objects[i]);
        #endif
        Object3D_destroy(scene->objects[i]);
    }
    free(scene->objects);
    free(scene);
}
void Object3D_destroy(Object3D* obj){
#ifdef db_destroy
    print_db_fct("Object3D_destroy");
#endif
    Object3D_destroy_helper(obj->root);
    free(obj);
}

/*frees each node in the linked list*/
void Object3D_destroy_helper(Triangle3DNode* cur){
    if (cur->next == NULL){
        free(cur);
        return;
    }
    else {
        Triangle3DNode* temp = cur->next;
        free(cur);
        Object3D_destroy_helper(temp);
    }
}
/*
 * Appends a new object to the end of the Scene3D's array of objects.
 * This function is responsible for handling the dynamic growing of the array
 * of Object3D pointers when necessary.
 *   Parameters:
 *     scene: The scene to have an object appended to
 *     object: The object to append to this scene
 */
void Scene3D_append(Scene3D* scene, Object3D* object){
#ifdef db_s_append
    print_db_fct("Scene3D_append");
#endif
    if (scene->objects == NULL){
        scene->objects = malloc(sizeof(Object3D*)*2);
        scene->size = 2;
    }
    if (scene->count == scene->size){
        unsigned int new_amount = (scene->size*2)*(sizeof(Object3D*));
        scene->objects = realloc(scene->objects, new_amount );
        scene->size = scene->size*2;
    }
    //scene->objects[scene->count] = malloc(sizeof(object)); //allocate
    scene->objects[scene->count] = object; //assign
    scene->count++;
    
#ifdef db_s_append
    printf("Scene3D_append()\n");
    for (int i = 0; i < scene->count; i++){
        printf("objects[%d] : %p\n", i, scene->objects[i]);
    }
#endif
    
}


/*
 * This function should create a new Object3D on the heap and populate it with
 * a bunch of triangles to represent a pyramid in 3D space.
 * The caller is responsible for freeing the memory, or, if this shape gets
 * added to a Scene3D, that is can be freed when the scene is.
 *   Parameters:
 *     origin: The origin point for the pyramid (center of base)
 *     width: The length of the sides of the base of the pyramid
 *     height: The height of the pyramid
 *     orientation: Determines the direction the pyramid points.
 *                  Should be either:
 *                    "forward"
 *                    "backward"
 *                    "up"
 *                    "down"
 *                    "left"
 *                    "right"
 */
Object3D* Object3D_create_pyramid(
#ifdef db_pyr
    print_db_fct("Object3D_create_pyramid");
#endif
    Coordinate3D origin,
    double w, double h, char* orientation){
    Object3D* pyramid = malloc(8*(sizeof(Triangle3DNode)));
    pyramid->count = 0;
    pyramid->root = NULL;
    
    Coordinate3D a,b,c,d;
    
    /* now, append the sides*/
    Coordinate3D tip;
    if (strcmp(orientation, "up") == 0){
        Object3D_update_coords(w, w, 'z', origin, &a, &b, &c, &d);
        Object3D_append_quadrilateral(pyramid, a,b,c,d);
        Object3D_coord_shift(origin, 'z', h, &tip);
        
        //front
        Triangle3D front = (Triangle3D){a,b,tip};
        Object3D_append_triangle(pyramid, front );
        
        //right
        Triangle3D right = (Triangle3D){b,c,tip};
        Object3D_append_triangle(pyramid, right );
        
        //back
        Triangle3D back = (Triangle3D){c,d,tip};
        Object3D_append_triangle(pyramid, back );
        
        //left
        Triangle3D left = (Triangle3D){a,d,tip};
        Object3D_append_triangle(pyramid, left );
    }//end up case
    
    else if (strcmp(orientation, "right") == 0){ //apex is along x-axis
        Object3D_update_coords(w, w, 'x', origin, &a, &b, &c, &d);
        Object3D_append_quadrilateral(pyramid, a,b,c,d);
        Object3D_coord_shift(origin, 'y', h, &tip);
        //top
        Triangle3D top = (Triangle3D){a,b,tip};
        Object3D_append_triangle(pyramid, top );
        
        //front
        Triangle3D front = (Triangle3D){b,c,tip};
        Object3D_append_triangle(pyramid, front );
        
        //bottom
        
        Triangle3D bottom = (Triangle3D){c,d,tip};
        Object3D_append_triangle(pyramid, bottom );
        
        //back
        Triangle3D back = (Triangle3D){a,d,tip};
        Object3D_append_triangle(pyramid, back);
    } //right
    else if (strcmp(orientation, "down") == 0){
        Object3D_update_coords(w, w, 'z', origin, &a, &b, &c, &d);
        Object3D_append_quadrilateral(pyramid, a,b,c,d);
        Object3D_coord_shift(origin, 'z', -h, &tip);
        
        //front
        Triangle3D front = (Triangle3D){a,b,tip};
        Object3D_append_triangle(pyramid, front );
        
        //right
        Triangle3D right = (Triangle3D){b,c,tip};
        Object3D_append_triangle(pyramid, right );
        
        //back
        Triangle3D back = (Triangle3D){c,d,tip};
        Object3D_append_triangle(pyramid, back );
        
        //left
        Triangle3D left = (Triangle3D){a,d,tip};
        Object3D_append_triangle(pyramid, left );
    } //down
    else if (strcmp(orientation, "left") == 0){
        Object3D_update_coords(w, w, 'x', origin, &a, &b, &c, &d);
        Object3D_append_quadrilateral(pyramid, a,b,c,d);
        Object3D_coord_shift(origin, 'y', -h, &tip);
        //top
        Triangle3D top = (Triangle3D){a,b,tip};
        Object3D_append_triangle(pyramid, top );
        
        //front
        Triangle3D front = (Triangle3D){b,c,tip};
        Object3D_append_triangle(pyramid, front );
        
        //bottom
        
        Triangle3D bottom = (Triangle3D){c,d,tip};
        Object3D_append_triangle(pyramid, bottom );
        
        //back
        Triangle3D back = (Triangle3D){a,d,tip};
        Object3D_append_triangle(pyramid, back);
    } //left
    else if (strcmp(orientation, "forward") == 0){
        Object3D_update_coords(w, w, 'y', origin, &a, &b, &c, &d);
        Object3D_append_quadrilateral(pyramid, a,b,c,d);
        Object3D_coord_shift(origin, 'x', h, &tip); //apex along x
        //top
        Triangle3D top = (Triangle3D){a,b,tip};
        Object3D_append_triangle(pyramid, top );
        
        //front
        Triangle3D front = (Triangle3D){b,c,tip};
        Object3D_append_triangle(pyramid, front );
        
        //bottom
        
        Triangle3D bottom = (Triangle3D){c,d,tip};
        Object3D_append_triangle(pyramid, bottom );
        
        //back
        Triangle3D back = (Triangle3D){a,d,tip};
        Object3D_append_triangle(pyramid, back);
   
    } //forward
    
    else if (strcmp(orientation, "backward") == 0){
        Object3D_update_coords(w, w, 'y', origin, &a, &b, &c, &d);
        Object3D_append_quadrilateral(pyramid, a,b,c,d);
        Object3D_coord_shift(origin, 'x', -h, &tip); //apex along the x
        //top
        Triangle3D top = (Triangle3D){a,b,tip};
        Object3D_append_triangle(pyramid, top );
        
        //front
        Triangle3D front = (Triangle3D){b,c,tip};
        Object3D_append_triangle(pyramid, front );
        
        //bottom
        
        Triangle3D bottom = (Triangle3D){c,d,tip};
        Object3D_append_triangle(pyramid, bottom );
        
        //back
        Triangle3D back = (Triangle3D){a,d,tip};
        Object3D_append_triangle(pyramid, back);
    } //backward
    else{
        printf("enter a valid orientation\n");
    }
    
#ifdef db_pyr
    Object3D_db_print(pyramid);
#endif
    return pyramid;
}

/*
 * This function should create a new Object3D on the heap and populate it with
 * a bunch of triangles to represent a cuboid in 3D space.
 * The caller is responsible for freeing the memory, or, if this shape gets
 * added to a Scene3D, that is can be freed when the scene is.
 *   Parameters:
 *     origin: The origin point for the cuboid (center)
 *     width: The width of the cuboid (x)
 *     height: The height of the cuboid (y)
 *     depth: The depth of the cuboid (z)
 */
Object3D* Object3D_create_cuboid(
    Coordinate3D origin,
    double w, double h, double depth){
    Object3D* cuboid = malloc(sizeof(Object3D));
    cuboid->count = 0;
    cuboid->root = NULL;
    Coordinate3D a,b,c,d;
    Object3D_update_coords(w, h, 'z', origin, &a, &b, &c, &d);
    
    
    
    Object3D_append_quadrilateral(cuboid, a,b,c,d);
    /* now, append the sides*/
    
    //side1
    Coordinate3D a1, b1;
    Object3D_update_coord_for_depth(a, depth, &a1);
    Object3D_update_coord_for_depth(b, depth, &b1);
    Object3D_append_quadrilateral(cuboid, a,b,a1,b1);
    
    //side2
    Coordinate3D c1;
    Object3D_update_coord_for_depth(c, depth, &c1);
    Object3D_append_quadrilateral(cuboid, b,c,b1,c1);
    
    //side3
    Coordinate3D d1;
    Object3D_update_coord_for_depth(d, depth, &d1);
    Object3D_append_quadrilateral(cuboid, c,d,c1,d1);
    
    //side4
    Object3D_append_quadrilateral(cuboid, a,d, a1, d1);
    
    //top
    Object3D_append_quadrilateral(cuboid, a1,b1, c1, d1);
        
    return cuboid;
}


void Object3D_append_triangle_helper(Triangle3DNode* cur, Triangle3D triangle){
    if (cur->next == NULL){ //this is ou
        cur->next =  malloc(sizeof(Triangle3DNode));
        cur->next->triangle.a = triangle.a;
        cur->next->triangle.b = triangle.b;
        cur->next->triangle.c = triangle.c;
        cur->next->next = NULL;
#ifdef db_o_append
        printf("cur       = %p\n", cur);
        printf("cur->next = %p\n", cur->next);
        print_down_arrow();
#endif
        return;
    }
    else{
        Object3D_append_triangle_helper(cur->next, triangle);
    }
}
/*
 * This function should append a triangle to the Linked list of Triangle3DNode's
 * within this object.
 *   Parameters:
 *     object: The object ot append the triangle to.
 *     triangle: The triangle to append.
 */
void Object3D_append_triangle(Object3D* this, Triangle3D triangle){
    //Object3D_append_triangle_helper(this->root, triangle);
    if (this->root == NULL){ //it's our first time adding a node
        this->root = Triangle3DNode_create_node(triangle);
#ifdef db
        printf("cur       = %p\n", this->root);
        printf("cur->next = %p\n", this->root->next);
        print_down_arrow();
#endif
    }
    else{
        Object3D_append_triangle_helper(this->root, triangle);
    }
    this->count++;
#ifdef db0
    print_db_fct("Object3D_append_triangle");
    printf("coord a: ");;Coordinate3D_db_print(this->root->triangle.a);
    printf("coord b: ");Coordinate3D_db_print(this->root->triangle.b);
    printf("coord c: ");Coordinate3D_db_print(this->root->triangle.c);
#endif
}



Triangle3DNode* Triangle3DNode_create_node(Triangle3D triangle){
    Triangle3DNode* this =  malloc(sizeof(Triangle3DNode));
    this->triangle.a = triangle.a;
    this->triangle.b = triangle.b;
    this->triangle.c = triangle.c;
#ifdef db
    print_db_fct("Triangle3DNode_create_node2");
    Coordinate3D_db_print(triangle.a);
    Coordinate3D_db_print(triangle.b);
    Coordinate3D_db_print(triangle.c);
#endif
    this->next = NULL;
    return this;
}

void Object3D_append_quadrilateral(
    Object3D* object,
    Coordinate3D a, Coordinate3D b, Coordinate3D c, Coordinate3D d) {
         Triangle3D triangle_1 = (Triangle3D) {a, b, c};
         Triangle3D triangle_2 = (Triangle3D) {b, c, d};
         Triangle3D triangle_3 = (Triangle3D) {a, c, d};
         Triangle3D triangle_4 = (Triangle3D) {a, b, d};
    
#ifdef db_quad
    print_db_fct("Object3D_append_quadrilateral");
#endif
    Object3D_append_triangle(object, triangle_1);
    Object3D_append_triangle(object, triangle_2);
    Object3D_append_triangle(object, triangle_3);
    Object3D_append_triangle(object, triangle_4);
#ifdef db_quad
    Object3D_db_print(object);
#endif
}

/* given a length l and width w, determine the 4 cordinates a,b, c,d
 in 3d space of a quadrilateral */
void Object3D_update_coords(double length, double width, char axis, Coordinate3D origin, Coordinate3D* a, Coordinate3D* b, Coordinate3D* c, Coordinate3D* d){
    double x = origin.x;
    double y = origin.y;
    double z = origin.z;
    switch (axis){
        case 'x':
            *a = (Coordinate3D){x - width/2, y , z + length/2};
            *b = (Coordinate3D){x + width/2, y, z + length/2};
            *c = (Coordinate3D){x + width/2, y, z - length/2};
            *d = (Coordinate3D){x - width/2, y, z - length/2};
        break;
        case 'y': //pyramid point is along the y axis
            *a = (Coordinate3D){x, y + length/2, z + length/2};
            *b = (Coordinate3D){x, y - length/2, z + length/2};
            *c = (Coordinate3D){x, y + length/2, z - length/2};
            *d = (Coordinate3D){x, y - length/2, z - length/2};
        break;
        case 'z':
            *a = (Coordinate3D){x - width/2, y + length/2, z};
            *b = (Coordinate3D){x + width/2, y + length/2, z};
            *c = (Coordinate3D){x + width/2, y - length/2, z};
            *d = (Coordinate3D){x - width/2, y - length/2, z};
        break;
    }
}
//helper fct for cuboid
void Object3D_update_coord_for_depth(Coordinate3D in, double depth, Coordinate3D* out){
    (*out).x = in.x;
    (*out).y = in.y;
    (*out).z = in.z + depth;
}

void Object3D_coord_shift(Coordinate3D in, char axis, double shamt, Coordinate3D* out){
    switch (axis){
        case 'x':
            (*out).x = in.x+ shamt;
            (*out).y = in.y;
            (*out).z = in.z;
        break;
        case 'y':
            (*out).x = in.x;
            (*out).y = in.y+shamt;
            (*out).z = in.z;
        break;
        case 'z':
            (*out).x = in.x;
            (*out).y = in.y;
            (*out).z = in.z + shamt;
        break;
    }
}

Triangle3DNode* Triangle3DNode_create_node1(Coordinate3D a,  Coordinate3D b, Coordinate3D c){
    Triangle3DNode* this = malloc(sizeof(Triangle3DNode));
    this->triangle = (Triangle3D){a,b,c};
    this->next = NULL;
    return this;
}



void Coordinate3D_db_print(Coordinate3D coord){
    printf("(%.2f, %.2f, %.2f)", coord.x, coord.y, coord.z);
    }

void Object3D_db_print(Object3D* obj){
    if (obj->root == NULL)
        printf("[empty]");
    else{
        Object3D_db_print_helper(obj->root, 0);
    }
}
void Object3D_db_print_helper(Triangle3DNode* cur, int level){
    if (cur == NULL){
        return;
    }
    else{
        printf("triangle %d :", level);
        
        print_spaces(2);Coordinate3D_db_print(cur->triangle.a);
        print_spaces(2);Coordinate3D_db_print(cur->triangle.b);
        print_spaces(2);Coordinate3D_db_print(cur->triangle.c);
        printf("\n");
        print_down_arrow();
        Object3D_db_print_helper(cur->next, level+1);
        
    }
}

void print_down_arrow(){
    printf("\t\t|\n");
    printf("\t\tV\n");
}

void print_spaces(int num){
    for (int i = 0; i < num; i++){
        printf("  ");
    }
}
void print_db_fct(char* name){
    printf("--------------- %s() ---------------\n", name);
}



void Coordinate3D_print(Coordinate3D coord){
    printf("%.1f %.1f %.1f\n", coord.x, coord.y, coord.z);
    }

void Scene3D_print(Scene3D* scene){
    printf("solid scene\n");
    for (int i = 0; i < scene->count; i++){
        Object3D_print(scene->objects[i]);
    }
    printf("endsolid scene\n");
}

void Object3D_print(Object3D* obj){
    if (obj->root == NULL)
        return;
    else{
        Object3D_print_helper(obj->root, 0);
    }
}
void Object3D_print_helper(Triangle3DNode* cur, int level){
    if (cur == NULL){
        return;
    }
    else{
        print_spaces(1); printf("facet normal 0.0 0.0 0.0\n");
        print_spaces(2); printf("outer loop\n");
        print_spaces(3); printf("vertex ");Coordinate3D_print(cur->triangle.a);
        print_spaces(3); printf("vertex ");Coordinate3D_print(cur->triangle.b);
        print_spaces(3); printf("vertex ");Coordinate3D_print(cur->triangle.c);
        print_spaces(2); printf("endloop\n");
        print_spaces(1); printf("endfacet\n");
        Object3D_print_helper(cur->next, level+1);
        
    }
}
/*
 * Write every shape from the Scene3D to the file with file_name using the STL
 * text format. The function is responsible for opening, writing to, and
 * closing the file.
 *   Parameters:
 *     scene: The scene to write to the file
 *     file_name: The name of the file to write the STL data to
 */
void Scene3D_write_stl_text(Scene3D* scene, char* file_name){
    /* check if file already exists, if it does remove it*/
    if (exists(file_name)){
        remove(file_name);
//        if (remove(file_name) == 0)
//              printf("%s deleted successfully\n", file_name);
//        else
//          printf("Unable to delete %s\n", file_name);
    }
    FILE* file = fopen(file_name, "a+");
    if (file == NULL) {
        fprintf(stderr, "Opening file failed with code %d.\n", errno);
    }
    Scene3D_write(scene, file);
    fclose(file);
}


void Scene3D_write(Scene3D* scene, FILE* file){
    fprintf(file, "solid scene\n");
    for (int i = 0; i < scene->count; i++){
        Object3D_write(scene->objects[i], file);
    }
    fprintf(file, "endsolid scene\n");
}

void Object3D_write(Object3D* obj, FILE* file){
    if (obj->root == NULL)
        return;
    else{
        Object3D_write_helper(obj->root, 0, file);
    }
}
void write_spaces(int num, FILE* file){
    for (int i = 0; i < num; i++)
        fprintf(file, "  ");
}
void Object3D_write_helper(Triangle3DNode* cur, int level, FILE* file){
    if (cur == NULL){
        return;
    }
    else{
        write_spaces(1, file); fprintf(file,"facet normal 0.0 0.0 0.0\n");
        write_spaces(2, file); fprintf(file,"outer loop\n");
        write_spaces(3, file); fprintf(file,"vertex "); Coordinate3D_write(file, cur->triangle.a);
        write_spaces(3, file); fprintf(file,"vertex "); Coordinate3D_write(file, cur->triangle.b);
        write_spaces(3, file); fprintf(file,"vertex "); Coordinate3D_write(file, cur->triangle.c);
        write_spaces(2, file); fprintf(file,"endloop\n");
        write_spaces(1, file); fprintf(file,"endfacet\n");
        Object3D_write_helper(cur->next, level+1, file);
        
    }
}
void Coordinate3D_write(FILE* file, Coordinate3D coord){
    fprintf(file, "%.5f %.5f %.5f\n", coord.x, coord.y, coord.z);
}
int exists(const char *fname){
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}
