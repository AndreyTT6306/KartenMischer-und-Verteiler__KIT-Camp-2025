#include <Stepper.h>

const int stepsPerRevolution = 2048;  
const int buttonPin = 5;
const int playerButtonPin = 3;
const int motor = 7; 
const int ledPin = 4;

int grad;
int players = 0;
int karten = 32;
int ausgabe = 0;
int rausgabe = 0;
int richtung;

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  myStepper.setSpeed(16);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(playerButtonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(motor, 7);

  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  int playerButtonState = digitalRead(playerButtonPin);

  // Spieler hinzufügen
  if (playerButtonState == LOW && players < 10) {
    players++;
    Serial.print("Spieler hinzugefügt: ");
    Serial.println(players);

    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(200);
  }

  ausgabe = karten / players;
  rausgabe = round(ausgabe);

  // Ausgabe
  if (buttonState == LOW && players > 0) {
    grad = stepsPerRevolution / players;

    Serial.print("Starte Spiel mit ");
    Serial.print(players);
    Serial.print(" Spielern. Schrittweite: ");
    Serial.println(grad);

    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);


    for (int i = 0; i < rausgabe; i++){
      for (int i = 0; i < players; i++) {
        myStepper.step(grad);
        delay(100);
        digitalWrite(motor, 1);
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(motor, 0);
        digitalWrite(ledPin, LOW);

      }
      grad = grad *-1;
    }

    players = 0;
    delay(500);
  }
}
