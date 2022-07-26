//
//  generator.c
//  pa8
//
//  Created by Rahel Gerson on 7/25/22.
//

#include <stdio.h>
#include "3d.h"
int main(){
//    Scene3D* star = Scene3D_create();
//    char* directions[] = {"up", "down", "left", "right", "forward", "backward"};
//    Coordinate3D origin = (Coordinate3D){100, 100, 100};
//    for (int i = 0; i <= 5; i ++) {
//        Object3D* object = Object3D_create_pyramid(origin, 20, 30, directions[i]);
//        Scene3D_append(star, object);
//   }
    Coordinate3D origin = {0,0,0};
    Object3D* pyramid = Object3D_create_pyramid(origin, 20.0, 40.0, "up");
    Object3D_destroy(pyramid);
    //Scene3D_write_stl_text(star, "star.stl");
}
