#define trigPin 9
#define echoPin 10
const int buzzerPin = 9; // Connect buzzer pin to 8
int duration, distance; //to measure the distance and time taken 

void setup() {
        Serial.begin (9600); 
        //Define the output and input objects(devices)
        pinMode(trigPin, OUTPUT); 
        pinMode(echoPin, INPUT);
        
        
}

void loop() {

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    //when distance is greater than or equal to 200 OR less than or equal to 0,
    the buzzer and LED are off
  if (distance >= 5 || distance <= 0) 
        {
        Serial.println("no object detected");
        
        }
  else {
        Serial.println("object detected \n");
        Serial.print("distance= ");              
        Serial.print(distance);        //prints the distance if it is between the range 0 to 200
        
        // play tone of 400Hz for 500 ms
  }
}
