

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_CHILD 3

struct jugador {
    int apuesta,ganancias,partidasGanadas,vecesPlantado,vecesRetirado;
    bool plantado;
    bool retirado;
    float sumaPuntos;
    
};

struct jugador jugadores[NUM_CHILD];


int main(void)
{
    pid_t pidC;
    int fd[2];
    int mainLoop = 0;
    float aux;
    int jugadoresRetirados;
    int jugadoresPlantados;
    int jugadoresFueraDeJuego;
    
    mainWhileLoop:
    while(mainLoop == 0){ //Loop infinito para que el juego no corte.
            
            
        
        
        wait(NULL);
        pidC = fork();
        
        if (pidC == 0){ //Proceso hijo
            
            if(jugadoresFueraDeJuego == NUM_CHILD){
            printf("\nLa banca gana\n");
            for(int i=0 ; i<=NUM_CHILD ; i++ ){
                jugadores[i].sumaPuntos = 0;    //Reiniciamos los puntos de todos los jugadores.
                jugadores[i].retirado = 0;
                jugadores[i].plantado = 0;
                jugadores[i].apuesta = 0;
                close(fd[0]);
                write(fd[1], &jugadores[i].sumaPuntos, sizeof(jugadores[i].sumaPuntos));
                close(fd[1]);
                write(fd[1], &jugadores[i].retirado, sizeof(jugadores[i].retirado));
                close(fd[1]);
                write(fd[1], &jugadores[i].plantado, sizeof(jugadores[i].plantado));
                close(fd[1]);
                write(fd[1], &jugadores[i].apuesta, sizeof(jugadores[i].apuesta));
                close(fd[1]);
               }
            jugadoresFueraDeJuego = 0;
            jugadoresPlantados = 0;
            jugadoresRetirados = 0;
            write(fd[1], &jugadoresFueraDeJuego, sizeof(jugadoresFueraDeJuego));
            close(fd[1]);
            write(fd[1], &jugadoresPlantados, sizeof(jugadoresPlantados));
            close(fd[1]);
            write(fd[1], &jugadoresRetirados, sizeof(jugadoresRetirados));
            close(fd[1]);
            close(fd[0]);
            goto mainWhileLoop;   
        }
            
            forLoop:
            for(int i=0 ; i<=NUM_CHILD ; i++ ){
                
                sleep (1);
            
                srand(time(0));
                int carta;
                int respuesta;
                float puntos;
                int menuLoop = 0;
                
                if (i == NUM_CHILD && jugadores[i].sumaPuntos < 7.5){    //el ultimo numero representa a la banca
                    carta = rand() %12 +1;
                    float puntos;
                    
                        if (carta > 7){
                            puntos = 0.5;
                        }
                        else{
                           puntos = carta;
                        }
                        jugadores[i].sumaPuntos = jugadores[i].sumaPuntos + puntos;
                        //printf("\nBanca - Puntaje: %f\n\n", jugadores[i].sumaPuntos);
                        goto mainWhileLoop;
                    }
                
                
                if(jugadores[i].retirado == 1){
                    jugadores[i].sumaPuntos == 0;   //Si esta retirado, fijamos los puntos en 0 y volvemos al mainLoop.
                    goto forLoop;
                }
                else if(jugadores[i].plantado == 1){
                    goto forLoop;  //Si esta plantado, dejamos los puntos como estan y volvemos al mainLoop.
                }
                
                while (menuLoop == 0){
                    printf("Jugador %d, elija una opcion: \n", i);
                    printf("1.Recibir carta\n2.Plantarse\n3.Retirarse\n\nOpcion: ");
                    scanf("%d", &respuesta);
                    if (respuesta > 0 && respuesta < 4){
                        menuLoop++;
                        }
                    else{
                        printf ("\nElija una opcion correcta.\n\n");
                    }
                }
                 
                switch(respuesta){
                        case 1:
                        
                        if (jugadores[i].apuesta == 0){
                            
                        
                            printf ("ingrese su apuesta: ");
                            scanf("%d", &jugadores[i].apuesta);
                            carta = rand() %12 +1;
                        
                            if (carta > 7){
                                puntos = 0.5;
                            }
                            else{
                               puntos = carta;
                            }
                            printf("\n");
                        }    
                    
                    
                        jugadores[i].sumaPuntos = jugadores[i].sumaPuntos + puntos;
                    
                        close(fd[0]);
                        write(fd[1], &jugadores[i].sumaPuntos , sizeof(jugadores[i].sumaPuntos));
                        close(fd[1]);
                        printf("Jugador % d - Puntaje: %f \n\n", i , jugadores[i].sumaPuntos);
                        sleep(1);
                        system("clear");
                        
                        
                        
                        
                        break;
                        
                    case 2:
                        jugadores[i].plantado = 1;
                        jugadores[i].vecesPlantado++;
                        jugadoresPlantados++;
                        jugadoresFueraDeJuego++;
                        close(fd[0]);
                        write(fd[1], &jugadores[i].plantado , sizeof(jugadores[i].plantado));
                        close(fd[1]);
                        write(fd[1], &jugadoresPlantados, sizeof(jugadoresPlantados));
                        close(fd[1]);
                        write(fd[1], &jugadoresFueraDeJuego, sizeof(jugadoresFueraDeJuego));
                        close(fd[1]);
                        system("clear");
                        break;
                    case 3:
                        jugadores[i].retirado = 1;
                        jugadores[i].vecesRetirado++;
                        jugadoresRetirados++;
                        jugadoresFueraDeJuego++;
                        close(fd[0]);
                        write(fd[1], &jugadores[i].retirado , sizeof(jugadores[i].retirado));
                        close(fd[1]);
                        write(fd[1], &jugadoresRetirados, sizeof(jugadoresRetirados));
                        close(fd[1]);
                        write(fd[1], &jugadoresFueraDeJuego, sizeof(jugadoresFueraDeJuego));
                        close(fd[1]);
                        system("clear");
                        break;
                    }
                
            }
            exit(0);
                
        }
        
        else if (pidC > 0){ //Proceso padre
            close(fd[1]);
            read(fd[0], &aux , sizeof(aux));
            
            for (int i=0 ; i<NUM_CHILD ; i++){
                printf("Jugador %d | Partidas ganadas: %d | Veces plantado: %d | Veces retirado: %d\n", i, jugadores[i].partidasGanadas, jugadores[i].vecesPlantado, jugadores[i].vecesRetirado);
            }
            printf("\n");
            
            for (int i=0 ; i<=NUM_CHILD ; i++){
                if(i == NUM_CHILD){
                    printf("Banca - Puntaje: %f \n\n", jugadores[i].sumaPuntos);
                }
                else{
                printf("Jugador % d - Puntaje: %f \n\n", i , jugadores[i].sumaPuntos);
                }
            }
            
            if(jugadores[NUM_CHILD].sumaPuntos == 7.5){
                printf("\nLa banca gana\n");
            }
            else{
                int ganadores = 0;
               for (int i=0 ; i<=NUM_CHILD ; i++){
                    
                    if(jugadores[i].sumaPuntos == 7.5){
                        printf("Jugador %d: Ganador de esta ronda\n",i);
                        printf("\nHa ganado %d\n", jugadores[i].apuesta*2);
                        ganadores++;
                        jugadores[i].partidasGanadas++;
                    }
                }
            if (ganadores == 0 && jugadores[NUM_CHILD].sumaPuntos > 7.5){
                for (int i=0 ; i<=NUM_CHILD ; i++){
                    if(jugadores[i].sumaPuntos < 7.5){
                        printf("Jugador %d: Ganador de esta ronda\n",i);
                        printf("\nHa ganado %d\n", jugadores[i].apuesta*2);
                        jugadores[i].partidasGanadas++;
                    }
                }
            }
            
            }       
            
            if (jugadores[NUM_CHILD].sumaPuntos >= 7.5){
                for(int i=0 ; i<=NUM_CHILD ; i++ ){
                jugadores[i].sumaPuntos = 0;    //Reiniciamos los puntos de todos los jugadores.
                jugadores[i].retirado = 0;
                jugadores[i].plantado = 0;
                jugadores[i].apuesta = 0;
                close(fd[0]);
                write(fd[1], &jugadores[i].sumaPuntos, sizeof(jugadores[i].sumaPuntos));
                close(fd[1]);
                write(fd[1], &jugadores[i].retirado, sizeof(jugadores[i].retirado));
                close(fd[1]);
                write(fd[1], &jugadores[i].plantado, sizeof(jugadores[i].plantado));
                close(fd[1]);
                write(fd[1], &jugadores[i].apuesta, sizeof(jugadores[i].apuesta));
                close(fd[1]);
               }
            jugadoresFueraDeJuego = 0;
            jugadoresPlantados = 0;
            jugadoresRetirados = 0;
            write(fd[1], &jugadoresFueraDeJuego, sizeof(jugadoresFueraDeJuego));
            close(fd[1]);
            write(fd[1], &jugadoresPlantados, sizeof(jugadoresPlantados));
            close(fd[1]);
            write(fd[1], &jugadoresRetirados, sizeof(jugadoresRetirados));
            close(fd[1]);
            close(fd[0]);
            goto mainWhileLoop;   
        } 
            }   
            
           
        
        else{
            printf("\nHa ocurrido un error.\n\n");
            continue;
        }
        
        
    }
    return 0;
}





