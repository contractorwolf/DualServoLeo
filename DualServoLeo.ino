
#define TORSOCHANNEL 0
#define LEGCHANNEL 2

#define TORSOCHANNEL2 4
#define LEGCHANNEL2 6



int servoCenter = 700;
int torsoMaxMovement = 220;
int legMaxMovement = 140;

boolean isTorsoActive = true;
boolean isLegActive = true;

int torsoMovementDelay = 360;//360
int legMovementDelay = 280;//280

void setup()  {
  //Servo Control board
  Serial1.begin(2400);

  Serial.begin(9600);
  Serial.println("DUAL SERVO started");
  
  
  MoveServo(TORSOCHANNEL, 0);
  MoveServo(LEGCHANNEL, 0);
  
  MoveServo(TORSOCHANNEL2, 0);
  MoveServo(LEGCHANNEL2, 0);
}


void loop() {

  if(isTorsoActive){
      MoveServo(TORSOCHANNEL, -torsoMaxMovement);//-220
      MoveServo(TORSOCHANNEL2, torsoMaxMovement);//220      
      delay(torsoMovementDelay);
  }    
      
  if(isLegActive){      
      MoveServo(LEGCHANNEL, legMaxMovement);//140
      MoveServo(LEGCHANNEL2, -legMaxMovement);//-140
      delay(legMovementDelay);
  }
  if(isTorsoActive){   
      MoveServo(TORSOCHANNEL, torsoMaxMovement);//220
      MoveServo(TORSOCHANNEL2, -torsoMaxMovement);//-220
      delay(torsoMovementDelay);
  }
  
  if(isLegActive){      
      MoveServo(LEGCHANNEL, -legMaxMovement);//-140
      MoveServo(LEGCHANNEL2, legMaxMovement);//140
      delay(legMovementDelay);
  }    

}



void MoveServo(int servo_channel, int movement){

  
    int servo_angle = servoCenter + movement;
  
  
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


