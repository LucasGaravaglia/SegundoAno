

static float alphaSpeedLPF = 0.03;
static float alphaSteerLPF = 0.03;
static float steerCoef = 1.0;
static float speedCoef = 1.0;
static int16_t speedCmd;
static int16_t steerCmd;
#define CMD_PERIOD (50U)

#include <WiFiClient.h> 
#include <WebServer.h>

String command;             //String to store app command state.
int speedCar = 1023;         // 400 - 1023.
int speed_Coeff = 3;

const char* ssid = "Hover_uart";
WebServer server(80);

void setup() {
  Serial.begin(115200);
  Serial2.begin(19200);
  
// Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
 // Starting WEB-server 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}



static void sendCmd(int16_t steer, int16_t speed){
  
  Serial2.write((uint8_t) steer);
  Serial2.write((uint8_t) (steer >> 8));

  Serial2.write((uint8_t) speed);
  Serial2.write((uint8_t) (speed >> 8));
}

static float lpf(float alpha, float newVal, float oldVal)
{
  return alpha*newVal + (1 - alpha)*oldVal;
}


static void sendSteerSpeedCmd(int16_t steer, int16_t speed)
{  
  int16_t newSteerCmd = lpf(alphaSteerLPF, steer*steerCoef, steerCmd);
  int16_t newSpeedCmd = lpf(alphaSpeedLPF, speed*steerCoef, speedCmd); 

  /** Do not stop sending some commands, if no command received by hoverboard 
   *  it sets its speed to 0
   */
  if(newSteerCmd != steerCmd || newSpeedCmd != speedCmd){
    steerCmd = newSteerCmd;
    speedCmd = newSpeedCmd;

   
    Serial.print("Control > After filter speedCmd = ");
    Serial.print(speedCmd);
    Serial.print(" steerCmd = ");
    Serial.println(steerCmd);
  }
  sendCmd(steerCmd, speedCmd);
}
void goAhead(){ 

      sendSteerSpeedCmd(0, 500);
  }

void goBack(){ 
sendSteerSpeedCmd(0, -500);
    
  }

void goRight(){ 
sendSteerSpeedCmd(1000, 200);
  }

void goLeft(){
sendSteerSpeedCmd(-1000, 200);
     
  }

void goAheadRight(){
     
   }

void goAheadLeft(){
      
   
  }

void goBackRight(){ 

  }

void goBackLeft(){ 

  }

void stopRobot(){  
sendSteerSpeedCmd(0, 0);
 
 }

void loop() {
    server.handleClient();
    
      command = server.arg("State");
      if (command == "F") goAhead();
      else if (command == "B") goBack();
      else if (command == "L") goLeft();
      else if (command == "R") goRight();
      else if (command == "I") goAheadRight();
      else if (command == "G") goAheadLeft();
      else if (command == "J") goBackRight();
      else if (command == "H") goBackLeft();
      else if (command == "0") speedCar = 400;
      else if (command == "1") speedCar = 470;
      else if (command == "2") speedCar = 540;
      else if (command == "3") speedCar = 610;
      else if (command == "4") speedCar = 680;
      else if (command == "5") speedCar = 750;
      else if (command == "6") speedCar = 820;
      else if (command == "7") speedCar = 890;
      else if (command == "8") speedCar = 960;
      else if (command == "9") speedCar = 1023;
      else if (command == "S") stopRobot();

      Serial.println(command);
}

void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
