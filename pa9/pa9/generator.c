//
//  generator.c
//  pa9
//
//  Created by Rahel Gerson on 7/25/22.
//

#include <stdio.h>
#include "3d.h"

#define test_sphere
int main(){
    Coordinate3D o = {0,0,0};

#ifdef test_sphere
    Scene3D* sphere = Scene3D_create();
    Object3D* sphere_obj = Object3D_create_sphere(o, 50, 90);
    Scene3D_append(sphere, sphere_obj);
    Scene3D_write_stl_text(sphere, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa8/tests/sphere.stl");
    Scene3D_destroy(sphere);
#endif
}
    
