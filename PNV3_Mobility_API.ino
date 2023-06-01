#include<string.h>
#include <Servo.h>
#define NORMAL 90
#define DISENGAGE 98
#define REVERSE 70
#define NO_BREAK 145
#define BREAK 95
#define STEERL 40
#define STEERR 140

// defines variables
long duration;
int distance;
bool reverse = false;
int steer_angle = 90;

Servo shift;
Servo esc;
Servo Break;
Servo Steer;


void setup() {
  Serial.begin(9600);
  shift.attach(10); 
  shift.write(NORMAL);
  
  Steer.attach(6);
  Steer.write(steer_angle);
  Break.attach(11);
  Break.write(NO_BREAK);
 
  esc.attach(9);
  esc.writeMicroseconds(1400);
  delay(2000);
}

void loop() {

  bool stop = false;
  if (Serial.available()) {
    String api_data = Serial.readStringUntil('\n');
    
    if (api_data.length() > 0) {
      String data = api_data.substring(1);
      char first_char = api_data[0];
      
      Serial.print(first_char);

      // switch (first_char) {
      //   case 'T':
      //     int th = data.toInt();
      //     // speedUp(th);
      //     Serial.println("THROTTLE");
      //     for(int throttle=1410; throttle<=th; throttle++) {
      //       esc.writeMicroseconds(throttle);
      //       delay(100);
      //     }
      //     break;
          
      //   case 'B':
      //     Serial.println("BREAK");
      //     esc.writeMicroseconds(0);
      //     shift.write(DISENGAGE);
      //     Break.write(BREAK);
      //     delay(2000);
      //     Break.write(NO_BREAK);
      //     shift.write(NORMAL);
      //     break;
        
      //   case 'R':
      //     Serial.println("REVERSE");
      //     if(!reverse) {
      //       esc.writeMicroseconds(0);
      //       shift.write(DISENGAGE);
      //       Break.write(BREAK);
      //       delay(1000);

      //       Break.write(NO_BREAK);
      //       shift.write(REVERSE);
      //       reverse = true;
      //       speedUp(1410);
      //     }
      
      //     else {
      //       esc.writeMicroseconds(0);
      //       delay(400);
      //       shift.write(DISENGAGE);
      //       Break.write(BREAK);
      //       delay(1000);
      //       Break.write(NO_BREAK);
      //       shift.write(NORMAL);
      //       reverse = false;
      //       speedUp(1410);
      //     }
          
      //     break;
        
      //   case 'S':
      //     Serial.println("STEERING");
      //     int a = data.toInt();
      //     // if(data == 'L'){
      //     //   int i;
      //     //   for(i=steer_angle;i>40;i--){
      //     //     Steer.write(i);
      //     //     delay(100);
      //     //   }
      //     //   steer_angle = i;
      //     // }
      //     // else{
      //     //   int j;
      //     //   for(j=steer_angle;j<140;j++){
      //     //     Steer.write(j);
      //     //     delay(100);
      //     //   }
      //     //   steer_angle = j;
      //     // }
      //     for(int j=90;j<140;j++){
      //         Steer.write(j);
      //         delay(100);
      //       }
      //     // Steer.write(a);
      //     delay(1000);
      //     break;
          
      //   default:
      //     Serial.println("Invalid first character.");
      //     break;
      // }

        if(first_char=='T'){

        
          int th = data.toInt();
          // speedUp(th);
          Serial.println("THROTTLE");
          for(int throttle=1410; throttle<=th; throttle++) {
            esc.writeMicroseconds(throttle);
            delay(100);
          }
        }

        else if(first_char=='B'){
          Serial.println("BREAK");
          esc.writeMicroseconds(0);
          shift.write(DISENGAGE);
          Break.write(BREAK);
          delay(2000);
          Break.write(NO_BREAK);
          shift.write(NORMAL);
        }

        else if(first_char=='R'){
          Serial.println("REVERSE");
          if(!reverse) {
            esc.writeMicroseconds(0);
            shift.write(DISENGAGE);
            Break.write(BREAK);
            delay(1000);

            Break.write(NO_BREAK);
            shift.write(REVERSE);
            reverse = true;
            speedUp(1430);
          }
      
          else {
            esc.writeMicroseconds(0);
            delay(400);
            shift.write(DISENGAGE);
            Break.write(BREAK);
            delay(1000);
            Break.write(NO_BREAK);
            shift.write(NORMAL);
            reverse = false;
            speedUp(1430);
          }

        }

        else if(first_char=='S'){
          Serial.println("STEERING");
          int a = data.toInt();
          // if(data == 'L'){
          //   int i;
          //   for(i=steer_angle;i>40;i--){
          //     Steer.write(i);
          //     delay(100);
          //   }
          //   steer_angle = i;
          // }
          // else{
          //   int j;
          //   for(j=steer_angle;j<140;j++){
          //     Steer.write(j);
          //     delay(100);
          //   }
          //   steer_angle = j;
          // }
          // for(int j=90;j<140;j++){
          //     Steer.write(j);
          //     delay(100);
          //   }
          Steer.write(a);
          delay(500);

        }

        else
          Serial.println("Invalid first character.");
    }
  }
}


void speedUp(int th){
  for(int throttle=1410; throttle<=th; throttle++) {
            esc.writeMicroseconds(throttle);
            delay(100);
          }
}
