
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
int lastLED = 0;//define last LED > target of fade, will change

void setup()
{ 
  /* Start communication. */
  OneSheeld.begin(); //currently not needed.
  /* Set the LED pin as output. */
  pinMode(firstLED,OUTPUT);
  pinMode(secondLED,OUTPUT);
  pinMode(thirdLED,OUTPUT);
}

/*IMPORTANT:
Make sure to set OneSheeld input to buttoninput (12);
*/

byte pressCount = 0;
void loop(){

  //start timer
  unsigned long currentMillis = millis();
  
  //button functionality for LED scale
  if (button.uniquePress())  
    
    //pressCount++;
  
    switch(pressCount)
        
        { case 0:
            pressCount++;
            
          break;
          case 1:
          
            digitalWrite(firstLED,HIGH);
            digitalWrite(thirdLED,LOW);
            digitalWrite(secondLED,LOW);
            lastLED=1;
            pressCount++;
  
          break;
          case 2:
  
            digitalWrite(secondLED,HIGH);
            digitalWrite(firstLED,HIGH);
            digitalWrite(6,LOW);
            lastLED=secondLED;
            lastLED=2;
            pressCount++;
   
          break;
          case 3:
    
            digitalWrite(thirdLED,HIGH);
            digitalWrite(secondLED,HIGH);
            digitalWrite(firstLED,HIGH);
            lastLED=thirdLED;
            lastLED=3;
            pressCount++;
        
          break;
          case 4:
          
            digitalWrite(firstLED,LOW);
            digitalWrite(thirdLED,LOW);
            digitalWrite(secondLED,LOW);
            lastLED=0;
            pressCount = 1;
            
          break;  

        }

//  //fade timer
//  if(currentMillis - previousMillis > interval) {
//    // save the last time you blinked the LED 
//    previousMillis = currentMillis;
//    //turn off last led
//    digitalWrite(lastLED, LOW);
//      if(pressCount>0){
//        pressCount--;
//      }
//  }  

}


