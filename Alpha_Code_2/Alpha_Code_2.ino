void lightUpLetter(); // functions must be declared before setup function
void debugger();

const int potPin = A5; // 10k pot
int state = 0; // which postion the pot is in

String input;
String empty; // empty string for clearing input
bool added = false;

// for the Tri-colour LED
const int redLEDPin = 13;
const int greenLEDPin = 11;
const int blueLEDPin = 12;

// left side buttons
const int button_1 = A0;
const int button_2 = A1;
const int button_3 = A2;

// right side buttons
const int button_4 = 10;
const int button_5 = 9;
const int button_6 = 8;

// left side lights
const int light_1 = 7;
const int light_2 = 6;
const int light_3 = 5;

// right side lights
const int light_4 = 4;
const int light_5 = 3;
const int light_6 = 2;

long randomNumber;

void setup() {
  Serial.begin(9600); // for debugging the pot

  // set up the Tri-colour LED
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);

  // set up the braille buttons
  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);
  pinMode(button_3, INPUT);
  pinMode(button_4, INPUT);
  pinMode(button_5, INPUT);
  pinMode(button_6, INPUT);

  // set up the braille lights
  pinMode(light_1, OUTPUT);
  pinMode(light_2, OUTPUT);
  pinMode(light_3, OUTPUT);
  pinMode(light_4, OUTPUT);
  pinMode(light_5, OUTPUT);
  pinMode(light_6, OUTPUT);

  randomSeed(42);
}

void loop() {
  state = analogRead(potPin);
  debugger();
  
  // CLEAR (white)
  if (state < 20) {

    analogWrite(redLEDPin, 255); // 0 - 255 RGB values
    analogWrite(greenLEDPin, 255);
    analogWrite(blueLEDPin, 255);

    input = empty;
  }

  // NEXT (red)
  if (state > 20 && state < 400) {

    analogWrite(redLEDPin, 255); // 0 - 255 RGB values
    analogWrite(greenLEDPin, 0);
    analogWrite(blueLEDPin, 0);

    added = false; // you can now add another braille letter
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  // WRITE (blue)
  if (state > 400 && state < 730) {

    analogWrite(redLEDPin, 0); // 0 - 255 RGB values
    analogWrite(greenLEDPin, 0);
    analogWrite(blueLEDPin, 255);

    if (digitalRead(button_1) == HIGH) {
      digitalWrite(light_1, HIGH);
      delay(100);
    }

    if (digitalRead(button_2) == HIGH) {
      digitalWrite(light_2, HIGH);
      delay(100);
    }

    if (digitalRead(button_3) == HIGH) {
      digitalWrite(light_3, HIGH);
      delay(100);
    }

    if (digitalRead(button_4) == HIGH) {
      digitalWrite(light_4, HIGH);
      delay(100);
    }

    if (digitalRead(button_5) == HIGH) {
      digitalWrite(light_5, HIGH);
      delay(100);
    }

    if (digitalRead(button_6) == HIGH) {
      digitalWrite(light_6, HIGH);
      delay(100);
    }
  }

  // STORE (purple)
  if (state > 730 && state < 1000) {

    analogWrite(redLEDPin, 180); // 0 - 255 RGB values
    analogWrite(greenLEDPin, 10);
    analogWrite(blueLEDPin, 180);

    // UEB english
    // store & decipher the answers
    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == LOW && digitalRead(light_3) == LOW && digitalRead(light_4) == LOW && digitalRead(light_5) == LOW && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "A"; // need to add it only once, when the pot direction is moved back added becomes true
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == HIGH && digitalRead(light_3) == LOW && digitalRead(light_4) == LOW && digitalRead(light_5) == LOW && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "B"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == LOW && digitalRead(light_3) == LOW && digitalRead(light_4) == HIGH && digitalRead(light_5) == LOW && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "C"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == LOW && digitalRead(light_3) == LOW && digitalRead(light_4) == HIGH && digitalRead(light_5) == HIGH && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "D"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == LOW && digitalRead(light_3) == LOW && digitalRead(light_4) == LOW && digitalRead(light_5) == HIGH && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "E"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == HIGH && digitalRead(light_3) == LOW && digitalRead(light_4) == HIGH && digitalRead(light_5) == LOW && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "F"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == HIGH && digitalRead(light_3) == LOW && digitalRead(light_4) == HIGH && digitalRead(light_5) == HIGH && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "G"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == HIGH && digitalRead(light_3) == LOW && digitalRead(light_4) == LOW && digitalRead(light_5) == HIGH && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "H"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == LOW && digitalRead(light_2) == HIGH && digitalRead(light_3) == LOW && digitalRead(light_4) == HIGH && digitalRead(light_5) == LOW && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "I"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == LOW && digitalRead(light_2) == LOW && digitalRead(light_3) == LOW && digitalRead(light_4) == HIGH && digitalRead(light_5) == HIGH && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "J"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == LOW && digitalRead(light_3) == HIGH && digitalRead(light_4) == LOW && digitalRead(light_5) == LOW && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "K"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == HIGH && digitalRead(light_3) == HIGH && digitalRead(light_4) == LOW && digitalRead(light_5) == LOW && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "L"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == LOW && digitalRead(light_3) == HIGH && digitalRead(light_4) == HIGH && digitalRead(light_5) == LOW && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "M"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == LOW && digitalRead(light_3) == HIGH && digitalRead(light_4) == HIGH && digitalRead(light_5) == HIGH && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "N"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == LOW && digitalRead(light_3) == HIGH && digitalRead(light_4) == LOW && digitalRead(light_5) == HIGH && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "O"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == HIGH && digitalRead(light_3) == HIGH && digitalRead(light_4) == HIGH && digitalRead(light_5) == LOW && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "P"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == HIGH && digitalRead(light_3) == HIGH && digitalRead(light_4) == HIGH && digitalRead(light_5) == HIGH && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "Q"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == HIGH && digitalRead(light_3) == HIGH && digitalRead(light_4) == LOW && digitalRead(light_5) == HIGH && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "R"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == LOW && digitalRead(light_2) == HIGH && digitalRead(light_3) == HIGH && digitalRead(light_4) == HIGH && digitalRead(light_5) == LOW && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "S"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == LOW && digitalRead(light_2) == HIGH && digitalRead(light_3) == HIGH && digitalRead(light_4) == HIGH && digitalRead(light_5) == HIGH && digitalRead(light_6) == LOW) {

      if (added == false) {
        input += "T"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == LOW && digitalRead(light_3) == HIGH && digitalRead(light_4) == LOW && digitalRead(light_5) == LOW && digitalRead(light_6) == HIGH) {

      if (added == false) {
        input += "U"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == HIGH && digitalRead(light_3) == HIGH && digitalRead(light_4) == LOW && digitalRead(light_5) == LOW && digitalRead(light_6) == HIGH) {

      if (added == false) {
        input += "V"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == LOW && digitalRead(light_2) == HIGH && digitalRead(light_3) == LOW && digitalRead(light_4) == HIGH && digitalRead(light_5) == HIGH && digitalRead(light_6) == HIGH) {

      if (added == false) {
        input += "W"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == LOW && digitalRead(light_3) == HIGH && digitalRead(light_4) == HIGH && digitalRead(light_5) == LOW && digitalRead(light_6) == HIGH) {

      if (added == false) {
        input += "X"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == LOW && digitalRead(light_3) == HIGH && digitalRead(light_4) == HIGH && digitalRead(light_5) == HIGH && digitalRead(light_6) == HIGH) {

      if (added == false) {
        input += "Y"; // need to add it only once
        added = true;
      }
    }

    if (digitalRead(light_1) == HIGH && digitalRead(light_2) == LOW && digitalRead(light_3) == HIGH && digitalRead(light_4) == LOW && digitalRead(light_5) == HIGH && digitalRead(light_6) == HIGH) {

      if (added == false) {
        input += "Z"; // need to add it only once
        added = true;
      }
    }

  }



  // SEND & RESPONSE (green)
  if (state > 1000) {
    analogWrite(redLEDPin, 0); // 0 - 255 RGB values
    analogWrite(greenLEDPin, 255);
    analogWrite(blueLEDPin, 0);

    // clear whats already on lights
    delay(200);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);

    // answer back using the lights as braille patterns
    if (input == "HI") {
      lightUpLetter('H'), lightUpLetter('E'), lightUpLetter('L'), lightUpLetter('L'), lightUpLetter('O');
    }

    if (input == "ALPHABET") {
      char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // an extra space is needed for the null terminating character
      for (int index = 0; index < 26; index ++) {
        lightUpLetter(alphabet[index]);
      }
    }

    // I've layed down the framework, theres is a lot that can be said,
    // you can turn this into a unique braille chatbot or even a text adventure game
    // you can even use it as a braille teaching tool
    if (input == "TALK") {
      randomNumber = random(0, 26);

      char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // an extra space is needed for the null terminating character
      for (int index = randomNumber; index < 26; index ++) {
        for (int index = randomNumber; index < 26; index ++) {
          lightUpLetter(alphabet[index]);
        }
      }
    }
    
  }

  
}



// EXTRA FUNCTIONS ------------------------------------------------------------------------------

void lightUpLetter(char letter) {

  if (letter == 'A') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'B') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'C') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'D') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, HIGH);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'E') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, HIGH);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'F') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'G') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, HIGH);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'H') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, HIGH);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'I') {
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'J') {
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, HIGH);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'K') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'L') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'M') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'N') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, HIGH);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'O') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, HIGH);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'P') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'Q') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, HIGH);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'R') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, HIGH);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'S') {
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'T') {
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, HIGH);
    digitalWrite(light_6, LOW);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'U') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, HIGH);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'V') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, HIGH);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'W') {
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, HIGH);
    digitalWrite(light_6, HIGH);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'X') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, HIGH);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'Y') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, HIGH);
    digitalWrite(light_6, HIGH);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }

  else if (letter == 'Z') {
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, HIGH);
    digitalWrite(light_6, HIGH);
    delay(1000);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
  }
}



void debugger() {
  // comment out what you need
  Serial.print(input);
  //Serial.print("pot stare: ");
  //Serial.print(state); // min 0 - 1023 max
  Serial.println();
  delay(100);

  //Serial.print("button 1: ");
  //Serial.print(digitalRead(button_1));
  //Serial.println();
  //delay(300);
  //
  //Serial.print("button 2: ");
  //Serial.print(digitalRead(button_2));
  //Serial.println();
  //delay(300);
  //
  //Serial.print("button 3: ");
  //Serial.print(digitalRead(button_3));
  //Serial.println();
  //delay(300);
  //
  //Serial.print("button 4: ");
  //Serial.print(digitalRead(button_4));
  //Serial.println();
  //delay(300);
  //
  //Serial.print("button 5: ");
  //Serial.print(digitalRead(button_5));
  //Serial.println();
  //delay(300);
  //
  //Serial.print("button 6: ");
  //Serial.print(digitalRead(button_6));
  //Serial.println();
  //delay(300);
}
