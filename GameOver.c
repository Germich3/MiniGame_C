//Include zone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "Pantalla.h"

/*
 * Game Over
 */
void gameOver() {
    Imagen gameOver = Pantalla_ImagenLee("assets/bg/gameover.bmp", 0);
    
    Pantalla_DibujaRellenoFondo(0, 0, 0, 255);
    Pantalla_DibujaImagen(gameOver, 110, 100, 400, 150);
    
    // Actualizar
    Pantalla_Actualiza();
    Pantalla_Espera(40);
    // Fin Actualizar

    Sleep(3000);
}
void youWin() {
    Imagen win = Pantalla_ImagenLee("assets/bg/win.bmp", 0);
    
    Pantalla_DibujaImagen(win, 0, 0, 640, 480);
    
    // Actualizar
    Pantalla_Actualiza();
    Pantalla_Espera(40);
    // Fin Actualizar

    Sleep(3000);
}