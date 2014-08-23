
#define TORSOCHANNEL 0
#define LEGCHANNEL 2

#define TORSOCHANNEL2 4
#define LEGCHANNEL2 6



int torsoMovementDelay = 360;
int legMovementDelay = 280;

int servoCenter = 700;

int torsoMin = 480;//220
int torsoMax = 920;//220


int legMin = 560;//140
int legMax = 840;//140




boolean isActive = true;

void setup()  {
  //Servo Control board
  Serial1.begin(2400);

  Serial.begin(9600);
  Serial.println("DUAL SERVO started");
  
  
  MoveServo(TORSOCHANNEL, servoCenter);
  MoveServo(LEGCHANNEL, servoCenter);
  
  MoveServo(TORSOCHANNEL2, servoCenter);
  MoveServo(LEGCHANNEL2, servoCenter);
}


void loop() {

  if(isActive){
   
      MoveServo(TORSOCHANNEL, torsoMin);
      MoveServo(TORSOCHANNEL2, torsoMax);
      delay(torsoMovementDelay);
      
      MoveServo(LEGCHANNEL, legMax);
      MoveServo(LEGCHANNEL2, legMin);
      delay(legMovementDelay);
   
      MoveServo(TORSOCHANNEL, torsoMax);
      MoveServo(TORSOCHANNEL2, torsoMin);
      delay(torsoMovementDelay);
      
      MoveServo(LEGCHANNEL, legMin);
      MoveServo(LEGCHANNEL2, legMax);
      delay(legMovementDelay);
      
  }
}



void MoveServo(int servo_channel, int servo_angle){
  
    byte lsb = servo_angle;
    byte msb =  servo_angle >> 8;
    int ramp = 0;
  
  
    Serial1.write(33);  //!
    Serial1.write(83);  //S
    Serial1.write(67);  //C
    Serial1.write(servo_channel);  //channel
    Serial1.write(ramp);  //rampspeed
    Serial1.write(lsb);  //LSB
    Serial1.write(msb);  //MSB
    Serial1.write(13);
    
    
    Serial.print("channel:");
    Serial.println(servo_channel);
       
    Serial.print("angle:");
    Serial.println(servo_angle);
}


