#ifndef SCORE_H
#define SCORE_H

/**
\mainpage La biblioteca Score crea un fichero donde guardar la puntuacion.
*/
/**
   \file Score.h
   \brief crea un fichero donde guardar la puntuacion.
*/
/**
    \brief TDA Score
 */
typedef struct ScoreRep *Score;
/**
  \brief Crea un nuevo Score.
  \param directory una cadena con el directorio.
  \return un nuevo Score.
 */
Score newScore(char *directory);
/**
  \brief libera un Score.
  \param sco objetivo.
 */
void freeScore(Score sco);
/**
  \brief actualiza la puntuacion escribiendo el nuevo valor.
  \param sco objetivo.
  \param value nuevo valor.
 */
void updateScoreChar(Score sco, char *value);
/**
  \brief obtiene la puntuacion del archivo.
  \param sco objetivo.
  \param str donde almacenar el valor.
 */
void getScoreChar(Score sco, char *str);
/**
  \brief actualiza la puntuacion escribiendo el nuevo valor en numerico.
  \param sco objetivo.
  \param value nuevo valor.
 */
void updateScoreInt(Score sco, int value);
/**
  \brief obtiene el valor del archivo en numerico.
  \param sco objetivo.
  \return el valor.
 */
int getScoreInt(Score sco);
/**
  \brief muestra la puntuacion del archivo por pantalla.
  \param directory localizacion del archivo.
 */
void lastScore(char *directory);

#endif /* SCORE_H */

