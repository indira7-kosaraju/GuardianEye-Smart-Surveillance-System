#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "esp_camera.h"
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
const char* ssid = "Indu";
const char* password = "indu7777";
int x=0;
// Initialize Telegram BOT
String BOTtoken = "8256967330:AAEt8Xolq8s2cCImiBea36piYNF9CiFfmfY";  // your Bot Token (Get from Botfather)

// Use @myidbot to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
String CHAT_ID = "7127751188";

bool sendPhoto = false;
int sss=0;
WiFiClientSecure clientTCP;

UniversalTelegramBot bot(BOTtoken, clientTCP);


#define FLASH_LED_PIN 4
#define BUTTON 14
#define LOCK 13
#define aud 12
bool flashState = LOW;
String strs[8]={"0","0","0","0","0","0","0","0"};
int StringCount = 0;
//Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

//CAMERA_MODEL_AI_THINKER
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22


void configInitCamera(){
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  //init with high specs to pre-allocate larger buffers
  if(psramFound()){
    config.frame_size = FRAMESIZE_UXGA;
    config.jpeg_quality = 10;  //0-63 lower number means higher quality
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 12;  //0-63 lower number means higher quality
    config.fb_count = 1;
  }
  
  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    delay(1000);
    ESP.restart();
  }

  // Drop down frame size for higher initial frame rate
  sensor_t * s = esp_camera_sensor_get();
  s->set_framesize(s, FRAMESIZE_CIF);  // UXGA|SXGA|XGA|SVGA|VGA|CIF|QVGA|HQVGA|QQVGA
}

void handleNewMessages(int numNewMessages) {
 // Serial.print("Handle New Messages: ");
  //Serial.println(numNewMessages);

  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    
    // Print the received message
    String text = bot.messages[i].text;
    Serial.print(text);
    
    String from_name = bot.messages[i].from_name;
    if (text == "/start") {
      String welcome = "Welcome , " + from_name + "\n";
      welcome += "Use the following commands to interact with the ESP32-CAM \n";
      welcome += "/photo : takes a new photo\n";
      welcome += "/flash : toggles flash LED \n";
      welcome += "/1 : buzzer On \n";
      welcome += "/2 : buzzer off \n";
      welcome += "/3 : Lock the door \n";
      welcome += "/4 : UnLock the door \n";
    
      bot.sendMessage(CHAT_ID, welcome, "");
    }
    if (text == "/flash") {
      flashState = !flashState;
      digitalWrite(FLASH_LED_PIN, flashState);
      //Serial.println("Change flash LED state");
    }
    if (text == "/photo") {
      sendPhoto = true;
      //Serial.println("New photo request");
    }

   if (text == "/1") {
      
      //Serial.println("Sound On");
      
      digitalWrite(aud,1);
              
    }

     if (text == "/2") {
      
      //Serial.println("Sound On");
      
      digitalWrite(aud,0);
              
    }


    if (text == "/3") {
        digitalWrite(LOCK,1);
       
    }
        if (text == "/4") {
       digitalWrite(LOCK,0);
       
    }
    
  }
}

String sendPhotoTelegram() {
  const char* myDomain = "api.telegram.org";
  String getAll = "";
  String getBody = "";

  camera_fb_t * fb = NULL;
  fb = esp_camera_fb_get();  
  if(!fb) {
   // Serial.println("Camera capture failed");
    delay(1000);
    ESP.restart();
    return "Camera capture failed";
  }  
  
  //Serial.println("Connect to " + String(myDomain));


  if (clientTCP.connect(myDomain, 443)) {
   // Serial.println("Connection successful");
    String head = "--RandomNerdTutorials\r\nContent-Disposition: form-data; name=\"chat_id\"; \r\n\r\n" + CHAT_ID + "\r\n--RandomNerdTutorials\r\nContent-Disposition: form-data; name=\"photo\"; filename=\"esp32-cam.jpg\"\r\nContent-Type: image/jpeg\r\n\r\n";
  
    String tail = "\r\n--RandomNerdTutorials--\r\n";

    uint16_t imageLen = fb->len;
    uint16_t extraLen = head.length() + tail.length();
    uint16_t totalLen = imageLen + extraLen;
  
    clientTCP.println("POST /bot"+BOTtoken+"/sendPhoto HTTP/1.1");
   
    clientTCP.println("Host: " + String(myDomain));
    clientTCP.println("Content-Length: " + String(totalLen));
    clientTCP.println("Content-Type: multipart/form-data; boundary=RandomNerdTutorials");
    clientTCP.println();
    clientTCP.print(head);
  
    uint8_t *fbBuf = fb->buf;
    size_t fbLen = fb->len;
    for (size_t n=0;n<fbLen;n=n+1024) {
      if (n+1024<fbLen) {
        clientTCP.write(fbBuf, 1024);
        fbBuf += 1024;
      }
      else if (fbLen%1024>0) {
        size_t remainder = fbLen%1024;
        clientTCP.write(fbBuf, remainder);
      }
    }  
    
    clientTCP.print(tail);
    
    esp_camera_fb_return(fb);
    
    int waitTime = 10000;   // timeout 10 seconds
    long startTimer = millis();
    boolean state = false;
    
    while ((startTimer + waitTime) > millis()){
      Serial.print(".");
      delay(100);      
      while (clientTCP.available()) {
        char c = clientTCP.read();
        if (state==true) getBody += String(c);        
        if (c == '\n') {
          if (getAll.length()==0) state=true; 
          getAll = "";
        } 
        else if (c != '\r')
          getAll += String(c);
        startTimer = millis();
      }
      if (getBody.length()>0) break;
    }
    clientTCP.stop();
    String x=getBody;
  }
  else {
    getBody="Connected to api.telegram.org failed.";
    //Serial.println("Connected to api.telegram.org failed.");
  }
  return getBody;
}

void setup(){
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); 
  // Init Serial Monitor
  Serial.begin(9600);

  // Set LED Flash as output
  pinMode(FLASH_LED_PIN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LOCK, OUTPUT);
  pinMode(aud, OUTPUT);
  digitalWrite(LOCK,0);
  digitalWrite(aud,0);
  digitalWrite(FLASH_LED_PIN, flashState);

  // Config and init the camera
  configInitCamera();

  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  //Serial.println();
 // Serial.print("Connecting to ");
//  Serial.println(ssid);
 // WiFi.begin(ssid, password);
  clientTCP.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
 
 // Serial.println();
 // Serial.print("ESP32-CAM IP Address: ");
 // Serial.println(WiFi.localIP()); 
}

void loop() {
 // Serial.println("initial");

 if(strs[2] !="0")
 {

  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
     const char* string0 = strs[2].c_str();
 const char* string1 = strs[3].c_str();
    WiFi.begin(string0,string1);
      for(int kk=0;kk<10;kk++)
      {
        digitalWrite(aud,0);
        delay(300);
        digitalWrite(aud,1);
        delay(300);
      }
   if(WiFi.status() == WL_CONNECTED)
    Serial.println("ok");
  }
  
   
 }
 
if (Serial.available()) 
{
   String rcv = Serial.readStringUntil('\n');
   StringCount=0;
    while (rcv.length() > 0)
    {
    int index = rcv.indexOf(',');
    if (index == -1) // No space found
    {
      strs[StringCount++] = rcv;
      break;
    }
    else
    {
      strs[StringCount++] = rcv.substring(0, index);
      rcv = rcv.substring(index+1);
    }
  }
     CHAT_ID=strs[0];
   BOTtoken=strs[1];
   if (WiFi.status() == WL_CONNECTED)
   {
    bot.sendMessage(CHAT_ID, strs[4]);
    //Serial.println("Preparing photo");
    
    if(strs[5]=="1")
    {
    sendPhotoTelegram(); 
    sendPhoto = false;
    }
    
    
   }
   
}
    
 

   

    if ((sendPhoto==true)) 
  {
    digitalWrite(aud,1);
    bot.sendMessage(CHAT_ID, "photo on request", "");
    //Serial.println("Preparing photo");
    sendPhotoTelegram(); 
    sendPhoto = false;
   delay(3000);
   digitalWrite(aud,0);
  }


  if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    while (numNewMessages) {
      //Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
  }