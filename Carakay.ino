/*
 * Created by Deniz Karakay // 13-05-2016 ver.1
*/
 //////MUSIC Star Wars////////
#define  C0 16.35
#define Db0 17.32
#define D0  18.35
#define Eb0 19.45
#define E0  20.60
#define F0  21.83
#define Gb0 23.12
#define G0  24.50
#define Ab0 25.96
#define LA0 27.50
#define Bb0 29.14
#define B0  30.87
#define C1  32.70
#define Db1 34.65
#define D1  36.71
#define Eb1 38.89
#define E1  41.20
#define F1  43.65
#define Gb1 46.25
#define G1  49.00
#define Ab1 51.91
#define LA1 55.00
#define Bb1 58.27
#define B1  61.74
#define C2  65.41
#define Db2 69.30
#define D2  73.42
#define Eb2 77.78
#define E2  82.41
#define F2  87.31
#define Gb2 92.50
#define G2  98.00
#define Ab2 103.83
#define LA2 110.00
#define Bb2 116.54
#define B2  123.47
#define C3  130.81
#define Db3 138.59
#define D3  146.83
#define Eb3 155.56
#define E3  164.81
#define F3  174.61
#define Gb3 185.00
#define G3  196.00
#define Ab3 207.65
#define LA3 220.00
#define Bb3 233.08
#define B3  246.94
#define C4  261.63
#define Db4 277.18
#define D4  293.66
#define Eb4 311.13
#define E4  329.63
#define F4  349.23
#define Gb4 369.99
#define G4  392.00
#define Ab4 415.30
#define LA4 440.00
#define Bb4 466.16
#define B4  493.88
#define C5  523.25
#define Db5 554.37
#define D5  587.33
#define Eb5 622.25
#define E5  659.26
#define F5  698.46
#define Gb5 739.99
#define G5  783.99
#define Ab5 830.61
#define LA5 880.00
#define Bb5 932.33
#define B5  987.77
#define C6  1046.50
#define Db6 1108.73
#define D6  1174.66
#define Eb6 1244.51
#define E6  1318.51
#define F6  1396.91
#define Gb6 1479.98
#define G6  1567.98
#define Ab6 1661.22
#define LA6 1760.00
#define Bb6 1864.66
#define B6  1975.53
#define C7  2093.00
#define Db7 2217.46
#define D7  2349.32
#define Eb7 2489.02
#define E7  2637.02
#define F7  2793.83
#define Gb7 2959.96
#define G7  3135.96
#define Ab7 3322.44
#define LA7 3520.01
#define Bb7 3729.31
#define B7  3951.07
#define C8  4186.01
#define Db8 4434.92
#define D8  4698.64
#define Eb8 4978.03
// DURATION OF THE NOTES 
#define BPM 120    //  you can change this value changing all the others
#define H 2*Q //half 2/4
#define Q 60000/BPM //quarter 1/4 
#define E Q/2   //eighth 1/8
#define S Q/4 // sixteenth 1/16
#define W 4*Q // whole 4/4
//L298 Connection   
  const int motorA1  = 5;  
  const int motorA2  = 6;  
  const int motorB1  = 8; 
  const int motorB2  = 9;  
  const int SpeedA = 3;
  const int SpeedB = 10;

 /* int outPins[] = {2,4,7,12,13,14};
  const int led01 = 2;
  const int led02 = 4;
  const int led03 = 7;
  const int led04 = 12;
  const int led05 = 13;
  const int led06 = 14;*/
//Buzzer
  const int buzzer = 11 ;
// Use it to make a delay... without delay() function!
//  long previousMillis = -1000*10;// -1000*10=-10sec. to read the first value. If you use 0 then you will take the first value after 10sec.  
//  long interval = 1000*10;       // interval at which to read battery voltage, change it if you want! (10*1000=10sec)
//  unsigned long currentMillis;   //unsigned long currentMillis;
//Useful Variables
  int i=0;
  int j=0;
  int b=0;
  int state;
  int vSpeed=200;     // Default speed, from 0 to 255
//Millis
int knightCounter = -1;
int knightLight = 0;
unsigned long previousMillis = 0;   
long interval = 50;
int ledState = LOW;
int sensorPin = A1; // select the input pin for ldr
int sensorValue = 0;

void setup() {
    // Set pins as outputs:
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
    pinMode(SpeedA, OUTPUT);
    pinMode(SpeedB, OUTPUT);
   /* pinMode(led01,OUTPUT);
    pinMode(led02,OUTPUT);
    pinMode(led03,OUTPUT);
    pinMode(led04,OUTPUT);
    pinMode(led05,OUTPUT);
    pinMode(led06,OUTPUT);*/
    // for(int p = 0; p < 6; p++) {
  //  pinMode(outPins[p], OUTPUT);
  
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}
 
void loop() {
  //Stop car when connection lost or bluetooth disconnected

  //Save income data to variable 'state'
   if(Serial.available() > 0){     
      state = Serial.read();   
    }
  
  //Change speed if state is equal from 0 to 4. Values must be from 0 to 255 (PWM)
    if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=100;}
    else if (state == '2'){
      vSpeed=180;}
    else if (state == '3'){
      vSpeed=200;}
    else if (state == '4'){
      vSpeed=255;}
 	  
   /*
          digitalWrite(led01,HIGH);          delay(50);
          digitalWrite(led01,LOW);           delay(50);
          
          digitalWrite(led02,HIGH);          delay(50);
          digitalWrite(led02,LOW);           delay(50);

          digitalWrite(led03,HIGH);          delay(50);
          digitalWrite(led03,LOW);           delay(50);
           
          digitalWrite(led04,HIGH);          delay(50);
          digitalWrite(led04,LOW);           delay(50);
            
          digitalWrite(led05,HIGH);          delay(50);
          digitalWrite(led05,LOW);           delay(50);
                
          digitalWrite(led06,HIGH);          delay(50);
          digitalWrite(led06,LOW);           delay(50);
            
          digitalWrite(led05,HIGH);          delay(50);
          digitalWrite(led05,LOW);           delay(50);
                           
          digitalWrite(led04,HIGH);          delay(50);
          digitalWrite(led04,LOW);           delay(50);
          
          digitalWrite(led03,HIGH);          delay(50);
          digitalWrite(led03,LOW);           delay(50);*/
  /***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
    if (state == 'F') {
      Kara();
    	digitalWrite(motorA1,HIGH ); digitalWrite(motorA2, LOW);
        digitalWrite(motorB1, LOW);      digitalWrite(motorB2, LOW);
        analogWrite(SpeedA,vSpeed); 

     
    }
  /**********************Forward Left************************/
 /* //If state is equal with letter 'G', car will go forward left
    else if (state == 'G') {
    	digitalWrite(motorA1, vSpeed); digitalWrite(motorA2, 0);  
        digitalWrite(motorB1, 200);    digitalWrite(motorB2, 0); 
    }*/
  /**********************Forward Right************************/
  /*//If state is equal with letter 'I', car will go forward right
    else if (state == 'I') {
      	digitalWrite(motorA1, vSpeed); digitalWrite(motorA2, LOW); 
        digitalWrite(motorB1, LOW);      digitalWrite(motorB2, 200); 
    }*/
  /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
     if (state == 'B') {
      Kara();
    	digitalWrite(motorA1, LOW);   digitalWrite(motorA2, HIGH); 
        digitalWrite(motorB1, LOW);   digitalWrite(motorB2, LOW); 
              analogWrite(SpeedA,vSpeed); 
    }
  /**********************Backward Left************************/
  /*//If state is equal with letter 'H', car will go backward left
    else if (state == 'H') {
    	analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, 200); analogWrite(motorB2, 0); 
    }*/
  /**********************Backward Right************************/
 /* //If state is equal with letter 'J', car will go backward right
    else if (state == 'J') {
    	analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, 200); 
    }*/
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left
    else if (state == 'L') {
      Kara();
    	digitalWrite(motorA1, LOW);   digitalWrite(motorA2, LOW); 
        digitalWrite(motorB1, HIGH); digitalWrite(motorB2, LOW); 
              analogWrite(SpeedB,vSpeed); 
    }
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
    else if (state == 'R') {
      Kara();
    	digitalWrite(motorA1, LOW);   digitalWrite(motorA2, LOW); 
        digitalWrite(motorB1, LOW);   digitalWrite(motorB2, HIGH);
              analogWrite(SpeedB,vSpeed);  		
    }
  /************************Lights*****************************/
  //If state is equal with letter 'W', turn leds on or of off
    else if (state == 'W') {
      Kara();
      if (i==0){  
    tone(buzzer,LA3,Q); 
    delay(1+Q); //delay duration should always be 1 ms more than the note in order to separate them.
    tone(buzzer,LA3,Q);
    delay(1+Q);     tone(buzzer,LA3,Q);    delay(1+Q);       tone(buzzer,F3,E+S);    delay(1+E+S);       tone(buzzer,C4,S);    delay(1+S);  
    tone(buzzer,LA3,Q);    delay(1+Q);    tone(buzzer,F3,E+S);    delay(1+E+S);    tone(buzzer,C4,S);    delay(1+S);    tone(buzzer,LA3,H);
    delay(1+H);    tone(buzzer,E4,Q);     delay(1+Q);    tone(buzzer,E4,Q);    delay(1+Q);    tone(buzzer,E4,Q);   delay(1+Q);    tone(buzzer,F4,E+S);
    delay(1+E+S);    tone(buzzer,C4,S);    delay(1+S);    tone(buzzer,Ab3,Q);    delay(1+Q);    tone(buzzer,F3,E+S);    delay(1+E+S);    tone(buzzer,C4,S);
    delay(1+S);    tone(buzzer,LA3,H);    delay(1+H);    tone(buzzer,LA4,Q);    delay(1+Q);    tone(buzzer,LA3,E+S);    delay(1+E+S);    tone(buzzer,LA3,S);
    delay(1+S);    tone(buzzer,LA4,Q);    delay(1+Q);    tone(buzzer,Ab4,E+S);    delay(1+E+S);    tone(buzzer,G4,S);    delay(1+S);    tone(buzzer,Gb4,S);
    delay(1+S);    tone(buzzer,E4,S);    delay(1+S);    tone(buzzer,F4,E);    delay(1+E);    delay(1+E);//PAUSE
    tone(buzzer,Bb3,E);    delay(1+E);    tone(buzzer,Eb4,Q);    delay(1+Q);    tone(buzzer,D4,E+S);    delay(1+E+S);    tone(buzzer,Db4,S);
    delay(1+S);    tone(buzzer,C4,S);    delay(1+S);    tone(buzzer,B3,S);    delay(1+S);    tone(buzzer,C4,E);    delay(1+E);    delay(1+E);//PAUSE QUASI FINE RIGA
    tone(buzzer,F3,E);    delay(1+E);    tone(buzzer,Ab3,Q);    delay(1+Q);    tone(buzzer,F3,E+S);    delay(1+E+S);    tone(buzzer,LA3,S);    delay(1+S);    tone(buzzer,C4,Q);
    delay(1+Q);     tone(buzzer,LA3,E+S);    delay(1+E+S);    tone(buzzer,C4,S);    delay(1+S);    tone(buzzer,E4,H);    delay(1+H);     tone(buzzer,LA4,Q);
    delay(1+Q);    tone(buzzer,LA3,E+S);    delay(1+E+S);    tone(buzzer,LA3,S);    delay(1+S);    tone(buzzer,LA4,Q);    delay(1+Q);    tone(buzzer,Ab4,E+S);
    delay(1+E+S);    tone(buzzer,G4,S);    delay(1+S);    tone(buzzer,Gb4,S);    delay(1+S);    tone(buzzer,E4,S);    delay(1+S);    tone(buzzer,F4,E);    delay(1+E);
    delay(1+E);//PAUSE
    tone(8,Bb3,E);    delay(1+E);    tone(buzzer,Eb4,Q);    delay(1+Q);    tone(buzzer,D4,E+S);    delay(1+E+S);    tone(buzzer,Db4,S);    delay(1+S);    tone(buzzer,C4,S);
    delay(1+S);    tone(buzzer,B3,S);    delay(1+S);    tone(buzzer,C4,E);    delay(1+E);    delay(1+E);//PAUSE QUASI FINE RIGA
    tone(buzzer,F3,E);    delay(1+E);    tone(buzzer,Ab3,Q);    delay(1+Q);    tone(buzzer,F3,E+S);    delay(1+E+S);    tone(buzzer,C4,S);    delay(1+S);    tone(buzzer,LA3,Q);
    delay(1+Q);     tone(buzzer,F3,E+S);    delay(1+E+S);    tone(buzzer,C4,S);    delay(1+S);    tone(buzzer,LA3,H);    delay(1+H);    
    delay(2*H); // Send 1KHz sound signal...
      }
      else if (i == 1){
          noTone(buzzer);  
         i=0;
      }
      state='n';
    }
  /**********************Horn sound***************************/
  //If state is equal with letter 'V', play (or stop) horn sound
    else if (state == 'V'){
     
      if (j==0){ 
         Kara(); 
         tone(buzzer, 1000);//Speaker on 
         
         j=1;
      }
      else if (j == 1){
         Kara();
         noTone(buzzer);    //Speaker off 
         j=0;
      }
      state='n';  
    }
    else if(state == 'U'){
          Kara();
                      
    }else if(state == 'u'){
/*        digitalWrite(led01,LOW);
        digitalWrite(led02,LOW);
        digitalWrite(led03,LOW);
        digitalWrite(led04,LOW);
        digitalWrite(led05,LOW);
        digitalWrite(led06,LOW);*/
      }
    
  /***********************Stop*****************************/
  //If state is equal with letter 'S', stop the car
   else if (state == 'S'){
        Kara();
        analogWrite(SpeedB, 0); analogWrite(SpeedA, 0);
          digitalWrite(motorA1, LOW);   digitalWrite(motorA2, LOW); 
        digitalWrite(motorB1, LOW);   digitalWrite(motorB2, LOW);
        
      //  analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
    }
    
  /***********************Battery*****************************/
 
    
    
}
void Kara(){
   unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    
    // reset last knight light
    //digitalWrite(outPins[knightLight], LOW);
    // calc new knight light
    sensorValue = analogRead(sensorPin); // read the value from the sensor
    Serial.print("Sensor:" );
    Serial.println(sensorValue);   
    if(sensorValue < 500){
     tone(buzzer,2000);
     noTone(buzzer);
     
   /* knightLight = knightLight + knightCounter;
    if (knightLight > 5) {
      knightLight = 5;
      knightCounter = -1;
    }
    if (knightLight < 0) {
     knightLight = 0;
     knightCounter = 1;
    }
    // set new knight light
    digitalWrite(outPins[knightLight], HIGH);*/
  }
  } }
 /*void LDRkod(){
   unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    sensorValue = analogRead(sensorPin); // read the value from the sensor
    if(sensorPin<400){
      Kara();
    }
    Serial.println(sensorValue); //prints the values coming from the sensor on the screen
  }
 }*/


