#include "ArrayList.h"
#define MAX 3 
struct ListaRep { 
    Elemento elem[MAX]; 
    int n;  
};
ArrayList newArrayList() { 
    ArrayList l = malloc(sizeof(struct ListaRep)); 
    l->n = 0; 
    return l; 
}
void freeArrayList(ArrayList l) { 
    free(l); 
}
void addArrayListElement(ArrayList l, int p, Elemento e) { 
    if(!isFull(l)){
        for (int i=l->n;i>p;i--) {
            l->elem[i]=l->elem[i-1];
        }
        l->elem[p]=e; 
        l->n++;
    }
}
void removeArrayListPosition(ArrayList l, int p) { 
    l->n--; 
    for(int i=p;i<l->n;i++){
        l->elem[i]=l->elem[i+1];
    }
}
Elemento getElementArrayList(ArrayList l, int p) { 
    return l->elem[p]; 
}
void setIndexElementArrayList(ArrayList l, int p, Elemento e) { 
    l->elem[p] = e;
}
int lenghtArrayList(ArrayList l) { 
    return l->n;
}
int firstIndexArrayList(ArrayList l) { 
    return 0;
}        
int lastIndexArrayList(ArrayList l) { 
    return l->n;
}
int nextIndexArrayList(ArrayList l, int p) {
    return p+1;
}
int prevIndexArrayList(ArrayList l, int p) {
    return p-1;
}
bool isFull(ArrayList l) {
    if (l->n == MAX) {
        return true;
    }
    return false;
}
//Utils
void drawShootArrayList(ArrayList shtList, Camera camera) {
    for (int i=0; i<lastIndexArrayList(shtList); i++) {
        drawShoot(getElementArrayList(shtList, i), camera);
    }
}
void updateShootArrayList(ArrayList list) {
    for (int i=0; i<lastIndexArrayList(list); i++) {
        setShootPrevY(getElementArrayList(list, i), getShootY(getElementArrayList(list, i)));
        if (isShootRev(getElementArrayList(list, i))) {
            decShootX(getElementArrayList(list, i), 10);
            if (getShootX(getElementArrayList(list, i)) < getShootStartX(getElementArrayList(list, i)) - getShootTravel(getElementArrayList(list, i))) {
                removeArrayListPosition(list, i);
            }
        }
        else {
            incShootX(getElementArrayList(list, i), 10);
            if (getShootX(getElementArrayList(list, i)) > getShootStartX(getElementArrayList(list, i)) + getShootTravel(getElementArrayList(list, i))) {
                removeArrayListPosition(list, i);
            }
        }
        setShootY(getElementArrayList(list, i), getShootY(getElementArrayList(list, i)) + getShootSpeed(getElementArrayList(list, i)));
        incShootSpeed(getElementArrayList(list, i), 2);
    }
}
void updateShootArrayListCollideWithObjects(ArrayList shtList, NodePtrObject objList) {
    for (int i=0; i<lastIndexArrayList(shtList); i++) {
        updateShootCollideWithObject(getElementArrayList(shtList, i), objList);
    }
}
void updateShootArrayListCollideWithEnemys(ArrayList shtList, NodePtrEnemy emyList, Score sco) {
    for (int i=0; i<lastIndexArrayList(shtList); i++) {
        NodePtrEnemy copyEnemyList = getNextNodePtrEnemy(emyList);
        NodePtrEnemy preEnemyPtr = emyList;
        while (copyEnemyList != NULL && !isCollidingWithEnemyS(getElementArrayList(shtList, i), getElementNodePtrEnemy(copyEnemyList))) {
            copyEnemyList = getNextNodePtrEnemy(copyEnemyList);
            preEnemyPtr = getNextNodePtrEnemy(preEnemyPtr);
        }
        if (copyEnemyList != NULL) {
            removeNextElementNodePtrEnemy(preEnemyPtr);
            updateScoreInt(sco, 200);
            removeArrayListPosition(shtList, i);
        }
    }
}