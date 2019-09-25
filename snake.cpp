#include<windows.h>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

//Números asociados a las teclas
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27

int n = 1, tam = 5, x = 10, y = 12, cuerpo[200][2], resp;
int dir = 3, xc = 30, yc = 15, velocidad = 100, h = 1, score;
char tecla;

void gotoxy(int x, int y){
	HANDLE hCon;//identificador de un objeto o recurso
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon,dwPos);
}

void pintar(){
    //lineas horizontales
    for(int i = 2; i < 78; i++){
        gotoxy(i,3);
        printf("%c", 205); //hasta aquí los renglones de arriba
        gotoxy(i, 23);
        printf("%c", 205); //hasta aquí los renglones de abajo
    }
    //lineas verticales
    for(int i = 4; i < 23; i++){
        gotoxy(2,i);
        printf("%c", 186); //hasta aquí los renglones de izquierda
        gotoxy(77, i);
        printf("%c", 186); //hasta aquí los renglones de derecha
    }
    gotoxy(2,3);
    printf("%c", 201); //hasta aquí los esquina superior izquierda
    gotoxy(77,3);
    printf("%c", 187); //hasta aquí los esquina superior derecha
    gotoxy(2,23);
    printf("%c", 200); //hasta aquí los esquina inferior izquierda
    gotoxy(77,23);
    printf("%c", 188); //hasta aquí los esquina inferior derecha
}

void guardar_posicion(){
    cuerpo[n][0] = x;
    cuerpo[n][1] = y;
    n++;
    if(n == tam)
        n = 1;
}

void dibujar_cuerpo(){
    for(int i = 1; i < tam; i++){
        gotoxy(cuerpo[i][0], cuerpo[i][1]);
        printf("*");
    }
}

void borrar_cuerpo(){
        gotoxy(cuerpo[n][0], cuerpo[n][1]); printf(" ");
}

void teclear(){
    if(kbhit()){
        tecla = getch();
        switch(tecla){
            case ARRIBA: if(dir!=2)
                            dir = 1;
                        break;
            case ABAJO: if(dir!=1)
                            dir = 2;
                        break;
            case DERECHA: if(dir!=4)
                            dir = 3;
                        break;
            case IZQUIERDA: if(dir!=3)
                            dir = 4;
                            break;
            }
    }
}
void comida(){
    if(x == xc && y ==yc){
        xc = (rand()%73)+4;
        yc = (rand()%19)+4;
        tam++;
        score +=1;
        gotoxy(xc,yc);
        printf("%c", 254);
    }
}

bool game_over(){
    if(y == 3 || y == 23 || x == 2 || x == 77)
        return false;
    for(int j = tam-1; j>0; j--){
        if(cuerpo[j][0] == x && cuerpo [j][1] == y){
            return false;
        }
    }
    return true;
}

void puntos(){
    gotoxy(3,1);
    printf("Puntaje %d", score);
}

void cambiar_velocidad(){
    if(score == h*5){
        velocidad -=5;
        h++;
    }
}

int main(){
    FILE *puntaje;
    fopen("puntaje", "w");
    fprintf(puntaje, "%" )
    pintar();
    gotoxy(xc,yc);
    printf("%c", 254);
    while(tecla != ESC && game_over()){
        borrar_cuerpo();
        guardar_posicion();
        dibujar_cuerpo();
        comida();
        puntos();
        cambiar_velocidad();
        teclear();
        teclear();//La llamo dos veces en el caso que se tenga que hacer movimientos bruscos se hagan rápido

        if (dir == 1)
            y--;
        if (dir == 2)
            y++;
        if (dir == 3)
            x++;
        if (dir == 4)
            x--;
        Sleep(velocidad);
        if(tecla == ESC){
            gotoxy(30,10);
            printf("Que deseas hacer.\n");
            gotoxy(30,11);
            printf("1. Salir del juego.\n");
            gotoxy(30,12);
            printf("2.Seguir jugando\n");
            gotoxy(30,13);
            scanf("%d", &resp);
            if(resp == 1){
                return 0;
            }else{
                tecla = 2;
                pintar();
            }
        }
    }
    el p
    fwrite(score, 1, sizeof(score), puntaje);
    fclose(puntaje);
    system("pause>null");
    return 0;
}
