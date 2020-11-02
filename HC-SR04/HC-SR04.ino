#define triggerPin 12 // Trigger Pin
#define echoPin 11 // Echo Pin

void setup() {
   pinMode(triggerPin, OUTPUT);
   pinMode(echoPin, INPUT);   
   
   Serial.begin(9600);
}

void loop() {

   long microseconds, distance;

   digitalWrite(triggerPin, LOW);
   delayMicroseconds(2);
   digitalWrite(triggerPin, HIGH);
   delayMicroseconds(20);
   digitalWrite(triggerPin, LOW);
   //return the lenght of the pulse when it´s changing from LOW to HIGH in microseconds
   microseconds = pulseIn(echoPin, HIGH);
   //0,0342 centimetre/microsecond (speed of sound) to work with HC-SR04  
   distance = microseconds * 0.0342 / 2;
   Serial.print(distance);
   Serial.print("cm");
   Serial.println();
   delay(100);
}
