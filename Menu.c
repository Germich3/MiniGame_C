//Include zone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pantalla.h"
#include "Level1.h"
#include "Score.h"
#include "RandomLevel.h"

void mainMenu() {
    Pantalla_Crea("MiniJuego", 640, 480);
    Imagen background = Pantalla_ImagenLee("assets/bg/menuBG.bmp", 0);
    int option = 0;
    bool isKeyPressing = false;
    bool isQuit = false;
    
    while (Pantalla_Activa() && !isQuit){
        
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)) {
            if (!isKeyPressing) {
                option++;
                if (option >= 3) {
                    option = 3;
                }
            }
            isKeyPressing = true;
        }
        else if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP)) {
            if (!isKeyPressing) {
                option--;
                if (option <= 0) {
                    option = 0;
                }
            }
            isKeyPressing = true;
        }
        else {
            isKeyPressing = false;
        }
        
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN)) {
            switch (option) {
                case 0 : playLevel1(); break;
                case 1 : playRandomLevel(); break;
                case 2 : lastScore("assets/sco/score.sco"); break;
                case 3 : isQuit = true; break;
            } 
        }
        
        Pantalla_ColorTrazo(0, 0, 0, 255);
        Pantalla_DibujaImagen(background, 0, 0, 640, 480);
        switch (option) {
            case 0 : Pantalla_DibujaTexto("> Play Level 1", 270, 200); 
                     Pantalla_DibujaTexto("Play Randomized Level", 270, 230);
                     Pantalla_DibujaTexto("Last Score", 270, 260);
                     Pantalla_DibujaTexto("Quit", 270, 320);
                     break;
            case 1 : Pantalla_DibujaTexto("Play Level 1", 270, 200); 
                     Pantalla_DibujaTexto("> Play Randomized Level", 270, 230);
                     Pantalla_DibujaTexto("Last Score", 270, 260);
                     Pantalla_DibujaTexto("Quit", 270, 320);
                     break;
            case 2 : Pantalla_DibujaTexto("Play Level 1", 270, 200); 
                     Pantalla_DibujaTexto("Play Randomized Level", 270, 230);
                     Pantalla_DibujaTexto("> Last Score", 270, 260);
                     Pantalla_DibujaTexto("Quit", 270, 320);
                     break;
            case 3 : Pantalla_DibujaTexto("Play Level 1", 270, 200); 
                     Pantalla_DibujaTexto("Play Randomized Level", 270, 230);
                     Pantalla_DibujaTexto("Last Score", 270, 260);
                     Pantalla_DibujaTexto("> Quit", 270, 320);
                     break;
        }
        
        // Actualizar
        Pantalla_Actualiza();
        Pantalla_Espera(40);
        // Fin Actualizar
    }
    
    // Libera
    Pantalla_ImagenLibera(background);
    Pantalla_Libera();
}