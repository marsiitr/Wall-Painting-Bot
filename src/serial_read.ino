/* Serial read from pi*/
         /*for driving motor*/
#define dir 11
#define pwm 10    
//encoder pins
#define encoderPin1 4
#define encoderPin2 3
//actuator pins to ULN
#define Actuation11 40
#define Actuation12 41
#define Actuation13 42
#define Actuation21 43
#define Actuation22 44
#define Actuation23 45
#define sensor 46

#include <Stepper.h>
//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(0,1);  //rx,tx

const int stepsPerRevolution = 200;
int step0 = 0;          //initial stepper step count
String inStringX = "";
String inStringY = "";
String inStringC = "";
int x = 0;       //x coordinate of the pixel
int y = 0;       //y coordinate of the pixel
int c = 0;       //value of present color
int c1 = 0;      //for storing previous value of color
int y1 = 0;      //for storing previous value of y coordinate
char d = "";
int i = 0;
int bump = 0;

Stepper myStepper1(stepsPerRevolution, 30, 31, 32, 33);           //for changing color
Stepper myStepper2(stepsPerRevolution, 8, 9);                   //for y coordinate

void ActuationOff(void);
void back(void);
void ActuationOn(void);

void setup() {
  Serial.begin(115200);
  while (!Serial){
    ;//wait for serial port to connect.
  }
  Serial.println('A');
  Serial.begin(115200);
  //Serial.println("Hello");
  //pinMode(13,OUTPUT);    //serial out
  pinMode(LED_BUILTIN,OUTPUT);
  //setting stepper speed
  myStepper1.setSpeed(60);
  myStepper2.setSpeed(60);
  
  //defining pin mode for ULN pins
  pinMode(Actuation11,OUTPUT);
  pinMode(Actuation12,OUTPUT);
  pinMode(Actuation13,OUTPUT);
  pinMode(Actuation21,OUTPUT);
  pinMode(Actuation22,OUTPUT);
  pinMode(Actuation23,OUTPUT);

  //defining pin mode for driving motor pins
  pinMode(dir, OUTPUT);
  pinMode(pwm, OUTPUT);

  //defining pin mode for bump sensor
  pinMode(sensor, INPUT);
}

void loop() {
  ActuationOff();                                  //initially markers not in contact
   //Read serial data
  while(Serial.available()>0){
    int inChar = Serial.read();
    d = char(inChar);
    if(isDigit(inChar)&& i==0){
      //convert the incoming byte to char and add it to the string
      inStringX += d;
    }
    if(d=='#'){
      if(i==0){
        i = 1;
        inChar = Serial.read();
        d = char(inChar);
      }
      else{
        i = 2;
        inChar = Serial.read();
        d = char(inChar);
      }
    }
    if(isDigit(inChar)&&i==1){
      inStringY += d;
    }
    if(isDigit(inChar)&&i==2){
      inStringC += d;
    }
    if(inChar == '\n'){
      x = inStringX.toInt();
      y = inStringY.toInt();
      c = inStringC.toInt();
      
      Serial.print("Start ");
      Serial.print(x);
      Serial.print(" ");
      Serial.print(y);
      Serial.print(" ");
      Serial.print(c);
      
      //mov(x,y);
      inStringX = "";
      inStringY = "";
      inStringC = "";
      i = 0;
      int y0 = y-y1;
      if(y0==0){
        continue;
      }
      else{
        back();
        myStepper2.step(100);
      }

      color(c,x);

      c1 = c;
      y1 = y;
      
      Serial.println('A');
      //Serial.write('A');
      delay(200);
    }
  }
}

void color(int c,int x){
  int step1 = c*1000;
  int stepIN = step1-step0;
  int c0 = c1-c;
  if(c==5){
    ActuationOff();               //markers not in contact when color is white
    //continue printing
  }
  else{
  if(c0==0){
    ActuationOn();                //marker in contact with wall
    //continue printing
  }
  else{
    ActuationOff();               //marker wall contact break
    //stepper action
    myStepper1.step(stepIN);      //setting marker color
    delay(1500);
    ActuationOn();                //markers in contact with wall
    //continue printing    
  }
step0 = stepIN;
}
}

void ActuationOn(void){
  digitalWrite(Actuation11,HIGH);
  digitalWrite(Actuation12,HIGH);
  digitalWrite(Actuation13,HIGH);
  digitalWrite(Actuation21,LOW);
  digitalWrite(Actuation22,LOW);
  digitalWrite(Actuation23,LOW);
}

void ActuationOff(void){
  digitalWrite(Actuation11,LOW);
  digitalWrite(Actuation12,LOW);
  digitalWrite(Actuation13,LOW);
  digitalWrite(Actuation21,HIGH);
  digitalWrite(Actuation22,HIGH);
  digitalWrite(Actuation23,HIGH);
}
void back(void){
  digitalWrite(dir,LOW);
  while(bump != HIGH){
    bump = analogRead(sensor);
    analogWrite(pwm,60);
  }
}
