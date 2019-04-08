#include <loraid.h>

long interval = 10000;    // 10 s interval to send message
long previousMillis = 0;  // will store last time message sent
unsigned int counter = 0;     // message counter

void setup() {
  // Setup loraid access
  lora.init();

  // Set LoRaWAN Class. CLASS_A and CLASS_C are available
  lora.setDeviceClass(CLASS_A);

  // Set Data Rate
	// SF12 to SF7 available. Also SF7_250 for 250KHz variant	
  lora.setDataRate(SF12);
  
  // Put your Antares account key and Lora.id device address here
  lora.setAccessKey("8878f39f897b9a50:bd6b3446f4c13871");
  lora.setDeviceId("d1580346");
}

void loop() {
  // put your main code here, to run in a loop:
  char outStr[255];
  int recvStatus = 0;
  
  unsigned long currentMillis = millis();

  // Check if more than 10 seconds
	if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis; 

 		String data = "Hello world! " + String(counter);   
    lora.sendToAntares(data);
    counter++;
  }

  recvStatus = lora.readData(outStr);
  if(recvStatus) {
    Serial.println(outStr);
  }
  
  // Check Lora RX
  lora.update();
}
