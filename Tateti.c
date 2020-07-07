// MEDINA, LUCAS NAHUEL
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// Declaracion funciones

int Pregunta_y_respuesta_usuario();
int igualar_cero_variables(int lugar_ocupado[9]);
int Asignacionficha(int contador, char tablero[9], int lugar_ocupado[9], int respuesta);
int AnalisisJugadas (char tablero[] , char ficha, int a, int b, int c);
int Yaexisteganador (char tablero[]);
int JugadaMaquina(char tablero[], int ficha, int a, int b, int c, int lugar_ocupado[]);
void dibujo_tablero(char tablero[9]);
void empataroganar_x(char tablero[9], int contador, int x[9], int o[9], int lugar_ocupado[9], int numero_aleatorio);
void empataroganar_y(char tablero[9], int contador, int x[9], int o[9], int lugar_ocupado[9], int numero_aleatorio);

int const posibilidades[][3] = {{0,1,2},{3,4,5},{6,7,8},{0,4,8},{2,4,6},{0,3,6},{1,4,7},{2,5,8}};

int main()
{
    int contador = 0, lugar_ocupado[9], numero_aleatorio, respuesta, ficha;
    char tablero[9]= "";
    srand(time(NULL)); // funcion para numeros aleatorios segun el caso.
    igualar_cero_variables(lugar_ocupado); // Funcion que iguala a cero las variables.
    while (contador<9) // While que cumple la funcion de ciclo para el ingreso de dato del usuario.
    {
        ficha = FichaMaquina(tablero,respuesta, contador); //Da el numero ASCII de la ficha que se juega
        dibujo_tablero(tablero);
        respuesta = Pregunta_y_respuesta_usuario(); //Recibe la respuesta del usuario
        contador = Asignacionficha(contador, tablero, lugar_ocupado, respuesta); // Asigna ficha a donde lo designe el usuario, y en el caso de que ya haya una ficha ahi, se le vuelve a preguntar.
        system("cls");
    }
    contador=0;
    if (Yaexisteganador(tablero)==1); // Si ya hay un ganador en el tablero planteado, Dice quien es el ganador y se termina el programa.
    else
    {
        for (int i=0; i<8; i++)
       {
            JugadaMaquina(tablero, ficha, posibilidades[i][0], posibilidades[i][1], posibilidades[i][2], lugar_ocupado); // La maquina asigna una ficha donde es conveniente (solo ganar por ahora)
       }
    }
    dibujo_tablero(tablero);
}

int Yaexisteganador (char tablero[]) // Funcion que analiza si en el tablero dado ya existe un ganador.
{
    for (int x=0; x<8; x++)
    {
        if (AnalisisJugadas(tablero, 'X',posibilidades[x][0], posibilidades[x][1], posibilidades[x][2])==3)
        {
            printf("\n\n EL GANADOR ES EL JUGADOR X");
            return 1;
        }
        if (AnalisisJugadas(tablero, 'O', posibilidades[x][0], posibilidades[x][1], posibilidades[x][2])==3)
        {
            printf("\n\n EL GANADOR ES EL JUGADOR O");
            return 1;
        }
    }
    return 0;
}
int AnalisisJugadas (char tablero[] , char ficha, int a, int b, int c) // Analiza las posiciones de las fichas.
{
    int contador=0;
    if (tablero[a]==ficha) {contador++;}
    if (tablero[b]==ficha) {contador++;}
    if (tablero[c]==ficha) {contador++;}
    return contador;
}
int JugadaMaquina(char tablero[], int ficha, int a, int b, int c, int lugar_ocupado[]) // Analiza si conviene empatar o ganar y llama a la funcion correspondiente
{
    char Simbolo;
    if (ficha==88)
    {
        Simbolo='O';
    }
    else { Simbolo='X'; }
    if ((AnalisisJugadas(tablero, Simbolo, a, b, c)==2)&& (lugar_ocupado[a]==0 || lugar_ocupado[b]==0 || lugar_ocupado[c]==0))
    {
        Ganar(lugar_ocupado, a, b, c, tablero);
    }
}
int Ganar (int lugar_ocupado[], int a, int b, int c, char tablero[]) // Asigna ficha para ganar
{
    int turno=0;
    if (lugar_ocupado[a]==0)
    {
        turno=a;
    }
    else if (lugar_ocupado[b]==0)
    {
        turno=b;
    }
    else
    {
        turno=c;
    }
    tablero[turno]='X';
    return 1;
}
int FichaMaquina (char tablero[], int ficha, int contador) // Devuelve numero ASCII de la ficha en juego
{
    if (contador%2==0)
    {
        ficha = 79;
    }
    else
    {
        ficha = 88;
    }
    return ficha;
}
void dibujo_tablero(char tablero[9]) // Dibuja el tablero
{
    printf(" %c | %c | %c \n---+---+---\n %c | %c | %c\n---+---+---\n %c | %c | %c\n",tablero[0],tablero[1],tablero[2],tablero[3],tablero[4],tablero[5],tablero[6],tablero[7],tablero[8]);
}
int igualar_cero_variables(int lugar_ocupado[9]) // Iguala a cero las variables
{
    for (int y=0;y<9;y++)
    {
        lugar_ocupado[y]=0;
    }
}
int Pregunta_y_respuesta_usuario () // Realiza la pregunta de a donde quiere posicionar al usuario
{
    int respuesta;
    gotoxy(1,7); printf("INGRESE UN ENTERO DEL 1 AL 9 PARA MARCAR CASILLERO.  SI DESEA TERMINAR DE PLANTEAR LA JUGADA, PRESIONE '0'.\n¿ DONDE DESEA COLOCAR LA O ? = "); scanf("%d",&respuesta);
    return respuesta;
}
int Asignacionficha(int contador, char tablero[9], int lugar_ocupado[9], int respuesta) //Asinga la ficha a donde quiere el usuario.
{
    if (respuesta == 0)
    {
        contador=10;
    }
    else if (lugar_ocupado[respuesta-1]==0)
    {
        if (contador%2==0)
        {
            tablero[respuesta-1]='X';
        }
        else
        {
            tablero[respuesta-1]='O';
        }
        lugar_ocupado[respuesta-1]=1;
        contador++;
    }
    else { contador==contador; }
    return contador;
}


