// MEDINA, LUCAS NAHUEL
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
char tablero[9]= "";
int contador,x[9],o[9],lugar_ocupado[9], numero_aleatorio;
char respuesta;
int main()
{
    srand(time(NULL)); // funcion para numeros aleatorios segun el caso.
    igualar_cero_variables(); // Funcion que iguala a cero las variables.
    while (contador<9) // While que cumple la funcion de ciclo para el ingreso de dato del usuario.
    {
        if (contador%2==0)
        {
            system("cls");
            dibujo_tablero(); // Funcion que dibuja el tablero.
            Pregunta_y_respuesta_usuario(); // Variable la cual le pregunta al usuario donde ubicar la ficha, terminar de armar el tablero, y recibe la respuesta del usuario.
            if (Analizar_respuesta_usuario_x()==1) // Si la respuesta esta dentro de los terminos del 1 al 9
            {
                contador++;
            }
            else if (Analizar_respuesta_usuario_x()==2) // Si el usuario ingreso 0.
            {
                contador=10;
            }
            else
            {
                contador=contador; // En caso de que ninguna de las anteriores condiciones se cumplen.
            }
        }
        else
        {
            system("cls");
            dibujo_tablero();
            Pregunta_y_respuesta_usuario()
            if (Analizar_respuesta_usuario_o()==1)
            {
                contador++;
            }
            else if (Analizar_respuesta_usuario_o()==2)
            {
                contador=10;
            }
            else
            {
                contador=contador;
            }
        }
    }
    // ------------------------
    if (contador%2==0) // Si es turno de la X
    {
        if (ganador_X()==1)
        {
            ganador_X();
        }
        else
        {
            empate_X();
        }
    }
    else // Si es turno de la O.
    {
        if (ganador_O()==1)
        {
            ganador_O();
        }
        else
        {
            empate_O();
        }
    }
    system("cls");
    dibujo_tablero();
}

int ganador_O() //
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
int ganador_X()
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
void empate_X() //
{
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
       numero_aleatorio= rand() % 9;
       if (lugar_ocupado[numero_aleatorio] != 1)
       {
           tablero[numero_aleatorio] = 'O';
       }
    }
}
void empate_O()
{
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
    else if (contador%2!=0)
    {
       numero_aleatorio= rand() % 9;
       if (lugar_ocupado[numero_aleatorio] != 1)
       {
           tablero[numero_aleatorio] = 'O';
       }
    }
}
void dibujo_tablero()
{
    printf(" %c | %c | %c \n---+---+---\n %c | %c | %c\n---+---+---\n %c | %c | %c\n",tablero[0],tablero[1],tablero[2],tablero[3],tablero[4],tablero[5],tablero[6],tablero[7],tablero[8]);
}
void igualar_cero_variables()
{
    for (int y=0;y<9;y++)
    {
        x[y]=y+1;
        o[y]=y+1;
        lugar_ocupado[y]=0;
        contador=0;
    }
}
int Analizar_respuesta_usuario_o()
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
int Analizar_respuesta_usuario_x()
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
void Pregunta_y_respuesta_usuario ()
{
    gotoxy(1,7); printf("INGRESE UN ENTERO DEL 1 AL 9 PARA MARCAR CASILLERO.  SI DESEA TERMINAR DE PLANTEAR LA JUGADA, PRESIONE '0'.\n¿ DONDE DESEA COLOCAR LA O ? = "); scanf("%d",&respuesta);
}
