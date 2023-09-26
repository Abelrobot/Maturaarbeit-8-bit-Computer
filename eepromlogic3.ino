#define DATA_SHIFT 2
#define CLOCK_SHIFT 3
#define SAVE_DATA 4

#define IO0 5
#define IO1 6
#define IO2 7
#define IO3 8
#define IO4 9
#define IO5 10
#define IO6 11
#define IO7 12

void write(){

  digitalWrite(SAVE_DATA, LOW);
  delayMicroseconds(1);
  digitalWrite(SAVE_DATA, HIGH);
  delay(1);

  digitalWrite(IO0, LOW);
  digitalWrite(IO1, LOW);
  digitalWrite(IO2, LOW);
  digitalWrite(IO3, LOW);
  digitalWrite(IO4, LOW);
  digitalWrite(IO5, LOW);
  digitalWrite(IO6, LOW);
  digitalWrite(IO7, LOW);

}

int a = 0;
int b = 0;
int c = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(DATA_SHIFT, OUTPUT);
  pinMode(CLOCK_SHIFT, OUTPUT);
  pinMode(SAVE_DATA, OUTPUT);
  pinMode(IO0, OUTPUT);
  pinMode(IO1, OUTPUT);
  pinMode(IO2, OUTPUT);
  pinMode(IO3, OUTPUT);
  pinMode(IO4, OUTPUT);
  pinMode(IO5, OUTPUT);
  pinMode(IO6, OUTPUT);
  pinMode(IO7, OUTPUT);

  digitalWrite(IO0, LOW);
  digitalWrite(IO1, LOW);
  digitalWrite(IO2, LOW);
  digitalWrite(IO3, LOW);
  digitalWrite(IO4, LOW);
  digitalWrite(IO5, LOW);
  digitalWrite(IO6, LOW);
  digitalWrite(IO7, LOW);

  digitalWrite(SAVE_DATA, HIGH);

  shiftOut(DATA_SHIFT, CLOCK_SHIFT, MSBFIRST, 0);
  shiftOut(DATA_SHIFT, CLOCK_SHIFT, MSBFIRST, 0);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(a < 16){
    int b = 0;
    while(b < 256){
      shiftOut(DATA_SHIFT, CLOCK_SHIFT, MSBFIRST, a);
      shiftOut(DATA_SHIFT, CLOCK_SHIFT, MSBFIRST, b);
      int c = 256 * a + b;
      Serial.println(c);
      if(c >= 1024 && c <= 2047){
        digitalWrite(IO0, HIGH);
        Serial.println("IR IN");
      }
      if(c >= 2304 && c <= 2367 || c >= 2370 && c <= 2431 && c % 4 == 2 || c >= 2370 && c <= 2431 && c % 4 == 3 || c >= 2433 && c <= 2495 && c % 2 == 1 || c >= 2496 && c <= 2815){
        digitalWrite(IO1, HIGH);
        Serial.println("IR OUT");
      }
      if(c >= 3584 && c <= 3647){
        digitalWrite(IO2, HIGH);
        Serial.println("RAM IN");
      }
      if(c >= 1024 && c <= 2047 || c >= 3520 && c <= 3583){
        digitalWrite(IO3, HIGH);
        Serial.println("RAM OUT");
      }
      if(c >= 3520 && c <= 3583){
        digitalWrite(IO4, HIGH);
        Serial.println("RAM OUT TO BUS");
      }
      write();
      b++;
      delay(50);
    }
    a++;
  }
  Serial.println("Program finished!");
  delay(10000000000000);
}
