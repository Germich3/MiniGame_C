//Include zone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Timer.h"
#include "Pantalla.h"
#include "Character.h"
#include "Camera.h"
#include "Object.h"
#include "Enemy.h"
#include "NodeObject.h"
#include "NodeEnemy.h"
#include "GameOver.h"
#include "Score.h"
#include "Shoot.h"
#include "ArrayList.h"

//Macros zone
#define length(x) (sizeof(x)/sizeof((x)[0]))
#define AREA 3160

/*
 * Level 1
 */
void playLevel1() {
    // Var zone
    // End play
    bool isPlaying = true;
    bool isKeyPressing = false;

    //Camera def.
    Camera camera = newCamera(AREA, 580);
    //Fin Camera

    // Player def.
    Imagen playerSprite[] = {Pantalla_ImagenLee("assets/chs/player.bmp", 1),
                             Pantalla_ImagenLee("assets/chs/playerinv.bmp", 1)};

    Imagen playerSpriteWalk[] = {Pantalla_ImagenLee("assets/chs/player.bmp", 1),
                                 Pantalla_ImagenLee("assets/chs/playerwalk.bmp", 1),
                                 Pantalla_ImagenLee("assets/chs/playerinv.bmp", 1),
                                 Pantalla_ImagenLee("assets/chs/playerwalkinv.bmp", 1)};

    Imagen playerSpriteRun[] = {Pantalla_ImagenLee("assets/chs/player.bmp", 1),
                                 Pantalla_ImagenLee("assets/chs/playerrun.bmp", 1),
                                 Pantalla_ImagenLee("assets/chs/playerinv.bmp", 1),
                                 Pantalla_ImagenLee("assets/chs/playerruninv.bmp", 1)};

    Imagen playerSpriteJump[] = {Pantalla_ImagenLee("assets/chs/playerjump.bmp", 1),
                                 Pantalla_ImagenLee("assets/chs/playerjumpinv.bmp", 1)};

    Imagen playerSpriteDown[] = {Pantalla_ImagenLee("assets/chs/playerdown.bmp", 1),
                                 Pantalla_ImagenLee("assets/chs/playerdowninv.bmp", 1)};

    Character player = newCharacter(playerSprite, playerSpriteWalk, playerSpriteRun, playerSpriteJump, playerSpriteDown);
    // Fin Player def.

    //Ground
    Imagen groundSprite = Pantalla_ImagenLee("assets/bg/floor.bmp", 0);
    Object ground_0 = newObject(0, 439, 600, 41, true, false, groundSprite);
    Object ground_1 = newObject(800, 439, 300, 41, true, false, groundSprite);
    Object ground_2 = newObject(1300, 439, 300, 41, true, false, groundSprite);
    Object ground_3 = newObject(1800, 439, 600, 41, true, false, groundSprite);
    Object ground_4 = newObject(2600, 439, 20, 41, true, false, groundSprite);
    Object ground_5 = newObject(2820, 439, 20, 41, true, false, groundSprite);
    Object ground_6 = newObject(3040, 439, 220, 41, true, false, groundSprite);

    //Objects
    Imagen plantSprite = Pantalla_ImagenLee("assets/bg/plants.bmp", 1);
    Object plant = newObject(0, 289, 300, 150, false, false, plantSprite);
    //Collectible
    Imagen coinSprite = Pantalla_ImagenLee("assets/obj/coin_1.bmp", 1);
    Object coin_0 = newObject(600, 380, 25, 25, true, true, coinSprite);
    Object coin_1 = newObject(630, 360, 25, 25, true, true, coinSprite);
    Object coin_2 = newObject(660, 340, 25, 25, true, true, coinSprite);
    Object coin_3 = newObject(690, 330, 25, 25, true, true, coinSprite);
    Object coin_4 = newObject(720, 340, 25, 25, true, true, coinSprite);
    Object coin_5 = newObject(750, 360, 25, 25, true, true, coinSprite);
    Object coin_6 = newObject(780, 380, 25, 25, true, true, coinSprite);
    //Objects list
    NodePtrObject objectsList = newNodePtrObject();
    addLastElementNodePtrObject(objectsList, ground_0);
    addLastElementNodePtrObject(objectsList, ground_1);
    addLastElementNodePtrObject(objectsList, ground_2);
    addLastElementNodePtrObject(objectsList, ground_3);
    addLastElementNodePtrObject(objectsList, ground_4);
    addLastElementNodePtrObject(objectsList, ground_5);
    addLastElementNodePtrObject(objectsList, ground_6);
    addLastElementNodePtrObject(objectsList, plant);
    addLastElementNodePtrObject(objectsList, coin_0);
    addLastElementNodePtrObject(objectsList, coin_1);
    addLastElementNodePtrObject(objectsList, coin_2);
    addLastElementNodePtrObject(objectsList, coin_3);
    addLastElementNodePtrObject(objectsList, coin_4);
    addLastElementNodePtrObject(objectsList, coin_5);
    addLastElementNodePtrObject(objectsList, coin_6);

    //Enemys
    Imagen goombaSprite = Pantalla_ImagenLee("assets/emy/goomba.bmp", 1);
    Enemy goomba_0 = newEnemy(250, 399, 40, 40, 300, false, false, goombaSprite);
    Enemy goomba_1 = newEnemy(300, 399, 40, 40, 250, false, false, goombaSprite);
    Enemy goomba_2 = newEnemy(350, 399, 40, 40, 200, false, false, goombaSprite);
    Imagen kappaSprite = Pantalla_ImagenLee("assets/emy/kappa.bmp", 1);
    Enemy kappa_0 = newEnemy(1100, 350, 40, 55, 150, false, true, kappaSprite);
    //Enemy list
    NodePtrEnemy enemyList = newNodePtrEnemy();
    addLastElementNodePtrEnemy(enemyList, goomba_0);
    addLastElementNodePtrEnemy(enemyList, goomba_1);
    addLastElementNodePtrEnemy(enemyList, goomba_2);
    addLastElementNodePtrEnemy(enemyList, kappa_0);

    //Shoots
    Imagen shootSprite = Pantalla_ImagenLee("assets/chs/shoot.bmp", 1);
    Shoot shoot = NULL;
    //NodePtrShoot shtList = newNodePtrShoot();
    ArrayList shtList = newArrayList();

    // Timer def.
    Timer timer = newTimer(400);
    char currentTime[4];
    Imagen timerSprite = Pantalla_ImagenLee("assets/bg/timer.bmp", 1);
    // fin def.

    //Score def.
    Score score = newScore("assets/sco/score.sco");
    char scoreNum[10];
    Imagen scoreSprite = Pantalla_ImagenLee("assets/bg/score.bmp", 1);
    //fin def.

    Imagen background = Pantalla_ImagenLee("assets/bg/bg.bmp", 0);
    Pantalla_ColorTrazo(0, 0, 0, 255); //Negro
    Pantalla_ColorRelleno(255, 255, 255, 255); //Blanco

    while (Pantalla_Activa() && isPlaying){
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)) {
            isPlaying = false;
        }

        int playerX = getCharacterX(player);
        int playerY = getCharacterY(player);

        // Update player on keypress
        updateCharacterKeyPress(player);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_X)){
            if (!isKeyPressing) {
                shoot = newShoot(getCharacterX(player), getCharacterY(player), 10, 10, 500, isCharacterInv(player), shootSprite);
                addArrayListElement(shtList, lastIndexArrayList(shtList), shoot);
            }
            isKeyPressing = true;
        }
        else {
            isKeyPressing = false;
        }
        // fin upadate

        // Update enemys
        updateEnemyList(enemyList);
        // fin upadate

        //update shoot
        updateShootArrayList(shtList);
        //fin update

        // find collides
        updateEnemyListCollideWithObjects(enemyList, objectsList);
        updateCharacterCollideWithObjects(player, objectsList, playerX, playerY, score);
        if (isCharacterCollideWithEnemy(player, enemyList, playerY, score)) {
            gameOver();
            isPlaying = false;
        }
        updateShootArrayListCollideWithObjects(shtList, objectsList);
        updateShootArrayListCollideWithEnemys(shtList, enemyList, score);
        // fin

        if (getTimerCurrentSecInt(timer) <= 0) {
            gameOver();
            isPlaying = false;
        }
        if (getCharacterY(player) > 500) {
            gameOver();
            isPlaying = false;
        }
        if (getCharacterX(player) >= AREA-20) {
            youWin();
            isPlaying = false;
        }
        if (getCharacterX(player) < 20) {
            setCharacterX(player, 20);
        }
        if (getCharacterX(player) > AREA-20) {
            setCharacterX(player, AREA-20);
        }

        //Zona de dibujado
        Pantalla_DibujaImagen(background, 0, 0, 640, 480);
        //Dibuajr las listas
        drawObjectList(objectsList, camera);
        drawEnemyList(enemyList, camera);
        drawShootArrayList(shtList, camera);
        //Fin de recorrer

        //timer
        getTimerCurrentSecChar(timer, currentTime);
        Pantalla_DibujaTexto(currentTime, 600, 30);
        Pantalla_DibujaImagen(timerSprite, 540, 0, 100, 50);

        //Score
        getScoreChar(score, scoreNum);
        Pantalla_DibujaTexto(scoreNum, 20, 31);
        Pantalla_DibujaImagen(scoreSprite, 0, 0, 100, 50);

        // Control de player
        updateCameraX(camera, getCharacterX(player));
        updateCharacterSprite(player, camera);
        // Fin de control

        // Actualizar
        Pantalla_Actualiza();
        Pantalla_Espera(40);
        // Fin Actualizar
    }

    // Libera
    freeObjectResources(ground_0);
    freeObjectResources(ground_1);
    freeObjectResources(ground_2);
    freeObjectResources(ground_3);
    freeObjectResources(ground_4);
    freeObjectResources(ground_5);
    freeObjectResources(ground_6);
    freeObjectResources(plant);
    freeObjectResources(coin_0);
    freeObjectResources(coin_1);
    freeObjectResources(coin_2);
    freeObjectResources(coin_3);
    freeObjectResources(coin_4);
    freeObjectResources(coin_5);
    freeObjectResources(coin_6);
    freeNodePtrObject(objectsList);
    freeEnemyResources(goomba_0);
    freeEnemyResources(goomba_1);
    freeEnemyResources(goomba_2);
    freeEnemyResources(kappa_0);
    freeNodePtrEnemy(enemyList);
    freeArrayList(shtList);
    freeScore(score);
    freeCharacterResources(player);
    freeCameraResources(camera);
    freeTimerResources(timer);
    Pantalla_ImagenLibera(timerSprite);
    Pantalla_ImagenLibera(scoreSprite);
    Pantalla_ImagenLibera(background);
}

