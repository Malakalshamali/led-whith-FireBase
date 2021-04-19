#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>


#include <Arduino_JSON.h>

#include <ESP8266WiFi.h>

#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""

#define ssid ""
#define password ""
int led = 2;
String status_led ;

void setup()
{ 
  
  Serial.begin(9600);
  pinMode ( led , OUTPUT );
  WiFi.disconnect();
  WiFi.begin(ssid , password);
Firebase.begin(FIREBASE_HOST ,FIREBASE_AUTH );
Firebase.set("Led/Led_Control","ON");


  }
  
 
void loop() {
  status_led = Firebase.getString("Led/Led_Control");                                      
  if (status_led == "ON") 
  {                                                        
    Serial.println("Led Turned ON");                                                        
    digitalWrite(led, HIGH);                                                  
  } 
  else if (status_led == "OFF") 
  {                                                
    Serial.println("Led Turned OFF");
    digitalWrite(led, LOW);                                                        
  }
  else 
  {
    Serial.println("Command Error! Please send ON/OFF");
  }


} 
