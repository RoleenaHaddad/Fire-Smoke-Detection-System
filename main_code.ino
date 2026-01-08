int V_GasSen = 0;
int V_TempSens = 0;

void setup() {
  pinMode(A0, INPUT);  // Gas Sensor
  pinMode(7, OUTPUT); // Buzzer
  pinMode(4, OUTPUT); // Gas LED
  pinMode(A1, INPUT); // Temp Sensor
  pinMode(2, OUTPUT); // Temp LED
}

void loop() {
  V_GasSen = analogRead(A0);
  if (V_GasSen >= 250) {
    tone(7, 523, 1000);
    digitalWrite(4, HIGH); // تم تعديل رقم المنفذ ليتناسب مع setup
  }

  V_TempSens = -40 + 0.488155 * (analogRead(A1) - 20);
  if (V_TempSens >= 70) {
    tone(7, 523, 1000);
    digitalWrite(2, HIGH);
  }
  delay(10);
}
