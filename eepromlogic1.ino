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
      if(c >= 2128 && c <= 2131 || c >= 2144 && c <= 2147 || c >= 2160 && c <= 2163 || c >= 2752 && c <= 2815 || c >= 3520 && c <= 3583){
        digitalWrite(IO0, HIGH);
        Serial.println("A IN");
      }
      if(c >= 2116 && c <= 2127){
        digitalWrite(IO1, HIGH);
        Serial.println("A OUT");
      }
      if(c >= 2116 && c <= 2119 || c >= 2148 && c <= 2151 || c >= 2624 && c <= 2751){
        digitalWrite(IO2, HIGH);
        Serial.println("B IN");
      }
      if(c >= 2128 && c <= 2131 || c >= 2136 && c <= 2143){
        digitalWrite(IO3, HIGH);
        Serial.println("B OUT");
      }
      if(c >= 2120 && c <= 2123 || c >= 2136 && c <= 2139 || c >= 2176 && c <= 2183 || c >= 3648 && c <= 3775){
        digitalWrite(IO4, HIGH);
        Serial.println("C IN");
      }
      if(c >= 2144 && c <= 2151 || c >= 2156 && c <= 2159 || c >= 3584 && c <= 3647){
        digitalWrite(IO5, HIGH);
        Serial.println("C OUT");
      }
      if(c >= 2124 && c <= 2127 || c >= 2140 && c <= 2143 || c >= 2156 && c <= 2159){
        digitalWrite(IO6, HIGH);
        Serial.println("OUTPUT IN");
      }
      if(c >= 2176 && c <= 2183 || c >= 3648 && c <= 3775){
        digitalWrite(IO7, HIGH);
        Serial.println("FLAG IN");
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
