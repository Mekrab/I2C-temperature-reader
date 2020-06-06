/*Create a program that can read the temperature of the 
Microchip TC74 using I2C and display it for the user to 
read by using UART. */

#ifndef F_CPU
#define F_CPU 16000000UL 
#endif
#define SCL_CLOCK  100000L

void setup() {
  Serial.begin(9600);//Begin Baud rate=9600
}

int reading = 0;

void loop() {
 
read_temp();//Go int 
delay(1000);
  
}

void read_temp()
{
  //initiate the clock sequence
  /* TWSR = Reflects the status of the TWI logic bus via codes. 
  Holds the prescalevalue for the TWI SCL pulse generator.*/
  TWSR = 0;
  /* TWBR = controls the period of SCL when the TWI module is 
  operating in Master mode */
  TWBR = ((F_CPU/SCL_CLOCK)-16)/2;

  
  // send start condition 
  TWCR = (1<<TWINT)| (1<<TWSTA) | (1<<TWEN);//TWCR= 1.x.1.0.x.1.0.x TCWR = 36
  while (!(TWCR & (1<<TWINT)));//Wait for TWINT flag set. 
  
  //set the register read
  TWDR = ((0x48<<1)+1);//So now we are setting TWDR to and moving the high bit in for read
  TWCR = ((1<<TWINT)|(1<<TWEN)|(1<<TWEA));//load SLA_W into TWDR register. Clear TWINT bit in TWCR to start trasnmission of address
  while(!(TWCR&(1<<TWINT)));//Wait for TWINT flag set.

  
  //read the TWCR register
  TWCR = ((1<<TWINT)|(1<<TWEN));
  while(!(TWCR&(1<<TWINT)));

  Serial.print("Temperature: ");
  Serial.print(TWDR);//print the TWCR register
  Serial.print("C\n");
  TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);//send stop condition

}
