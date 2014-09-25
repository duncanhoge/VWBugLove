/* Include 1Sheeld library. */
#include <OneSheeld.h>
#include <Button.h>


/* Define LEDs */
int firstLED = 7;
int secondLED = 8;
int thirdLED = 9;

/* Physical Button */
//hopefully can get OneSheeld to do this
Button button = Button(12,PULLUP);

void setup()
{
  /* Start communication. */
  OneSheeld.begin(); //currently not needed.
  /* Set the LED pin as output. */
  pinMode(firstLED,OUTPUT);
  pinMode(secondLED,OUTPUT);
  pinMode(thirdLED,OUTPUT);
}

/*GOAL: toggle light on and off, esp in succession for two leds*/
/*ToggleButton may be the way to go.*/

byte pressCount = 0;
void loop(){

  if (button.uniquePress())  
    
    pressCount++;
  
    switch(pressCount)
        
        { case 1:
          
            digitalWrite(firstLED,HIGH);
            digitalWrite(thirdLED,LOW);
            digitalWrite(secondLED,LOW);
  
          break;
          case 2:
  
            digitalWrite(secondLED,HIGH);
            digitalWrite(firstLED,HIGH);
            digitalWrite(6,LOW);
   
          break;
          case 3:
    
            digitalWrite(thirdLED,HIGH);
            digitalWrite(secondLED,HIGH);
            digitalWrite(firstLED,HIGH);
        
          break;
          case 4:
          
            digitalWrite(firstLED,LOW);
            digitalWrite(thirdLED,LOW);
            digitalWrite(secondLED,LOW);
       
          pressCount = 0;
          break;  

  }

 
   }
