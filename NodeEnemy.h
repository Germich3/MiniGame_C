#ifndef __NODEENEMY_H
#define __NODEENEMY_H

#include <stdlib.h>
#include "Enemy.h"
#include "Camera.h"
#include "NodeObject.h"

/**
\mainpage La biblioteca NodeEnemy define una lista de enemigos.
*/
/**
   \file NodeEnemy.h
   \brief define define una lista de enemigos.
*/
/**
    \brief TDA NodePtrEnemy
 */
typedef struct NodeRep *NodePtrEnemy;
/**
  \brief Crea una nueva lista de enemigos.
  \return una nueva lista de enemigos.
 */
NodePtrEnemy newNodePtrEnemy();
/**
  \brief libera una lista de enemigos.
  \param list una lista de enemigos.
 */
void freeNodePtrEnemy(NodePtrEnemy list) ;
/**
  \brief obtiene el siguiene nodo de la lista.
  \param node una lista de enemigos.
  \return el siguiente nodo.
 */
NodePtrEnemy getNextNodePtrEnemy(NodePtrEnemy node);
/**
  \brief obtiene el elemento del nodo actual.
  \param node una lista de enemigos.
  \return el elemento.
 */
Enemy getElementNodePtrEnemy(NodePtrEnemy node);
/**
  \brief añade al principio de la lista un enemigo.
  \param list una lista de enemigos.
  \param elem el enemigo.
 */
void addFirstElementNodePtrEnemy(NodePtrEnemy list, Enemy elem);
/**
  \brief añade al final de la lista un enemigo.
  \param list una lista de enemigos.
  \param elem el enemigo.
 */
void addLastElementNodePtrEnemy(NodePtrEnemy list, Enemy elem);
/**
  \brief añade en una posicion de la lista un enemigo.
  \param list una lista de enemigos.
  \param index posicion en la lista.
  \param elem el enemigo.
 */
void addElementNodePtrEnemy(NodePtrEnemy list, int index, Enemy elem);
/**
  \brief elimina de la lista el siguiente nodo al actual.
  \param list una lista de enemigos.
 */
void removeNextElementNodePtrEnemy(NodePtrEnemy list);
/**
  \brief actualiza cada elemento de una lista de enemigos.
  \param list una lista de enemigos.
 */
void updateEnemyList(NodePtrEnemy list);
/**
  \brief actualiza cada elemento de una lista de enemigos si colisionan con objetos.
  \param emyList una lista de enemigos.
  \param objList una lista de objetos.
 */
void updateEnemyListCollideWithObjects(NodePtrEnemy emyList, NodePtrObject objList);
/**
  \brief dibuja una lista de enemigos.
  \param emyList una lista de enemigos.
  \param camera objetivo.
 */
void drawEnemyList(NodePtrEnemy emyList, Camera camera);
#endif
