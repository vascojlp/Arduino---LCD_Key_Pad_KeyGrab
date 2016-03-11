//Sample using LiquidCrystal library
#include <LiquidCrystal.h>

/*******************************************************

This program will test the LCD panel and the buttons
Mark Bramwell, July 2010

********************************************************/

// select the pins used on the LCD panel
LiquidCrystal lcd(13,12, 11, 10, 9, 8); //uno
//LiquidCrystal lcd(12, 13, 11, 10, 9, 8);

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor 
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
 // For V1.1 us this threshold
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 250)  return btnUP; 
 if (adc_key_in < 450)  return btnDOWN; 
 if (adc_key_in < 650)  return btnLEFT; 
 if (adc_key_in < 850)  return btnSELECT;  

 // For V1.0 comment the other threshold and use the one below:
/*
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 195)  return btnUP; 
 if (adc_key_in < 380)  return btnDOWN; 
 if (adc_key_in < 555)  return btnLEFT; 
 if (adc_key_in < 790)  return btnSELECT;   
*/


 return btnNONE;  // when all others fail, return this...
}

void setup()
{
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 lcd.print("Push the buttons"); // print a simple message
}
 
void loop()
{
 lcd.setCursor(0,1);            // move to the begining of the second line
 lcd_key = read_LCD_buttons();  // read the buttons

 switch (lcd_key)               // depending on which button was pushed, we perform an action
 {
   case btnRIGHT:
     {
     lcd.clear();
     lcd.print("RIGHT    ");
     lcd.print(adc_key_in);
     delay(2000);
     break;
     }
   case btnLEFT:
     {
       lcd.clear();
     lcd.print("LEFT   ");
     lcd.print(adc_key_in);
     delay(2000);
     break;
     }
   case btnUP:
     {
       lcd.clear();
     lcd.print("UP    ");
     lcd.print(adc_key_in);
     delay(2000);
     break;
     }
   case btnDOWN:
     {
       lcd.clear();
     lcd.print("DOWN     ");
     lcd.print(adc_key_in);
     delay(2000);
     break;
     }
   case btnSELECT:
     {
       lcd.clear();
     lcd.print("SEL   ");
     lcd.print(adc_key_in);
     delay(2000);
     break;
     }
     case btnNONE:
     {
       lcd.clear();
     lcd.print("NONE  ");
     lcd.print(adc_key_in);
     delay(2000);
     break;
     }
 }

}

