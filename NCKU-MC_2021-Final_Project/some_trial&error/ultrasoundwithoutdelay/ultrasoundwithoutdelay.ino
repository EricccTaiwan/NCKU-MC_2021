#include <Ultrasonic.h>

Ultrasonic ultrasonic(2,3); // (Trig PIN,Echo PIN)

void setup() {

Serial.begin(9600);

}

void loop()

{

Serial.print(ultrasonic.Ranging(CM)); // CM or INC

Serial.println("cm" );

delay(100);

}
