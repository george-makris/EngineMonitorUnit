#define r1 220.00
#define inPin A4

int raw;
float pressRes;
double psi;

void setup(){
    Serial.begin(9600);
}

void loop(){
    raw = analogRead(inPin);
    pressRes = r1*raw/(1023.00-raw);
    psi =  (1E-05*pow(pressRes,3) - 0.0015*pow(pressRes,2) + 0.1087*pressRes - 0.1902)*14.50377;
    Serial.println(psi);
}