#include <Servo.h>
#define NORMAL 90
#define DISENGAGE 98
#define REVERSE 70
#define NO_BREAK 145
#define BREAK 95

Servo ph_shift;
Servo esc;
Servo Break;


void setup() {
  Serial.begin(9600);
  
  ph_shift.attach(10); 
  ph_shift.write(90);
  
  Break.attach(11);
  Break.write(NO_BREAK);
 
  esc.attach(9);
  esc.writeMicroseconds(1400);
  delay(3000);

}

void loop() {
  bool reverse = false;

  for(int throttle=1410; throttle<=1500; throttle++) {
    // Serial.println(throttle);
    esc.writeMicroseconds(throttle);
    delay(100);

    // if(throttle==1460){
    //   Serial.println("1460");
    //   esc.writeMicroseconds(0);
    //   delay(2000);
    // }

    // if(throttle==1499){
    //   esc.writeMicroseconds(0);
    //   ph_shift.write(DISENGAGE);
    //   for(int angle = NO_BREAK; angle > BREAK; angle-=15)    
    //     {                                
    //       Break.write(angle);           
    //       delay(100);       
    //     }
    //     delay(1000);
    //   ph_shift.write(NORMAL);
    //   for(int angle = BREAK; angle < NO_BREAK; angle+=15)  
    //     {                                  
    //       Break.write(angle);               
    //       delay(100);                   
    //     }
    // }

     

    if (Serial.available() > 0){
      String msg = Serial.readString();
      int num;
      num = msg.toInt();
      
      if(!reverse) {
        esc.writeMicroseconds(0);
        ph_shift.write(DISENGAGE);
        for(int angle = NO_BREAK; angle > BREAK; angle-=15)    
        {                                
          Break.write(angle);           
          delay(100);       
        } 
        delay(1000);

        for(int angle = BREAK; angle < NO_BREAK; angle+=15)  
        {                                  
          Break.write(angle);               
          delay(100);                   
        } 
        ph_shift.write(REVERSE);
        throttle=1410;
        reverse = true;
      }
      
      else {
        esc.writeMicroseconds(0);
        delay(400);
        ph_shift.write(DISENGAGE);
        for(int angle = NO_BREAK; angle > BREAK; angle-=15)    
        {                                
          Break.write(angle);           
          delay(100);       
        } 
        delay(1000);
        for(int angle = BREAK; angle < NO_BREAK; angle+=15)  
        {                                  
          Break.write(angle);               
          delay(100);                   
        }
        ph_shift.write(NORMAL);
        throttle=1410;
        reverse = false;
      }

    }
  }

}
