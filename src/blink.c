/*********************************************************************
* File         blink.c
* Authors      Priya Chandanshive, Varun Vijaykumar
* Description  File to control the LED glow of Gertboard via wiringPi
*              Library
* Date         24 Nov 2015
**********************************************************************/

// Standard includes
# include <stdio.h>
# include <stdbool.h>

// Wiring PI Includes
# include <wiringPi.h>

// Setting a clean return interfacing
# define FAILURE -1
# define SUCCESS  0

/////////////////////////////////////////////////////////////////////////////////
// Set Pin Mode to all the required pins
/////////////////////////////////////////////////////////////////////////////////
void setPinModes()
{
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(13,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(14,OUTPUT);
}

/////////////////////////////////////////////////////////////////////////////////
// Reset All pins for the Gertboard
/////////////////////////////////////////////////////////////////////////////////
void resetAllPins(void)
{
  // Setting all the pins as low here ...
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(7,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(14,LOW);
}

/////////////////////////////////////////////////////////////////////////////////
// Pin LED Control Function
/////////////////////////////////////////////////////////////////////////////////
int LEDGlowControl()
{
  setPinModes();
  resetAllPins();

  //"Only light up the LED one after the other ... NO switching off necessary"
  // We need to write the checks to confirm that we are on the same board of raspberry pi variant
  // Lets give an initial delay of 500 ms

  delay(500);


  if (wpiPinToGpio(8) == 2 )
  {
   printf("Glowing 0 \n");
   digitalWrite(8,HIGH);
  }
  else
  {
   printf("Failed due to Pin number 0 \n");
   return FAILURE;
  }

  delay(500);

  if (wpiPinToGpio(9) == 3 )
  {
    printf("Glowing 1 \n");
    digitalWrite(9,HIGH);
  }
  else
  {
    printf("Failed due to Pin number 1 \n" );
    return FAILURE;
  }

   delay(800);

 if (wpiPinToGpio(7) == 4 )
  {
   printf("Glowing 4 \n");
    digitalWrite(7,HIGH);
  }
  else
  {printf("Glowing 10 \n");
    printf("Failed due to Pin number 4 \n" );
    return FAILURE;
  }

  delay(500);

  if (wpiPinToGpio(11) == 7 )
  {
   printf("Glowing 7 \n");
    digitalWrite(11,HIGH);
  }
  else
  {
    printf("Failed due to Pin number 7 \n" );
    return FAILURE;
  }

  delay(500);

  if (wpiPinToGpio(10) == 8 )
  {
   printf("Glowing 8 \n");
    digitalWrite(10,HIGH);
  }
  else
  {
    printf("Failed due to Pin number 8 \n" );
    return FAILURE;
  }

  delay(500);

  if (wpiPinToGpio(13) == 9 )
  {
   printf("Glowing 9 \n");
    digitalWrite(13,HIGH);
  }
  else
  {
    printf("Failed due to Pin number 9 \n" );
    return FAILURE;
  }

  delay(500);

  if (wpiPinToGpio(12) == 10 )
  {
    printf("Glowing 10 \n");
    digitalWrite(12,HIGH);
  }
  else
  {
    printf("Failed due to Pin number 10 \n" );
    return FAILURE;
  }

  delay(500);

  if (wpiPinToGpio(14) == 11 )
  {
   printf("Glowing 11 \n");
    digitalWrite(14,HIGH);
  }
  else
  {
    printf("Failed due to Pin number 11 \n" );
    return FAILURE;
  }

  // Passed ...
  return SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////
// Main Function --- Initiate all
/////////////////////////////////////////////////////////////////////////////////
int main (void)
{
  // Initialize Wiring Pi
  wiringPiSetup () ;

  // Start the board LED control
  if  (LEDGlowControl() == FAILURE)
  {
      printf("LED Glow failed! \n ");
      return FAILURE;
  }
  return SUCCESS ;
}
