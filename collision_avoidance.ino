// Motor 1 pins
int motor1pin1 = 2;
int motor1pin2 = 3;
int motor1pwm  = 9;   // PWM pin for speed control

// Motor 2 pins
int motor2pin1 = 4;
int motor2pin2 = 5;
int motor2pwm  = 10;  // PWM pin for speed control

// HC-SR04 pins
int trigPin = 7;
int echoPin = 8;

int motorSpeed = 50;        // 0–255
int stopDistance = 20;       // cm — stop if obstacle closer than this

void setup() {
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor1pwm,  OUTPUT);

  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor2pwm,  OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;   // convert to cm
  return distance;
}

void driveForward(int spd) {
  analogWrite(motor1pwm, spd);
  analogWrite(motor2pwm, spd);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

void driveBackward(int spd) {
  analogWrite(motor1pwm, spd);
  analogWrite(motor2pwm, spd);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void stopMotors() {
  analogWrite(motor1pwm, 0);
  analogWrite(motor2pwm, 0);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}

void loop() {
  long dist = getDistance();
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");

  if (dist > 0 && dist < stopDistance) {
    stopMotors();
  } else {
    driveForward(motorSpeed);
  }

  delay(100);
}