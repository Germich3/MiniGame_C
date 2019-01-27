#ifndef CAMERA_H
#define CAMERA_H

#include <stdio.h>
#include <stdlib.h>

/**
\mainpage La biblioteca Camara nos hace una especie de zoom.
*/
/**
   \file Camera.h
   \brief  permite establecer un area maxima y adaptar los objetos a este area.
*/
/**
    \brief TDA Camara
 */
typedef struct CameraRep *Camera;

/**
  \brief Crea una nueva camara.
  \param width define el ancho maximo del espacio de la camara.
  \param resolution calcula cual es la mitad exacta de tu superficie.
 */
Camera newCamera(int width, int resolution);
/**
  \brief libera una camara.
  \param camera objetivo.
 */
void freeCameraResources(Camera camera);
/**
  \brief obtiene el valor X de una camara.
  \param camera camara objetivo.
  \return el valor de X.
 */
int getCameraX(Camera camera);
/**
  \brief obtiene el valor Y de una camara.
  \param camera camara objetivo.
  \return el valor de Y.
 */
int getCameraY(Camera camera);
/**
  \brief obtiene el valor Width de una camara.
  \param camera camara objetivo.
  \return el valor de Width.
 */
int getCameraWidth(Camera camera);
/**
  \brief cambia el valor X de una camara.
  \param camera camara objetivo.
  \value el nuevo valor.
 */
void setCameraX(Camera camera, int value);
/**
  \brief cambia el valor Y de una camara.
  \param camera camara objetivo.
  \value el nuevo valor.
 */
void setCameraY(Camera camera, int value);
/**
  \brief Actualiza la coordenada X de un camara.
  \param camera camara objetivo.
  \x el valor objetivo.
 */
void updateCameraX(Camera camera, int x);
/**
  \brief Transforma una coordenada a una coordenada de la camara.
  \param camera camara objetivo.
  \x el valor objetivo.
 */
int transformaCameraX(Camera camera, int x);

#endif
