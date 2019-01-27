#ifndef __NODEOBJECT_H
#define __NODEOBJECT_H

#include <stdlib.h>
#include "Object.h"
#include "Camera.h"

/**
\mainpage La biblioteca NodeObject define una lista de objetos.
*/
/**
   \file NodeObject.h
   \brief define define una lista de objetos.
*/
/**
    \brief TDA NodePtrObject
 */
typedef struct NodeRep *NodePtrObject;
/**
  \brief Crea una nueva lista de objetos.
  \return una nueva lista de objetos.
 */
NodePtrObject newNodePtrObject();
/**
  \brief libera una lista de objetos.
  \param list una lista de objetos.
 */
void freeNodePtrObject(NodePtrObject list);
/**
  \brief obtiene el siguiene nodo de la lista.
  \param node una lista de objetos.
  \return el siguiente nodo.
 */
NodePtrObject getNextNodePtrObject(NodePtrObject node);
/**
  \brief obtiene el elemento del nodo actual.
  \param node una lista de objetos.
  \return el elemento.
 */
Object getElementNodePtrObject(NodePtrObject node);
/**
  \brief añade al principio de la lista un objeto.
  \param list una lista de objeto.
  \param elem el objeto.
 */
void addFirstElementNodePtrObject(NodePtrObject list, Object elem);
/**
  \brief añade al final de la lista un objeto.
  \param list una lista de objeto.
  \param elem el objeto.
 */
void addLastElementNodePtrObject(NodePtrObject list, Object elem);
/**
  \brief añade en una posicion de la lista un objeto.
  \param list una lista de objeto.
  \param index posicion de la lista.
  \param elem el objeto.
 */
void addElementNodePtrObject(NodePtrObject list, int index, Object elem);
/**
  \brief elimina de la lista el siguiente nodo al actual.
  \param list una lista de objetos.
 */
void removeNextElementNodePtrObject(NodePtrObject list);
/**
  \brief dibuja una lista de objetos.
  \param objectsList una lista de objetos.
  \param camera objetivo.
 */
void drawObjectList(NodePtrObject objectsList, Camera camera);
#endif
