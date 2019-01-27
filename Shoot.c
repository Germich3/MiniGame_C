//Include zone
#include "Shoot.h"

//Type Score
struct ShootRep {
    int x;           // X axis
    int y;           // Y axis
    int w;           // Width
    int h;           // Height
    int startX;      // initial x
    int prevY;       // previous y
    int speed;       // speed
    int travel;      // max distance traveled
    bool isRev;      // reverse
    Imagen shootSprite;         // Base sprite
};

//Constructor
Shoot newShoot(int x, int y, int w, int h, int travel, bool isRev, Imagen shootSprite){
    Shoot sht = malloc(sizeof(struct ShootRep));
        sht -> x = x;
        sht -> y = y;
        sht -> w = w;
        sht -> h = h;
        sht -> startX = x;
        sht -> prevY = y;
        sht -> speed = 0;
        sht -> travel = travel;
        sht -> isRev = isRev;
        sht -> shootSprite = shootSprite;
    return sht;
}

void freeShoot(Shoot sht) {
    Pantalla_ImagenLibera(sht -> shootSprite);
    free(sht);
}

// Getters
int getShootX(Shoot sht) {
    return sht -> x;
}
int getShootY(Shoot sht) {
    return sht -> y;
}
int getShootW(Shoot sht) {
    return sht -> w;
}
int getShootH(Shoot sht) {
    return sht -> h;
}
int getShootStartX(Shoot sht) {
    return sht -> startX;
}
int getShootPrevY(Shoot sht) {
    return sht -> prevY;
}
int getShootSpeed(Shoot sht) {
    return sht -> speed;
}
int getShootTravel(Shoot sht) {
    return sht -> travel;
}
bool isShootRev(Shoot sht) {
    return sht -> isRev;
}

//Setters
void setShootX(Shoot sht, int value) {
    sht -> x = value;
}
void setShootY(Shoot sht, int value) {
    sht -> y = value;
}
void setShootSpeed(Shoot sht, int value) {
    sht -> speed = value;
}
void setShootRev(Shoot sht, bool value) {
    sht -> isRev = value;
}
void setShootPrevY(Shoot sht, int value) {
    sht -> prevY = value;
}

//Inc
void incShootSpeed(Shoot sht, int inc) {
    sht -> speed = sht -> speed + inc;
}
void incShootX(Shoot sht, int inc) {
    sht -> x = sht -> x + inc;
}
void decShootX(Shoot sht, int dec) {
    sht -> x = sht -> x - dec;
}

//Collides
bool isCollidingWithObjectS(Shoot sht, Object obj) {
    if (getShootY(sht)+getShootH(sht) > getObjectY(obj)
            && getShootY(sht) < getObjectY(obj)+getObjectH(obj)
            && getShootX(sht) < getObjectX(obj)+getObjectW(obj)
            && getShootX(sht)+getShootW(sht) > getObjectX(obj)
            && isCollidingWithObjectSWidth(sht, obj)
            && isCollidingWithObjectSHeight(sht, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectSTop(Shoot sht, Object obj) {
    if (getShootY(sht)+getShootH(sht) > getObjectY(obj) 
            && isCollidingWithObjectSWidth(sht, obj)
            && isCollidingWithObjectSHeight(sht, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectSDown(Shoot sht, Object obj) {
    if (getShootY(sht) < getObjectY(obj)+getObjectH(obj) 
            && isCollidingWithObjectSWidth(sht, obj)
            && isCollidingWithObjectSHeight(sht, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectSRight(Shoot sht, Object obj) {
    if (getShootX(sht) < getObjectX(obj)+getObjectW(obj)
            && isCollidingWithObjectSWidth(sht, obj)
            && isCollidingWithObjectSHeight(sht, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectSLeft(Shoot sht, Object obj) {
    if (getShootX(sht)+getShootW(sht) > getObjectX(obj)
            && isCollidingWithObjectSWidth(sht, obj)
            && isCollidingWithObjectSHeight(sht, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectSWidth(Shoot sht, Object obj) {
    if (getShootX(sht)+getShootW(sht) > getObjectX(obj) 
            && getShootX(sht) < getObjectX(obj)+getObjectW(obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectSHeight(Shoot sht, Object obj) {
    if (getShootY(sht)+getShootH(sht) > getObjectY(obj) 
            && getShootY(sht) < getObjectY(obj)+getObjectH(obj)
            ) {
        return true;
    }
    return false;
}

/*
 * Update shoot collide with objects.
 */
void updateShootCollideWithObject(Shoot sht, NodePtrObject objPtr){
    NodePtrObject copyObjList;
    
    copyObjList = getNextNodePtrObject(objPtr);
    while (copyObjList != NULL && !isCollidingWithObjectS(sht, getElementNodePtrObject(copyObjList))) {
        copyObjList = getNextNodePtrObject(copyObjList);
    }
    if (copyObjList != NULL) {
        if (getObjectInteractive(getElementNodePtrObject(copyObjList))) {
            if (getShootPrevY(sht) < getShootY(sht)) {
                if (isCollidingWithObjectSTop(sht, getElementNodePtrObject(copyObjList))) {
                    setShootSpeed(sht, -15);
                }
            }
        }
    }
}

// Collides Enemys
bool isCollidingWithEnemyS(Shoot sht, Enemy emy) {
    if (getShootY(sht)+getShootH(sht) > getEnemyY(emy)
            && getShootY(sht) < getEnemyY(emy)+getEnemyH(emy)
            && getShootX(sht) < getEnemyX(emy)+getEnemyW(emy)
            && getShootX(sht)+getShootW(sht) > getEnemyX(emy)
            && isCollidingWithEnemySWidth(sht, emy)
            && isCollidingWithEnemySHeight(sht, emy)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithEnemySTop(Shoot sht, Enemy emy) {
    if (getShootY(sht)+getShootH(sht) > getEnemyY(emy) 
            && isCollidingWithEnemySWidth(sht, emy)
            && isCollidingWithEnemySHeight(sht, emy)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithEnemySDown(Shoot sht, Enemy emy) {
    if (getShootY(sht) < getEnemyY(emy)+getEnemyH(emy) 
            && isCollidingWithEnemySWidth(sht, emy)
            && isCollidingWithEnemySHeight(sht, emy)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithEnemySRight(Shoot sht, Enemy emy) {
    if (getShootX(sht) < getEnemyX(emy)+getEnemyW(emy)
            && isCollidingWithEnemySWidth(sht, emy)
            && isCollidingWithEnemySHeight(sht, emy)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithEnemySLeft(Shoot sht, Enemy emy) {
    if (getShootX(sht)+getShootW(sht) > getEnemyX(emy)
            && isCollidingWithEnemySWidth(sht, emy)
            && isCollidingWithEnemySHeight(sht, emy)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithEnemySWidth(Shoot sht, Enemy emy) {
    if (getShootX(sht)+getShootW(sht) > getEnemyX(emy) 
            && getShootX(sht) < getEnemyX(emy)+getEnemyW(emy)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithEnemySHeight(Shoot sht, Enemy emy) {
    if (getShootY(sht)+getShootH(sht) > getEnemyY(emy) 
            && getShootY(sht) < getEnemyY(emy)+getEnemyH(emy)
            ) {
        return true;
    }
    return false;
}

void drawShoot(Shoot sht, Camera camera){
    Pantalla_DibujaImagen(sht -> shootSprite, transformaCameraX(camera, getShootX(sht)), sht -> y, sht -> w, sht -> h);
}