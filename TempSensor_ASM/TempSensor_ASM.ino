//Point to .h file
#include "Lab_4_TempSensor_ASM.h"

void setup(){
  Serial.begin(9600);//Begin Baud rate = 9600
}

void loop() {

  read_temp();//Go into function
  Serial.print("Temperature: ");
  Serial.print(TWDR);//Read TWDR register
  Serial.print("C\n");
  delay(1000); //Delay 1 Sec
}
