
  int ledPin = 9;
  int button = 10;
  int pressed = 0;
  int brightness =0;
  int potPin =2;
void setup() {
  // put your setup code here, to run once:
 pinMode(ledPin, OUTPUT);
 pinMode(button, INPUT);
 //pinMode(potPin, INPUT);
 Serial.begin(9600);
}

void loop() { 
  // put your main code here, to run repeatedly:
  pressed = digitalRead(button);
  if (pressed == HIGH){

    brightness = analogRead(potPin);
    brightness = brightness/2;
    brightness=brightness-256;
    Serial.print(brightness);
    Serial.print( "\n");
    analogWrite(ledPin, brightness);

    }
else {
    digitalWrite(ledPin, LOW);

}
  

}