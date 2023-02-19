// Version 0.8 need some timing fixing?
// Schlagtürme AE
// vars
const int turm1 = 7;
const int turm2 = 4;
const int t1out = 6;
const int t2out = 5;
int t1cnt = 0;
int t2cnt = 0;

void setup() {
  
  // Input Pins
  pinMode(turm1, INPUT_PULLUP);
  pinMode(turm2, INPUT_PULLUP);
  // Output Pins
  pinMode(t1out, OUTPUT);
  pinMode(t2out, OUTPUT);

 //Serial.begin(9600);
  
}

void loop() {
  // Turm 1
  if(digitalRead(turm1) == LOW)
  {
    t1cnt++;
    if(t1cnt > 2)
    {
      digitalWrite(t1out, LOW); 
      //Serial.println('Links zulange');
    }
    else
    {
      analogWrite(t1out, 64); // 64 / 255 = 25%
      delay(15); // Für eine Sekunde?
      digitalWrite(t1out, LOW); // dann wieder aus.
      //Serial.println('Links AN');
    }
  }
  else
  {
    digitalWrite(t1out, LOW); 
    //Serial.println('Links AUS');
    t1cnt = 0;
  }
  // Turm 2
  if(digitalRead(turm2) == LOW)
  {
    t2cnt++;
    if(t2cnt > 2)
    {
      digitalWrite(t2out, LOW); 
      //Serial.println('Rechts zulange');
    }
    else
    {
      analogWrite(t2out, 64); // 64 / 255 = 25%
      delay(15); // Für eine Sekunde?
      digitalWrite(t2out, LOW); // dann wieder aus.
      //Serial.println('Rechts AN');
    }
  }
  else
  {
    digitalWrite(t2out, LOW);
    //Serial.println('Rechts AUS');
    t2cnt = 0;
  }
  delay(1);
}
