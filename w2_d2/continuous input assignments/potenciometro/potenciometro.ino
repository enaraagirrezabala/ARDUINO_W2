/*
  Continious output assignments
  Utilizar dos sensores analógicos (resistencias variables) y asignarles
  un valor umbral para controlar un LED

  Enara Agirrezabala
  3 de Marzo del 2017
*/
int porcentaje = 75 * 5 / 100; //el 75% del maximo que es 100%. (de 0 a 5)
void setup() {
  Serial.begin(9600); //Empezar serial
  pinMode(A0, INPUT); //definir que pin y en que modo. Recoje información.
  pinMode(A1, INPUT); //definir que pin y en que modo. Recoje información.
  pinMode(2, OUTPUT); //Definir posicion y comportamiento del led
}

void loop() {
  // Leer valor de voltaje del LDR (0-1023)
  int val = analogRead (A0); //Leer el valor del pin A0 y guardarlo como variable v
  int val2 = analogRead(A1);
  //Imprimir valor en el serial
  Serial.println(val);
  Serial.println(val2);
  //mapear valores para relacionar los valores obtenidos de forma indirecta
  val = map(val, 0, 1023, 0, 5);
  val2 = map(val2, 0, 1023, 0, 5);
  Serial.print("este es el valor de val una vez mapeado = ");
  Serial.println(val);
  erial.print("este es el valor val 2 una vez mapeado = ");
  Serial.println(val2);
  // delay(1000); //Esperar 1s
  if (val > porcentaje && val2 > porcentaje) {
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(2, LOW);
  }
  delay(1000);

}
