//Include zone
#include "Enemy.h"

//Macros zone

//Type Charapter
struct EnemyRep {
    //Enemy properties
    int x;           // X axis
    int y;           // Y axis
    int w;           // Width
    int h;           // Height
    int speed;       // Speed
    int prevX;       // X before change
    int prevY;       // Y before change
    int startX;      // initial X
    int startY;      // initial Y
    int moveZoneX;   // for move in both directions X axis
    bool isStatic;   // is Static?
    bool isFly;      // is Fly?
    bool isRev;      // is reverse?
    // Player variables
    Imagen sprite;   // Base sprite
};
//Constructor
Enemy newEnemy(int x, int y, int w, int h, int moveZoneX, bool isStatic, bool isFly, Imagen sprite) {
    Enemy emy = malloc(sizeof(struct EnemyRep));
        emy -> x = x;
        emy -> y = y;
        emy -> w = w;
        emy -> h = h;
        emy -> speed = 0;
        emy -> prevX = x;
        emy -> prevY = y;
        emy -> startX = x;
        emy -> startY = y;
        emy -> moveZoneX = moveZoneX;
        emy -> isStatic = isStatic;
        emy -> isFly = isFly;
        emy -> isRev = false;
        emy -> sprite = sprite;
    return emy;
}
// free images
void freeEnemyResources(Enemy emy) {
    //Pantalla_ImagenLibera(emy -> sprite);
    free(emy);
}

// Data Select
// Getters
int getEnemyX(Enemy emy) {
    return emy -> x;
}
int getEnemyY(Enemy emy) {
    return emy -> y;
}
int getEnemyW(Enemy emy) {
    return emy -> w;
}
int getEnemyH(Enemy emy) {
    return emy -> h;
}
int getEnemySpeed(Enemy emy) {
    return emy -> speed;
}
int getEnemyPrevX(Enemy emy) {
    return emy -> prevX;
}
int getEnemyPrevY(Enemy emy) {
    return emy -> prevY;
}
int getEnemyStartX(Enemy emy) {
    return emy -> startX;
}
int getEnemyStartY(Enemy emy) {
    return emy -> startY;
}
int getEnemyMoveZoneX(Enemy emy) {
    return emy -> moveZoneX;
}
bool isEnemyStatic(Enemy emy) {
    return emy -> isStatic;
}
bool isEnemyFly(Enemy emy) {
    return emy -> isFly;
}
bool isEnemyRev(Enemy emy) {
    return emy -> isRev;
}
//Setters
void setEnemyX(Enemy emy, int value) {
    emy -> x = value;
}
void setEnemyY(Enemy emy, int value) {
    emy -> y = value;
}
void setEnemySpeed(Enemy emy, int value) {
    emy -> speed = value;
}
void setEnemyPrevX(Enemy emy, int value) {
    emy -> prevX = value;
}
void setEnemyPrevY(Enemy emy, int value) {
    emy -> prevY = value;
}
void setEnemyStatic(Enemy emy, bool value) {
    emy -> isStatic = value;
}
void setEnemyFly(Enemy emy, bool value) {
    emy -> isFly = value;
}
void setEnemyRev(Enemy emy, bool value) {
    emy -> isRev = value;
}
// Increments
void incEnemyX(Enemy emy, int inc) {
    emy -> x = emy -> x + inc;
}
void incEnemyY(Enemy emy, int inc) {
    emy -> y = emy -> y + inc;
}
void incEnemySpeed(Enemy emy, int inc) {
    emy -> speed = emy -> speed + inc;
}
// Decrements
void decEnemyX(Enemy emy, int dec) {
    emy -> x = emy -> x - dec;
}
void decEnemyY(Enemy emy, int dec) {
    emy -> y = emy -> y - dec;
}
void decEnemySpeed(Enemy emy, int dec) {
    emy -> speed = emy -> speed - dec;
}

//Functions
/*
 * Update enemy
 */
void updateEnemy(Enemy emy) {
    setEnemyPrevX(emy, getEnemyX(emy));
    setEnemyPrevY(emy, getEnemyY(emy));
    if (getEnemyX(emy) > (getEnemyStartX(emy) + getEnemyMoveZoneX(emy))) {
        setEnemyRev(emy, false);
    }
    else if (getEnemyX(emy) < getEnemyStartX(emy)) {
        setEnemyRev(emy, true);
    }
    if (isEnemyRev(emy)) {
        if (!isEnemyStatic(emy)) {
            incEnemyX(emy, 2);
        }
    }
    else {
        if (!isEnemyStatic(emy)) {
            decEnemyX(emy, 2);
        }
    }
    if (!isEnemyFly(emy)) {
        setEnemyY(emy, getEnemyY(emy) + getEnemySpeed(emy));
        incEnemySpeed(emy, 2);
    }
}

//Collides
bool isCollidingWithObjectE(Enemy emy, Object obj) {
    if (getEnemyY(emy)+getEnemyH(emy) > getObjectY(obj)
            && getEnemyY(emy) < getObjectY(obj)+getObjectH(obj)
            && getEnemyX(emy) < getObjectX(obj)+getObjectW(obj)
            && getEnemyX(emy)+getEnemyW(emy) > getObjectX(obj)
            && isCollidingWithObjectEWidth(emy, obj)
            && isCollidingWithObjectEHeight(emy, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectETop(Enemy emy, Object obj) {
    if (getEnemyY(emy)+getEnemyH(emy) > getObjectY(obj)
            && isCollidingWithObjectEWidth(emy, obj)
            && isCollidingWithObjectEHeight(emy, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectEDown(Enemy emy, Object obj) {
    if (getEnemyY(emy) < getObjectY(obj)+getObjectH(obj)
            && isCollidingWithObjectEWidth(emy, obj)
            && isCollidingWithObjectEHeight(emy, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectERight(Enemy emy, Object obj) {
    if (getEnemyX(emy) < getObjectX(obj)+getObjectW(obj)
            && isCollidingWithObjectEWidth(emy, obj)
            && isCollidingWithObjectEHeight(emy, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectELeft(Enemy emy, Object obj) {
    if (getEnemyX(emy)+getEnemyW(emy) > getObjectX(obj)
            && isCollidingWithObjectEWidth(emy, obj)
            && isCollidingWithObjectEHeight(emy, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectEWidth(Enemy emy, Object obj) {
    if (getEnemyX(emy)+getEnemyW(emy) > getObjectX(obj)
            && getEnemyX(emy) < getObjectX(obj)+getObjectW(obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectEHeight(Enemy emy, Object obj) {
    if (getEnemyY(emy)+getEnemyH(emy) > getObjectY(obj)
            && getEnemyY(emy) < getObjectY(obj)+getObjectH(obj)
            ) {
        return true;
    }
    return false;
}

/*
 * Update Enemy collide with objects.
 */
void updateEnemyCollideWithObjects(Enemy emy, NodePtrObject objPtr){
    NodePtrObject copyObjectsList;
    if (getEnemyPrevY(emy) > getEnemyY(emy)) {
        copyObjectsList = getNextNodePtrObject(objPtr);
        while (copyObjectsList != NULL && !isCollidingWithObjectEDown(emy, getElementNodePtrObject(copyObjectsList))) {
            copyObjectsList = getNextNodePtrObject(copyObjectsList);
        }
        if (copyObjectsList != NULL) {
            if (getObjectInteractive(getElementNodePtrObject(copyObjectsList))) {
                setEnemyY(emy, getObjectY(getElementNodePtrObject(copyObjectsList)) + getObjectH(getElementNodePtrObject(copyObjectsList)));
                setEnemySpeed(emy, 0);
            }
        }
    }
    else if (getEnemyPrevY(emy) < getEnemyY(emy)) {
        copyObjectsList = getNextNodePtrObject(objPtr);
        while (copyObjectsList != NULL && !isCollidingWithObjectETop(emy, getElementNodePtrObject(copyObjectsList))) {
            copyObjectsList = getNextNodePtrObject(copyObjectsList);
        }
        if (copyObjectsList != NULL) {
            if (getObjectInteractive(getElementNodePtrObject(copyObjectsList))) {
                setEnemyY(emy, getObjectY(getElementNodePtrObject(copyObjectsList)) - getEnemyH(emy));
                setEnemySpeed(emy, 0);
            }
        }
    }
    if (getEnemyPrevX(emy) < getEnemyX(emy)) {
        copyObjectsList = getNextNodePtrObject(objPtr);
        while (copyObjectsList != NULL && !isCollidingWithObjectELeft(emy, getElementNodePtrObject(copyObjectsList))) {
            copyObjectsList = getNextNodePtrObject(copyObjectsList);
        }
        if (copyObjectsList != NULL) {
            if (getObjectInteractive(getElementNodePtrObject(copyObjectsList))) {
                setEnemyX(emy, getObjectX(getElementNodePtrObject(copyObjectsList)) - getEnemyW(emy));
            }
        }
    }
    else if (getEnemyPrevX(emy) > getEnemyX(emy)) {
        copyObjectsList = getNextNodePtrObject(objPtr);
        while (copyObjectsList != NULL && !isCollidingWithObjectERight(emy, getElementNodePtrObject(copyObjectsList))) {
            copyObjectsList = getNextNodePtrObject(copyObjectsList);
        }
        if (copyObjectsList != NULL) {
            if (getObjectInteractive(getElementNodePtrObject(copyObjectsList))) {
                setEnemyX(emy, getObjectX(getElementNodePtrObject(copyObjectsList)) + getObjectW(getElementNodePtrObject(copyObjectsList)));
            }
        }
    }
}

void drawEnemy(Enemy emy, Camera camera){
    Pantalla_DibujaImagen(emy -> sprite, transformaCameraX(camera, getEnemyX(emy)), emy -> y, emy -> w, emy -> h);
}
