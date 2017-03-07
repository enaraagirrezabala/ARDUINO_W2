/*
  MILIS()


  a couple of leds fading in-out at different rates!


*/
// las constantes no cambian. Define el numero del pines:
const int led1 =  5;// pin 2
const int led2 =  3;// pin 3

// definir direccion de led
#define UP 0
#define DOWN 1

// constants for min and max PWM
const int minPWM = 0;
const int maxPWM = 255;

// State Variable for Fade Direction
byte fadeDirection = UP;

// Variables que cambian :
int fadeValue1 = 0;
int fadeValue2 = 0;

// How smooth to fade?
byte fadeIncrement = 5;

// Normalmente se debería de utilizar "unsigned long" para variables de tiempo
// Ya que el valor rapidamente crece hasta valores que el int no puede guardar
unsigned long previousMillis1;        // guardara la última vez que se guardo el millis
unsigned long previousMillis2;        // guardara la última vez que se guardo el millis



int interval1 = 50;           // intervalo del blink 1 en milisegundos
int interval2 = 20;           // intervalo del blink 2 en milisegundos



void setup() {
  // put pwmLED into known state (off)
  analogWrite(led1, fadeValue1);
  analogWrite(led2, fadeValue2);
}

void doTheFade(unsigned long thisMillis, int led, int interval) {
  // is it time to update yet?
  // if not, nothing happens
  if (thisMillis - previousMillis1 >= interval) {
    // yup, it's time!
    if (fadeDirection == UP) {
      fadeValue1 = fadeValue1 + fadeIncrement;
      if (fadeValue1 >= maxPWM) {
        // At max, limit and change direction
        fadeValue1 = maxPWM;
        fadeDirection = DOWN;
      }
    } else {
      //if we aren't going up, we're going down
      fadeValue1 = fadeValue1 - fadeIncrement;
      if (fadeValue1 <= minPWM) {
        // At min, limit and change direction
        fadeValue1 = minPWM;
        fadeDirection = UP;
      }
    }
    // Only need to update when it changes
    analogWrite(led, fadeValue1);

    // reset millis for the next iteration (fade timer only)
    previousMillis1 = thisMillis;
  }
}

void loop() {
  // get the current time, for this time around loop
  // all millis() timer checks will use this time stamp
  unsigned long currentMillis = millis();

  doTheFade(currentMillis, led1, interval1);
  doTheFade(currentMillis, led2, interval2);
  

}

