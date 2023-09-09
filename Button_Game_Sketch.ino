const int switchPin3 = 3;
const int switchPin12 = 12;
const int ledPin2 = 2;
const int ledPin13 = 13;
const int size = 30;
const int left = 1;
const int right = 2;
boolean buttonFlag = true;
int score = 0;
int switchState = 0;
int directions[size];

void lightLed(int direction, int storedDirection, int pin) {
  if(direction == storedDirection) {
    delay(500);
    digitalWrite(pin, HIGH);
    delay(1000);
    digitalWrite(pin, LOW);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin13, OUTPUT);
  pinMode(switchPin3, INPUT);
  pinMode(switchPin12, INPUT);
  randomSeed(analogRead(0));

  for(int i = 0; i < size; i++) {
    directions[i] = random(2) + 1;
  }
}

void loop() {
  for(int i = 0; i < size; i++) {
    if(score >= i) {
      lightLed(left, directions[i], ledPin2);
      lightLed(right, directions[i], ledPin13);
    }
  }

  int count = 0;
  while(true) {
    int pressedDirection;

    if(!digitalRead(switchPin3) && !digitalRead(switchPin12)) {
      buttonFlag = false;
    }
    
    if(digitalRead(switchPin3) == HIGH && buttonFlag == false) {
      buttonFlag = true;
      pressedDirection = left;
      if(pressedDirection != directions[count]) {
        count = 0;
        break;
      }
      count++;
    } else if(digitalRead(switchPin12) == HIGH && buttonFlag == false) {
      buttonFlag = true;
      pressedDirection = right;
      if(pressedDirection != directions[count]) {
        count = 0;
        break;
      }
      count++;
    }

    if(count > score) {
      score++;
      buttonFlag = true;
      break;
    }
  }
}