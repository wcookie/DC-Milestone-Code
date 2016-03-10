
  int ledPin = 9;
  int button = 10;
  int pressed = 0;
  int brightness =0;
  int potPin =2;
  int secondpressed = 1;
  int secondbutton =6;
  int secondledPin = 5;
  unsigned long time;
  bool off = false;
  int mypot = 0;
void setup() {
  // put your setup code here, to run once:
 pinMode(ledPin, OUTPUT);
 pinMode(button, INPUT);
 pinMode(secondledPin, OUTPUT);
 pinMode(secondbutton, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  pressed = digitalRead(button);
  secondpressed = digitalRead(secondbutton);
  time = millis();
  mypot = analogRead(potPin);
  if (off==false){
    if (time>=60000){
      //set the off variable
      off =true;
      // turn off both LEDs
      digitalWrite(ledPin, LOW);
      digitalWrite(secondledPin, LOW);
    }
    

    else if (mypot < 819 && mypot>614) {
      digitalWrite(ledPin, HIGH);
      //alternate at 10 Hz
      delay(100);
      digitalWrite(ledPin, LOW);
      digitalWrite(secondledPin, HIGH);
      delay(100);
      digitalWrite(secondledPin, LOW);
    }
    
    else if (pressed==LOW && secondpressed==LOW){
    brightness=.75*256;
    analogWrite(ledPin, brightness);
    analogWrite(secondledPin, brightness);
    }
    else if (pressed==LOW && secondpressed==HIGH) {
      brightness=.25*256;
      //set both led to 25%
      analogWrite(ledPin, brightness);
      analogWrite(secondledPin, brightness);
      // wait a sec
      delay(1000);
      //set first to 0 second to 100
      digitalWrite(ledPin, LOW);
      digitalWrite(secondledPin, HIGH);
      //wait a sec
      delay(1000);
      //reset second to 0
      digitalWrite(secondledPin, LOW);
    }
    else if (pressed==HIGH && secondpressed==LOW) {
        brightness=.25*256;
      //set both led to 25%
      analogWrite(ledPin, brightness);
      analogWrite(secondledPin, brightness);
      // wait a sec
      delay(1000);
      //set second to 0 first to 100
      digitalWrite(ledPin, HIGH);
      digitalWrite(secondledPin, LOW);
      //wait a sec
      delay(1000);
      //reset first to 0
      digitalWrite(ledPin, LOW);
    }

  
  }
}

