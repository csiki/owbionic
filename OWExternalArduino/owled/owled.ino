
const int ledPin = 9;
int readOwState();

void setup() {
  
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  digitalWrite(ledPin, LOW);
  
}

void loop() {

  int status = readOwState();

  if (status == 1)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
  
}

int readOwState() {
  int status = 0;
  while (true) {
    while (Serial.available() > 0) {
      status = Serial.parseInt();
      return status;
    }
  }
  return status;
}
