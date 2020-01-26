#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
#include <RotaryEncoder.h>
LiquidCrystal_I2C lcd(0x27, 6,12);


RotaryEncoder encoder(A2, A3);
#define ROTARYMIN 0
int ROTARYMAX = 9;
int mode_button=2;
long pwr=0;
unsigned int att=0;
int mode=0; // 0 for set frequency and 1 for set attenuator
int freq_sel=0;
char *freq[10]={"30 MHz","50 MHz","144MHz","433MHz","1,2GHz","1,8GHz","2,1GHz","2,4GHz","3,4GHz","5,7GHz"};
int matrix[10][4] = {
  {0,1023,0,50},
  {0,1023,0,50},
  {0,1023,0,50},
  {0,1023,0,50},
  {0,1023,0,50},
  {0,1023,0,50},
  {0,1023,0,50},
  {0,1023,0,50},
  {0,1023,0,50},
  {0,1023,0,50},
};



void setup() {
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0,1);
  lcd.print("RF Power meter");
  lcd.setCursor(1,1);
  lcd.print("by canis_lupus");
  attachInterrupt(digitalPinToInterrupt(mode_button), mode_interrupt, RISING);
  encoder.setPosition(freq_sel);
}

void mode_interrupt()
{
  detachInterrupt(mode_interrupt);
  
  if (mode == 0) {
    mode = 1;
    encoder.setPosition(att);
    ROTARYMAX = 100;
    
  }
  else if (mode == 1){
    mode = 0;
    encoder.setPosition(freq_sel);
    ROTARYMAX = 9;
  }
  
  attachInterrupt(digitalPinToInterrupt(mode_button), mode_interrupt, RISING);
}

void update_disp(){
  
}

int measure(){
  return analogRead(A5);
}


void loop() {
  encoder.tick();

}

