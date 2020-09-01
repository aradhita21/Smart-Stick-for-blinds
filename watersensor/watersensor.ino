const int ledPin =  8;      // the number of the LED pin
int buttonPin=2;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}
 
void loop() {
  // read the state of the pushbutton value:
  
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    //Tone takes three arguments tone(pin, frequency, duration) 
  tone(8, 2000, 1000);
  
  //The loop does not wait for the tone to finish, so lets delay to here 2 seconds to hear
  //one second of noise and one second of silence - essentially a beep
  delay(2000);}
   if (buttonState == LOW){
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
  
}//Close Loop
