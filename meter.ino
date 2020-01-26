#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
#include <RotaryEncoder.h>
LiquidCrystal_I2C lcd(0x27, 6,12);
RotaryEncoder encoder(A2, A3);

long pwr=0;
int att=0;
int menu=0;
char *freq[]={"30 MHz","50 MHz","144MHz","433MHz","1,2GHz","1,8GHz","2,4GHz","3,4GHz","5,7GHz"};


void setup() {
  lcd.begin(16,2);
}

void disp(){
  
}

int measure(){
  
}


void loop() {
  // put your main code here, to run repeatedly:

}

