#include "NodeObject.h"

struct NodeRep {
    Object elem;
    NodePtrObject next;
};

NodePtrObject newNodePtrObject() { 
    NodePtrObject list = malloc( sizeof( struct NodeRep ) );
    list->next = NULL;
    return list;
}
void freeNodePtrObject(NodePtrObject list) {
    while ( list->next != NULL ) {
        NodePtrObject aux = list;
        list = aux->next;
        free(aux);
    }
    free(list);
}
NodePtrObject getNextNodePtrObject(NodePtrObject node){
    return node->next;
}
Object getElementNodePtrObject(NodePtrObject node){
    return node->elem;
}
void addFirstElementNodePtrObject(NodePtrObject list, Object elem) {
    NodePtrObject newNode = malloc( sizeof( struct NodeRep ) );
    newNode->elem = elem;
    newNode->next = list->next;
    list->next = newNode;
}
void addLastElementNodePtrObject(NodePtrObject list, Object elem) {
    NodePtrObject newNode = malloc( sizeof( struct NodeRep ) );
    newNode->elem = elem;
    if ( list == NULL ) {
        newNode->next = NULL;
        list = newNode;
    }
    else { 
        NodePtrObject aux = list;
        while ( aux->next != NULL ) { 
            aux = aux->next; 
        } 
        newNode->next = NULL;
        aux->next = newNode;
    }
}
void addElementNodePtrObject(NodePtrObject list, int index, Object elem) {
    NodePtrObject newNode = malloc( sizeof( struct NodeRep ) );
    newNode->elem = elem; 
    if ( index == 1 ) {
        newNode->next = list;
        list = newNode;
    }
    else {
        NodePtrObject aux = list;
        for (int i=1; i < index - 1; i++) {
            aux = aux->next;
        }
        newNode->next = aux->next;
        aux->next = newNode;
    }
}
void removeNextElementNodePtrObject(NodePtrObject list) {
    NodePtrObject remNode = list->next;
    list->next = list->next->next;
    free(remNode);
}
//Utils
void drawObjectList(NodePtrObject objectsList, Camera camera) {
    for (NodePtrObject copyObjectsList = getNextNodePtrObject(objectsList); copyObjectsList != NULL; copyObjectsList = getNextNodePtrObject(copyObjectsList)) {
        drawObject(getElementNodePtrObject(copyObjectsList), camera);
    }
}