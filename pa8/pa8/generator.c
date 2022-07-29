//
//  generator.c
//  pa8
//
//  Created by Rahel Gerson on 7/25/22.
//

#include <stdio.h>
#include "3d.h"
//#define test_star
//#define test_destroy
//#define test_scene_append
#define test_cuboid
#define test_pyramid_valgrind
#define test_cube2
#define test_cube3
//#define test_quad
#define local

int main(){
    Coordinate3D o = {0,0,0};
#ifdef test_star
    Scene3D* star = Scene3D_create();
    char* directions[] = {"up", "down", "left", "right", "forward", "backward"};
    Coordinate3D origin = (Coordinate3D){100, 100, 100};
    for (int i = 0; i <= 5; i ++) {
        Object3D* object = Object3D_create_pyramid(origin, 20, 30, directions[i]);
        Scene3D_append(star, object);
   }
    //Scene3D_write_stl_text(star, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/star.stl");
    Scene3D_destroy(star);
#endif
#ifdef test_destroy
    //Coordinate3D o = {0,0,0};
    Object3D* pyramid_obj = Object3D_create_pyramid(o, 20.0, 40.0, "up");
    Object3D_destroy(pyramid_obj);
#endif
#ifdef test_scene_append
    Scene3D* pyramid_s = Scene3D_create();
    
    Object3D* pyramid_o0 = Object3D_create_pyramid(o, 6, 5, "up");
    Object3D* pyramid_o1 = Object3D_create_pyramid(o, 20.0, 40.0, "up");
    Object3D* pyramid_o2 = Object3D_create_pyramid(o, 20.0, 40.0, "up");
    Scene3D_append(pyramid_s, pyramid_o0);
    Scene3D_append(pyramid_s, pyramid_o1);
    Scene3D_append(pyramid_s, pyramid_o2);
    //Scene3D_print(pyramid_s);
    //Scene3D_write_stl_text(pyramid_s, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/pyramid.stl");
    Scene3D_destroy(pyramid_s);
#endif
    //Scene3D_write_stl_text(star, "star.stl")
#ifdef test_cuboid
    Scene3D* cuboid = Scene3D_create();
    Object3D* cuboid_o = Object3D_create_cuboid(o, 4, 6, 2);
    Scene3D_append(cuboid, cuboid_o);
#ifdef local
    Scene3D_write_stl_text(cuboid, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/cuboid.stl");
#else
    Scene3D_write_stl_text(cuboid, "out.stl");
#endif
    
    Scene3D_destroy(cuboid);
#endif
    
#ifdef test_pyramid_valgrind
    Scene3D* pyramid_s = Scene3D_create();
    Object3D* pyramid_o = Object3D_create_pyramid(o, 6, 5, "backward");
    Scene3D_append(pyramid_s, pyramid_o);
#ifdef local
    Scene3D_write_stl_text(pyramid_s, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/pyramid_backward.stl");
#else
    Scene3D_write_stl_text(pyramid_s, "out.stl");
#endif
    Scene3D_destroy(pyramid_s);
#endif
    
//make a house
    double base_height, roof_height;
    base_height = 10;
    Scene3D* house = Scene3D_create();
    Object3D* base = Object3D_create_cuboid(o, base_height, base_height, base_height);
    Coordinate3D roof_o = {0,0,base_height/2};
    roof_height = 5;
    Object3D* roof = Object3D_create_pyramid(roof_o, base_height, roof_height, "up");
    Scene3D_append(house, base);
    Scene3D_append(house, roof);
#ifdef local
    Scene3D_write_stl_text(house, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/house.stl");
#else
    Scene3D_write_stl_text(house, "out.stl");
    Scene3D_destroy(house);
#endif
    //make a diamond

#ifdef test_cube2
//
    Scene3D* cube1 = Scene3D_create();
    //Coordinate3D o = {20,20,20};
    base_height = 10;
    Object3D* cube1_o = Object3D_create_cuboid(o, base_height, base_height, base_height);
    
    Scene3D_append(cube1, cube1_o);
#ifdef local
    Scene3D_write_stl_text(cube1, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/cube_origin20.stl");
#else
    Scene3D_write_stl_text(cube1, "out.stl");
    Scene3D_destroy(cube1);
#endif
#endif
    
#ifdef test_cube3
//
    Scene3D* cube3 = Scene3D_create();
    //Coordinate3D o = {0,0,0};
    base_height = 10;
    Object3D* cube3_o = Object3D_create_cuboid(o, base_height, base_height, base_height);
    
    Scene3D_append(cube3, cube3_o);
#ifdef local
    Scene3D_write_stl_text(cube3, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/cube_origin0.stl");
#else
    Scene3D_write_stl_text(cube3, "out.stl");
    Scene3D_destroy(cube1);
#endif
#endif
}
