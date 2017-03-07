/*
  Continious output assignments
  Leer un LDR y mostrar su valor utilizando Serial
  Esos valores controlarán la velocidad de un led que se enciende y se apaga
  de forma directa e indirecta utilizando la funcion map.
  Fija el umbral de encendido y apagado

  Enara Agirrezabala
  3 de Marzo del 2017
*/
void setup() {
  Serial.begin(9600); //Empezar serial
  pinMode(A0, INPUT); //definir que pin y en que modo. Recoje información.
  pinMode(2, OUTPUT); //Definir posicion y comportamiento del led
}

void loop() {
  // Leer valor de voltaje del LDR
  int val = analogRead (A0); //Leer el valor del pin A0 y guardarlo como variable v

  //Imprimir valor en el serial
  Serial.println(val);
  // delay(1000); //Esperar 1s
  digitalWrite(3, HIGH);
  delay(val);
  digitalWrite(3, LOW);
  delay(val);

}
