#ifndef RANDOMLEVEL_H
#define RANDOMLEVEL_H

/**
\mainpage La biblioteca RandomLevel define un nivel randomizado.
*/
/**
   \file RandomLevel.h
   \brief define un nivel randomizado.

/**
    \brief ejecuta el nivel.
 */
void playRandomLevel();
/**
    \brief devuelve un numero aleatorio comprendido entre min y max.
    \param min valor minimo.
    \param max valor maximo.
    \return un numero aleatorio.
 */
int getIntRandom(int min, int max);

#endif /* RANDOMLEVEL_H */

