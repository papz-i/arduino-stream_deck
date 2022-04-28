#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <string.h>

LiquidCrystal_I2C lcd(0x27, 20,2); 

int buttonOnePin = 2;
int buttonTwoPin = 3;
int buttonThreePin = 4;
int buttonFourPin = 5;
int buttonFivePin = 6;

int lcdDelay = 1000;

String messageOne = "Chrome";
String messageTwo = "Edge";
String messageThree = "VsCode";
String messageFour = "Sublime Text";
String messageFive = "Files";
String noMessage = "No message";

void setup() {  
  pinMode(buttonOnePin, INPUT);
  pinMode(buttonTwoPin, INPUT);
  pinMode(buttonThreePin, INPUT);
  pinMode(buttonFourPin, INPUT);
  pinMode(buttonFivePin, INPUT);

  lcd.init();                      
  lcd.backlight();                                                                                                                                              

  Serial.begin(9600);
}

void printMessage(String message){
  lcd.print(message + " selected.");
  delay(lcdDelay);
  lcd.clear();
}

void loop() { 
  int buttonOne = digitalRead(buttonOnePin);
  int buttonTwo = digitalRead(buttonTwoPin);
  int buttonThree = digitalRead(buttonThreePin);
  int buttonFour = digitalRead(buttonFourPin);
  int buttonFive = digitalRead(buttonFivePin);

  if(buttonOne == 1){
    Serial.println("1"); 
    delay(lcdDelay);
    printMessage(messageOne);
  }else if(buttonTwo == 1){
    Serial.println("2");
    printMessage(messageTwo);
  }else if(buttonThree == 1){
    printMessage(messageThree);
    Serial.println("3");
  }else if(buttonFour == 1){
    Serial.println("4");
    printMessage(messageFour);
  }else if(buttonFive == 1){
    Serial.println("5");
    printMessage(messageFive);
  }else{
    Serial.println("0");
    
  } 
  delay(1000);
}
