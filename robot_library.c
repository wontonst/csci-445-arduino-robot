// Community of Robots//

//Dc motor example code//

int motorpinRR = 3;                  //define digital output pin no.

int motorpinRL = 4;                  //define digital output pin no.

int motorpinLR = 5;

int motorpinLL = 6;

void setup () {

  pinMode(motorpinRR,OUTPUT);        //set pin 3 as output
pinMode(motorpinRL,OUTPUT);
  pinMode(motorpinLR,OUTPUT);        // set pin 4 as output
pinMode(motorpinLL,OUTPUT);
}

void loop () {

  forward();
  delay(2000);
  stop();
  delay(1500);
  reverse();
  delay(2000);
  stop();
  delay(1500);
  turnRight();
  delay(2000);
  stop();
  delay(1500);
  turnLeft();
  delay(2000);
  stop();
  delay(1500);
}

void stop(){
 digitalWrite(motorpinRR,LOW); 
  digitalWrite(motorpinRL,LOW); 
   digitalWrite(motorpinLR,LOW); 
    digitalWrite(motorpinLL,LOW); 
}

void forward(){
  digitalWrite(motorpinRR, HIGH);
  digitalWrite(motorpinRL, LOW);
  digitalWrite(motorpinLR, HIGH);
  digitalWrite(motorpinLL,LOW);  
}

void reverse(){
  digitalWrite(motorpinRR, LOW);
  digitalWrite(motorpinRL, HIGH);
  digitalWrite(motorpinLR, LOW);
  digitalWrite(motorpinLL,HIGH);  
}

void turnRight()
{
  digitalWrite(motorpinRR, HIGH);
  digitalWrite(motorpinRL, LOW);
  digitalWrite(motorpinLR, LOW);
  digitalWrite(motorpinLL,HIGH);  
}

void turnLeft()
{
  digitalWrite(motorpinRR, LOW);
  digitalWrite(motorpinRL, HIGH);
  digitalWrite(motorpinLR, HIGH);
  digitalWrite(motorpinLL,LOW);  
}

