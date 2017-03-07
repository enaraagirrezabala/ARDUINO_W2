/*
  MILIS()


  a couple of leds fading in-out at different rates!


*/
// las constantes no cambian. Define el numero del pines:
const int led1 =  2;// pin 2
const int led2 =  3;// pin 3
const int led3 =  4;// pin 4
const int led4 =  5;// pin 5


// Variables que cambian :
int ledState1 = 0;             // Estado del led 1
int ledState2 = 0;             // Estado del led 2
int ledState3 = 0;             // Estado del led 3
int ledState4 = 0;             // Estado del led 4

// Normalmente se debería de utilizar "unsigned long" para variables de tiempo
// Ya que el valor rapidamente crece hasta valores que el int no puede guardar
unsigned long previousMillis1 = 0;        // guardara la última vez que se guardo el millis
unsigned long previousMillis2 = 0;        // guardara la última vez que se guardo el millis
unsigned long previousMillis3 = 0;        // guardara la última vez que se guardo el millis
unsigned long previousMillis4 = 0;        // guardara la última vez que se guardo el millis



const long interval1 = 1000;           // intervalo del blink 1 en milisegundos
const long interval2 = 1100;           // intervalo del blink 2 en milisegundos
const long interval3 = 1030;           // intervalo del blink 3 en milisegundos
const long interval4 = 1200;           // intervalo del blink 4 en milisegundos





void setup() {
  // Definimos cada digital pin como output. Tendremos 4 pins por lo que el contador irá de 0
  //hasta llegar a 5, ya que la primera posición dentro del array es 0 (a0,a1,a2,a3)
  // Empezar el puerto de serial.
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

}

void loop() {
  // Compruba si la diferencia del valor actual de los millis
  // y el de la última vez que parpadeó es mayor que el intervalo
  // que se ha definido para el parpadeo del blink
  // blink the LED.
  unsigned long currentMillis = millis();


  if (currentMillis - previousMillis1 >= interval1) {
    // guardar la ultima vez que parpadeo
    previousMillis1 = currentMillis;
    // Si el led esta apagado enciendelo, sino apagalo:
    if (ledState1 == LOW) {
      ledState1 = HIGH;
    } else {
      ledState1 = LOW;
    }
    // define el led segun los estados definidos:

    digitalWrite(led1, ledState1);
  }



  if (currentMillis - previousMillis2 >= interval2) {
    // guardar la ultima vez que parpadeo
    previousMillis2 = currentMillis;
    // Si el led esta apagado enciendelo, sino apagalo:
    if (ledState2== LOW) {
      ledState2 = HIGH;
    } else {
      ledState2 = LOW;
    }
    // define el led segun los estados definidos:
    digitalWrite(led2, ledState2);
  }



  if (currentMillis - previousMillis3 >= interval3) {
    // guardar la ultima vez que parpadeo
    previousMillis3 = currentMillis;
    // Si el led esta apagado enciendelo, sino apagalo:
    if (ledState3 == LOW) {
      ledState3 = HIGH;
    } else {
      ledState3 = LOW;
    }
    // define el led segun los estados definidos:

    digitalWrite(led3, ledState3);
  }



  if (currentMillis - previousMillis4 >= interval4) {
    // guardar la ultima vez que parpadeo
    previousMillis4 = currentMillis;
    // Si el led esta apagado enciendelo, sino apagalo:
    if (ledState4 == LOW) {
      ledState4 = HIGH;
    } else {
      ledState4 = LOW;
    }
    // define el led segun los estados definidos:
    digitalWrite(led4, ledState4);
  }

}


