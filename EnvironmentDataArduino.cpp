// Arduino Program

mySerial.print('*'); // Starting char
mySerial.print(round(DHT.temperature)); //2 digit data
mySerial.print(round(DHT.humidity)); //2 digit data
void setup() {
 // put your setup code here, to run once:
 Serial.begin(9600); delay(2000);
}
void loop() {
 // put your main code here, to run repeatedly:
 Serial.print("Start");
 Serial.println(analogRead(A0));
op_value = map(op_value,550,0,0,100);
   Serial.print("Moisture(%): ");
   Serial.print(op_value);
   Serial.print("%");
   Serial.println("\n ------------------------- \n");
   //------Sending Data to ESP8266--------//
   mySerial.print('*'); // Starting char
   mySerial.print(round(DHT.temperature)); //2 digit data
   mySerial.print(round(DHT.humidity)); //2 digit data
   mySerial.print(op_value); //2 digit data
   mySerial.println('#'); // Ending char
   //------------------------------------//
   delay(2000);
 }
 if (ack == 1)
 { 
   Serial.print("NO DATA");
   Serial.print("\n\n");
   delay(2000);
 }
