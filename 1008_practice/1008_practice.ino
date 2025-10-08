const int buttonPin = 2;
const int rLEDPin = 3;
const int gLEDPin = 4;
const int bLEDPin = 5;

int buttonState = 0;
int ledstate = LOW;
int ledcolor = 0;

bool ButtonPressed = false;
unsigned long previousMillis = 0;
const long interval = 1000;
bool ledColorOrder = true;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(rLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

  buttonState = digitalRead(buttonPin);
 

  if(buttonState == HIGH && !ButtonPressed) {
  ledcolor = ledcolor + 1;
  ButtonPressed = true;
  } 
  if(buttonState == LOW && ButtonPressed){
  ButtonPressed = false;
  }

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if(ledColorOrder == true) {
      ledcolor = ledcolor + 1;
      if(ledcolor > 3)
      ledcolor = 0;

    } 
    else {
      ledcolor = ledcolor - 1;
      if(ledcolor < 0)
      ledcolor = 3;
    }
  }

  else if (ledcolor == 0){

  digitalWrite(rLEDPin, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(gLEDPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(bLEDPin, HIGH);
  }

  else if (ledcolor == 1){
  
  digitalWrite(rLEDPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(gLEDPin, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(bLEDPin, HIGH);
  }

  else if (ledcolor == 2){
  
  digitalWrite(rLEDPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(gLEDPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(bLEDPin, LOW);
  }

  else if (ledcolor == 3){
 
  digitalWrite(rLEDPin, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(gLEDPin, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(bLEDPin, LOW);
  }
}