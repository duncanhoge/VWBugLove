
/* Include 1Sheeld library. */
#include <OneSheeld.h> //optional
#include <Button.h> //critical, functionality
//#include <Curve.h> //critical, animation
//#include <LEDFader.h> //critical, animation

/* Define LEDs */
int firstLED = 4;
int secondLED = 5;
int thirdLED = 6;
int fourthLED = 7;
int fifthLED = 8;

int burstLED = 11;

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
  pinMode(fourthLED,OUTPUT);
  pinMode(fifthLED,OUTPUT);
  /* Burst LED */
  pinMode(burstLED,OUTPUT);

}

byte pressCount = 0;

void loop(){
  
  //start timer
  unsigned long currentMillis = millis();
  
  //button functionality for LED scale
  if (button.uniquePress())  
   
   
 // ledFadeAnimation();
    
    //Light Scale
    switch(pressCount)
        
        { case 0:
            pressCount++;
            
          break;
          case 1:
          
            digitalWrite(firstLED,HIGH);
            digitalWrite(secondLED,LOW);
            digitalWrite(thirdLED,LOW);
            digitalWrite(fourthLED,LOW);
            digitalWrite(fifthLED,LOW);
            currentLED=firstLED;
            pressCount++;
            previousMillis=currentMillis;
            digitalWrite(burstLED,HIGH);
            delay(800);
            digitalWrite(burstLED,LOW);

  
          break;
          case 2:
            
            digitalWrite(firstLED,HIGH);
            digitalWrite(secondLED,HIGH);
            digitalWrite(thirdLED,LOW);
            digitalWrite(fourthLED,LOW);
            digitalWrite(fifthLED,LOW);
            currentLED=secondLED;
            pressCount++;
            previousMillis=currentMillis;
            digitalWrite(burstLED,HIGH);
            delay(800);
            digitalWrite(burstLED,LOW);

   
          break;
          case 3:
    
            digitalWrite(firstLED,HIGH);
            digitalWrite(secondLED,HIGH);
            digitalWrite(thirdLED,HIGH);
            digitalWrite(fourthLED,LOW);
            digitalWrite(fifthLED,LOW);
            currentLED=thirdLED;
            pressCount++;
            previousMillis=currentMillis;
            digitalWrite(burstLED,HIGH);
            delay(800);
            digitalWrite(burstLED,LOW);

    
          break; 
          case 4:
          
            digitalWrite(firstLED,HIGH);
            digitalWrite(secondLED,HIGH);
            digitalWrite(thirdLED,HIGH);
            digitalWrite(fourthLED,HIGH);
            digitalWrite(fifthLED,LOW);
            currentLED=fourthLED;
            pressCount++;
            previousMillis=currentMillis;
            digitalWrite(burstLED,HIGH);
            delay(800);
            digitalWrite(burstLED,LOW); 
            
          break; 
          case 5:
          
            digitalWrite(firstLED,HIGH);
            digitalWrite(secondLED,HIGH);
            digitalWrite(thirdLED,HIGH);
            digitalWrite(fourthLED,HIGH);
            digitalWrite(fifthLED,HIGH);
            currentLED=fifthLED;
           // pressCount++;
            previousMillis=currentMillis;
            digitalWrite(burstLED,HIGH);
            delay(800);
            digitalWrite(burstLED,LOW); 
         
           break;

        }



  //fade timer
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;
    //turn off last led
    digitalWrite(currentLED, LOW);
      if(pressCount>0 && currentLED==fifthLED){
        currentLED=fourthLED;
        pressCount=5;
      } 
      else if(pressCount>0 && currentLED==fourthLED){
        currentLED=thirdLED;
        pressCount=4;
      } 
      else if(pressCount>0 && currentLED==thirdLED){
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
//
//void ledFadeAnimation() {
//  led.update();
//
//  if (led.is_fading() == false) {
//
//    // Fade from 255 - 0
//    if (led.get_value() == 255) {
//      led.fade(0, 3000);
//    }
//    // Fade from 0 - 255
//    else {
//      led.fade(255, 3000);
//    }
//  }
//}


