// Version 1.0 Working
// FlipperFinger AE
// vars
const int links = 13;
const int rechts = 12;
const int lout = 7;
const int rout = 6;
int lcnt = 0;
int rcnt = 0;

void setup() {
  
  // Input Pins
  pinMode(links, INPUT_PULLUP);
  pinMode(rechts, INPUT_PULLUP);
  // Output Pins
  pinMode(lout, OUTPUT);
  pinMode(rout, OUTPUT);

  //Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // Links
  if(digitalRead(links) == LOW)
  {
    lcnt++;
    if(lcnt > 1000)
    {
      digitalWrite(lout, LOW); 
      //Serial.println('Links zulange');
    }
    else
    {
      digitalWrite(lout, HIGH);
      //Serial.println('Links AN');
    }
  }
  else
  {
    digitalWrite(lout, LOW); 
    //Serial.println('Links AUS');
    lcnt = 0;
  }
  // Rechts
  if(digitalRead(rechts) == LOW)
  {
    rcnt++;
    if(rcnt > 1000)
    {
      digitalWrite(rout, LOW); 
      //Serial.println('Rechts zulange');
    }
    else
    {
      digitalWrite(rout, HIGH);
      //Serial.println('Rechts AN');
    }
  }
  else
  {
    digitalWrite(rout, LOW);
    //Serial.println('Rechts AUS');
    rcnt = 0;
  }
  delay(1);
}
