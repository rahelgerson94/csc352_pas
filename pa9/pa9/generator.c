/*
 Rahel Gerson
 csc352
 pa9 extends the functionalitty of pa8 by adding three new functions:
 create_fractal,
 write_stl_binary
 create_sphere
 */

#include <stdio.h>
#include "3d.h"

#define test_sphere
//#define test_fractal
//#define test_Object3D_append_helper
//#define test_print
//#define test_cube2
//#define test_pyramid_valgrind
#define db_round
//#define test_star

//#define local
char* file_name;
#ifndef local
    char* file_name = "out.stl";
#endif

int main(){
#ifdef db_round
    //double x = 0.00004;
    double x  = 0.00015;
    //x = 0.00012;
     x = 0.00004;
    int prec = 4;
    //printf("%f\n", fmod(50.125553, 10000.0));

    printf("%d: %.5f\n", prec, round_double(x, prec));
//    for (int i = 1; i <= 5; i ++)
//        printf("%d: %.5f\n", i, round_double(x, i));
#endif
    Coordinate3D o = {0,0,0};
    Coordinate3D oz = {0,0,100};
    Coordinate3D oy = {0,100,0};
    Coordinate3D ox = {100,0,0};



#ifdef test_sphere
    Scene3D* sphere = Scene3D_create();
    Object3D* sphere_objx = Object3D_create_sphere(ox, 50, 20);
    Object3D* sphere_obj0 = Object3D_create_sphere(o, 50, 20);
    Scene3D_append(sphere, sphere_objx);
    Scene3D_append(sphere, sphere_obj0);
#ifdef local
    file_name = "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa9/tests/spherex.stl";
#endif
    Scene3D_write_stl_text(sphere, file_name);
    Scene3D_destroy(sphere);
    
    sphere = Scene3D_create();
    sphere_obj0 = Object3D_create_sphere(o, 50, 20);
    Object3D* sphere_objy = Object3D_create_sphere(oy, 50, 20);
    Scene3D_append(sphere, sphere_objy);
    Scene3D_append(sphere, sphere_obj0);
    Scene3D_write_stl_text(sphere, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa9/tests/spherey.stl");
    
    Scene3D_write_stl_text(sphere, file_name);
    Scene3D_destroy(sphere);
    
    sphere = Scene3D_create();
    Object3D* sphere_objz = Object3D_create_sphere(oz, 50, 20);
    sphere_obj0 = Object3D_create_sphere(o, 50, 20);
    Scene3D_append(sphere, sphere_objz);
    Scene3D_append(sphere, sphere_obj0);
    Scene3D_write_stl_text(sphere, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa9/tests/spherez.stl");
    Scene3D_destroy(sphere);
    
    sphere = Scene3D_create();
    Object3D* sphere90 = Object3D_create_sphere(o, 100, 90);
    Scene3D_append(sphere, sphere90);
    Scene3D_write_stl_text(sphere, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa9/tests/sphere90.stl");
    Scene3D_destroy(sphere);
    
#endif
#ifdef test_Object3D_append_helper
    
    Coordinate3D o2 = {0,0,20};
    Object3D* cube1 = Object3D_create_cuboid(o, 10, 10, 10);
    Object3D* cube2 =  Object3D_create_cuboid(o2, 10, 10, 10);
    
    Object3D_append(cube1, cube2);
    Object3D_db_print(cube1);
     Object3D_destroy(cube1);
#endif
    
#ifdef test_print
    #ifdef local
    char* file_name_bin = "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa9/tests/cube_bin.stl";
    char* file_name_txt = "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa9/tests/cube_txt.stl";
    #endif
    Scene3D* cube = Scene3D_create();
    Object3D* cube_o = Object3D_create_cuboid(o, 10, 10, 10);
    
    Scene3D_append(cube, cube_o);
    
    Scene3D_write_stl_binary(cube, "out.stl");
    Scene3D_write_stl_text(cube, "out.stl");
    Scene3D_destroy(cube);


    Object3D* sphere1 = Object3D_create_sphere(o, 50, 90);
    Scene3D* sphere = Scene3D_create();
    Scene3D_append(sphere, sphere1);
#ifdef local
    char* sphere_bin = "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa9/tests/sphere_bin.stl";
    Scene3D_write_stl_binary(sphere, sphere_bin);
#endif
    Scene3D_write_stl_binary(sphere, "out.stl");
    Scene3D_destroy(sphere);
//    Coordinate3D test_coord = {20, 30, 40};
//    char* coord3d_fname = "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa9/tests/coord3d_test.stl";
//    FILE* coord3d_test= fopen(coord3d_fname, "wb+");
//    Coordinate3D_write_binary(test_coord, coord3d_test);
//    fclose(coord3d_test);
#endif //test_print
    
#ifdef test_fractal
#ifdef local
    char* file_name = "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa9/tests/fractal_3_levels.stl";
#endif
    
    Object3D* frac = Object3D_create_fractal(o, 16, 2);
    Scene3D* frac_s = Scene3D_create();
    Scene3D_append(frac_s, frac);
    Scene3D_write_stl_binary(frac_s, file_name);
    Scene3D_destroy(frac_s);
#ifdef local
    file_name = "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa9/tests/fractal_y.stl";
#endif
    Object3D* fracy = Object3D_create_fractal(oy, 16, 3);
    Scene3D* fracz_s = Scene3D_create();
    Scene3D_append(fracz_s, fracy);

#ifdef local
    Scene3D_write_stl_binary(fracz_s, file_name);
#else
    Scene3D_write_stl_binary(fracz_s, file_name);
#endif
    Scene3D_destroy(fracz_s);
#endif //test_fractal

#ifdef test_cube2
    Scene3D* cube2 = Scene3D_create();
    Coordinate3D o2 = {35,0,0};
    Object3D* cube2_o = Object3D_create_cuboid(o2, 5, 10, 15);
    
    Scene3D_append(cube2, cube2_o);
#ifdef local
    Scene3D_write_stl_text(cube2, "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa9/tests/cuboid_origin20.stl");
#else
    Scene3D_write_stl_text(cube2, "out.stl");
    
#endif
    Scene3D_destroy(cube2);
#endif //test_cube2
    

#ifdef test_pyramid_valgrind
    Scene3D* pyramid_s = Scene3D_create();
    Object3D* pyramid_o = Object3D_create_pyramid(o, 6, 5, "backward");
    Scene3D_append(pyramid_s, pyramid_o);
#ifdef local
    file_name= "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa9/tests/pyramid_backward.stl";
#else
    file_name = "out.stl";
#endif
    Scene3D_write_stl_text(pyramid_s, file_name);
    Scene3D_destroy(pyramid_s);
#endif //test_pyramid_valgrind

#ifdef test_star
    Scene3D* star = Scene3D_create();
    char* directions[] = {"up", "down", "left", "right", "forward", "backward"};
    Coordinate3D origin = (Coordinate3D){100, 100, 100};
    for (int i = 0; i <= 5; i ++) {
        Object3D* object = Object3D_create_pyramid(origin, 20, 30, directions[i]);
        Scene3D_append(star, object);
   }
#ifdef local
    file_name = "/Users/rahelmizrahi/Library/Mobile Documents/com~apple~CloudDocs/csc352_pas/pa9/tests/star.stl";
#else
    Scene3D_write_stl_text(star, file_name);
#endif
    Scene3D_destroy(star);
#endif //test_star
}

