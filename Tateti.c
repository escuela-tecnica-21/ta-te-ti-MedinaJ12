// MEDINA, LUCAS NAHUEL
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// Declaracion funciones
int ganador_O(char tablero[9], int o[9], int lugar_ocupado[9]);
int ganador_X(char tablero[9], int x[9], int lugar_ocupado[9]);
int Pregunta_y_respuesta_usuario();
int igualar_cero_variables(int x[9], int o[9], int lugar_ocupado[9]);
int Asignacionficha(int contador, char tablero[9], int lugar_ocupado[9], int respuesta);
int Verificaciondeganador (char tablero[] , char ficha, int a, int b, int c);
int Yaexisteganador (char tablero[]);
void empate_X(char tablero[9], int contador, int o[9], int lugar_ocupado[9], int numero_aleatorio);
void empate_O(char tablero[9], int contador, int x[9], int lugar_ocupado[9], int numero_aleatorio);
void dibujo_tablero(char tablero[9]);
void empataroganar_x(char tablero[9], int contador, int x[9], int o[9], int lugar_ocupado[9], int numero_aleatorio);
void empataroganar_y(char tablero[9], int contador, int x[9], int o[9], int lugar_ocupado[9], int numero_aleatorio);

int const posibilidades[][3] = {{0,1,2},{3,4,5},{6,7,8},{0,4,8},{2,4,6},{0,3,6},{1,4,7},{2,5,8}};

int main()
{
    int contador = 0, x[9], o[9], lugar_ocupado[9], numero_aleatorio, respuesta;
    char tablero[9]= "";
    srand(time(NULL)); // funcion para numeros aleatorios segun el caso.
    igualar_cero_variables(x, o, lugar_ocupado); // Funcion que iguala a cero las variables.
    while (contador<9) // While que cumple la funcion de ciclo para el ingreso de dato del usuario.
    {
        dibujo_tablero(tablero);
        respuesta = Pregunta_y_respuesta_usuario();
        contador = Asignacionficha(contador, tablero, lugar_ocupado, respuesta);
        system("cls");
    }
    while (Yaexisteganador(tablero)!=1)
    {
         if (contador%2==0) // Si es turno de la X
        {
            empataroganar_x(tablero, contador, x, o, lugar_ocupado, numero_aleatorio);  // Decide donde colocar la siguiente ficha, y si es posible ganar o bloquear en el turno de X
        }
        else // Si es turno de la O.
        {
            empataroganar_o(tablero, contador, x, o, lugar_ocupado, numero_aleatorio); // Decide donde colocar la siguiente ficha, y si es posible ganar o bloquear en el turno de O
        }
        system("cls");
        dibujo_tablero(tablero);
    }
    return 0;
}

int Yaexisteganador (char tablero[])
{
    for (int x=0; x<8; x++)
    {
        if (Verificaciondeganador(tablero, 'X',posibilidades[x][0], posibilidades[x][1], posibilidades[x][2])==3)
        {
            printf("\n\n EL GANADOR ES EL JUGADOR X");
            return 1;
        }
        if (Verificaciondeganador(tablero, 'O', posibilidades[x][0], posibilidades[x][1], posibilidades[x][2])==3)
        {
            return 1;
            printf("\n\n EL GANADOR ES EL JUGADOR O");
        }
    }
    return 0;
}
int Verificaciondeganador (char tablero[] , char ficha, int a, int b, int c)
{
    int contador=0;
    if (tablero[a]==ficha) {contador++;}
    if (tablero[b]==ficha) {contador++;}
    if (tablero[c]==ficha) {contador++;}
    return contador;
}
int ganador_O(char tablero[9], int o[9], int lugar_ocupado[9]) // Analiza el caso y devuelve 1 si es posible ganar en el turno de la X
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
    else if (o[3]==o[4] || o[4]==o[5] || o[5]==o[3])
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
    else if (o[6]==o[7] || o[8]==o[7] || o[6]==o[8])
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
    else if (o[0]==o[3] || o[6]==o[3] || o[0]==o[6])
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
    else if (o[1]==o[4] || o[4]==o[7] || o[1]==o[7])
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
    else if (o[2]==o[5] || o[5]==o[8] || o[2]==o[8])
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
    else if (o[0]==o[4] || o[4]==o[8] || o[0]==o[8])
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
    else if (o[2]==o[4] || o[4]==o[6] || o[2]==o[6])
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
int ganador_X(char tablero[9], int x[9], int lugar_ocupado[9]) // Analiza el caso y devuelve 1 si es posible ganar en el turno de la O
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
    else if (x[3]==x[4] || x[4]==x[5] || x[5]==x[3])
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
    else if (x[6]==x[7] || x[8]==x[7] || x[6]==x[8])
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
    else if (x[0]==x[3] || x[6]==x[3] || x[0]==x[6])
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
    else if (x[1]==x[4] || x[4]==x[7] || x[1]==x[7])
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
    else if (x[2]==x[5] || x[5]==x[8] || x[2]==x[8])
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
    else if (x[0]==x[4] || x[4]==x[8] || x[0]==x[8])
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
    else if (x[2]==x[4] || x[4]==x[6] || x[2]==x[6])
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
void empate_X(char tablero[9], int contador, int o[9], int lugar_ocupado[9], int numero_aleatorio) // Analiza el caso y devuelve 1 si es posible empatar en el turno de la X
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
    else if (o[3]==o[4] || o[4]==o[5] || o[5]==o[3])
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
    else if (o[6]==o[7] || o[8]==o[7] || o[6]==o[8])
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
    else if (o[0]==o[3] || o[6]==o[3] || o[0]==o[6])
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
    else if (o[1]==o[4] || o[4]==o[7] || o[1]==o[7])
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
    else if (o[2]==o[5] || o[5]==o[8] || o[2]==o[8])
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
    else if (o[0]==o[4] || o[4]==o[8] || o[0]==o[8])
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
    else if (o[2]==o[4] || o[4]==o[6] || o[2]==o[6])
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
void empate_O(char tablero[9], int contador, int x[9], int lugar_ocupado[9], int numero_aleatorio) // Analiza el caso y devuelve 1 si es posible empatar en el turno de la O
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
     else if (x[3]==x[4] || x[4]==x[5] || x[5]==x[3])
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
     else if (x[6]==x[7] || x[8]==x[7] || x[6]==x[8])
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
     else if (x[0]==x[3] || x[6]==x[3] || x[0]==x[6])
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
     else if (x[1]==x[4] || x[4]==x[7] || x[1]==x[7])
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
     else if (x[2]==x[5] || x[5]==x[8] || x[2]==x[8])
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
     else if (x[0]==x[4] || x[4]==x[8] || x[0]==x[8])
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
     else if (x[2]==x[4] || x[4]==x[6] || x[2]==x[6])
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
void dibujo_tablero(char tablero[9]) // Funcion la cual dibuja el tablero
{
    printf(" %c | %c | %c \n---+---+---\n %c | %c | %c\n---+---+---\n %c | %c | %c\n",tablero[0],tablero[1],tablero[2],tablero[3],tablero[4],tablero[5],tablero[6],tablero[7],tablero[8]);
}
int igualar_cero_variables(int x[9], int o[9], int lugar_ocupado[9]) // Iguala a cero las variables
{
    for (int y=0;y<9;y++)
    {
        x[y]=y+1;
        o[y]=y+1;
        lugar_ocupado[y]=0;
    }
}
int Pregunta_y_respuesta_usuario () // Realiza la pregunta de a donde quiere posicionar al usuario
{
    int respuesta;
    gotoxy(1,7); printf("INGRESE UN ENTERO DEL 1 AL 9 PARA MARCAR CASILLERO.  SI DESEA TERMINAR DE PLANTEAR LA JUGADA, PRESIONE '0'.\n¿ DONDE DESEA COLOCAR LA O ? = "); scanf("%d",&respuesta);
    return respuesta;
}
int Asignacionficha(int contador, char tablero[9], int lugar_ocupado[9], int respuesta) // Todo lo relacionado al turno de la X
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



void empataroganar_x(char tablero[9], int contador, int x[9], int o[9], int lugar_ocupado[9], int numero_aleatorio) // Decide si es conveniente bloquear o jugar a ganar en el turno de la X
{
    if (ganador_X(tablero, x, lugar_ocupado)==1)
    {
        ganador_X(tablero, x, lugar_ocupado);
    }
    else
    {
        empate_X(tablero, contador, o, lugar_ocupado, numero_aleatorio);
    }
}

void empataroganar_o(char tablero[9], int contador, int x[9], int o[9], int lugar_ocupado[9], int numero_aleatorio) // Decide si es conveniente bloquear o jugar a ganar en el turno de la X
{
    if (ganador_O(tablero, o, lugar_ocupado)==1)
    {
        ganador_O(tablero, o, lugar_ocupado);
    }
    else
    {
        empate_O(tablero, contador, x, lugar_ocupado, numero_aleatorio);
    }
}
