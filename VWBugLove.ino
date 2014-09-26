
/* Include 1Sheeld library. */
#include <OneSheeld.h> //optional
#include <Button.h> //critical, functionality
#include <Curve.h> //critical, animation
#include <LEDFader.h> //critical, animation

/* Define LEDs */
int firstLED = 7;
int secondLED = 8;
int thirdLED = 9;
int burstLED = 11; //burst led, accent lighting

/* Physical Button*/
Button button = Button(12,PULLUP);

/* Timer, to fade LEDs*/
long previousMillis = 0;//last time LED updated
long interval = 5000; //time til fade
byte currentLED = firstLED;//define last lit LED > target of fade, will change

void setup()
{ 
  /* Start communication. */
  OneSheeld.begin(); //currently not needed.
  /* Set the LED pin as output. */
  pinMode(firstLED,OUTPUT);
  pinMode(secondLED,OUTPUT);
  pinMode(thirdLED,OUTPUT);
  /* Burst LED */
  pinMode(burstLED,OUTPUT);
}

byte pressCount = 1;
void loop(){
  
              //Burst of awesome!
            //digitalWrite(burstLED,HIGH);
  
  //start timer
  unsigned long currentMillis = millis();
  
  //button functionality for LED scale
  if (button.uniquePress())  

    
    //Light Scale
    switch(pressCount)
        
        { case 0:
            pressCount++;
            
          break;
          case 1:
          
            digitalWrite(firstLED,HIGH);
            digitalWrite(secondLED,LOW);
            digitalWrite(thirdLED,LOW);
            currentLED=firstLED;
            pressCount++;
            previousMillis=currentMillis;

  
          break;
          case 2:
            
            digitalWrite(firstLED,HIGH);
            digitalWrite(secondLED,HIGH);
            digitalWrite(thirdLED,LOW);
            currentLED=secondLED;
            pressCount++;
            previousMillis=currentMillis;
   
          break;
          case 3:
    
            digitalWrite(firstLED,HIGH);
            digitalWrite(secondLED,HIGH);
            digitalWrite(thirdLED,HIGH);
            currentLED=thirdLED;
            //pressCount=3;
            previousMillis=currentMillis;
    
          break;  

        }



  //fade timer
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;
    //turn off last led
    digitalWrite(currentLED, LOW);
      if(pressCount>0 && currentLED==thirdLED){
        currentLED=secondLED;
        pressCount=3;
      } 
      else if(pressCount>0 && currentLED==secondLED){
        currentLED=firstLED;
        pressCount=2;
      } 
      else if(pressCount>0 && currentLED==firstLED){
        currentLED=firstLED;
        pressCount=1;
      } 
      else{
        pressCount=1;
      }
  }  

}


