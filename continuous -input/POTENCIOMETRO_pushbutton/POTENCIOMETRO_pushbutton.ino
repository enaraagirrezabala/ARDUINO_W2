/*
  vue-METER


  Controlar el número de leds que esta encendido utilizando un potenciometro
  un pushbutton para cambiar valores de voltaje del potenciometro re-mapear
  un segundo pushbutton para encender un led random


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
  pinMode(A0, INPUT); //definir que pin y en que modo pot.
  pinMode(A1, INPUT); // definir push button
  for (int i = 0 ; i < 5; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {

  int val = analogRead (A0); //Leer el valor del pot
  //Imprimir valor en el serial
  Serial.print("val_pot= ");
  Serial.println(val); //ver valores maximos y minimos
  //delay(200);
  val = map(val, 3, 1008, 0, 5); //mapear el valor de val entre 0 y 5
  Serial.print("val_LDR mapeado= ");
  Serial.println(val);

  int val_pushbutton = digitalRead (A1); //Leer el valor del pushbutton
  //Imprimir valor en el serial
  Serial.print("val_pushbutton= ");
  Serial.println(val_pushbutton);

  int val_pushbutton2 = digitalRead (A2); //Leer el valor del pushbutton
  //Imprimir valor en el serial
  Serial.print("val_pushbutton2= ");
  Serial.println(val_pushbutton2);

  if (val_pushbutton == 1) {
    //si el boton está pulsado, cambiar direccion.
    val = map(val, 0, 5, 5, 0);
    Serial.print("val_LDR re- mapeado pushbutton= ");
    Serial.println(val);

  }
  if (val_pushbutton2 == 1) {
    //si el boton está pulsado, encender random led.
    int i= random(0,4);
    digitalWrite(led[i], a);
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
    digitalWrite(led[i], b);
  }

}

