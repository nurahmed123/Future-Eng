/*        Arduino Code

const int numPins = 6;
int pins[numPins] = {A0, A1, A2, A3, A4, A5};

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long startTime = millis();

  for (int i = 0; i < numPins; i++) {
    int value = analogRead(pins[i]);
    Serial.print("Pin ");
    Serial.print(i);
    Serial.print(" value: ");
    Serial.println(value);
  }

  unsigned long endTime = millis();
  unsigned long elapsedTime = endTime - startTime;

  Serial.print("Time to read all analog pins: ");
  Serial.print(elapsedTime);
  Serial.println(" ms");

  delay(1000);
}

*/









////////////////////////////// ESP-32 COde ///////////////////////////
// when high value comes 4095, low --> 0

#include <esp32-hal.h>

int pins[] = {36, 39, 34, 35, 32, 33}; // ADC1 = 1ms
// int pins[] = {25, 26, 27, 12, 14, 13, 4, 0, 2, 15}; // ADC2 = 124ms
// int pins[] = {36, 39, 34, 35, 32, 33, 25, 26, 27, 12, 14, 13, 4, 0, 2, 15}; // ADC1 + ADC2 = 247ms

int num = sizeof(pins) / sizeof(pins[0]);

void setup() {
  Serial.begin(9600);
  // Set CPU frequency to 240 MHz
  setCpuFrequencyMhz(240);
}

void loop() {
  unsigned long startTime = millis();

  for (int i = 0; i < num; i++) {
    int value = analogRead(pins[i]);
    Serial.print("Pin ");
    Serial.print(i);
    Serial.print(" value: ");
    Serial.println(value);
  }

  unsigned long endTime = millis();
  unsigned long elapsedTime = endTime - startTime;

  Serial.print("Time to read all analog pins: ");
  Serial.print(elapsedTime);
  Serial.println(" ms");
  Serial.println("arr length: ");
  Serial.println(num);


  delay(1000);
}





/*
#include <esp32-hal.h>
unsigned long start_time, end_time;

void setup() {
  Serial.begin(9600); // initialize serial communication
  start_time = micros(); // get current time in microseconds
  setCpuFrequencyMhz(180);
}

void loop() {
  int total = 0;
  int a = 545;
  int b = 23;
  int c = 424;
  int d = 9834;
  int e = 345;

  total = a * b * c * d * e ;
/*
# sum er time
180MHZ -> 8microSec
240MHZ -> 12microSec
40MHZ -> value doesn't shoowing
80MHZ -> 150microSec

#multiplication er time
180MHZ -> 8
240MHZ -> 12
40MHZ -> X
80MHZ -> 146 -150
*/ 
/*

  end_time = micros();

  Serial.print("The sum of the 5 numbers is: ");
  Serial.println(total);
  Serial.print("Time taken to execute the sum is: ");
  Serial.print(end_time - start_time);
  Serial.println(" microseconds");

  while (1); // stop execution
}


*/

