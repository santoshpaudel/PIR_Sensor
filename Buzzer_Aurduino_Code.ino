//define the pins
int LED = 13;
int PIR = 7;
int Buzzer=5;
int minSecsBetweenEmails = 60; // 1 min
int toneFreq[] = { 150,   
                   326,   
                   564,   
                    }; 
int toneCount = sizeof(toneFreq)/sizeof(int);
 
long lastSend = -minSecsBetweenEmails * 1000l;

void setup() {
  //define the LED and Buzzer pin as output
  pinMode(LED, OUTPUT);
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
    //digitalWrite(Buzzer, HIGH);
    siren();
    if (now > (lastSend + minSecsBetweenEmails * 1000l))
    {
      Serial.println("MOVEMENT");
      lastSend = now;
    }
    
 
  
 

  }
  
  else {
    digitalWrite(LED, LOW);
    noTone(Buzzer);
  }
   delay(500);
}
void siren(){
   for (int i=0; i < toneCount; ++i) {
    tone(Buzzer, toneFreq[i]);
    delay(500);  // Pause for half a second.
  }
  // Loop down through all the tones from finish to start again.
  for (int i=toneCount-1; i >= 0; --i) {
    tone(Buzzer, toneFreq[i]);
    delay(500);
  }
}


