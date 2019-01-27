//Include zone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "Pantalla.h"
#include "Score.h"

//Type Score
struct ScoreRep {
    FILE *score;
    char str[10];
};

//Constructor
Score newScore(char *directory){
    Score sco = malloc(sizeof(struct ScoreRep));
        sco -> score = fopen(directory, "w+");
        fprintf(sco->score, "0");
    return sco;
}

void freeScore(Score sco) {
    fclose(sco->score);
    free(sco);
}

void updateScoreChar(Score sco, char *value) {
    fseek(sco->score, 0, SEEK_SET);
    fputs(value, sco->score);
}

void getScoreChar(Score sco, char *str) {
    fseek(sco->score, 0, SEEK_SET);
    fgets(str, 10, sco->score);
}

void updateScoreInt(Score sco, int value) {
    getScoreChar(sco, sco->str);
    int num = atoi(sco->str);
    num = num + value;
    sprintf(sco->str, "%d", num);
    updateScoreChar(sco, sco->str);
}

int getScoreInt(Score sco) {
    fseek(sco->score, 0, SEEK_SET);
    fgets(sco->str, 10, sco->score);
    int num = atoi(sco->str);
    return num;
}

void lastScore(char *directory){
    
    Imagen lastScore = Pantalla_ImagenLee("assets/bg/lastScore.bmp", 0);
    
    Pantalla_DibujaRellenoFondo(0, 0, 0, 255);
    Pantalla_DibujaImagen(lastScore, 110, 100, 400, 150);
    
    char last[10];
    FILE *score = fopen(directory, "r");
    fgets(last, 10, score);
    fclose(score);
    
    Pantalla_ColorTrazo(255, 255, 255, 255);
    Pantalla_DibujaTexto(last, 280, 300);
    
    // Actualizar
    Pantalla_Actualiza();
    Pantalla_Espera(40);
    // Fin Actualizar

    Sleep(3000);
}