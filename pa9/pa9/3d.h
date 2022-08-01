#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/*
 * File: 3d.h
 * Author: Benjamin Dicken
 * Course: CS 352 at the UofA
 * Description:
 * A C library for creating 3D shapes and scenes.
 * This header includes several structs needed for representing the 3D shapes.
 * It also contains the prototypes for several of the public-facing functions.
 */

#ifndef THREE_D_H
#define THREE_D_H

/*
 * Represents a Cartesian coordinate (x,y,z) in 3D space.
 */
typedef struct Coordinate3D {
  double x;
  double y;
  double z;
} Coordinate3D;

/*
 * Represents a triangle in 3D Space.
 * a, b, and c represent the locations of each corner of the triangle.
 */
typedef struct Triangle3D {
  Coordinate3D a;
  Coordinate3D b;
  Coordinate3D c;
} Triangle3D;

/*
 * An Object3D is made up of zero or more triangles,  which can be combined to
 * create a shape such as a cuboid, a circle, a pyramid, etc. This
 * Triangle3DNode allows us to chain together multiple triangles in a linked
 * list type of structure. Object3D will store a pointer to the first node of
 * a Triangle3DNode linked list.
 */
typedef struct Triangle3DNode {
  Triangle3D triangle;
  struct Triangle3DNode * next;
} Triangle3DNode;

/*
 * An Object3D is made up of zero or more triangles, which can be combined to
 * create a single 3D object such as a cube, a circle, a pyramid, etc.
 * The count field should be used to track how many triangles are being used
 * to represent this shape. Then, we have a pointer to the root (the first)
 * Triangle3DNode, which stores a triangle, and a pointer to the next
 * Triangle3DNode.
 */
typedef struct Object3D {
  long count;
  Triangle3DNode* root;
} Object3D;

/*
 * This represents a scene in 3D space containing 0 or more objects within it.
 * The count field represents the number of Object3D's this scene contains.
 * The size field represents the size of the array to store the Object3Ds.
 * The objects field represents a pointer to an array of Object3D pointers.
 * This array should start off with a small value to save memory, and only grow
 * as needed as more Object3Ds are added.
 */
typedef struct Scene3D {
  long count;
  long size;
  Object3D** objects;
} Scene3D;

/*
 * This function allocate space for a new Scene3D object on the heap,
 * initializes the values to defaults as necessary, and returns a pointer to
 * the object in memory.
 */
Scene3D* Scene3D_create();

/*
 * Frees the memory on the heap for the Scene3D itself, as well as the Object3D
 * and Triangle3DNode's within it.
 *   Parameters:
 *     scene: The scene to destroy
 */
void Scene3D_destroy(Scene3D* scene);

/*
 * Appends a new object to the end of the Scene3D's array of objects.
 * This function is responsible for handling the dynamic growing of the array
 * of Object3D pointers when necessary.
 *   Parameters:
 *     scene: The scene to have an object appended to
 *     object: The object to append to this scene
 */
void Scene3D_append(Scene3D* scene, Object3D* object);
void Scene3D_write_stl_text(Scene3D* scene, char* file_name);
void Scene3D_write_stl_binary(Scene3D* scene, char* file_name);

/* helper funcs for Scene3D_write_stl_text() */
int exists(const char *fname);
void Scene3D_write(Scene3D* scene, FILE* file);
void Object3D_write_helper(Triangle3DNode* cur, int level, FILE* file);
void Object3D_write(Object3D* obj, FILE* file);
void Coordinate3D_write(FILE* file, Coordinate3D coord);

/* helper funcs for Scene3D_write_stl_binary() */
void Object3D_write_binary_helper(Triangle3DNode* cur, int level, FILE* file);
void Object3D_write_binary(Object3D* obj, FILE* file);
void Scene3D_write_stl_binary(Scene3D* scene, char* file_name);
void Coordinate3D_write_binary(Coordinate3D coord, FILE* file);
void Scene3D_write_stl_binary_header(Scene3D* scene, FILE* file);
void Scene3D_write_stl_binary_triangle_count(Scene3D* scene, FILE* file);
void Scene3D_write_stl_binary_normal( FILE* file);
void Scene3D_write_stl_binary_scene(Scene3D* scene, FILE* file);
void Scene3D_write_stl_binary_facet(Scene3D* scene, FILE* file);
Object3D* Object3D_create_pyramid(
    Coordinate3D origin,
    double width, double height, char* orientation);

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
    double width, double height, double depth);
void Object3D_coord_shift(Coordinate3D in, char axis, double shamt, Coordinate3D* out);
void Object3D_update_coord_for_depth(Coordinate3D in, double depth, Coordinate3D* out_);
/*
 * This function should append a triangle to the Linked list of Triangle3DNode's
 * within this object.
 *   Parameters:
 *     object: The object ot append the triangle to.
 *     triangle: The triangle to append.
 */
void Object3D_append_triangle(Object3D* object, Triangle3D triangle);

void Object3D_append_quadrilateral(Object3D* object,
                Coordinate3D a, Coordinate3D b, Coordinate3D c, Coordinate3D d);
void Object3D_destroy(Object3D* obj);
void Object3D_destroy_helper(Triangle3DNode* cur);
Triangle3DNode* Triangle3DNode_create_node(Triangle3D triangle);

void Coordinate3D_db_print(Coordinate3D coord);
void Object3D_update_coords(double length, double width, char axis, Coordinate3D origin, Coordinate3D* a, Coordinate3D* b, Coordinate3D* c, Coordinate3D* d);
void Object3D_update_coords2(double x_dim, double y_dim, double z_dim, char axis, Coordinate3D origin, Coordinate3D* a, Coordinate3D* b, Coordinate3D* c, Coordinate3D* d);
void Object3D_db_print_helper(Triangle3DNode* cur, int level);
void Object3D_db_print(Object3D* obj);
void Scene3D_print(Scene3D* scene);
void Coordinate3D_print(Coordinate3D coord);
void Object3D_print_helper(Triangle3DNode* cur, int level);
void Object3D_print(Object3D* obj);
void print_down_arrow();
void print_spaces(int num);
void print_db_fct(char* name);

Object3D* Object3D_create_fractal(Coordinate3D origin, double size, int levels);
Object3D* Object3D_create_fractal_helper(Coordinate3D origin, double orig_size, double cur_size, Object3D* fractal);
Object3D* Object3D_create_sphere(Coordinate3D origin, double radius, double increment);
void Object3D_spherical2cartesian(Coordinate3D origin, double radius, double theta, double phi, Coordinate3D* out);
void Scene3D_write_stl_binary(Scene3D* scene, char* file_name);
double to_degrees(double in);
int Scene3D_count_triangles(Scene3D* this);
void Object3D_append(Object3D* o1, Object3D* o2);
void Object3D_append_helper(Triangle3DNode* a, Triangle3DNode* b);

#endif
