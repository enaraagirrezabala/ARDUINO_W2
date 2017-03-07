
/*
  Pitido

  circuito constituido por cinco Leds, 5 Resistencias de 220 ohms cada una, cables,
  placa Arduino nano y protoboard.

  Enciender Led por segundo en orden y dejarlo encendido.

  Enara Agirrezabala
  Oinarria: Blink ariketa.

*/

// Definimos las variables que vayamos a utilizar
int dur = 10000; 
int freq = 200; //frecuencia de pitidos en hertz

void setup() {
  // Definimos cada pin como output. Tendremos 4 pins por lo que el contador irá de 0
  //hasta llegar a 5, ya que la primera posición dentro del array es 0 (a0,a1,a2,a3)
  // Abrir el puerto de seial.
  pinMode(10, OUTPUT);
}

void loop() {

  pitido(dur, freq);
  pitido(dur * 2, 440);
  delay(500);
}

void pitido(int d, int f) {
  for (int i = 0; i < d/f; i++) {
    digitalWrite(10, HIGH);
    delayMicroseconds(1000000 / (2 * f));
    digitalWrite(10, LOW);
    delayMicroseconds(1000000 / (2 * f));
  }
}
