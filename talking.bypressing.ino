#include <M5Stack.h>

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

    ESP.restart();
  }  
  out = new AudioOutputI2S(0, 1, 32);
  out->begin();
}

void loop()
{
  
     M5.update();  
         ESP8266SAM *sam = new ESP8266SAM;

    if (M5.BtnA.wasPressed()) {  
        M5.Lcd.println("A wasPressed");
        sam->Say(out, "Sedrick");
       
                                         
    } else if (M5.BtnB.wasPressed()) {
        M5.Lcd.println("B wasPressed");
        sam->Say(out, "sorry");
 
                                    
    } else if (M5.BtnC.wasPressed()) {
        M5.Lcd.println("I wantend to say thank you");
      sam->Say(out, "I wantend to say thank you");

    }
   
}
