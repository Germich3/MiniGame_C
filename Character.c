//Include zone
#include "Character.h"

//Macros zone

//Type Charapter
struct CharacterRep {
    // Player properties
    int x;           // X axis
    int y;           // Y axis
    int w;           // Width
    int h;           // Height
    int speed;       // phisics
    int frame;       // Walk, Run frame
    bool isInv;      // is inverse?
    bool isJumping;  // is jumping?
    bool isWalking;  // is walking?
    bool isRunning;  // is running?
    bool isDown;     // is down?
    bool isStable;   // is on the ground?
    
    // Player variables
    Imagen characterSprite[2];         // Base sprite
    Imagen characterSpriteJump[2];     // Jumping sprite
    Imagen characterSpriteWalk[4];     // Walking sprite
    Imagen characterSpriteRun[4];      // Running sprite
    Imagen characterSpriteDown[2];     // Down sprite
};
//Constructor
Character newCharacter(Imagen characterSprite[2], Imagen characterSpriteWalk[4], Imagen characterSpriteRun[4], Imagen characterSpriteJump[2], Imagen characterSpriteDown[2]){
    Character character = malloc(sizeof(struct CharacterRep));
        character -> x = 20;
        character -> y = 350;
        character -> w = 42;
        character -> h = 90;
        character -> frame = 0;
        character -> speed = 0;
        character -> isInv = false;
        character -> isJumping = false;
        character -> isWalking = false;
        character -> isRunning = false;
        character -> isDown = false;
        character -> isStable = false;
        character -> characterSprite[0] = characterSprite[0];
        character -> characterSprite[1] = characterSprite[1];
        character -> characterSpriteWalk[0] = characterSpriteWalk[0];
        character -> characterSpriteWalk[1] = characterSpriteWalk[1];
        character -> characterSpriteWalk[2] = characterSpriteWalk[2];
        character -> characterSpriteWalk[3] = characterSpriteWalk[3];
        character -> characterSpriteRun[0] = characterSpriteRun[0];
        character -> characterSpriteRun[1] = characterSpriteRun[1];
        character -> characterSpriteRun[2] = characterSpriteRun[2];
        character -> characterSpriteRun[3] = characterSpriteRun[3];
        character -> characterSpriteJump[0] = characterSpriteJump[0];
        character -> characterSpriteJump[1] = characterSpriteJump[1];
        character -> characterSpriteDown[0] = characterSpriteDown[0];
        character -> characterSpriteDown[1] = characterSpriteDown[1];
    return character;
}
// free images
void freeCharacterResources(Character character) {
    for (int i=0; i<2; i++){
            Pantalla_ImagenLibera(character -> characterSprite[i]);
            Pantalla_ImagenLibera(character -> characterSpriteJump[i]);
            Pantalla_ImagenLibera(character -> characterSpriteDown[i]);
    }
    for (int i=0; i<4; i++){
            Pantalla_ImagenLibera(character -> characterSpriteWalk[i]);
            Pantalla_ImagenLibera(character -> characterSpriteRun[i]);
    }
    free(character);
}

// Data Select
// Getters
int getCharacterX(Character character) {
    return character -> x;
}
int getCharacterY(Character character) {
    return character -> y;
}
int getCharacterW(Character character) {
    return character -> w;
}
int getCharacterH(Character character) {
    return character -> h;
}
int getCharacterSpeed(Character character) {
    return character -> speed;
}
int getCharacterFrame(Character character) {
    return character -> frame;
}
bool isCharacterInv(Character character) {
    return character -> isInv;
}
bool isCharacterJumping(Character character) {
    return character -> isJumping;
}
bool isCharacterWalking(Character character) {
    return character -> isWalking;
}
bool isCharacterRunning(Character character) {
    return character -> isRunning;
}
bool isCharacterDown(Character character) {
    return character -> isDown;
}
bool isCharacterStable(Character character) {
    return character -> isStable;
}

//Setters
void setCharacterX(Character character, int value) {
    character -> x = value;
}
void setCharacterY(Character character, int value) {
    character -> y = value;
}
void setCharacterSpeed(Character character, int value) {
    character -> speed = value;
}
void setCharacterInv(Character character, bool value) {
    character -> isInv = value;
}
void setCharacterJumping(Character character, bool value) {
    character -> isJumping = value;
}
void setCharacterWalking(Character character, bool value) {
    character -> isWalking = value;
}
void setCharacterRunning(Character character, bool value) {
    character -> isRunning = value;
}
void setCharacterDown(Character character, bool value) {
    character -> isDown = value;
}
void setCharacterStable(Character character, bool value) {
    character -> isStable = value;
}

// Increments
void incCharacterX(Character character, int inc) {
    character -> x = character -> x + inc;
}
void incCharacterY(Character character, int inc) {
    character -> y = character -> y + inc;
}
void incCharacterSpeed(Character character, int inc) {
    character -> speed = character -> speed + inc;
}
// Decrements
void decCharacterX(Character character, int dec) {
    character -> x = character -> x - dec;
}
void decCharacterY(Character character, int dec) {
    character -> y = character -> y - dec;
}
void decCharacterSpeed(Character character, int dec) {
    character -> speed = character -> speed - dec;
}
// actualiza el frame del walking
void updateCharacterFrame(Character character) {
    if (character -> frame == 0) {
        character -> frame = 1;
    } 
    else {
        character -> frame = 0;
    }
}

//Functions for character
/*
 * Update character sprite in each position.
 */
void updateCharacterSprite(Character character, Camera camera){
    int inv = 0;
    int frame = character -> frame;
    if (character -> isInv == true) {
        frame = frame + 2;
        inv = 1;
    }
    if (character -> isJumping == true) {
        Pantalla_DibujaImagen(character -> characterSpriteJump[inv], transformaCameraX(camera, getCharacterX(character)), character -> y, character -> w, character -> h);
    }
    else if (character -> isDown == true) {
        Pantalla_DibujaImagen(character -> characterSpriteDown[inv], transformaCameraX(camera, getCharacterX(character)), character -> y, character -> w, character -> h);
    }
    else if (character -> isRunning == true) {
        Pantalla_DibujaImagen(character -> characterSpriteRun[frame], transformaCameraX(camera, getCharacterX(character)), character -> y, character -> w, character -> h);
        updateCharacterFrame(character);
    }
    else if (character -> isWalking == true) {
        Pantalla_DibujaImagen(character -> characterSpriteWalk[frame], transformaCameraX(camera, getCharacterX(character)), character -> y, character -> w, character -> h);
        updateCharacterFrame(character);
    }
    else {
        Pantalla_DibujaImagen(character -> characterSprite[inv], transformaCameraX(camera, getCharacterX(character)), character -> y, character -> w, character -> h);
    }
}
/*
 * Update character on keypress.
 */
void updateCharacterKeyPress(Character character){
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE)){
        if (isCharacterJumping(character) == false) {
            setCharacterSpeed(character, -20);
            setCharacterJumping(character, true);
        }
    }
        
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)) {
        setCharacterDown(character, true);
    }
    else {
        setCharacterDown(character, false);
    }

    if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT) && !isCharacterStable(character)){
        if (isCharacterDown(character) == false) {
            incCharacterX(character, 6);
            setCharacterInv(character, false);
            setCharacterWalking(character, true);
        }
        if (isCharacterInv(character) == false && Pantalla_TeclaPulsada(SDL_SCANCODE_Z)){
            incCharacterX(character, 3);
            setCharacterRunning(character, true);
        }
        else {
            setCharacterRunning(character, false);
        }
    }
    else if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT) && !isCharacterStable(character)){
        if (isCharacterDown(character) == false) {
            decCharacterX(character, 6);
            setCharacterInv(character, true);
            setCharacterWalking(character, true);
        }
        if (isCharacterInv(character) == true && Pantalla_TeclaPulsada(SDL_SCANCODE_Z)){
            decCharacterX(character, 3);
            setCharacterRunning(character, true);
        }
        else {
            setCharacterRunning(character, false);
        }
    }
    else {
        setCharacterWalking(character, false);
        setCharacterRunning(character, false);
    }
    setCharacterY(character, getCharacterY(character) + getCharacterSpeed(character));
    incCharacterSpeed(character, 2);
}
// Collides Objects
bool isCollidingWithObjectC(Character character, Object obj) {
    if (getCharacterY(character)+getCharacterH(character) > getObjectY(obj)
            && getCharacterY(character) < getObjectY(obj)+getObjectH(obj)
            && getCharacterX(character) < getObjectX(obj)+getObjectW(obj)
            && getCharacterX(character)+getCharacterW(character) > getObjectX(obj)
            && isCollidingWithObjectCWidth(character, obj)
            && isCollidingWithObjectCHeight(character, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectCTop(Character character, Object obj) {
    if (getCharacterY(character)+getCharacterH(character) > getObjectY(obj) 
            && isCollidingWithObjectCWidth(character, obj)
            && isCollidingWithObjectCHeight(character, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectCDown(Character character, Object obj) {
    if (getCharacterY(character) < getObjectY(obj)+getObjectH(obj) 
            && isCollidingWithObjectCWidth(character, obj)
            && isCollidingWithObjectCHeight(character, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectCRight(Character character, Object obj) {
    if (getCharacterX(character) < getObjectX(obj)+getObjectW(obj)
            && isCollidingWithObjectCWidth(character, obj)
            && isCollidingWithObjectCHeight(character, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectCLeft(Character character, Object obj) {
    if (getCharacterX(character)+getCharacterW(character) > getObjectX(obj)
            && isCollidingWithObjectCWidth(character, obj)
            && isCollidingWithObjectCHeight(character, obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectCWidth(Character character, Object obj) {
    if (getCharacterX(character)+getCharacterW(character) > getObjectX(obj) 
            && getCharacterX(character) < getObjectX(obj)+getObjectW(obj)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithObjectCHeight(Character character, Object obj) {
    if (getCharacterY(character)+getCharacterH(character) > getObjectY(obj) 
            && getCharacterY(character) < getObjectY(obj)+getObjectH(obj)
            ) {
        return true;
    }
    return false;
}
// Collides Enemys
bool isCollidingWithEnemy(Character character, Enemy emy) {
    if (getCharacterY(character)+getCharacterH(character) > getEnemyY(emy)
            && getCharacterY(character) < getEnemyY(emy)+getEnemyH(emy)
            && getCharacterX(character) < getEnemyX(emy)+getEnemyW(emy)
            && getCharacterX(character)+getCharacterW(character) > getEnemyX(emy)
            && isCollidingWithEnemyWidth(character, emy)
            && isCollidingWithEnemyHeight(character, emy)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithEnemyTop(Character character, Enemy emy) {
    if (getCharacterY(character)+getCharacterH(character) > getEnemyY(emy) 
            && isCollidingWithEnemyWidth(character, emy)
            && isCollidingWithEnemyHeight(character, emy)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithEnemyDown(Character character, Enemy emy) {
    if (getCharacterY(character) < getEnemyY(emy)+getEnemyH(emy) 
            && isCollidingWithEnemyWidth(character, emy)
            && isCollidingWithEnemyHeight(character, emy)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithEnemyRight(Character character, Enemy emy) {
    if (getCharacterX(character) < getEnemyX(emy)+getEnemyW(emy)
            && isCollidingWithEnemyWidth(character, emy)
            && isCollidingWithEnemyHeight(character, emy)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithEnemyLeft(Character character, Enemy emy) {
    if (getCharacterX(character)+getCharacterW(character) > getEnemyX(emy)
            && isCollidingWithEnemyWidth(character, emy)
            && isCollidingWithEnemyHeight(character, emy)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithEnemyWidth(Character character, Enemy emy) {
    if (getCharacterX(character)+getCharacterW(character) > getEnemyX(emy) 
            && getCharacterX(character) < getEnemyX(emy)+getEnemyW(emy)
            ) {
        return true;
    }
    return false;
}
bool isCollidingWithEnemyHeight(Character character, Enemy emy) {
    if (getCharacterY(character)+getCharacterH(character) > getEnemyY(emy) 
            && getCharacterY(character) < getEnemyY(emy)+getEnemyH(emy)
            ) {
        return true;
    }
    return false;
}
/*
 * Update character collide with objects.
 */
void updateCharacterCollideWithObjects(Character character, NodePtrObject objPtr, int x, int y, Score sco){
    NodePtrObject copyObjectsList;
    NodePtrObject preObjectPtr;
    if (y > getCharacterY(character)) {
        copyObjectsList = getNextNodePtrObject(objPtr);
        preObjectPtr = objPtr;
        while (copyObjectsList != NULL && !isCollidingWithObjectCDown(character, getElementNodePtrObject(copyObjectsList))) {
            copyObjectsList = getNextNodePtrObject(copyObjectsList);
            preObjectPtr = getNextNodePtrObject(preObjectPtr);
        }
        if (copyObjectsList != NULL) {
            if (getObjectInteractive(getElementNodePtrObject(copyObjectsList))) {
                if (getObjectScoreable(getElementNodePtrObject(copyObjectsList))){
                    removeNextElementNodePtrObject(preObjectPtr);
                    updateScoreInt(sco, 200);
                }
                else {
                    setCharacterY(character, getObjectY(getElementNodePtrObject(copyObjectsList)) + getObjectH(getElementNodePtrObject(copyObjectsList)));
                    setCharacterSpeed(character, 0);
                }
            }
        }
    }
    else if (y < getCharacterY(character)) {
        copyObjectsList = getNextNodePtrObject(objPtr);
        preObjectPtr = objPtr;
        while (copyObjectsList != NULL && !isCollidingWithObjectCTop(character, getElementNodePtrObject(copyObjectsList))) {
            copyObjectsList = getNextNodePtrObject(copyObjectsList);
            preObjectPtr = getNextNodePtrObject(preObjectPtr);
        }
        if (copyObjectsList != NULL) {
            if (getObjectInteractive(getElementNodePtrObject(copyObjectsList))) {
                if (getObjectScoreable(getElementNodePtrObject(copyObjectsList))){
                    removeNextElementNodePtrObject(preObjectPtr);
                    updateScoreInt(sco, 200);
                }
                else {
                    setCharacterY(character, getObjectY(getElementNodePtrObject(copyObjectsList)) - getCharacterH(character));
                    setCharacterJumping(character, false);
                    setCharacterSpeed(character, 0);
                    setCharacterStable(character, false);
                }
            }
        }
    }
    if (x < getCharacterX(character)) {
        copyObjectsList = getNextNodePtrObject(objPtr);
        preObjectPtr = objPtr;
        while (copyObjectsList != NULL && !isCollidingWithObjectCLeft(character, getElementNodePtrObject(copyObjectsList))) {
            copyObjectsList = getNextNodePtrObject(copyObjectsList);
            preObjectPtr = getNextNodePtrObject(preObjectPtr);
        }
        if (copyObjectsList != NULL) {
            if (getObjectInteractive(getElementNodePtrObject(copyObjectsList))) {
                if (getObjectScoreable(getElementNodePtrObject(copyObjectsList))){
                    removeNextElementNodePtrObject(preObjectPtr);
                    updateScoreInt(sco, 200);
                }
                else {
                    setCharacterX(character, getObjectX(getElementNodePtrObject(copyObjectsList)) - getCharacterW(character));
                    setCharacterStable(character, true);
                }
            }
        }
    }
    else if (x > getCharacterX(character)) {
        copyObjectsList = getNextNodePtrObject(objPtr);
        preObjectPtr = objPtr;
        while (copyObjectsList != NULL && !isCollidingWithObjectCRight(character, getElementNodePtrObject(copyObjectsList))) {
            copyObjectsList = getNextNodePtrObject(copyObjectsList);
            preObjectPtr = getNextNodePtrObject(preObjectPtr);
        }
        if (copyObjectsList != NULL) {
            if (getObjectInteractive(getElementNodePtrObject(copyObjectsList))) {
                if (getObjectScoreable(getElementNodePtrObject(copyObjectsList))){
                    removeNextElementNodePtrObject(preObjectPtr);
                    updateScoreInt(sco, 200);
                }
                else {
                    setCharacterX(character, getObjectX(getElementNodePtrObject(copyObjectsList)) + getObjectW(getElementNodePtrObject(copyObjectsList)));
                    setCharacterStable(character, true);
                }
            }
        }
    }
}
/*
 * Update character collide with enemys.
 */
bool isCharacterCollideWithEnemy(Character character, NodePtrEnemy emyPtr, int y, Score sco){
    NodePtrEnemy copyEnemyList;
    NodePtrEnemy preEnemyPtr;
    
    copyEnemyList = getNextNodePtrEnemy(emyPtr);
    preEnemyPtr = emyPtr;
    while (copyEnemyList != NULL && !isCollidingWithEnemy(character, getElementNodePtrEnemy(copyEnemyList))) {
        copyEnemyList = getNextNodePtrEnemy(copyEnemyList);
        preEnemyPtr = getNextNodePtrEnemy(preEnemyPtr);
    }
    if (copyEnemyList != NULL) {
        if (y < getCharacterY(character)) {
            if (isCollidingWithEnemyTop(character, getElementNodePtrEnemy(copyEnemyList))) {
                removeNextElementNodePtrEnemy(preEnemyPtr);
                updateScoreInt(sco, 200);
            }
        }
        else {
            return true;
        }
    }
    
    return false;
}