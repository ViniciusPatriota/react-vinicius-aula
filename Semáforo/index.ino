
float valorLum = 0;
const int ledBrancoPin = 2;     // Pino do LED Branco
const int ledVerdePin = 3;      // Pino do LED Verde
const int ledVermelhoPin = 4;   // Pino do LED Vermelho
const int buzzerPin = 5;        // Pino do Buzzer

void setup() {
  Serial.begin(9600);
  pinMode(ledBrancoPin, OUTPUT);
  pinMode(ledVerdePin, OUTPUT);
  pinMode(ledVermelhoPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) {
    char led = Serial.read();

    switch (led) {
      case 'B':
        digitalWrite(ledBrancoPin, HIGH);
        digitalWrite(ledVerdePin, LOW);
        digitalWrite(ledVermelhoPin, LOW);
        digitalWrite(buzzerPin, LOW); 
        break;
      case 'V':
        digitalWrite(ledBrancoPin, LOW);
        digitalWrite(ledVerdePin, HIGH);
        digitalWrite(ledVermelhoPin, LOW);
        digitalWrite(buzzerPin, LOW); 
        break;
      case 'R':
        digitalWrite(ledBrancoPin, LOW);
        digitalWrite(ledVerdePin, LOW);
        digitalWrite(ledVermelhoPin, HIGH);
        digitalWrite(buzzerPin, HIGH); 
        break;
    }
  }
  valorLum = lum.getLumC();
  Serial.println(valorLum);
  delay(2000);
}