#ifndef ENEMY_H
#define ENEMY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pantalla.h"
#include "Camera.h"
#include "Object.h"
#include "NodeObject.h"

/**
\mainpage La biblioteca Enemy define a un enemigo.
*/
/**
   \file Character.h
   \brief define a un enemigo.
*/
/**
    \brief TDA Enemy
 */
typedef struct EnemyRep *Enemy;
/**
  \brief Crea un nuevo enemigo.
  \param x coordenada x de spawn.
  \param y coordenada y de spawn.
  \param w ancho del enemigo.
  \param h alto del enemigo.
  \param moveZoneX numero de unidades que se desplazara el enemigo.
  \param isStatic si es estatico.
  \param isFly si es volador.
  \param sprite del enemigo.
  \return un nuevo enemigo.
 */
Enemy newEnemy(int x, int y, int w, int h, int moveZoneX, bool isStatic, bool isFly, Imagen sprite);
/**
  \brief Libera los recursos del enemigo.
  \param emy objetivo.
 */
void freeEnemyResources(Enemy emy);
/**
  \brief obtiene la coordenada X del enemigo.
  \param emy objetivo.
  \return el valor de X.
 */
int getEnemyX(Enemy emy);
/**
  \brief obtiene la coordenada Y del enemigo.
  \param emy objetivo.
  \return el valor de Y.
 */
int getEnemyY(Enemy emy);
/**
  \brief obtiene la coordenada W del enemigo.
  \param emy objetivo.
  \return el valor de W.
 */
int getEnemyW(Enemy emy);
/**
  \brief obtiene la coordenada H del enemigo.
  \param emy objetivo.
  \return el valor de H.
 */
int getEnemyH(Enemy emy);
/**
  \brief obtiene la coordenada speed del enemigo.
  \param emy objetivo.
  \return el valor de speed.
 */
int getEnemySpeed(Enemy emy);
/**
  \brief obtiene la coordenada PrevX del enemigo.
  \param emy objetivo.
  \return el valor de PrevX.
 */
int getEnemyPrevX(Enemy emy);
/**
  \brief obtiene la coordenada PrevY del enemigo.
  \param emy objetivo.
  \return el valor de PrevY.
 */
int getEnemyPrevY(Enemy emy);
/**
  \brief obtiene la coordenada StartX del enemigo.
  \param emy objetivo.
  \return el valor de StartX.
 */
int getEnemyStartX(Enemy emy);
/**
  \brief obtiene la coordenada StartY del enemigo.
  \param emy objetivo.
  \return el valor de StartY.
 */
int getEnemyStartY(Enemy emy);
/**
  \brief obtiene la coordenada MoveZoneX del enemigo.
  \param emy objetivo.
  \return el valor de MoveZoneX.
 */
int getEnemyMoveZoneX(Enemy emy);
/**
  \brief obtiene si el enemigo es estatico.
  \param emy objetivo.
  \return true si es estatico.
 */
bool isEnemyStatic(Enemy emy);
/**
  \brief obtiene si el enemigo es volador.
  \param emy objetivo.
  \return true si es volador.
 */
bool isEnemyFly(Enemy emy);
/**
  \brief obtiene si el enemigo esta mirado a la derecha o a la izquierda.
  \param emy objetivo.
  \return true si mira a la izquierda.
 */
bool isEnemyRev(Enemy emy);
/**
  \brief cambia el valor X del enemigo.
  \param emy objetivo.
  \param value nuevo valor.
 */
void setEnemyX(Enemy emy, int value);
/**
  \brief cambia el valor Y del enemigo.
  \param emy objetivo.
  \param value nuevo valor.
 */
void setEnemyY(Enemy emy, int value);
/**
  \brief cambia el valor Speed del enemigo.
  \param emy objetivo.
  \param value nuevo valor.
 */
void setEnemySpeed(Enemy emy, int value);
/**
  \brief cambia el valor PrevX del enemigo.
  \param emy objetivo.
  \param value nuevo valor.
 */
void setEnemyPrevX(Enemy emy, int value);
/**
  \brief cambia el valor PrevY del enemigo.
  \param emy objetivo.
  \param value nuevo valor.
 */
void setEnemyPrevY(Enemy emy, int value);
/**
  \brief cambia el valor Static del enemigo.
  \param emy objetivo.
  \param value nuevo valor.
 */
void setEnemyStatic(Enemy emy, bool value);
/**
  \brief cambia el valor Fly del enemigo.
  \param emy objetivo.
  \param value nuevo valor.
 */
void setEnemyFly(Enemy emy, bool value);
/**
  \brief cambia el valor Rev del enemigo.
  \param emy objetivo.
  \param value nuevo valor.
 */
void setEnemyRev(Enemy emy, bool value);
/**
  \brief incrementa el valor X del enemigo.
  \param emy objetivo.
  \param value nuevo valor.
 */
void incEnemyX(Enemy emy, int inc);
/**
  \brief incrementa el valor Y del enemigo.
  \param emy objetivo.
  \param value nuevo valor.
 */
void incEnemyY(Enemy emy, int inc);
/**
  \brief incrementa el valor Speed del enemigo.
  \param emy objetivo.
  \param value nuevo valor.
 */
void incEnemySpeed(Enemy emy, int inc);
/**
  \brief decrementa el valor X del enemigo.
  \param emy objetivo.
  \param value nuevo valor.
 */
void decEnemyX(Enemy emy, int dec);
/**
  \brief decrementa el valor Y del enemigo.
  \param emy objetivo.
  \param value nuevo valor.
 */
void decEnemyY(Enemy emy, int dec);
/**
  \brief decrementa el valor Speed del enemigo.
  \param emy objetivo.
  \param value nuevo valor.
 */
void decEnemySpeed(Enemy emy, int dec);
/**
  \brief actualiza la posicion del enemigo.
  \param emy objetivo.
 */
void updateEnemy(Enemy emy);
/**
  \brief comprueba si un enemigo choca con un objeto.
  \param emy objetivo.
  \param obj objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithObjectE(Enemy emy, Object obj);
/**
  \brief comprueba si un enemigo choca con un objeto por arriba.
  \param emy objetivo.
  \param obj objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithObjectETop(Enemy emy, Object obj);
/**
  \brief comprueba si un enemigo choca con un objeto por abajo.
  \param emy objetivo.
  \param obj objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithObjectEDown(Enemy emy, Object obj);
/**
  \brief comprueba si un enemigo choca con un objeto por derecha.
  \param emy objetivo.
  \param obj objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithObjectERight(Enemy emy, Object obj);
/**
  \brief comprueba si un enemigo choca con un objeto por izquierda.
  \param emy objetivo.
  \param obj objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithObjectELeft(Enemy emy, Object obj);
/**
  \brief comprueba si un enemigo choca con un objeto por ancho.
  \param emy objetivo.
  \param obj objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithObjectEWidth(Enemy emy, Object obj);
/**
  \brief comprueba si un enemigo choca con un objeto por alto.
  \param emy objetivo.
  \param obj objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithObjectEHeight(Enemy emy, Object obj);
/**
  \brief actualiza la posicion de un enemigo si choca con un objeto.
  \param emy objetivo.
  \param objPtr lista de objetos.
 */
void updateEnemyCollideWithObjects(Enemy emy, NodePtrObject objPtr);
/**
  \brief dibuja al enemigo.
  \param emy objetivo.
  \param camera objetivo.
 */
void drawEnemy(Enemy emy, Camera camera);

#endif

