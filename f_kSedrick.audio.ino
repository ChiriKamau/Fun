#include <M5Stack.h>
//#include <M5StackUpdater.h>
#include <Arduino.h>
#include <ESP8266SAM.h>  //https://github.com/earlephilhower/ESP8266SAM
#include <AudioOutputI2S.h>  //https://github.com/earlephilhower/ESP8266Audio

AudioOutputI2S *out = NULL;

void setup()
{
  M5.begin();
  Wire.begin();
  if(digitalRead(BUTTON_A_PIN) == 0){
    Serial.println("Will load menu binary");
//    updateFromFS(SD);
    ESP.restart();
  }  
  out = new AudioOutputI2S(0, 1, 32);
  out->begin();
}

void loop()
{
  ESP8266SAM *sam = new ESP8266SAM;
  sam->Say(out, "Fuck you Sedrick!!");
  delay(500);
  sam->Say(out, "Fuck you");
  delete sam;
}
