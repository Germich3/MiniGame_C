#ifndef OBJECT_H
#define OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pantalla.h"
#include "Camera.h"

/**
\mainpage La biblioteca Object define a un objeto.
*/
/**
   \file Object.h
   \brief define a un objeto.
*/
/**
    \brief TDA Object
 */
typedef struct ObjectRep *Object;
/**
  \brief Crea un nuevo objeto.
  \param x coordenada x de spawn.
  \param y coordenada y de spawn.
  \param w ancho del objeto.
  \param h alto del objeto.
  \param isInteractive si se puede interactuar con el.
  \param isScoreable si da puntos.
  \param sprite del enemigo.
  \return un nuevo objeto.
 */
Object newObject(int x, int y, int w, int h, bool isInteractive, bool isScoreable, Imagen sprite);
/**
  \brief Libera los recursos del objeto.
  \param obj objetivo.
 */
void freeObjectResources(Object obj);
/**
  \brief obtiene la coordenada X del objeto.
  \param obj objetivo.
  \return el valor de X.
 */
int getObjectX(Object obj);
/**
  \brief obtiene la coordenada Y del objeto.
  \param obj objetivo.
  \return el valor de Y.
 */
int getObjectY(Object obj);
/**
  \brief obtiene la coordenada W del objeto.
  \param obj objetivo.
  \return el valor de W.
 */
int getObjectW(Object obj);
/**
  \brief obtiene la coordenada H del objeto.
  \param obj objetivo.
  \return el valor de H.
 */
int getObjectH(Object obj);
/**
  \brief obtiene si el objeto es interactivo
  \param obj objetivo.
  \return true si es interactivo.
 */
bool getObjectInteractive(Object obj);
/**
  \brief obtiene si el objeto es Scoreable
  \param obj objetivo.
  \return true si es Scoreable.
 */
bool getObjectScoreable(Object obj);
/**
  \brief dibuja un objeto
  \param obj objetivo.
  \param camera objetivo.
 */
void drawObject(Object obj, Camera camera);

#endif /* OBJECT_H */

