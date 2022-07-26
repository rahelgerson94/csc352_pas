//
//  3d.c
//  pa8
//
//  Created by Rahel Gerson on 7/25/22.
//
#include <math.h>
#include "3d.h"
//#define db0 //db for basis funcs
//#define db_pyramid
//#define db_quad
//#define db_o_append
#define db_o_destroy
#define db_s_append
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
    for (int i = 0; i < scene->count; i++){
        Object3D_destroy(scene->objects[i]);
    }
}
void Object3D_destroy(Object3D* obj){
#ifdef db_destroy
    print_db_fct("Object3D_destroy");
#endif
    Object3D_destroy_helper(obj->root);
    free(obj);
}
void Object3D_destroy_helper(Triangle3DNode* cur){
    if (cur == NULL)
        return;
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
    print_db_fct("Scene3D_append");
    if (scene->objects == NULL){
        scene->objects = malloc(sizeof(Object3D*)*2);
        scene->size = 2;
    }
    if (scene->count == scene->size){
        unsigned int new_amount = (scene->size*2)*(sizeof(Object3D*));
        scene->objects = realloc(scene->objects, new_amount );
        scene->size = scene->size*2;
    }
    scene->objects[scene->count] = malloc(sizeof(object)); //allocate
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
 * Write every shape from the Scene3D to the file with file_name using the STL
 * text format. The function is responsible for opening, writing to, and
 * closing the file.
 *   Parameters:
 *     scene: The scene to write to the file
 *     file_name: The name of the file to write the STL data to
 */
void Scene3D_write_stl_text(Scene3D* scene, char* file_name){}

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
    Object3D_update_coords(w, w, origin, &a, &b, &c, &d);
    Object3D_append_quadrilateral(pyramid, a,b,c,d);
    /* now, append the sides*/
    double x0 = origin.x;
    double y0 = origin.y;
    double z0 = origin.z;
    
    if (strcmp(orientation, "up") == 0){
        //up triangle
        a = (Coordinate3D){x0, y0, h};
        b = (Coordinate3D){x0 + (w/2), y0 + (w/2), z0};
        c = (Coordinate3D){x0 - (w/2), y0 + (w/2), z0};
        Triangle3D up = (Triangle3D){a,b,c};
        Object3D_append_triangle(pyramid, up );
        
        //right triangle
        a = (Coordinate3D){x0, y0, h};
        b = (Coordinate3D){x0 + (w/2), y0 - (w/2), z0};
        c = (Coordinate3D){x0 + (w/2), y0 + (w/2), z0};
        Triangle3D right = (Triangle3D){a,b,c};
        Object3D_append_triangle(pyramid, right );
        
        //down triangle
        a = (Coordinate3D){x0, y0, h};
        b = (Coordinate3D){x0 - (w/2), y0 - (w/2), z0};
        c = (Coordinate3D){x0 + (w/2), y0 - (w/2), z0};
        Triangle3D down = (Triangle3D){a,b,c};
        Object3D_append_triangle(pyramid, down );
        
        //left triangle
        a = (Coordinate3D){x0, y0, h};
        b = (Coordinate3D){x0 - (w/2), y0 - (w/2), z0};
        c = (Coordinate3D){x0 - (w/2), y0 + (w/2), z0};
        Triangle3D left = (Triangle3D){a,b,c};
        Object3D_append_triangle(pyramid, left);
    }//end up case
    else if (strcmp(orientation, "right") == 0){
        

    } //right
    else if (strcmp(orientation, "down") == 0){
        
   
    } //down
    else if (strcmp(orientation, "left") == 0){
        
   
    } //left
    
#ifdef db_pyr
    Object3D_print(pyramid);
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
    double width, double height, double depth){
    Object3D* obj = malloc(sizeof(Object3D));
    return obj;
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
    printf("coord a: ");;Coordinate3D_print(this->root->triangle.a);
    printf("coord b: ");Coordinate3D_print(this->root->triangle.b);
    printf("coord c: ");Coordinate3D_print(this->root->triangle.c);
#endif
}



Triangle3DNode* Triangle3DNode_create_node(Triangle3D triangle){
    Triangle3DNode* this =  malloc(sizeof(Triangle3DNode));
    this->triangle.a = triangle.a;
    this->triangle.b = triangle.b;
    this->triangle.c = triangle.c;
#ifdef db
    print_db_fct("Triangle3DNode_create_node2");
    Coordinate3D_print(triangle.a);
    Coordinate3D_print(triangle.b);
    Coordinate3D_print(triangle.c);
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
   
    Object3D_print(object);
#endif
}

/* given a length l and width w, determine the 4 cordinates a,b, c,d
 in 3d space of a quadrilateral */
void Object3D_update_coords(double length, double width, Coordinate3D origin, Coordinate3D* a, Coordinate3D* b, Coordinate3D* c, Coordinate3D* d){
    double x = origin.x;
    double y = origin.y;
    double z = origin.z;
    *a = (Coordinate3D){x - width/2, y + length/2, z};
    *b = (Coordinate3D){x + width/2, y + length/2, z};
    *c = (Coordinate3D){x + width/2, y - length/2, z};
    *d = (Coordinate3D){x - width/2, y - length/2, z};
}

Triangle3DNode* Triangle3DNode_create_node1(Coordinate3D a,  Coordinate3D b, Coordinate3D c){
    Triangle3DNode* this = malloc(sizeof(Triangle3DNode));
    this->triangle = (Triangle3D){a,b,c};
    this->next = NULL;
    return this;
}



void Coordinate3D_print(Coordinate3D coord){
    printf("(%.2f, %.2f, %.2f)", coord.x, coord.y, coord.z);
    }

void Object3D_print(Object3D* obj){
    if (obj->root == NULL)
        printf("[empty]");
    else{
        Object3D_print_helper(obj->root, 0);
    }
}
void Object3D_print_helper(Triangle3DNode* cur, int level){
    if (cur == NULL){
        return;
    }
    else{
        printf("triangle %d :", level);
        
        print_spaces(2);Coordinate3D_print(cur->triangle.a);
        print_spaces(2);Coordinate3D_print(cur->triangle.b);
        print_spaces(2);Coordinate3D_print(cur->triangle.c);
        printf("\n");
        print_down_arrow();
        Object3D_print_helper(cur->next, level+1);
        
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

double log2( double n ){
    return log( n ) / log( 2 ); // log(n)/log(2) is log2.
}
