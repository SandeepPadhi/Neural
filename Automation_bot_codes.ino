#include <Servo.h>

#include<PS2X_lib.h>
PS2X ps2x;
Servo myservo1;
Servo myservo2;
Servo myservo3;
static int pos=0;
int o=200;
int p=200;
int F=100;
int y=50;

static int count1=0;
static int count2=0;
static int count3=0;
static int count4=0;
static int count5=0;
static int count6=0;
static int count7=0;
static int flagr3=0;
static int LSA01=39;
static int LSA02=41;
static int LSA03=43;
static int LSA04=45;
static int LSA05=47;
static int LSA06=49;
static int LSA07=51;
static int LSA08=53;
static int tm=0;
static int pr1=0;
static int flag=0;
static int flag2=0;
static int flagup=0;
static int flaggreen=0;
static int flagright=0;
static int flagred=0;
static int count12=0;
const int WP01=2;
const int WP02=3;
const int WP03=4;
const int WP04=5;
const int WD01=26;
const int WD02=27;
const int WD03=28;
const int WD04=29;
static int LVL01T=6;
static int LVL02T=7;


static int pressed=0;
static int upcount=0;
static int rightcount=0;
static int motor=0;
static int t=1;
static int x=0;
static int x1=30;
static int x2=50;
static int x3=20;
static int g=0;
static int value1=96;
static int value2=96;
static int flagleft=0;
static int count11=0;
static int flagr1=0;
static int tm1=0;
static int a=0;
static int b=0;
static int tmech=0;
static int tr=0;
static int servo=0;
static int rightturn=0;
const int servo1=9;//connect your servo pins.
const int servo2=10;






void setup() {
  // put your setup code here, to run once:
ps2x.config_gamepad(25,24,23,22);
pinMode(WP01,OUTPUT);
pinMode(WP02,OUTPUT);
pinMode(WP03,OUTPUT);
pinMode(WP04,OUTPUT);
pinMode(WD01,OUTPUT);
pinMode(WD02,OUTPUT);
pinMode(WD03,OUTPUT);
pinMode(WD04,OUTPUT);
pinMode(servo1,OUTPUT);
pinMode(servo2,OUTPUT);

analogWrite(WP01,0);
analogWrite(WP02,0);
analogWrite(WP03,0);
analogWrite(WP04,0);
digitalWrite(WD01,LOW);
digitalWrite(WD02,LOW);
digitalWrite(WD03,LOW);
digitalWrite(WD04,LOW);

digitalWrite(LVL01T,LOW);
digitalWrite(LVL02T,LOW);

digitalWrite(servo1,LOW);
digitalWrite(servo2,LOW);

tmech=0;


Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 
 // Serial.print("Time: ");
  //tm1 = millis();
  //a=tm1-b;
  //b=tm1;
  
  //prints time since program started
  //Serial.println(a);
  //tm=0;
  
  ps2x.read_gamepad();


  //Codes without the use of joystick

  if(Serial.available())
{   m='0';
    i=-1;
   while(m!='d')//matlab command code ends with character 'd'
   {i=i+1;
    m=Serial.read();
    command[i]=m;
    
   }  
    top=i-1;

/*Following is the communication protocol
 * a moveleft a moveright a rpm a d
 * ex: a 1 2 3 a 0 0 0 a 45 a d
 * here moveleft and moveright is in terms of the delay that will be given to the motors due to image processing for correction
 * rmpm value is the change in rpm values due to image processing for correction
 * 'a' in the string abolve  will symbolize start and end values corresponding to moveright,moveleft and rmp and d symbolizes end of string
 * communication between Matlab and arduino involves sending the delay values and change in rpm values to arduino for error correction obtained from image 
 * processing and machine learning .
 * These delay and rpm values will be send to arduino using the above protocol so that we can distinguish moveleft,moveright and rpm values.
*/
i=0;
if(command[i]=='a')
while(1)
{if(command[i]=='d')
 break;

 count=-1;
 for(;command[i]!='a';i=i+1)
 {count=count+1;
    valuearduino[count]=command[i];
  
  }
  delayleft=atof(valuearduino);
  i=i+1;


  count=-1;
 for(;command[i]!='a';i=i+1)
 {count=count+1;
    valuearduino[count]=command[i];
  
  }
  delayright=atof(valuearduino);
  i=i+1;

  count=-1;
 for(;command[i]!='a';i=i+1)
 {count=count+1;
    valuearduino[count]=command[i];
  
  }
  rpmchange=atof(valuearduino);
  count=-1;

  i=i+1;
  
  
  }

  //moveleft

  Serial.println("left");
  analogWrite(WP01,o);
   digitalWrite(WD01,HIGH);
  analogWrite(WP02,o);
  digitalWrite(WD02,HIGH);
  analogWrite(WP03,p);
 digitalWrite(WD03,HIGH);
  analogWrite(WP04,p);
 digitalWrite(WD04,HIGH);
    delay(15);
 


  //moveright

  analogWrite(WP01,o);
 digitalWrite(WD01,LOW);
  analogWrite(WP02,o);
 digitalWrite(WD02,LOW);
  analogWrite(WP03,p);
 digitalWrite(WD03,LOW);
  analogWrite(WP04,p);
 digitalWrite(WD04,LOW);
    delay(15);


  //change rpm
  x=x+rpmchange;
analogWrite(motor,x);

  


Serial.println("k");//telling matlab that changes are done;

//Servo motor code for shooting disk

  myservo2.attach(10);
  myservo2.write(150);
  delay(400);
  myservo2.write(10);
  delay(400); 
  myservo2.write(150);
  //Serial.println(g);
  delay(1000);
 myservo2.detach();
            


   
      
      
      
      
      
      
      
      }
    
  
 }


  
  


if((ps2x.Button(PSB_PAD_UP))&&(count1==0))
{
  
  count1=1;
  
  }
  
if((ps2x.Button(PSB_PAD_RIGHT))&&(count1==1))
{
  
  Serial.println("up");
 
 analogWrite(WP01,F);
 digitalWrite(WD01,HIGH);
  analogWrite(WP02,F);
 digitalWrite(WD02,LOW);
  analogWrite(WP03,F);
 digitalWrite(WD03,HIGH);
  analogWrite(WP04,F);
 digitalWrite(WD04,LOW);
  delay(15);
  rightcount=rightcount-1;
  flagup=1;
  count1=0;
  pressed=1;
  
  }


 if((ps2x.Button(PSB_PAD_RIGHT))&&(count2==0)&&flagup!=1)
{
  
  count2=1;
  
  }
if((ps2x.Button(PSB_PAD_DOWN))&&(count2==1))
{
  
  Serial.println("right");

     // Serial.println("up1");
    analogWrite(WP01,o);
 digitalWrite(WD01,LOW);
  analogWrite(WP02,o);
 digitalWrite(WD02,LOW);
  analogWrite(WP03,p);
 digitalWrite(WD03,LOW);
  analogWrite(WP04,p);
 digitalWrite(WD04,LOW);
    delay(15);
 
    upcount=upcount+1;
    flagright=1;
    count2=0;
    pressed=1;
  
  }
  
if((ps2x.Button(PSB_PAD_DOWN))&&(count3==0)&&flagright!=1)
{
  
  count3=1;
  
  }
  
if((ps2x.Button(PSB_PAD_LEFT))&&(count3==1))
{
  
  Serial.println("down");

  analogWrite(WP01,F);
 digitalWrite(WD01,LOW);
  analogWrite(WP02,F);
 digitalWrite(WD02,HIGH);
  analogWrite(WP03,F);
 digitalWrite(WD03,LOW);
  analogWrite(WP04,F);
 digitalWrite(WD04,HIGH);
 
  delay(15);

  rightcount=rightcount+1;
  count3=0;
  flag=1;
  pressed=1;
  
  
  }

  if((ps2x.Button(PSB_PAD_LEFT))&&(flag!=1))
{
  
    Serial.println("left");
  analogWrite(WP01,o);
   digitalWrite(WD01,HIGH);
  analogWrite(WP02,o);
  digitalWrite(WD02,HIGH);
  analogWrite(WP03,p);
 digitalWrite(WD03,HIGH);
  analogWrite(WP04,p);
 digitalWrite(WD04,HIGH);
    delay(15);
 

    upcount=upcount-1;
    pressed=1;
    flagleft=1;
  
  
  }
  else
  flag=0;






flagup=0;
flagright=0;


if((ps2x.Button(PSB_GREEN))&&(count5==0))
{
  
  count5=1;
  
  }
if((ps2x.Button(PSB_RED))&&(count5==1))
{
  
  Serial.println("GREEN");
  
  tmech=tmech+1;
switch(tmech)
{
  case 1: x=x1;
        motor=LVL01T;
        servo=servo1;
        Serial.println("mech1");
         analogWrite(LVL01T,x);
         digitalWrite(LVL02T,LOW);
         
         g=1;
        break;
        
       
   case 2:x=x2;
          motor=LVL02T;
          servo=servo2;
          Serial.println("mech2");
         digitalWrite(LVL01T,LOW);
         analogWrite(LVL02T,x);
        
         g=2;
         break;
          
 

  default:tmech=0;
          g=0;
}
          
  
  flaggreen=1;
  count5=0;
  }


 if((ps2x.Button(PSB_RED))&&(count6==0)&&flaggreen!=1)
{
  
  count6=1;
  
  }
if((ps2x.Button(PSB_BLUE))&&(count6==1))
{
  
  Serial.println("RED");
      Serial.println("turn-right");
   analogWrite(WP01,y);
   digitalWrite(WD01,HIGH);
  analogWrite(WP02,y);
   digitalWrite(WD02,HIGH);
  analogWrite(WP03,y);
  digitalWrite(WD03,LOW);
  analogWrite(WP04,y);
  digitalWrite(WD04,LOW);
  delay(200);
    rightturn=rightturn+1;
    flagred=1;
  count6=0;
  }
   
if((ps2x.Button(PSB_BLUE))&&(count7==0)&&flagred!=1)
{
  
  count7=1;
  
  }
  
if((ps2x.Button(PSB_PINK))&&(count7==1))
{
  
  Serial.println("BLUE");
   
  Serial.println("BLUE STOP ALL MOTORS");
  
  analogWrite(LVL01T,0);
  analogWrite(LVL02T,0);
  
  count7=0;
  flag2=1;
  
  }


 if((ps2x.Button(PSB_PINK))&&(flag2!=1))
{
  
  Serial.println("PINK");
  
Serial.println("turn-left");

analogWrite(WP01,y);
 digitalWrite(WD01,LOW);
  analogWrite(WP02,y);
 digitalWrite(WD02,LOW);
  analogWrite(WP03,y);
 digitalWrite(WD03,HIGH);
  analogWrite(WP04,y);
 digitalWrite(WD04,HIGH);
 delay(200);

    rightturn=rightturn-1;
  }
  else
  flag2=0;

  flaggreen=0;
  flagred=0;

  


 


 flag2=0;

 flaggreen=0;
 flagred=0;
  




  if(pressed!=1)
{
analogWrite(WP01,0);
 digitalWrite(WD01,HIGH);
  analogWrite(WP02,0);
 digitalWrite(WD02,HIGH);
  analogWrite(WP03,0);
 digitalWrite(WD03,LOW);
  analogWrite(WP04,0);
 digitalWrite(WD04,LOW);
 delay(15);
  
  
}

else pressed=0;





switch(g)
{
  case 1:x1=x;
         break;
  case 2:x2=x;
         break;
  default: g=0;

}

value1=ps2x.Analog(PSS_RX);

if(value1>=250)
{
Serial.println("RX255")  ;






     
// goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    switch(g)
    {case 1:myservo1.attach(9);
           myservo1.write(170);
           delay(400);
            myservo1.write(10);
            Serial.println(g);
            delay(400); 
            myservo1.write(170);
            delay(1000);
            myservo1.detach();
            break;
     case 2:myservo2.attach(10);
            myservo2.write(150);
            delay(400);
            myservo2.write(10);
             delay(400); 
             myservo2.write(150);
            Serial.println(g);
            delay(1000);
            myservo2.detach();
            break;
                 // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  default: Serial.print(5);
  }
 // goes from 180 degrees to 0 degrees
      
                  // tell servo to go to position in variable 'pos'
    
                 // tell servo to go to position in variable 'pos'
               
  


delay(500);
value1=96;
}






value2=ps2x.Analog(PSS_RY);
//Serial.println(value1);
//delay(2000);
if(value2>250)
{
Serial.println("RY255")  ;
x=x+20;
Serial.println(x);
analogWrite(motor,x);
delay(500);
value2=96;
}

if(value2<10)
{
Serial.println("RY000")  ;
x=x-20;
Serial.println(x);
analogWrite(motor,x);
delay(500);
value2=96;
}





if(ps2x.ButtonPressed(PSB_L1)&&(count11==0))
{
  
  count11=1;
  
  }
  
if((ps2x.ButtonPressed(PSB_R1))&&(count11==1))
{
  
  Serial.println("l1");
  x=x+1;
  Serial.println(x);
  analogWrite(motor,x);
  flagr1=1;
  count11=0;
  
  
  }
  if(ps2x.ButtonPressed(PSB_R1)&&(flagr1!=1))
{
  
  Serial.println("r1");
  
  x=x-1;
  Serial.println(x);
  analogWrite(motor,x);
  
}
else flagr1=0;

if(ps2x.ButtonPressed(PSB_L3)&&(count12==0))
{
  
  count12=1;
  
  }
  
  if(ps2x.ButtonPressed(PSB_R3)&&count12==1)
{
  Serial.println("l3");
  count12=0;
  flagr3=1;
  
  }
if(ps2x.ButtonPressed(PSB_R3)&&flagr3!=1)
{
  Serial.println("R3");
  
  }

  else flagr3=0;

                  
  
  
  
  



 
  
  
  



  





}

