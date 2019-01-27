#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdlib.h>
#include "Shoot.h"
#include "Camera.h"
#include "Character.h"
#include "NodeEnemy.h"
#include "NodeObject.h"

/**
\mainpage La biblioteca ArrayList representa una lista de disparos en forma de array.
*/
/**
   \file ArrayList.h
   \brief define representa una lista de disparos en forma de array.
*/
/**
    \brief TDA ArrayList
 */
typedef struct ListaRep *ArrayList;
/**
    \brief TDA Elemento
 */
typedef Shoot Elemento;
/**
  \brief Crea una nueva lista de disparos.
  \return una nueva lista de disparos.
 */
ArrayList newArrayList();
/**
  \brief libera una lista de disparos.
  \param list una lista de disparos.
 */
void freeArrayList(ArrayList l);
/**
  \brief añade un elemento en una posicion del array.
  \param l una lista de disparos.
  \param p posicion en el array.
  \param e disparo objetivo.
 */
void addArrayListElement(ArrayList l, int p, Elemento e);
/**
  \brief Elimina un elemento del array.
  \param l una lista de disparos.
  \param p posicion en el array.
 */
void removeArrayListPosition(ArrayList l, int p);
/**
  \brief devuelve un elemento de una posicion del array.
  \param l una lista de disparos.
  \param p posicion en el array.
 */
Elemento getElementArrayList(ArrayList l, int p);
/**
  \brief modifica un valor del array.
  \param l una lista de disparos.
  \param p posicion en el array.
  \param e nuevo disparo.
 */
void setIndexElementArrayList(ArrayList l, int p, Elemento e);
/**
  \brief longitud maxima del array.
  \param l una lista de disparos.
 */
int lenghtArrayList(ArrayList l);
/**
  \brief devuelve la primera posicion del array.
  \param l una lista de disparos.
  \return una posicion.
 */
int firstIndexArrayList(ArrayList l);
/**
  \brief devuelve la ultima posicion del array.
  \param l una lista de disparos.
  \return una posicion.
 */
int lastIndexArrayList(ArrayList l);
/**
  \brief devuelve la siguiente posicion del array.
  \param l una lista de disparos.
  \param p una posicion.
  \return una posicion.
 */
int nextIndexArrayList(ArrayList l, int p);
/**
  \brief devuelve la anterior posicion del array.
  \param l una lista de disparos.
  \param p una posicion.
  \return una posicion.
 */
int prevIndexArrayList(ArrayList l, int p);
/**
  \brief devuelve si la lista esta llena.
  \param l una lista de disparos.
  \return true si esta llena.
 */
bool isFull(ArrayList l);
/**
  \brief dibuja una lista de disparos.
  \param shtList una lista de disparos.
  \param camera objetivo.
 */
void drawShootArrayList(ArrayList shtList, Camera camera);
/**
  \brief actualiza cada elemento de una lista de disparos.
  \param list una lista de disparos.
 */
void updateShootArrayList(ArrayList list);
/**
  \brief actualiza cada elemento de una lista de disparos si colisionan con objetos.
  \param shtList una lista de disparos.
  \param objList una lista de objetos.
 */
void updateShootArrayListCollideWithObjects(ArrayList shtList, NodePtrObject objList);
/**
  \brief actualiza cada elemento de una lista de disparos si colisionan con enemigos.
  \param shtList una lista de disparos.
  \param emyList una lista de enemigos.
  \param sco a actualizar.
 */
void updateShootArrayListCollideWithEnemys(ArrayList shtList, NodePtrEnemy emyList, Score sco);
#endif /* ARRAYLIST_H */

