int trigPin = 11;   
int echoPin = 12;    
long duration, cm, duration1 ,cm1;
int trigPin1 = 6;    
int echoPin1 = 7;   

 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}
 
void loop()
{
 
 
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
   digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
    pinMode(echoPin1, INPUT);
  duration1= pulseIn(echoPin1, HIGH);
 
 
 
  cm = (duration/2) / 29.1;
   cm1 = (duration1/2)/29.1;
   if(cm>15&&cm1>15)
   {
    digitalWrite(8,0);
    digitalWrite(9,0);
   }
 
  if(cm<=15)
  {
    digitalWrite(9,0);
    digitalWrite(8,1);
  
  }
if(cm1<=15)
  {
   
    digitalWrite(8,1);
    digitalWrite(9,0);
  
  }
  Serial.print(cm);
  Serial.print("cm");
  Serial.print(cm1);
  Serial.print("cm");
  Serial.println();
  
 
}
