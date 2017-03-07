void setup() {
  Serial.begin(9600); //Empezar serial
  pinMode(2, INPUT); //definir que pin y en que modo.
}

void loop() {
  // put your main code here, to run repeatedly:
  int v = digitalRead (2); //Leer el valor del pin 2 y guardarlo como variable v

  //Comparar si el valor de v es igual a HIGH or LOW
  if (v == HIGH) {
    Serial.println("Encendido");
  }
  else{
    Serial.println("Apagado");
  }
  delay(1000); //Esperar 1s

}
