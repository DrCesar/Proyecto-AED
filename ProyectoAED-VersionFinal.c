/*Programa Final Algoritmos y Estructuras de Datos
Grupo #6

Pablo Muñoz
Josué Cifuentes
Marcel Velasquez
Josué Jacobs

Algoritmo para que un ActivityBot puede ingresar y salir de un laberinto rápidamente.
Se utilizan matrices y vectores para poder navegar en el laberinto y saber
por donde ya a pasado el robot.

*/

#include "simpletools.h"                      // Include simpletools header
#include "abdrive.h"                          // Include abdrive header
#include "ping.h"                             // Include ping header


//Variables para la navegación del robot.
int turn, sFront, sRight,cont;                                     


//Variables para el manejo de la matriz del laberinto y el vector de direccines.
int maze[50][50];
int dir[50];
int spd,spx, spy, band;
int contDis;


/*
Metodo en el cual se hace push al vector dir.
*/
void push(int info){
  dir[spd] = info;
  spd++;
}  


/*
Metodo en el cual se hace pop del vector dir.
*/
int pop(){
  spd--;
  return dir[spd];
}  


/*
Metodo en el cual se modifica al matriz maze para saber cuantas veces ha pasado el robot
por una posición. Cada vez que el robot se mueve a una casilla nueva se llama a este metodo
y a esta casilla se incrementa el contador por 1.
*/
void incCont(){
  maze[spx][spy]= maze[spx][spy]+1;
}  


/*
Metodo donde se incrementa la coordenada segun para donde se este moviendo el carrito.
Estas coordenadas sirven para guardar la info en la matriz maze.
*/
int incCoorde(){
  if(band == 0){
    spy++;
  }    
  if(band == 1){
    spx++;
  }
  if(band == 2){
    spy--;
  }
  if(band == 3){
    spx--;
  }  
}  



int main()                                    // main function
{
  //Se hace una pausa de 1 seg para poder colcar el robot en el lugar adecuado.
  pause(1000);
 
  //Se inicializan las Variables.
  spx = 25;
  spy = 0;
  band = 0;
  
  //While infinito que es donde se mueve al robot.
  while(1)
  {                       
    //Se inicializan las variables de los sensores derecho y frontal.
    sFront = ping_cm(8);
    sRight = ping_cm(10);
    contDis = 0;
    
    
    //While en el cual se mueve al robot hacia enfrente mientras no encuentre un cruze o tenga pared cerca enfrente.
    while(sFront >= 10 && sRight < 25)
    {
      sFront = ping_cm(8);
      sRight = ping_cm(10); 
      
      drive_ramp(50,50);
         
      //Cada vez que el robot recorre 1 casilla se llama incrementa el contador en la matriz maze.   
      if(contDis == 50){       
        incCoorde();
        incCont();
        contDis = 0;
      }else{
        contDis++;
      }   
      
      pause(5);            
    }
   
  
    //El robot cruza a la izquierda
    if(sRight < 25)
    {
      drive_speed(-30,30);
      cont = 0;
      while(cont < 97)
      {
        cont++;  
        pause(5);
      }        
      
      //Se le dice a la bandera que se hizo un cruce a la izquierda.
      band = band + 3;
      band = band % 4;             
        
    }else{
    //El robot cruza a la derecha.
      cont = 0;
      while(cont < 160)
      {
        drive_ramp(30,30);
        cont++;  
        pause(5);
      }
      
      
      drive_speed(30,-30);
      cont = 0;
      while(cont < 148)
      {
        cont++;  
        pause(5);
      }
      
      
      drive_speed(50,50);  
      cont = 0;
      while(cont < 180)
      {
        cont++;  
        pause(5);
      }    
      
      //Se le dice a la bandera que se hizo un cruce a la derecha.
      band++;
      band = band % 4;
    }      
 
 
 
  }  //Regresa al while infinito.     
                         
}


