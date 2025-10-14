const int buttonPin = 2;
const int rLEDPin = 3;
const int gLEDPin = 4;
const int bLEDPin = 5;

int buttonState = 0;
int ledcolor = 0;

bool ButtonPressed = false;
String currentcolor="led" ;

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
  Serial.print("Current Color: ");
  Serial.println(currentcolor);

  if(buttonState == HIGH && !ButtonPressed) {
  ledcolor = ledcolor + 1;
  ButtonPressed = true;
  } 
  if(buttonState == LOW && ButtonPressed){
  ButtonPressed = false;
  }


  if (ledcolor == 0){
  currentcolor="LED Off";
  digitalWrite(rLEDPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(gLEDPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(bLEDPin, HIGH);
  }

  else if (ledcolor == 1){
  currentcolor="Red";
  digitalWrite(rLEDPin, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(gLEDPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(bLEDPin, HIGH);
  }

  else if (ledcolor == 2){
  currentcolor="Blue";
  digitalWrite(rLEDPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(gLEDPin, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(bLEDPin, HIGH);
  }

  else if (ledcolor == 3){
  currentcolor="Green";
  digitalWrite(rLEDPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(gLEDPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(bLEDPin, LOW);
  }

  else if (ledcolor == 4){
  currentcolor="Purple";
  digitalWrite(rLEDPin, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(gLEDPin, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(bLEDPin, HIGH);
  }

  else if (ledcolor == 5){
  currentcolor="Yellow";
  digitalWrite(rLEDPin, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(gLEDPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(bLEDPin, LOW);
  }

  else if (ledcolor == 6){
  currentcolor="Cyan";
  digitalWrite(rLEDPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(gLEDPin, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(bLEDPin, LOW);
  }

  else if (ledcolor == 7){
  currentcolor="White";
  digitalWrite(rLEDPin, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(gLEDPin, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(bLEDPin, LOW);
  }

  else if (ledcolor == 8){
    ledcolor = 0;
  }
}