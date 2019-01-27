#ifndef SHOOT_H
#define SHOOT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pantalla.h"
#include "Camera.h"
#include "Object.h"
#include "NodeObject.h"
#include "Enemy.h"
#include "NodeEnemy.h"
#include "Score.h"

/**
\mainpage La biblioteca Shoot define un disparo.
*/
/**
   \file Shoot.h
   \brief define un disparo.
*/
/**
    \brief TDA Shoot
 */
typedef struct ShootRep *Shoot;
/**
  \brief Crea un nuevo disparo.
  \param x coordenada x de spawn.
  \param y coordenada y de spawn.
  \param w ancho del disparo.
  \param h alto del disparo.
  \param travel numero de unidades que se desplazara el disparo.
  \param isRev direccion del disparo.
  \param shootSprite del disparo.
  \return un nuevo disparo.
 */
Shoot newShoot(int x, int y, int w, int h, int travel, bool isRev, Imagen shootSprite);
/**
  \brief Libera los recursos del disparo.
  \param sht objetivo.
 */
void freeShoot(Shoot sht);
/**
  \brief obtiene la coordenada X del disparo.
  \param sht objetivo.
  \return el valor de X.
 */
int getShootX(Shoot sht);
/**
  \brief obtiene la coordenada Y del disparo.
  \param sht objetivo.
  \return el valor de Y.
 */
int getShootY(Shoot sht);
/**
  \brief obtiene la coordenada W del disparo.
  \param sht objetivo.
  \return el valor de W.
 */
int getShootW(Shoot sht);
/**
  \brief obtiene la coordenada H del disparo.
  \param sht objetivo.
  \return el valor de H.
 */
int getShootH(Shoot sht);
/**
  \brief obtiene la coordenada StartX del disparo.
  \param sht objetivo.
  \return el valor de StartX.
 */
int getShootStartX(Shoot sht);
/**
  \brief obtiene la coordenada PrevY del disparo.
  \param sht objetivo.
  \return el valor de PrevY.
 */
int getShootPrevY(Shoot sht);
/**
  \brief obtiene la coordenada Speed del disparo.
  \param sht objetivo.
  \return el valor de Speed.
 */
int getShootSpeed(Shoot sht);
/**
  \brief obtiene la coordenada Travel del disparo.
  \param sht objetivo.
  \return el valor de Travel.
 */
int getShootTravel(Shoot sht);
/**
  \brief obtiene la direccion.
  \param sht objetivo.
  \return true si es hacia la izquierda.
 */
bool isShootRev(Shoot sht);
/**
  \brief actualiza la posicion del disparo.
  \param sht objetivo.
 */
void updateShoot(Shoot sht);
/**
  \brief dibuja un disparo.
  \param sht objetivo.
  \param camera objetivo.
 */
void drawShoot(Shoot sht, Camera camera);
/**
  \brief cambia el valor de X.
  \param sht objetivo.
  \param value nuevo valor.
 */
void setShootX(Shoot sht, int value);
/**
  \brief cambia el valor de Y.
  \param sht objetivo.
  \param value nuevo valor.
 */
void setShootY(Shoot sht, int value);
/**
  \brief cambia el valor de Speed.
  \param sht objetivo.
  \param value nuevo valor.
 */
void setShootSpeed(Shoot sht, int value);
/**
  \brief cambia el valor de Rev.
  \param sht objetivo.
  \param value nuevo valor.
 */
void setShootRev(Shoot sht, bool value);
/**
  \brief cambia el valor de PrevY.
  \param sht objetivo.
  \param value nuevo valor.
 */
void setShootPrevY(Shoot sht, int value);
/**
  \brief incrementa el valor de Speed.
  \param sht objetivo.
  \param value valor.
 */
void incShootSpeed(Shoot sht, int inc);
/**
  \brief incrementa el valor de X.
  \param sht objetivo.
  \param value valor.
 */
void incShootX(Shoot sht, int inc);
/**
  \brief decrementa el valor de X.
  \param sht objetivo.
  \param value valor.
 */
void decShootX(Shoot sht, int dec);
/**
  \brief comprueba si un disparo esta colisionando con un objeto.
  \param sht objetivo.
  \param obj objetivo.
  \return si ha colisionado.
 */
bool isCollidingWithObjectS(Shoot sht, Object obj);
/**
  \brief comprueba si un disparo esta colisionando con un objeto por abajo.
  \param sht objetivo.
  \param obj objetivo.
  \return si ha colisionado.
 */
bool isCollidingWithObjectSDown(Shoot sht, Object obj);
/**
  \brief comprueba si un disparo esta colisionando con un objeto por arriba.
  \param sht objetivo.
  \param obj objetivo.
  \return si ha colisionado.
 */
bool isCollidingWithObjectSTop(Shoot sht, Object obj);
/**
  \brief comprueba si un disparo esta colisionando con un objeto por la derecha.
  \param sht objetivo.
  \param obj objetivo.
  \return si ha colisionado.
 */
bool isCollidingWithObjectSRight(Shoot sht, Object obj);
/**
  \brief comprueba si un disparo esta colisionando con un objeto por la izquierda.
  \param sht objetivo.
  \param obj objetivo.
  \return si ha colisionado.
 */
bool isCollidingWithObjectSLeft(Shoot sht, Object obj);
/**
  \brief comprueba si un disparo esta colisionando con un objeto en su ancho.
  \param sht objetivo.
  \param obj objetivo.
  \return si ha colisionado.
 */
bool isCollidingWithObjectSWidth(Shoot sht, Object obj);
/**
  \brief comprueba si un disparo esta colisionando con un objeto en su alto.
  \param sht objetivo.
  \param obj objetivo.
  \return si ha colisionado.
 */
bool isCollidingWithObjectSHeight(Shoot sht, Object obj);
/**
  \brief actualiza un disparo si colisiona con un objeto.
  \param sht objetivo.
  \param objPtr lista de objetos.
 */
void updateShootCollideWithObject(Shoot sht, NodePtrObject objPtr);
/**
  \brief comprueba si un disparo esta colisionando con un enemigo.
  \param sht objetivo.
  \param obj objetivo.
  \return si ha colisionado.
 */
bool isCollidingWithEnemyS(Shoot sht, Enemy emy);
/**
  \brief comprueba si un disparo esta colisionando con un enemigo por abajo.
  \param sht objetivo.
  \param emy objetivo.
  \return si ha colisionado.
 */
bool isCollidingWithEnemySDown(Shoot sht, Enemy emy);
/**
  \brief comprueba si un disparo esta colisionando con un enemigo por arriba.
  \param sht objetivo.
  \param emy objetivo.
  \return si ha colisionado.
 */
bool isCollidingWithEnemySTop(Shoot sht, Enemy emy);
/**
  \brief comprueba si un disparo esta colisionando con un enemigo por la derecha.
  \param sht objetivo.
  \param emy objetivo.
  \return si ha colisionado.
 */
bool isCollidingWithEnemySRight(Shoot sht, Enemy emy);
/**
  \brief comprueba si un disparo esta colisionando con un enemigo por la izquierda.
  \param sht objetivo.
  \param emy objetivo.
  \return si ha colisionado.
 */
bool isCollidingWithEnemySLeft(Shoot sht, Enemy emy);
/**
  \brief comprueba si un disparo esta colisionando con un enemigo por su ancho.
  \param sht objetivo.
  \param emy objetivo.
  \return si ha colisionado.
 */
bool isCollidingWithEnemySWidth(Shoot sht, Enemy emy);
/**
  \brief comprueba si un disparo esta colisionando con un enemigo por su alto.
  \param sht objetivo.
  \param emy objetivo.
  \return si ha colisionado.
 */
bool isCollidingWithEnemySHeight(Shoot sht, Enemy emy);
/**
  \brief actualiza un disparo si colisiona con un enemigo.
  \param sht objetivo.
  \param emyPtr lista de objetos.
  \param sco para actualizar la puntuacion.
 */
void updateShootCollideWithEnemy(Shoot sht, NodePtrEnemy emyPtr, Score sco);

#endif /* SHOOT_H */

