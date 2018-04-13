//define the pins
int LED = 13;
int PIR = 7;
//int Buzzer = 2;
int minSecsBetweenEmails = 60; // 1 min
 
long lastSend = -minSecsBetweenEmails * 1000l;

void setup() {
  //define the LED and Buzzer pin as output
  pinMode(LED, OUTPUT);
  //pinMode(Buzzer, OUTPUT);
  //define the sensor pin as input
  pinMode(PIR, INPUT);
  Serial.begin(9600);
}

void loop() {
  //using the digitalRead function we will read the signal of the sensor
  int value = digitalRead(PIR);
   long now = millis();
  //if its high or if an any object is detected it will activate the LED 
  if (value == HIGH){
    digitalWrite(LED, HIGH);
    if (now > (lastSend + minSecsBetweenEmails * 1000l))
    {
      Serial.println("MOVEMENT DETECTED");
      lastSend = now;
    }
    
  }
  
 
   // digitalWrite(Buzzer, HIGH);
  
  else {
    digitalWrite(LED, LOW);
    //digitalWrite(Buzzer, LOW);
  }
   delay(500);
}
