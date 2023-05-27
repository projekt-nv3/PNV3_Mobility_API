#include <Servo.h>
#define NORMAL 90
#define DISENGAGE 98
#define REVERSE 70

Servo ph_shift;
Servo esc;

void setup() {
  // put your setup code here, to run once:4
  Serial.begin(9600);
  
  Serial.println("ATTACHED");
  ph_shift.attach(10);  // attaches the servo on pin 10 to the servo object
  ph_shift.write(90);
  esc.attach(9);
  // delay(5000);
  Serial.println("INITIALIZED");
  
  esc.writeMicroseconds(1400);
  delay(3000);
  Serial.println("INITIALIZED");
  
  // esc.writeMicroseconds(1600);
  // delay(3000);
}

void loop() {
  bool reverse = false;

  for(int throttle=1410; throttle<=1500; throttle++) {
    Serial.println(throttle);
    esc.writeMicroseconds(throttle);
    delay(100);
  
    if (Serial.available() > 0){
      String msg = Serial.readString();
      int num;
      num = msg.toInt();
      
      if(!reverse) {
        esc.writeMicroseconds(0);
        ph_shift.write(DISENGAGE);
        delay(1000);

        ph_shift.write(REVERSE);
        throttle=1410;
        reverse = true;
      }
      
      else {
        esc.writeMicroseconds(0);
        delay(400);
        ph_shift.write(DISENGAGE);
        delay(1000);

        ph_shift.write(NORMAL);
        throttle=1410;
        reverse = false;
      }


    }
  }

}



// void bbslowdown(int throttle) {
//   for(; throttle>=1410; throttle)
// }