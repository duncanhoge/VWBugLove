
/* Include 1Sheeld library. */
#include <OneSheeld.h>
#include <Button.h>

/* Define LEDs */
int firstLED = 7;
int secondLED = 8;
int thirdLED = 9;

/* Physical Button*/
Button button = Button(12,PULLUP);

/* Timer, to fade LEDs*/
long previousMillis = 0;//last time LED updated
long interval = 5000; //time til fade
byte lastLED = 0;//define last LED > target of fade, will change

void setup()
{ 
  /* Start communication. */
  OneSheeld.begin(); //currently not needed.
  /* Set the LED pin as output. */
  pinMode(firstLED,OUTPUT);
  pinMode(secondLED,OUTPUT);
  pinMode(thirdLED,OUTPUT);
}

byte pressCount = 1;
void loop(){
  
  //button functionality for LED scale
  if (button.uniquePress())  
    
    //pressCount++;
  
    switch(pressCount)
        
        { case 0:
            pressCount++;
            
          break;
          case 1:
          
            digitalWrite(firstLED,HIGH);
            digitalWrite(secondLED,LOW);
            digitalWrite(thirdLED,LOW);
            lastLED=firstLED;
            pressCount++;
  
          break;
          case 2:
            
            digitalWrite(firstLED,HIGH);
            digitalWrite(secondLED,HIGH);
            digitalWrite(thirdLED,LOW);
            lastLED=secondLED;
            pressCount++;
   
          break;
          case 3:
    
            digitalWrite(firstLED,HIGH);
            digitalWrite(secondLED,HIGH);
            digitalWrite(thirdLED,HIGH);
            lastLED=thirdLED;
            pressCount=3;
            
          break;  

        }

  //start timer
  unsigned long currentMillis = millis();

  //fade timer
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;
    //turn off last led
    digitalWrite(lastLED, LOW);
      if(pressCount>0){
        pressCount--;
      }
  }  

}


