int LSpd=10;                  // Left Motor Speed (0-255)
int RSpd=11;                  // Right Motor Speed (0-255)
int LDir=12;                  // Left Motor Direction (HIGH=Reverse, LOW=Forward)
int RDir=13;                  // Right Motor Direction (HIGH=Reverse, LOW=Forward)
int LFRL=8;                   // Left LFR IR Sensor (HIGH= WHITE,LOW= BLACK)
int LFRR=9;                   // Right LFR IR Sensor (HIGH= WHITE,LOW=BLACK)
int TCSclr=7;                 // TCS 230 Colour Detection
int PATHL=5;                   // Left PATH IR Sensor (HIGH= WHITE,LOW= BLACK)
int PATHR=6;                   // Right PATH IR Sensor (HIGH= WHITE,LOW= BLACK)
void setup() {

// Set pin modes
pinMode(LSpd,OUTPUT);
pinMode(RSpd,OUTPUT);
pinMode(LDir,OUTPUT);
pinMode(RDir,OUTPUT);  
pinMode(LFRL,INPUT);
pinMode(LFRR,INPUT);  
pinMode(PATHL,INPUT);
pinMode(PATHR,INPUT);
pinMode(TCSclr,INPUT);

// Initiate Motors
digitalWrite(LDir,LOW);
digitalWrite(RDir,LOW);
analogWrite(LSpd,0);
analogWrite(RSpd,0);

}

void loop() {
  
//LINE FOLLOWING MECHANISM
if(digitalRead(PATHL) && digitalRead(PATHR))
{
  // Stop Moving At Checkpoint
  delay(100);
  digitalWrite(LDir,LOW);
  digitalWrite(RDir,LOW);
  analogWrite(LSpd,0);
  analogWrite(RSpd,0);
}
else if(digitalRead(LFRL) && digitalRead(LFRR)==0)      // Goes a little LEFT of track
  {
    analogWrite(RSpd,200);                            // Slow the Right Motor
  }
else if(digitalRead(LFRL)==0 && digitalRead(LFRR))      // Goes a little RIGHT of track
  {
    analogWrite(LSpd,200);                            // Slow the Left Motor
  }  
else
{                         
  analogWrite(LSpd,200);                              // Can Be Increased to 255 AT WILL           
  analogWrite(RSpd,200);                              // Can Be Increased to 255 AT WILL
}
//LINE WILL BE FOLLOWED DDHANG SE ^_^


//180 DEGREE ROTATION AT RED COLOUR

if(analogRead(TCSclr)==12)                                  // Red Input
{
  // Clockwise Rotation of Bot 
  digitalWrite(LDir,LOW);
  digitalWrite(RDir,HIGH);
  analogWrite(LSpd,200);
  analogWrite(RSpd,200);
  delay(2500);                // 5 sec should be enough for 180 degree rotation
}

// TURNING CONTROL

if(digitalRead(PATHL)==0 && digitalRead(LFRL)==0 && digitalRead(PATHR) &&digitalRead(LFRR))      // LEFT Path Available  [straight also might be there]
{
  digitalWrite(LDir,HIGH);
  digitalWrite(RDir,LOW);
  analogWrite(LSpd,50);
  analogWrite(RSpd,255);
  delay(1500);                            // Let it rotate 90 Degrees
  digitalWrite(LDir,LOW);
  digitalWrite(RDir,LOW);
  analogWrite(LSpd,255);
  analogWrite(RSpd,255);
  delay(1500);                            // Let it come a little forward on that path
  
}
else
{ 
  if(digitalRead(PATHL) && digitalRead(LFRL) && digitalRead(PATHR)==0 &&digitalRead(LFRR)==0)      // RIGHT Path Available [straight also might be there]
  { delay(400);                            // 1 Second should be enough to pass the track on its right.
    if(analogRead(TCSclr)==10)          // white input
    {
    digitalWrite(LDir,LOW);
    digitalWrite(RDir,HIGH);
    analogWrite(LSpd,255);
    analogWrite(RSpd,50);
    delay(1500);                            // Let it rotate 90 Degrees
    digitalWrite(LDir,LOW);
    digitalWrite(RDir,LOW);
    analogWrite(LSpd,255);
    analogWrite(RSpd,255);
    delay(1500);                             // Let it come a little forward on that path
    }
    else                                     // If STRAIGHT PATH is available, keep going forward
    {
    analogWrite(RSpd,255);
    analogWrite(LSpd,255);
    }
  }
  else 
    if(digitalRead(PATHL)==0 && digitalRead(LFRL)==0 && digitalRead(PATHR)==0 &&digitalRead(LFRR)==0)      // LEFT & RIGHT Paths Available [straight also might be there]
    {
    //ROTATE TOWARDS THE LEFT PATH
    digitalWrite(LDir,HIGH);
    digitalWrite(RDir,LOW);
    analogWrite(LSpd,50);
    analogWrite(RSpd,255);
    delay(1500);                            // Let it rotate 90 Degrees
    digitalWrite(LDir,LOW);
    digitalWrite(RDir,LOW);
    analogWrite(LSpd,255);
    analogWrite(RSpd,255);
    delay(1500);                            // Let it come a little forward on that path
    }
  }




























}
