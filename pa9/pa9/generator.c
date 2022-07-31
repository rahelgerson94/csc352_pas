//
//  generator.c
//  pa9
//
//  Created by Rahel Gerson on 7/25/22.
//

#include <stdio.h>
#include "3d.h"

//#define test_sphere
//#define test_Object3D_append_helper
#define test_print
int main(){
    Coordinate3D o = {0,0,0};

#ifdef test_sphere
    Scene3D* sphere = Scene3D_create();
    Object3D* sphere_obj = Object3D_create_sphere(o, 50, 90);
    Scene3D_append(sphere, sphere_obj);
    Scene3D_write_stl_text(sphere, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/sphere.stl");
    Scene3D_destroy(sphere);
#endif
#ifdef test_Object3D_append_helper
    
    Coordinate3D o2 = {0,0,20};
    Object3D* cube1 = Object3D_create_cuboid(o, 10, 10, 10);
    Object3D* cube2 =  Object3D_create_cuboid(o2, 10, 10, 10);
    
    Object3D_append(cube1, cube2);
    Object3D_db_print(cube1);
     //Scene3D* test_append = Scene3D_create();
    //Scene3D_append(test_append, cube1);
    //Scene3D_append(test_append, cube2);
     //Scene3D_append(test_append, cube1);
    //Scene3D_write_stl_text(test_append, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/cubetest.stl");
     //Scene3D_destroy(test_append);
    //Object3D_destroy(cube2);
    
    
    
     Object3D_db_print(cube1);
    //Object3D_destroy(cube2);
     Object3D_destroy(cube1);
#endif
    
#ifdef test_print
    char* file_name = "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa9/tests/cube_stl.bin";
    Scene3D* cube = Scene3D_create();
    Object3D* cube_o = Object3D_create_cuboid(o, 10, 10, 10);
    Scene3D_append(cube, cube_o);
    Scene3D_write_stl_binary(cube, file_name);
    Scene3D_destroy(cube);
#endif
    
}
    
