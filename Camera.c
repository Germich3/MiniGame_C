//Include zone
#include "Camera.h"

//Macros zone

//Type Charapter
struct CameraRep {
    // Camera Properties
    int x;
    int y;
    int width;
    int resolution;
};
//Constructor
Camera newCamera(int width, int resolution){
    Camera camera = malloc(sizeof(struct CameraRep));
        camera -> x = 0;
        camera -> y = 0;
        camera -> width = width;
        camera -> resolution = resolution;
    return camera;
};
void freeCameraResources(Camera camera){
    free(camera);
}
//Getters
int getCameraX(Camera camera){
    return camera -> x;
};
int getCameraY(Camera camera){
    return camera -> y;
};
int getCameraWidth(Camera camera){
    return camera -> width;
};
//Setters
void setCameraX(Camera camera, int value) {
    camera -> x = value;
}
void setCameraY(Camera camera, int value) {
    camera -> y = value;
}
//Functions
void updateCameraX(Camera camera, int x) {
    camera -> x = x - (camera -> resolution/2);
    if (camera -> x < 0) {
        camera -> x = 0;
    }
    if (camera -> x > camera -> width - camera -> resolution) {
        camera -> x = camera -> width - camera -> resolution;
    }
}
int transformaCameraX(Camera camera, int x) {
   return x - getCameraX(camera);
}