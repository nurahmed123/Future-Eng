/*
#define pushButton_pin   33
#define LED_pin   32
void IRAM_ATTR toggleLED()
{
  digitalWrite(LED_pin, !digitalRead(LED_pin));
}
void setup()
{
  pinMode(LED_pin, OUTPUT);
  pinMode(pushButton_pin, INPUT_PULLUP);
  attachInterrupt(pushButton_pin, toggleLED, RISING);
} 
void loop()
{
}




*/

/*
// Pin numbers
const int buttonPin = 33; // The button is connected to GPIO 32
const int ledPin = 32; // The LED is connected to GPIO 33

// Variables
volatile bool buttonPressed = false; // Flag to indicate if the button was pressed

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as an input with a pull-up resistor
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, HIGH); // Attach the interrupt to the button pin
}

void loop() {
  // Check if the button was pressed
  if (buttonPressed) {
    digitalWrite(ledPin, LOW); // Turn on the LED
    buttonPressed = false; // Reset the flag
  }
  // Check if the button was released
  else if (!digitalRead(buttonPin)) {
    digitalWrite(ledPin, HIGH); // Turn off the LED
    Serial.println(digitalRead(buttonPin));
    Serial.println("called");
  }

  // delay(30000);

}

void buttonInterrupt() {
  buttonPressed = true; // Set the flag
}
*/


/*


const int button_1 = 32;
const int button_2 = 33;
const int button_3 = 34;

void IRAM_ATTR button1(){
  Serial.println("button1 pressed");
}

void IRAM_ATTR button2(){
  Serial.println("button2 pressed");
}

void IRAM_ATTR button3(){
  Serial.println("button3 pressed");
}

void setup(){
  Serial.begin(9600);

  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  pinMode(button_3, INPUT_PULLUP);

  attachInterrupt(button_1, button1, HIGH);
  attachInterrupt(button_2, button2, HIGH);
  attachInterrupt(button_3, button3, HIGH);
}


void loop(){

}
*/

/*
#define button_1 32
#define button_2 33
#define button_3 34

void IRAM_ATTR button1(){
  Serial.println("button1 pressed");
}

void IRAM_ATTR button2(){
  Serial.println("button2 pressed");
}

void IRAM_ATTR button3(){
  Serial.println("button3 pressed");
}

void setup()
{
  Serial.begin(9600);

  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  pinMode(button_3, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(button_1), button1, FALLING);
  attachInterrupt(digitalPinToInterrupt(button_2), button2, FALLING);
  attachInterrupt(digitalPinToInterrupt(button_3), button3, FALLING);
} 
void loop()
{
}
*/

//-------------#TODO: without debounce ------
/*

// Define pin numbers for buttons
const int buttonPin1 = 32;
const int buttonPin2 = 33;
const int buttonPin3 = 36;
const int buttonPin4 = 35;
const int buttonPin5 = 34;
const int buttonPin6 = 39;

// Define messages to print for each button
const char* message1 = "Button 1 pressed";
const char* message2 = "Button 2 pressed";
const char* message3 = "Button 3 pressed";
int b1=0;
int b2=0;
int b3=0;
int b4=0;
int b5=0;
int b6=0;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin1), button1Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), button2Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin3), button3Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin4), button4Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin5), button5Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin6), button6Pressed, FALLING);
}

void loop() {
  // Empty loop
  Serial.print(b1);
  Serial.print("  ");
  Serial.print(b2);
  Serial.print("  ");
  Serial.print(b3);
  Serial.print("  ");
  Serial.print(b4);
  Serial.print("  ");
  Serial.print(b5);
  Serial.print("  ");
  Serial.print(b6);
  Serial.println("  ");
  

}

void button1Pressed() {
  // Serial.println("m");
  b1++;
}

void button2Pressed() {
  // Serial.println(message2);
  b2++;
}

void button3Pressed() {
  b3++;
}

void button4Pressed() {
  b4++;
}

void button5Pressed() {
  b5++;
}

void button6Pressed() {
  b6++;
}



*/





//--------------#TODO: with debounce -------------
/*
#include <ezButton.h>
// Define pin numbers for buttons
ezButton buttonPin1 (32);
ezButton buttonPin2 (33);
ezButton buttonPin3 (36);
ezButton buttonPin4 (35);
ezButton buttonPin5 (34);
ezButton buttonPin6 (39);

int b1=0;
int b2=0;
int b3=0;
int b4=0;
int b5=0;
int b6=0;

volatile bool buttonPin1Satus = false;
volatile bool buttonPin2Satus = false;
volatile bool buttonPin3Satus = false;
volatile bool buttonPin4Satus = false;
volatile bool buttonPin5Satus = false;
volatile bool buttonPin6Satus = false;

void setup() {
  Serial.begin(115200);
  // pinMode(buttonPin1, INPUT_PULLUP);
  // pinMode(buttonPin2, INPUT_PULLUP);
  // pinMode(buttonPin3, INPUT_PULLUP);
  // pinMode(buttonPin4, INPUT_PULLUP);
  // pinMode(buttonPin5, INPUT_PULLUP);
  // pinMode(buttonPin6, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin1), button1Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), button2Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin3), button3Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin4), button4Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin5), button5Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin6), button6Pressed, FALLING);

  button.setDebounceTime(50);
  button.setCountMode(EZCOUNT_CLICKS);
  button.setDoubleClickTime(400);
}

void loop() {
  // Empty loop
  buttonPin1.loop();
  buttonPin2.loop();
  buttonPin3.loop();
  buttonPin4.loop();
  buttonPin5.loop();
  buttonPin6.loop();

  if (button.isPressed()) {
    buttonPin1Satus = !buttonPin1Satus;
    b1++;
  }


  Serial.print(b1);
  Serial.print("  ");
  Serial.print(b2);
  Serial.print("  ");
  Serial.print(b3);
  Serial.print("  ");
  Serial.print(b4);
  Serial.print("  ");
  Serial.print(b5);
  Serial.print("  ");
  Serial.print(b6);
  Serial.println("  ");
  

}

void button1Pressed() {
  // Serial.println("m");
  b1++;
}

void button2Pressed() {
  // Serial.println(message2);
  b2++;
}

void button3Pressed() {
  b3++;
}

void button4Pressed() {
  b4++;
}

void button5Pressed() {
  b5++;
}

void button6Pressed() {
  b6++;
}

*/

/*
#include <ezButton.h>

const int buttonPins[] = {32, 33, 36, 35, 34, 39};
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);
volatile bool buttonStates[numButtons] = {false};

for (int pin = 0; pin < numButtons; pin++){
  ezButton buttons[pin] (buttonPins[pin]);

}

void IRAM_ATTR handleInterrupt() {
  for (int i = 0; i < numButtons; i++) {
    buttons[i].loop();
  }
}

void setup() {
  Serial.begin(115200);

  // Attach interrupts to button pins, trigger on falling edge
  for (int i = 0; i < numButtons; i++) {
    attachInterrupt(digitalPinToInterrupt(buttonPins[i]), handleInterrupt, FALLING);
  }

  // Configure EzButton objects
  for (int i = 0; i < numButtons; i++) {
    buttons[i].setDebounceTime(50);
    buttons[i].setCountMode(EZCOUNT_CLICKS);
    buttons[i].setDoubleClickTime(400);
    buttons[i].setHoldTime(500);
  }
}

void loop() {
  // Check if any button was pressed
  for (int i = 0; i < numButtons; i++) {
    if (buttons[i].isPressed()) {
      buttonStates[i] = !buttonStates[i];
      Serial.print("Button ");
      Serial.print(i + 1);
      Serial.print(" state: ");
      Serial.println(buttonStates[i]);
    }
  }

  // Update EzButton objects
  for (int i = 0; i < numButtons; i++) {
    buttons[i].loop();
  }
}*/
/*

#include <ezButton.h>

const int buttonPins[] = {23, 22, 21, 19, 18, 5};
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);
volatile bool buttonStates[numButtons] = {false};
for (int k = 0; k < numButtons; k++) {
    ezButton buttons[k] (buttonPins[i]);
  }

void IRAM_ATTR handleInterrupt() {
  for (int i = 0; i < numButtons; i++) {
    buttons[i].loop();
  }
}

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  // Attach interrupts to button pins, trigger on falling edge
  for (int i = 0; i < numButtons; i++) {
    if (digitalPinToInterrupt(buttonPins[i]) != NOT_AN_INTERRUPT) {
      attachInterrupt(digitalPinToInterrupt(buttonPins[i]), handleInterrupt, FALLING);
    } else {
      Serial.print("Error: Pin ");
      Serial.print(buttonPins[i]);
      Serial.println(" cannot be used as interrupt pin.");
    }
  }

  // Configure EzButton objects
  for (int i = 0; i < numButtons; i++) {
    buttons[i].setDebounceTime(50);
    buttons[i].setCountMode(EZCOUNT_CLICKS);
    buttons[i].setDoubleClickTime(400);
    buttons[i].setHoldTime(500);
  }
}

void loop() {
  // Check if any button was pressed
  for (int i = 0; i < numButtons; i++) {
    if (buttons[i].isPressed()) {
      buttonStates[i] = !buttonStates[i];
      Serial.print("Button ");
      Serial.print(i + 1);
      Serial.print(" state: ");
      Serial.println(buttonStates[i]);
    }
  }

  // Update EzButton objects
  for (int i = 0; i < numButtons; i++) {
    buttons[i].loop();
  }
}

*/
/*

#include <ezButton.h>

// Define pin numbers for buttons
ezButton buttonPin1 (2);
ezButton buttonPin2 (3);
ezButton buttonPin3 (19);
ezButton buttonPin4 (18);
ezButton buttonPin5 (21);
ezButton buttonPin6 (20);

#define DEBOUNCE_TIME 50 // the debounce time in millisecond, increase this time if it still chatters

int b1=0;
int b2=0;
int b3=0;
int b4=0;
int b5=0;
int b6=0;

void IRAM_ATTR handleInterrupt() {
  buttonPin1.loop();
  buttonPin2.loop();
  buttonPin3.loop();
  buttonPin4.loop();
  buttonPin5.loop();
  buttonPin6.loop();
}

void setup() {
  Serial.begin(115200);
  buttonPin1.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds
  buttonPin2.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds
  buttonPin3.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds
  buttonPin4.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds
  buttonPin5.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds
  buttonPin6.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds

  attachInterrupt(digitalPinToInterrupt(buttonPin1), handleInterrupt, FALLING);  
  attachInterrupt(digitalPinToInterrupt(buttonPin2), handleInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin3), handleInterrupt, FALLING);  
  attachInterrupt(digitalPinToInterrupt(buttonPin4), handleInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin5), handleInterrupt, FALLING);  
  attachInterrupt(digitalPinToInterrupt(buttonPin6), handleInterrupt, FALLING);

}

void loop() {
  buttonPin1.loop();
  buttonPin2.loop();
  buttonPin3.loop();
  buttonPin4.loop();
  buttonPin5.loop();
  buttonPin6.loop();

  // Empty loop
  Serial.print(b1);
  Serial.print("  ");
  Serial.print(b2);
  Serial.print("  ");
  Serial.print(b3);
  Serial.print("  ");
  Serial.print(b4);
  Serial.print("  ");
  Serial.print(b5);
  Serial.print("  ");
  Serial.print(b6);
  Serial.println("  ");
  
  if(buttonPin1.isPressed()){
    b1++;
  }
  if(buttonPin2.isPressed()){
    b2++;
  }
  if(buttonPin3.isPressed()){
    b3++;
  }
  if(buttonPin4.isPressed()){
    b4++;
  }
  if(buttonPin5.isPressed()){
    b5++;
  }
  if(buttonPin6.isPressed()){
    b6++;
  }


}

*/



// const int buttonPin1 = 2;
// const int buttonPin2 = 3;
// const int buttonPin3 = 19;
// const int buttonPin4 = 18;
// const int buttonPin5 = 21;
// const int buttonPin6 = 20;


const int buttonPin1 = 32;
const int buttonPin2 = 33;
const int buttonPin3 = 34; // well
const int buttonPin4 = 35;  //well
const int buttonPin5 = 36;  // well
const int buttonPin6 = 39;  //well
volatile bool buttonPin1_state = LOW;
volatile bool buttonPin2_state = LOW;
volatile bool buttonPin3_state = LOW;
volatile bool buttonPin4_state = LOW;
volatile bool buttonPin5_state = LOW;
volatile bool buttonPin6_state = LOW;
volatile unsigned long last_interrupt_time = 0;
const int debounce_time  = 100;
int b1=0;
int b2=0;
int b3=0;
int b4=0;
int b5=0;
int b6=0;
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin1), interrupt1_handler, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), interrupt2_handler, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonPin3), interrupt3_handler, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonPin4), interrupt4_handler, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonPin5), interrupt5_handler, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonPin6), interrupt6_handler, CHANGE);
}

void loop() {
  Serial.print(b1);
  Serial.print("  ");
  Serial.print(b2);
  Serial.print("  ");
  Serial.print(b3);
  Serial.print("  ");
  Serial.print(b4);
  Serial.print("  ");
  Serial.print(b5);
  Serial.print("  ");
  Serial.print(b6);
  Serial.println("  ");
}
// 01622970142 number phone
void interrupt1_handler() {
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > debounce_time) {
    b1++;
  }
  last_interrupt_time = interrupt_time;
}

void interrupt2_handler() {
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > debounce_time) {
    b2++;
  }
  last_interrupt_time = interrupt_time;
}

void interrupt3_handler() {
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > debounce_time) {
    b3++;
  }
  last_interrupt_time = interrupt_time;
}

void interrupt4_handler() {
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > debounce_time) {
    b4++;
  }
  last_interrupt_time = interrupt_time;
}

void interrupt5_handler() {
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > debounce_time) {
    b5++;
  }
  last_interrupt_time = interrupt_time;
}

void interrupt6_handler() {
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > debounce_time) {
    b6++;
  }
  last_interrupt_time = interrupt_time;
}


