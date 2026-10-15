const int buttonPin = 2;
const int RledPin = 3;
const int GledPin = 6;  
const int BledPin = 5;

int buttonState = 0;
int ledcolor = 0;
int ledState = LOW;
bool ButtonPressed = false;
String currentcolor="led";
unsigned long previousMillis = 0;
const long interval = 1000;

// NEW: fading variables
int fadeValue = 0;              // 0-255
int fadeStep = 0;               // 0 = red->green, 1 = green->blue, 2 = blue->red
unsigned long fadeMillis = 0;
const long fadeInterval = 10;   // ms between each brightness step
void setup() {
//initialize the LED pin as an output
pinMode(RledPin, OUTPUT);
pinMode(GledPin, OUTPUT);
pinMode(BledPin, OUTPUT);
//initialize the pushbutton pin as an input
pinMode(buttonPin, INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
//read the state of the pushbutton value
buttonState = digitalRead(buttonPin);
Serial.print("Current Color: ");
Serial.println(currentcolor);

unsigned long currentMillis = millis();
if (currentMillis - previousMillis >= interval){  // FIX: was >-
  previousMillis = currentMillis;
if (ledState == LOW){
  ledState = HIGH;
} else {
  ledState =LOW;
}
}

if(buttonState == LOW && ButtonPressed == false){
  ledcolor = ledcolor + 1;
  ButtonPressed = true;
  delay(50);
}
if(buttonState == HIGH && ButtonPressed == true){
  ButtonPressed = false;
  delay(50);
}

if(ledcolor == 0){
  currentcolor="LED off";
  digitalWrite(RledPin, HIGH);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, HIGH);
}
else if(ledcolor == 1){
  currentcolor="Red";
  if (ledState ==LOW){
  digitalWrite(RledPin, LOW);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, HIGH);
  } else {
  digitalWrite(RledPin, HIGH);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, HIGH);
  }
}
else if(ledcolor == 2){
  currentcolor="Green";
  if (ledState ==LOW){
  digitalWrite(RledPin, HIGH);
  digitalWrite(GledPin, LOW);
  digitalWrite(BledPin, HIGH);
  } else {
  digitalWrite(RledPin, HIGH);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, HIGH);
  }
}
else if(ledcolor == 3){
  currentcolor="Blue";
  if (ledState ==LOW){
  digitalWrite(RledPin, HIGH);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, LOW);
  } else {
  digitalWrite(RledPin, HIGH);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, HIGH);
  }
}
else if(ledcolor == 4){
  currentcolor="Yellow";
  if (ledState ==LOW){
  digitalWrite(RledPin, LOW);
  digitalWrite(GledPin, LOW);
  digitalWrite(BledPin, HIGH);
  } else {
  digitalWrite(RledPin, HIGH);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, HIGH);
  }
}
else if(ledcolor == 5){
  currentcolor="Purple";
  if (ledState ==LOW){
  digitalWrite(RledPin, LOW);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, LOW);
  } else {
  digitalWrite(RledPin, HIGH);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, HIGH);
  }
}
else if(ledcolor == 6){
  currentcolor="Cyan";
  if (ledState ==LOW){
  digitalWrite(RledPin, HIGH);
  digitalWrite(GledPin, LOW);
  digitalWrite(BledPin, LOW);
  } else {
  digitalWrite(RledPin, HIGH);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, HIGH);
  }
}
else if(ledcolor == 7){
  currentcolor="White";
  if (ledState == LOW){
  digitalWrite(RledPin, LOW);
  digitalWrite(GledPin, LOW);
  digitalWrite(BledPin, LOW);
  } else {
  digitalWrite(RledPin, HIGH);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, HIGH);
  }
}
// NEW: color fading mode
else if(ledcolor == 8){
  currentcolor="Fade";
  if (currentMillis - fadeMillis >= fadeInterval){
    fadeMillis = currentMillis;
    fadeValue = fadeValue + 1;
    if (fadeValue > 255){
      fadeValue = 0;
      fadeStep = fadeStep + 1;
      if (fadeStep > 2){
        fadeStep = 0;
      }
    }
  }
  int redValue = 0;
  int greenValue = 0;
  int blueValue = 0;
  if (fadeStep == 0){          // red -> green
    redValue = 255 - fadeValue;
    greenValue = fadeValue;
  } else if (fadeStep == 1){   // green -> blue
    greenValue = 255 - fadeValue;
    blueValue = fadeValue;
  } else {                     // blue -> red
    blueValue = 255 - fadeValue;
    redValue = fadeValue;
  }
  analogWrite(RledPin, 255 - redValue);
  analogWrite(GledPin, 255 - greenValue);
  analogWrite(BledPin, 255 - blueValue);
}
else if(ledcolor == 9){  
  ledcolor = 0;
}
}
