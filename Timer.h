#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
\mainpage La biblioteca Timer crea un termporizador.
*/
/**
   \file Timer.h
   \brief crea un termporizador.
*/
/**
    \brief TDA Timer
 */
typedef struct TimerRep *Timer;
/**
  \brief Crea un nuevo temporizador.
  \param sec tiempo en segundos del temporizador.
  \return un nuevo temporizador.
 */
Timer newTimer(int sec);
/**
  \brief libera un temporizador.
  \param timer objetivo.
 */
void freeTimerResources(Timer timer);
/**
  \brief obtiene el tiempo que dura el temporizador.
  \param timer objetivo.
  \return el valor.
 */
long int getTimerTimerSec(Timer timer);
/**
  \brief obtiene el tiempo actual que falta en el temporizador.
  \param timer objetivo.
  \return el valor.
 */
long int getTimerCurrentTime(Timer timer);
/**
  \brief obtiene el tiempo actual en segundos que falta en el temporizador.
  \param timer objetivo.
  \return el valor.
 */
int getTimerCurrentSecInt(Timer timer);
/**
  \brief obtiene el tiempo actual en segundos que falta en el temporizador.
  \param timer objetivo.
  \param str puntero donde guardar el valor.
 */
void getTimerCurrentSecChar(Timer timer, char *str);

#endif
