#include "NodeEnemy.h"

struct NodeRep {
    Enemy elem;
    NodePtrEnemy next;
};

NodePtrEnemy newNodePtrEnemy() { 
    NodePtrEnemy list = malloc( sizeof( struct NodeRep ) );
    list->next = NULL;
    return list;
}
void freeNodePtrEnemy(NodePtrEnemy list) {
    while ( list->next != NULL ) {
        NodePtrEnemy aux = list;
        list = aux->next;
        free(aux);
    }
    free(list);
}
NodePtrEnemy getNextNodePtrEnemy(NodePtrEnemy node){
    return node->next;
}
Enemy getElementNodePtrEnemy(NodePtrEnemy node){
    return node->elem;
}
void addFirstElementNodePtrEnemy(NodePtrEnemy list, Enemy elem) {
    NodePtrEnemy newNode = malloc( sizeof( struct NodeRep ) );
    newNode->elem = elem;
    newNode->next = list->next;
    list->next = newNode;
}
void addLastElementNodePtrEnemy(NodePtrEnemy list, Enemy elem) {
    NodePtrEnemy newNode = malloc( sizeof( struct NodeRep ) );
    newNode->elem = elem;
    if ( list == NULL ) {
        newNode->next = NULL;
        list = newNode;
    }
    else { 
        NodePtrEnemy aux = list;
        while ( aux->next != NULL ) { 
            aux = aux->next; 
        } 
        newNode->next = NULL;
        aux->next = newNode;
    }
}
void addElementNodePtrEnemy(NodePtrEnemy list, int index, Enemy elem) {
    NodePtrEnemy newNode = malloc( sizeof( struct NodeRep ) );
    newNode->elem = elem; 
    if ( index == 1 ) {
        newNode->next = list;
        list = newNode;
    }
    else {
        NodePtrEnemy aux = list;
        for (int i=1; i < index - 1; i++) {
            aux = aux->next;
        }
        newNode->next = aux->next;
        aux->next = newNode;
    }
}
void removeNextElementNodePtrEnemy(NodePtrEnemy list) {
    NodePtrEnemy remNode = list->next;
    list->next = list->next->next;
    free(remNode);
}
//Utils from Enemys
void updateEnemyList(NodePtrEnemy list) {
    for (NodePtrEnemy copyEnemyList = getNextNodePtrEnemy(list); copyEnemyList != NULL; copyEnemyList = getNextNodePtrEnemy(copyEnemyList)) {
        updateEnemy(getElementNodePtrEnemy(copyEnemyList));
    }
}
void updateEnemyListCollideWithObjects(NodePtrEnemy emyList, NodePtrObject objList) {
    for (NodePtrEnemy copyEnemyList = getNextNodePtrEnemy(emyList); copyEnemyList != NULL; copyEnemyList = getNextNodePtrEnemy(copyEnemyList)) {
        updateEnemyCollideWithObjects(getElementNodePtrEnemy(copyEnemyList), objList);
    } 
}
void drawEnemyList(NodePtrEnemy emyList, Camera camera) {
    for (NodePtrEnemy copyEnemyList = getNextNodePtrEnemy(emyList); copyEnemyList != NULL; copyEnemyList = getNextNodePtrEnemy(copyEnemyList)) {
        drawEnemy(getElementNodePtrEnemy(copyEnemyList), camera);
    }
}