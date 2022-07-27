//
//  generator.c
//  pa8
//
//  Created by Rahel Gerson on 7/25/22.
//

#include <stdio.h>
#include "3d.h"
//#define test1
//#define test_destroy
//#define test_scene_append
#define test_cuboid

//#define test_quad
int main(){
    Coordinate3D o = {0,0,0};
#ifdef test1
    Scene3D* star = Scene3D_create();
    char* directions[] = {"up", "down", "left", "right", "forward", "backward"};
    Coordinate3D origin = (Coordinate3D){100, 100, 100};
    for (int i = 0; i <= 5; i ++) {
        Object3D* object = Object3D_create_pyramid(origin, 20, 30, directions[i]);
        Scene3D_append(star, object);
   }
#endif
#ifdef test_destroy
    Coordinate3D o = {0,0,0};
    Object3D* pyramid_obj = Object3D_create_pyramid(o, 20.0, 40.0, "up");
    //Object3D_destroy(pyramid);
#endif
#ifdef test_scene_append
    Scene3D* pyramid_s = Scene3D_create();
    
    Object3D* pyramid_o0 = Object3D_create_pyramid(o, 6, 5, "up");
    Object3D* pyramid_o1 = Object3D_create_pyramid(o, 20.0, 40.0, "up");
    Object3D* pyramid_o2 = Object3D_create_pyramid(o, 20.0, 40.0, "up");
    Scene3D_append(pyramid_s, pyramid_o0);
    //Scene3D_append(pyramid_s, pyramid_o1);
    //Scene3D_append(pyramid_s, pyramid_o2);
    //Scene3D_print(pyramid_s);
    Scene3D_write_stl_text(pyramid_s, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/pyramid.stl");
    Scene3D_destroy(pyramid_s);
#endif
    //Scene3D_write_stl_text(star, "star.stl")
#ifdef test_cuboid
    Scene3D* cuboid = Scene3D_create();
    Object3D* cuboid_o = Object3D_create_cuboid(o, 4, 6, 2);
    Scene3D_append(cuboid, cuboid_o);
    Scene3D_write_stl_text(cuboid, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/cuboid.stl");

    Scene3D_destroy(cuboid);
#endif
    

}
