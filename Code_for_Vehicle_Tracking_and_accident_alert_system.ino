#include  <Wire.h> 
#include  <ESP8266WiFi.h>
#include  <Adafruit_Sensor.h> 
#include  <Adafruit_ADXL345_U.h>
#include  <IFTTTWebhook.h>

#define  WIFISSID  "Ananya Home  2.4"  //  Your  WiFi  Name #define  PASSWORD  "000joy000"  //  Your  WiFi  Password

#define  CRITICAL_API_KEY  "6N_U4salr0r0R9Jq-czeE" #define  CRITICAL_EVENT_NAME  "sms_alert"

#define  minVal  -0.12
#define  MaxVal  -0.7


Adafruit_ADXL345_Unified  accel  =  Adafruit_ADXL345_Unified(12345); IFTTTWebhook  critical_webhook(CRITICAL_API_KEY, CRITICAL_EVENT_NAME);

void  setup()
{

//  Initializing  Serial  communication. Serial.begin(115200);
Serial.println("Init...  Accident  Alert  System");


//  Setup  up  WiFi  and  Connecting  to  an  active  hotspot. Serial.print("\n\nConnecting  to  ");
 

Serial.println(WIFISSID);


WiFi.begin(WIFISSID,  PASSWORD);
while  (WiFi.status()  !=  WL_CONNECTED)  {  //  Waiting  for successful  connection
delay(500); Serial.print(".");
}


Serial.print("WiFi  connected.  IP  address:  "); Serial.println(WiFi.localIP()); if(!accel.begin())
{

Serial.println("Ooops,  no  ADXL345  detected  ...  Check  your wiring!");
while(1);

}
accel.setRange(ADXL345_RANGE_4_G);
}


void  loop()
{

sensors_event_t  event; accel.getEvent(&event);

int  valuex=(event.acceleration.x)/9.8; int  valuey=(event.acceleration.y)/9.8; int  valuez=(event.acceleration.z)/9.8;
 

Serial.print((event.acceleration.x)/9.8);  Serial.print(","); Serial.print((event.acceleration.y)/9.8);  Serial.print(","); Serial.println((event.acceleration.z)/9.8);

//condition  for  accident  detection if(valuex  <  MaxVal  ||  valuez  <  minVal  )
{Serial.println("Accident  Detected!");
//Trigger  IFTTT  webhook  in  case  of  accident  for  notification critical_webhook.trigger();


Serial.end();
//delay(1000);}
}}





Serial.end();
//delay(1000);}
}}
