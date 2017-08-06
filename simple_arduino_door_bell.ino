/* Simple Arduino Door Bell
 * Author: Hiruna Wijesinghe
 * Last Modified: 06/08/2017
 */

 /***********HARDWARE***********/
 /*
  * + Arduino (I used a custom Uno board)
  * + 47ohm resistor (for piezo buzzer) + a resistor for the push button (I used ~100 ohms)
  * + 1602 LCD
  * + 16mm Push Button
  * + I2C LCD module
  */

/* Libraries */
#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //I2C

int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers


void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  //initialize ring button pin
  pinMode(5, INPUT);

  //initialize piezo buzzer pin
  pinMode(9,OUTPUT);

  //initiallize
  lcd.begin(16,4);


  //DISPLAY ADDRESS (default message)
  displayAddress(lcd);
  
}


void loop()
{
  

  //Read from push button
  reading = digitalRead(5);

  
  if (reading == HIGH && millis() - time > debounce) { //ignore signal noice
    //if user presses button
    displayRingingMessage(lcd); //display ringing message
    ringBell(); //call ring bell
    delay(1500); //pause for 1.5 seconds
    displayAddress(lcd); //show the default message
    time = millis();    
  }

  previous = reading;

}

void displayAddress(LiquidCrystal_I2C lcd){ //display default message/address
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("WELCOME");
  lcd.setCursor(0,1);
  lcd.print("________________");
}

void displayRingingMessage(LiquidCrystal_I2C lcd){ //display ringing message
  lcd.clear();
  lcd.setCursor(3,0); //Start at character 4 on line 0
  lcd.print("RINGING...");
  blinkLCD(lcd);
}

void blinkLCD(LiquidCrystal_I2C lcd){ //blink the lcd 3 times for fun :P
  for(int i = 0; i< 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); // finish with backlight on 
}

void ringBell(){ //plays a tone on the piezo buzzer
  for(int i=1;i<=3;i++){
    
    tone(9,2500,1000);
    delay(1000);
    tone(9,1000,2000);
    delay(2000);
    digitalWrite(9,LOW);
    delay(2000);
    
  }   
   
}
