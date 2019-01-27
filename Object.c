//Include zone
#include "Object.h"

//Macros zone

//Type Charapter
struct ObjectRep {
    //Object properties
    int x;           // X axis
    int y;           // Y axis
    int w;           // Width
    int h;           // Height
    bool isInteractive;  // is interactive?
    bool isScoreable;    // is scoreable?
    // Player variables
    Imagen sprite;   // Base sprite
};
//Constructor
Object newObject(int x, int y, int w, int h, bool isInteractive, bool isScoreable, Imagen sprite){
    Object obj = malloc(sizeof(struct ObjectRep));
        obj -> x = x;
        obj -> y = y;
        obj -> w = w;
        obj -> h = h;
        obj -> isInteractive = isInteractive;
        obj -> isScoreable = isScoreable;
        obj -> sprite = sprite;
    return obj;
}
// free images
void freeObjectResources(Object obj) {
    //Pantalla_ImagenLibera(obj -> sprite);
    free(obj);
}

// Data Select
// Getters
int getObjectX(Object obj) {
    return obj -> x;
}
int getObjectY(Object obj) {
    return obj -> y;
}
int getObjectW(Object obj) {
    return obj -> w;
}
int getObjectH(Object obj) {
    return obj -> h;
}
bool getObjectInteractive(Object obj) {
    return obj -> isInteractive;
}
bool getObjectScoreable(Object obj) {
    return obj -> isScoreable;
}

//Functions
void drawObject(Object obj, Camera camera){
    Pantalla_DibujaImagen(obj -> sprite, transformaCameraX(camera, getObjectX(obj)), obj -> y, obj -> w, obj -> h);
}
