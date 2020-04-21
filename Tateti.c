// MEDINA, LUCAS NAHUEL
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int ganador_O(char tablero[9]);
int ganador_X(char tablero[9]);
int igualar_cero_variables();
int Analizar_respuesta_usuario_o(char tablero[9]);
int Analizar_respuesta_usuario_x(char tablero[9]);
int juego_x(int contador, char tablero[9]);
int juego_o(int contador, char tablero[9]);
void empate_X(char tablero[9], int contador);
void empate_O(char tablero[9], int contador);
void dibujo_tablero(char tablero[9]);
void verificacion_juego_x(char tablero[9], int contador);
void verificacion_juego_y(char tablero[9], int contador);

int x[9],o[9],lugar_ocupado[9], numero_aleatorio;
int respuesta;

int main()
{
    int contador = 0;
    char tablero[9]= "";
    srand(time(NULL)); // funcion para numeros aleatorios segun el caso.
    igualar_cero_variables(); // Funcion que iguala a cero las variables.
    while (contador<9) // While que cumple la funcion de ciclo para el ingreso de dato del usuario.
    {
        if (contador%2==0)
        {
            contador = juego_x(contador, tablero); // juego_x es una funcion que se encarga todo sobre el juego en el turno de X, dode posicionar la x, la opcion del usuario, preguntas, etc.
        }
        else
        {
            contador = juego_o(contador, tablero);
        }
    }
    // ------------------------
    if (contador%2==0) // Si es turno de la X
    {
        verificacion_juego_x(tablero, contador);
    }
    else // Si es turno de la O.
    {
        verificacion_juego_y(tablero, contador);
    }
    system("cls");
    dibujo_tablero(tablero);
}

int ganador_O(char tablero[9]) //
{
    if (o[1]==o[0] || o[1]==o[2] || o[0]==o[2])
    {
       for (int a=0;a<3;a++)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='O';
                return 1;
                break;
            }
        }
    }
    if (o[3]==o[4] || o[4]==o[5] || o[5]==o[3])
    {

       for (int a=0;a<3;a++)
        {
            switch (lugar_ocupado[a+3])
            {
            case 0:
                tablero[a+3]='O';
                return 1;
                break;
            }
        }
    }
    if (o[6]==o[7] || o[8]==o[7] || o[6]==o[8])
    {
       for (int a=0;a<3;a++)
        {
            switch (lugar_ocupado[a+6])
            {
            case 0:
                tablero[a+6]='O';
                return 1;
                break;
            }
        }
    }
    if (o[0]==o[3] || o[6]==o[3] || o[0]==o[6])
    {
       for (int a=0;a<9;a=a+3)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='O';
                return 1;
                break;
            }
        }
    }
    if (o[1]==o[4] || o[4]==o[7] || o[1]==o[7])
    {
       for (int a=1;a<9;a=a+3)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='O';
                return 1;
                break;
            }
        }
    }
    if (o[2]==o[5] || o[5]==o[8] || o[2]==o[8])
    {
       for (int a=2;a<9;a=a+3)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='O';
                return 1;
                break;
            }
        }
    }
    if (o[0]==o[4] || o[4]==o[8] || o[0]==o[8])
    {
       for (int a=0;a<9;a=a+4)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='O';
                return 1;
                break;
            }
        }
    }
    if (o[2]==o[4] || o[4]==o[6] || o[2]==o[6])
    {
       for (int a=2;a<9;a=a+2)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='O';
                return 1;
                break;
            }
        }
    }
}
int ganador_X(char tablero[9])
{
    if (x[1]==x[0] || x[1]==x[2] || x[0]==x[2])
    {
       for (int a=0;a<3;a++)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='X';
                return 1;
                break;
            }
        }
    }
    if (x[3]==x[4] || x[4]==x[5] || x[5]==x[3])
    {

       for (int a=0;a<3;a++)
        {
            switch (lugar_ocupado[a+3])
            {
            case 0:
                tablero[a+3]='X';
                return 1;
                break;
            }
        }
    }
    if (x[6]==x[7] || x[8]==x[7] || x[6]==x[8])
    {
       for (int a=0;a<3;a++)
        {
            switch (lugar_ocupado[a+6])
            {
            case 0:
                tablero[a+6]='X';
                return 1;
                break;
            }
        }
    }
    if (x[0]==x[3] || x[6]==x[3] || x[0]==x[6])
    {
       for (int a=0;a<9;a=a+3)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='X';
                return 1;
                break;
            }
        }
    }
    if (x[1]==x[4] || x[4]==x[7] || x[1]==x[7])
    {
       for (int a=1;a<9;a=a+3)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='X';
                return 1;
                break;
            }
        }
    }
    if (x[2]==x[5] || x[5]==x[8] || x[2]==x[8])
    {
       for (int a=2;a<9;a=a+3)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='X';
                return 1;
                break;
            }
        }
    }
    if (x[0]==x[4] || x[4]==x[8] || x[0]==x[8])
    {
       for (int a=0;a<9;a=a+4)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='X';
                return 1;
                break;
            }
        }
    }
    if (x[2]==x[4] || x[4]==x[6] || x[2]==x[6])
    {
       for (int a=2;a<9;a=a+2)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='X';
                return 1;
                break;
            }
        }
    }
}
void empate_X(char tablero[9], int contador) //
{
    int repetir = 0;
    if (o[1]==o[0] || o[1]==o[2] || o[0]==o[2])
    {
       for (int a=0;a<3;a++)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='X';
                break;
            }
        }
    }
    if (o[3]==o[4] || o[4]==o[5] || o[5]==o[3])
    {

       for (int a=0;a<3;a++)
        {
            switch (lugar_ocupado[a+3])
            {
            case 0:
                tablero[a+3]='X';
                break;
            }
        }
    }
    if (o[6]==o[7] || o[8]==o[7] || o[6]==o[8])
    {
       for (int a=0;a<3;a++)
        {
            switch (lugar_ocupado[a+6])
            {
            case 0:
                tablero[a+6]='X';
                break;
            }
        }
    }
    if (o[0]==o[3] || o[6]==o[3] || o[0]==o[6])
    {
       for (int a=0;a<9;a=a+3)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='X';
                break;
            }
        }
    }
    if (o[1]==o[4] || o[4]==o[7] || o[1]==o[7])
    {
       for (int a=1;a<9;a=a+3)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='X';
                break;
            }
        }
    }
    if (o[2]==o[5] || o[5]==o[8] || o[2]==o[8])
    {
       for (int a=2;a<9;a=a+3)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='X';
                break;
            }
        }
    }
    if (o[0]==o[4] || o[4]==o[8] || o[0]==o[8])
    {
       for (int a=0;a<9;a=a+4)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='X';
                break;
            }
        }
    }
    if (o[2]==o[4] || o[4]==o[6] || o[2]==o[6])
    {
       for (int a=2;a<9;a=a+2)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='X';
                break;
            }
        }
    }
    else if (contador%2==0)
    {
        while (repetir==0)
        {
            numero_aleatorio=rand() % 9;
            if (lugar_ocupado[numero_aleatorio] != 1)
            {
                tablero[numero_aleatorio] = 'X';
                repetir++;
            }
        }
    }
}
void empate_O(char tablero[9], int contador)
{
    int repetir = 0;
    if (x[1]==x[0] || x[1]==x[2] || x[0]==x[2])
    {
       for (int a=0;a<3;a++)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='O';
                break;
            }
        }
    }
     if (x[3]==x[4] || x[4]==x[5] || x[5]==x[3])
    {

       for (int a=0;a<3;a++)
        {
            switch (lugar_ocupado[a+3])
            {
            case 0:
                tablero[a+3]='O';
                break;
            }
        }
    }
     if (x[6]==x[7] || x[8]==x[7] || x[6]==x[8])
    {
       for (int a=0;a<3;a++)
        {
            switch (lugar_ocupado[a+6])
            {
            case 0:
                tablero[a+6]='O';
                break;
            }
        }
    }
     if (x[0]==x[3] || x[6]==x[3] || x[0]==x[6])
    {
       for (int a=0;a<9;a=a+3)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='O';
                break;
            }
        }
    }
     if (x[1]==x[4] || x[4]==x[7] || x[1]==x[7])
    {
       for (int a=1;a<9;a=a+3)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='O';
                break;
            }
        }
    }
     if (x[2]==x[5] || x[5]==x[8] || x[2]==x[8])
    {
       for (int a=2;a<9;a=a+3)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='O';
                break;
            }
        }
    }
     if (x[0]==x[4] || x[4]==x[8] || x[0]==x[8])
    {
       for (int a=0;a<9;a=a+4)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='O';
                break;
            }
        }
    }
     if (x[2]==x[4] || x[4]==x[6] || x[2]==x[6])
    {
       for (int a=2;a<9;a=a+2)
        {
            switch (lugar_ocupado[a])
            {
            case 0:
                tablero[a]='O';
                break;
            }
        }
    }
     else if (contador%2!=0)
    {
        while (repetir==0)
        {
            numero_aleatorio= rand() % 9;
            if (lugar_ocupado[numero_aleatorio] != 1)
            {
                tablero[numero_aleatorio] = 'O';
                repetir++;
            }
        }
    }
}
void dibujo_tablero(char tablero[9])
{
    printf(" %c | %c | %c \n---+---+---\n %c | %c | %c\n---+---+---\n %c | %c | %c\n",tablero[0],tablero[1],tablero[2],tablero[3],tablero[4],tablero[5],tablero[6],tablero[7],tablero[8]);
}
int igualar_cero_variables()
{
    for (int y=0;y<9;y++)
    {
        x[y]=y+1;
        o[y]=y+1;
        lugar_ocupado[y]=0;
    }
}
int Analizar_respuesta_usuario_o(char tablero[9])
{
    if (respuesta == 0)
    {
        return 2;
    }
    else if (lugar_ocupado[respuesta-1]==0 && respuesta > 0 && respuesta < 10)
    {
        tablero[respuesta-1]= 'O';
        lugar_ocupado[respuesta-1]=1;
        o[respuesta-1]=14;
        return 1;
    }
    else
    {
        return 0;
    }
}
int Analizar_respuesta_usuario_x(char tablero[9])
{
    if (respuesta== 0)
    {
        return 2;
    }
    if (lugar_ocupado[respuesta-1]==0 && respuesta > 0 && respuesta < 10)
    {
        tablero[respuesta-1]= 'X';
        lugar_ocupado[respuesta-1]=1;
        x[respuesta-1]=13;
        return 1;
    }
    else
    {
        return 0;
    }
}
int Pregunta_y_respuesta_usuario ()
{
    gotoxy(1,7); printf("INGRESE UN ENTERO DEL 1 AL 9 PARA MARCAR CASILLERO.  SI DESEA TERMINAR DE PLANTEAR LA JUGADA, PRESIONE '0'.\n¿ DONDE DESEA COLOCAR LA O ? = "); scanf("%d",&respuesta);
    return respuesta;
}

int juego_x(int contador, char tablero[9])
{
    system("cls");
    dibujo_tablero(tablero); // Funcion que dibuja el tablero.
    Pregunta_y_respuesta_usuario(); // Variable la cual le pregunta al usuario donde ubicar la ficha, terminar de armar el tablero, y recibe la respuesta del usuario.
    if (Analizar_respuesta_usuario_x(tablero)==1) // Si la respuesta esta dentro de los terminos del 1 al 9
    {
        contador++;
    }
    else if (Analizar_respuesta_usuario_x(tablero)==2) // Si el usuario ingreso 0.
    {
        contador=contador+10;
    }
    else
    {
        contador=contador; // En caso de que ninguna de las anteriores condiciones se cumplen.
    }
    return contador;
}

int juego_o(int contador, char tablero[9])
{
    system("cls");
    dibujo_tablero(tablero);
    Pregunta_y_respuesta_usuario();
    if (Analizar_respuesta_usuario_o(tablero)==1)
    {
        contador++;
    }
    else if (Analizar_respuesta_usuario_o(tablero)==2)
    {
        contador=contador+10;
    }
    else
    {
        contador=contador;
    }
    return contador;
}

void verificacion_juego_x(char tablero[9], int contador)
{
    if (ganador_X(tablero)==1)
    {
        ganador_X(tablero);
    }
    else
    {
        empate_X(tablero, contador);
    }
}

void verificacion_juego_y(char tablero[9], int contador)
{
    if (ganador_O(tablero)==1)
    {
        ganador_O(tablero);
    }
    else
    {
        empate_O(tablero, contador);
    }
}
