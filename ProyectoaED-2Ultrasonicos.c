/*
  Detect and Turn from Obstacle.c

  Detect obstacles in the ActivityBot's path, and turn a random direction to avoid them.

  http://learn.parallax.com/activitybot/roaming-ultrasound
*/

#include "simpletools.h"                      // Include simpletools header
#include "abdrive.h"                          // Include abdrive header
#include "ping.h"                             // Include ping header

int turn, sFront, sRight,cont,numVeces;                                     // Navigation variable

int main()                                    // main function
{
  pause(1000);
  //low(27);
  

  while(1)
  {                       // Forward 2 RPS
    sFront = ping_cm(8);
    sRight = ping_cm(10);
    
    while(sFront >= 10 && sRight < 19)
    {
      sFront = ping_cm(8);
      sRight = ping_cm(10); 
      drive_ramp(50,50);
      pause(5);           // Wait until object in range
    }
    
    
    /*drive_ramp(20,20);
    cont = 0;
    while(cont < 20)
    {
      cont++;  
      pause(5);
    }*/
  
  
  
    if(sRight < 19)
    {
      drive_speed(-30,30);
      cont = 0;
      while(cont < 97)
      {
        cont++;  
        pause(5);
      }                            
        
    }else{
      
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
    }      
 
 
 
  }       
                         
}


