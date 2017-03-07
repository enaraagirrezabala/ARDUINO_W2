
void setup() {
  pinMode(13, OUTPUT);
  pinMode(A0,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 	int v= digitalRead (A0);
  Serial.println(v);
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
  
}
