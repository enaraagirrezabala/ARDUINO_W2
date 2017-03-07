/*
  vu meter. usando LDRs

  circuito constituido por cinco Leds, 6 Resistencias de 220 ohms cada una, cables, LDR
  placa Arduino nano y protoboard.

  Encender leds segun la cantidad de luz que haya en el lugar.

  Enara Agirrezabala
  Oinarria: Blink ariketa.

*/

// Definimos las variables que vayamos a utilizar
int i;  //contador
int led [] = {2, 3, 4, 5, 6};//Definimos el array que contiene los números de
int b = LOW;
int a = HIGH;

void setup() {
  // Definimos cada pin como output. Tendremos 4 pins por lo que el contador irá de 0
  //hasta llegar a 5, ya que la primera posición dentro del array es 0 (a0,a1,a2,a3)
  // Abrir el puerto de seial.
  Serial.begin(9600);
  pinMode(A0, INPUT); //definir que pin y en que modo LDR.
  pinMode(A1, INPUT); // definir push button
  for (int i = 0 ; i < 5; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {

  int val = analogRead (A0); //Leer el valor del pin 2 y guardarlo como variable v
  //Imprimir valor en el serial
  Serial.print("val_LDR= ");
  Serial.println(val); //ver valores maximos y minimos
  //delay(200);
  val = map(val, 3, 1008, 0, 5); //mapear el valor de val entre 0 y 5
  Serial.print("val_LDR mapeado= ");
  Serial.println(val);
  
  int val_pushbutton = digitalRead (A1); //Leer el valor del pushbutton
  //Imprimir valor en el serial
  Serial.print("val_pushbutton= ");
  Serial.println(val_pushbutton);
  
  if (val_pushbutton == 1) {
    //si el boton está pulsado, cambiar direccion.
    val = map(val, 0, 5, 5, 0);
    Serial.print("val_LDR re- mapeado pushbutton= ");
    Serial.println(val);

  }
  // delay(1000); //Esperar 1s

  if (val > 4) {
    //mayor que 4V,
    digitalWrite(led[0], a);
  }
  if (val > 3) {
    //mayor que 3V
    digitalWrite(led[1], a);
  }

  if (val > 2)  {
    //mayor que 2V
    digitalWrite(led[2], a);
  }
  if (val > 1)  {
    //mayor que 1V
    digitalWrite(led[3], a);
  }
  if (val > 0) {
    //encender todos mayor que 0V
    digitalWrite(led[4], a);
  }
  delay(100);




  //Apagar todos
  for (int i = 0; i < 5; i++) {
    //apagar todos
    digitalWrite(led[i], LOW);
  }

}

