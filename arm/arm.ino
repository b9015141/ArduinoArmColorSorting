#include <Arduino.h>
#include <Servo.h>
#include <Pixy2.h>
 
//Arm components
  Servo base, left, right, claw;
  Pixy2 pixy;
  
  bool running = false;
  char action;
  int basePos = 90;
  int leftPos = 90;
  int rightPos = 90;
  int clawPos = 90;

  int color=0;
 

void setup()
{
    base.attach(11);
    left.attach(10);
    right.attach(9);
    claw.attach(6);

    base.write(basePos);
    left.write(leftPos);
    right.write(rightPos);
    claw.write(clawPos);
    
    Serial.begin(115200);    
}

void positions()
{
    String basePosStr = String(basePos);
    String leftPosStr = String(leftPos);
    String rightPosStr = String(rightPos);
    String clawPosStr = String(clawPos);

    // String midPosStr = String(midPos);
    String msg = ("base: " + basePosStr + " left: " + leftPosStr + " right: " + rightPosStr + " claw: " + clawPosStr);
    Serial.println(msg);
    delay(250);
}

void loop() { 

  delay(10);
  
  if (color==1){     //RED

     claw.write(90);   //open
     delay(2000); 
  
         
     claw.write(0);  //close
     delay(2000);

     base.write(35); 
     delay(2000);

     claw.write(90);   //open
     delay(2000); 

     claw.write(0);  //close
     delay(2000);
        
     base.write(0); 
     delay(2000);

     claw.write(90);   //open
     delay(2000);   
  }
    else if (color==2){    //GREEN

     claw.write(90);   //open
     delay(2000); 
      
     claw.write(0);  //close
     delay(2000);

     base.write(65); 
     delay(2000);

     claw.write(90);   //open
     delay(2000); 

     claw.write(0);  //close
     delay(2000);
        
     base.write(0); 
     delay(2000);

     claw.write(90);   //open
     delay(2000); 
     
    } 

   else if (color==3){     //BLUE

     claw.write(90);   //open
     delay(2000); 
    
     claw.write(0);  //close
     delay(2000);

     base.write(95); 
     delay(2000);

     claw.write(90);   //open
     delay(2000); 

     claw.write(0);  //close
     delay(2000);
        
     base.write(0); 
     delay(2000);

     claw.write(90);   //open
     delay(2000); 
 }

 color=0;
}
