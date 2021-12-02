#include <math.h>

#define A 0.001681734
#define B 0.000193812
#define C 0.0000003986830665

const int input_pin = A4;
int raw;
float r2;
double coolantTemp;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    raw = analogRead(input_pin);
    r2 = 2240.00*raw/(1023.00-raw);
    coolantTemp = pow(A + B*log(r2) + C*pow(log(r2),3),-1)-273.00;
    Serial.println(coolantTemp);
}
