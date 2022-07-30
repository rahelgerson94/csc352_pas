//
//  generator.c
//  pa8
//
//  Created by Rahel Gerson on 7/25/22.
//

#include <stdio.h>
#include "3d.h"
#define test_star
#define test_destroy
#define test_scene_append
#define test_cuboid
#define test_pyramid_valgrind
#define test_cube2
#define test_cube3
#define parallel_cubes
//#define test_quad
#define test_face
#define test_cuboid
//#define local

int main(){
    Coordinate3D o = {0,0,0};
//test1
#ifdef test_star
    Scene3D* star = Scene3D_create();
    char* directions[] = {"up", "down", "left", "right", "forward", "backward"};
    Coordinate3D origin = (Coordinate3D){100, 100, 100};
    for (int i = 0; i <= 5; i ++) {
        Object3D* object = Object3D_create_pyramid(origin, 20, 30, directions[i]);
        Scene3D_append(star, object);
   }
#ifdef local
    Scene3D_write_stl_text(star, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/star.stl");
#else
    Scene3D_write_stl_text(star, "out.stl");
#endif
    Scene3D_destroy(star);
#endif

//test2
#ifdef test_destroy
    //Coordinate3D o = {0,0,0};
    Object3D* pyramid_obj = Object3D_create_pyramid(o, 20.0, 40.0, "up");
    Object3D_destroy(pyramid_obj);
#endif
    
//test3
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
    
    
//test4
#ifdef test_cuboid
    Scene3D* cuboid = Scene3D_create();
    Object3D* cuboid_o = Object3D_create_cuboid(o, 6, 4, 12);
    Scene3D_append(cuboid, cuboid_o);
#ifdef local
    Scene3D_write_stl_text(cuboid, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/cuboid.stl");
#else
    Scene3D_write_stl_text(cuboid, "out.stl");
#endif
    Scene3D_destroy(cuboid);
#endif
    
//test5
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
    
//ttest6: make a house
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
    
#endif
    Scene3D_destroy(house);
    
//test7
#ifdef test_cube2
//
    Scene3D* cube2 = Scene3D_create();
    Coordinate3D o2 = {35,0,0};
    Object3D* cube2_o = Object3D_create_cuboid(o2, 5, 10, 15);
    
    Scene3D_append(cube2, cube2_o);
#ifdef local
    Scene3D_write_stl_text(cube2, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/cuboid_origin20.stl");
#else
    Scene3D_write_stl_text(cube2, "out.stl");
    
#endif
    Scene3D_destroy(cube2);
#endif
    
//test8
#ifdef test_cube3
//
    Scene3D* cube3 = Scene3D_create();
    //Coordinate3D o = {0,0,0};
    Object3D* cube3_o = Object3D_create_cuboid(o, 5, 10, 15);
    
    Scene3D_append(cube3, cube3_o);
#ifdef local
    Scene3D_write_stl_text(cube3, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/cuboid_origin0.stl");
#else
    Scene3D_write_stl_text(cube3, "out.stl");
#endif
    Scene3D_destroy(cube3);
#endif
    
//test9
#ifdef parallel_cubes
    Scene3D* s3 = Scene3D_create();
    Scene3D_append(s3, cube3_o);
    Scene3D_append(s3, cube2_o);
#ifdef local
    Scene3D_write_stl_text(cube3, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/parallel_cubes.stl");
#else
    Scene3D_write_stl_text(cube3, "out.stl");
#endif
    Scene3D_destroy(s3);
#endif
    
//test10
#ifdef test_face
    Scene3D*  face = Scene3D_create();
    Coordinate3D coordinate;
    Object3D* object;
    // Head
    coordinate = (Coordinate3D){25, 25, 25};
    object = Object3D_create_cuboid(coordinate, 50, 50, 50);
    Scene3D_append(face, object);
    // Eye
    coordinate = (Coordinate3D){15, 40, 0};
    object = Object3D_create_cuboid(coordinate, 10, 10, 10); Scene3D_append(face, object);
    // Eye
    coordinate = (Coordinate3D){35, 40, 0};
    object = Object3D_create_cuboid(coordinate, 10, 10, 10); Scene3D_append(face, object);
    // Mouth
    coordinate = (Coordinate3D){25, 15, 0};
    object = Object3D_create_cuboid(coordinate, 30, 7, 10);
#ifdef local
    Scene3D_append(face, object); Scene3D_write_stl_text(face, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/face.stl");
#else
    Scene3D_write_stl_text(face, "out.stl");
#endif
    Scene3D_destroy(face);
#endif
}
