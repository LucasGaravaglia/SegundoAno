
static float alphaSpeedLPF = 0.03;
static float alphaSteerLPF = 0.03;
static float steerCoef = 1.0;
static float speedCoef = 1.0;
static int16_t speedCmd;
static int16_t steerCmd;
#define CMD_PERIOD (50U)

void setup() {
 Serial2.begin(19200);

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

void loop() {
  sendSteerSpeedCmd(1000, 1000);
  delay(CMD_PERIOD);

}
