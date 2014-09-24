/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the LED on pin 13. */
int firstLED = 13;
int secondLED = 12;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  pinMode(firstLED,OUTPUT);
}

void loop()
{
  /* Always check if the push button is pressed. */
  if(PushButton.isPressed())
  {
    /* Turn on the LED. */
    digitalWrite(firstLED,HIGH);
    digitalWrite(secondLED,HIGH);
  }
  else
  {
    /* Turn on the LED. */
    digitalWrite(firstLED,LOW);
    digitalWrite(secondLED,LOW);
  }

}
