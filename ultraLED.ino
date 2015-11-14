const int LED_R=9;            //LED 赤
const int LED_G=11;           //LED 緑
const int LED_B=10;           //LED 青
const int echoPin=8; // Echo Pin
const int trigPin=7; // Trigger Pin

int H ;
int R , G , B ;
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LED_R, OUTPUT);
 pinMode(LED_G, OUTPUT);
 pinMode(LED_B, OUTPUT);
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");
 }
 else {
  if(distance<=10){
    analogWrite(LED_R, 150);
    analogWrite(LED_G, 255);
    analogWrite(LED_B, 255);
  }
 
  if(distance>10 and distance<30){
    analogWrite(LED_R, 150);
    analogWrite(LED_G, 150);
    analogWrite(LED_B, 255);
  }
  if(distance>30){
    analogWrite(LED_R, 255);
    analogWrite(LED_G, 150);
    analogWrite(LED_B, 255);
  }  
  
 Serial.println(distance);
 }
 
 //Delay 50ms before next reading.
 delay(50);
}
