#ifndef CHARACTER_H
#define CHARACTER_H

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
\mainpage La biblioteca Character define a un personaje principal jugable.
*/
/**
   \file Character.h
   \brief define a un personaje principal jugable.
*/
/**
    \brief TDA Character
 */
typedef struct CharacterRep *Character;
/**
  \brief Crea un nuevo personaje.
  \param playerSprite sprite base del personaje en sentido izquierdo y derecho
  \param playerSpriteWalk sprite andando del personaje en sentido izquierdo y derecho
  \param playerSpriteRun sprite corriendo del personaje en sentido izquierdo y derecho
  \param playerSpriteJump sprite saltando del personaje en sentido izquierdo y derecho
  \param playerSpriteDown sprite agachado del personaje en sentido izquierdo y derecho
  \return un nuevo personaje.
 */
Character newCharacter(Imagen playerSprite[2], Imagen playerSpriteWalk[4], Imagen playerSpriteRun[4], Imagen playerSpriteJump[2], Imagen playerSpriteDown[2]);
/**
  \brief Libera los recursos del personaje.
  \param character objetivo.
 */
void freeCharacterResources(Character character);
/**
  \brief obtiene la coordenada X del personaje.
  \param character objetivo.
  \return el valor de X.
 */
int getCharacterX(Character character);
/**
  \brief obtiene la coordenada Y del personaje.
  \param character objetivo.
  \return el valor de Y.
 */
int getCharacterY(Character character);
/**
  \brief obtiene la coordenada W del personaje.
  \param character objetivo.
  \return el valor de W.
 */
int getCharacterW(Character character);
/**
  \brief obtiene la coordenada H del personaje.
  \param character objetivo.
  \return el valor de H.
 */
int getCharacterH(Character character);
/**
  \brief obtiene la coordenada Speed del personaje.
  \param character objetivo.
  \return el valor de Speed.
 */
int getCharacterSpeed(Character character);
/**
  \brief obtiene si el porsonaje esta mirando a la izquierda o a la derecha.
  \param character objetivo.
  \return true si mira a la izquierda.
 */
bool isCharacterInv(Character character);
/**
  \brief obtiene si el porsonaje esta saltando.
  \param character objetivo.
  \return true si esta saltando.
 */
bool isCharacterJumping(Character character);
/**
  \brief obtiene si el porsonaje esta caminando.
  \param character objetivo.
  \return true si esta caminando.
 */
bool isCharacterWalking(Character character);
/**
  \brief obtiene si el porsonaje esta corriendo.
  \param character objetivo.
  \return true si esta corriendo.
 */
bool isCharacterRunning(Character character);
/**
  \brief obtiene si el porsonaje esta agachado.
  \param character objetivo.
  \return true si esta agachado.
 */
bool isCharacterDown(Character character);
/**
  \brief obtiene si el porsonaje esta parado.
  \param character objetivo.
  \return true si esta parado.
 */
bool isCharacterStable(Character character);
/**
  \brief cambia el valor X del personaje.
  \param character objetivo.
  \param value nuevo valor.
 */
void setCharacterX(Character character, int value);
/**
  \brief cambia el valor Y del personaje.
  \param character objetivo.
  \param value nuevo valor.
 */
void setCharacterY(Character character, int value);
/**
  \brief cambia el valor Speed del personaje.
  \param character objetivo.
  \param value nuevo valor.
 */
void setCharacterSpeed(Character character, int value);
/**
  \brief cambia el valor Inv del personaje.
  \param character objetivo.
  \param value nuevo valor.
 */
void setCharacterInv(Character character, bool value);
/**
  \brief cambia el valor Jumping del personaje.
  \param character objetivo.
  \param value nuevo valor.
 */
void setCharacterJumping(Character character, bool value);
/**
  \brief cambia el valor Walking del personaje.
  \param character objetivo.
  \param value nuevo valor.
 */
void setCharacterWalking(Character character, bool value);
/**
  \brief cambia el valor Running del personaje.
  \param character objetivo.
  \param value nuevo valor.
 */
void setCharacterRunning(Character character, bool value);
/**
  \brief cambia el valor Down del personaje.
  \param character objetivo.
  \param value nuevo valor.
 */
void setCharacterDown(Character character, bool value);
/**
  \brief cambia el valor Stable del personaje.
  \param character objetivo.
  \param value nuevo valor.
 */
void setCharacterStable(Character character, bool value);
/**
  \brief incrementa el valor X del personaje.
  \param character objetivo.
  \param value valor a incrementar.
 */
void incCharacterX(Character character, int inc);
/**
  \brief incrementa el valor Y del personaje.
  \param character objetivo.
  \param value valor a incrementar.
 */
void incCharacterY(Character character, int inc);
/**
  \brief incrementa el valor Speed del personaje.
  \param character objetivo.
  \param value valor a incrementar.
 */
void incCharacterSpeed(Character character, int inc);
/**
  \brief decrementa el valor X del personaje.
  \param character objetivo.
  \param value valor a decrementar.
 */
void decCharacterX(Character character, int dec);
/**
  \brief decrementa el valor Y del personaje.
  \param character objetivo.
  \param value valor a decrementar.
 */
void decCharacterY(Character character, int dec);
/**
  \brief decrementa el valor Speed del personaje.
  \param character objetivo.
  \param value valor a decrementar.
 */
void decCharacterSpeed(Character character, int dec);
/**
  \brief actualiza la animacion del personaje.
  \param character objetivo.
  \param camera objetivo.
 */
void updateCharacterSprite(Character player, Camera camera);
/**
  \brief actualiza el personaje al pulsar una tecla.
  \param character objetivo.
 */
void updateCharacterKeyPress(Character player);
/**
  \brief actualiza al personaje si colisiona con objetos.
  \param character objetivo.
  \param objPtr lista de objetos.
  \param x posicion anterior a la actual del character.
  \param y posicion anterior a la actual del character.
  \param sco para actualizar la puntuacion.
 */
void updateCharacterCollideWithObjects(Character character, NodePtrObject objPtr, int x, int y, Score sco);
/**
  \brief actualiza al personaje si colisiona con enemigos.
  \param character objetivo.
  \param emyPtr lista de enemigos.
  \param y posicion anterior a la actual del character.
  \param sco para actualizar la puntuacion.
  \return true si ha colisionado.
 */
bool isCharacterCollideWithEnemy(Character character, NodePtrEnemy emyPtr, int y, Score sco);
/**
  \brief comprueba si un personaje choca con un objeto.
  \param character objetivo.
  \param obj objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithObjectC(Character character, Object obj);
/**
  \brief comprueba si un personaje choca con un objeto por abajo.
  \param character objetivo.
  \param obj objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithObjectCDown(Character character, Object obj);
/**
  \brief comprueba si un personaje choca con un objeto por arriba.
  \param character objetivo.
  \param obj objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithObjectCTop(Character character, Object obj);
/**
  \brief comprueba si un personaje choca con un objeto por la derecha.
  \param character objetivo.
  \param obj objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithObjectCRight(Character character, Object obj);
/**
  \brief comprueba si un personaje choca con un objeto por la izquierda.
  \param character objetivo.
  \param obj objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithObjectCLeft(Character character, Object obj);
/**
  \brief comprueba si un personaje esta chocando con la longitud de un objeto.
  \param character objetivo.
  \param obj objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithObjectCWidth(Character character, Object obj);
/**
  \brief comprueba si un personaje esta chocando con la altitud de un objeto.
  \param character objetivo.
  \param obj objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithObjectCHeight(Character character, Object obj);
/**
  \brief comprueba si un personaje esta chocando con un enemigo por abajo.
  \param character objetivo.
  \param emy objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithEnemyDown(Character character, Enemy emy);
/**
  \brief comprueba si un personaje esta chocando con un enemigo por arriba.
  \param character objetivo.
  \param emy objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithEnemyTop(Character character, Enemy emy);
/**
  \brief comprueba si un personaje esta chocando con un enemigo por la derecha.
  \param character objetivo.
  \param emy objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithEnemyRight(Character character, Enemy emy);
/**
  \brief comprueba si un personaje esta chocando con un enemigo por la izquierda.
  \param character objetivo.
  \param emy objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithEnemyLeft(Character character, Enemy emy);
/**
  \brief comprueba si un personaje esta chocando con la longitud de un enemigo.
  \param character objetivo.
  \param emy objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithEnemyWidth(Character character, Enemy emy);
/**
  \brief comprueba si un personaje esta chocando con la altitud de un enemigo.
  \param character objetivo.
  \param emy objetivo.
  \return true si ha colisionado.
 */
bool isCollidingWithEnemyHeight(Character character, Enemy emy);
#endif
