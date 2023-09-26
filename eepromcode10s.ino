#define LED_DONE 2
#define DATA_SHIFT 3
#define CLOCK_SHIFT 4

#define A 5
#define B 6
#define C 7
#define D 8
#define E 9
#define F 10
#define G 11

#define SAVE_DATA 12


void digitnuill(){

  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH); 
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

  digitalWrite(SAVE_DATA, LOW);
  delayMicroseconds(1);
  digitalWrite(SAVE_DATA, HIGH);
  delay(50);

}

void digitzero(){

  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW); 
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);

  digitalWrite(SAVE_DATA, LOW);
  delayMicroseconds(1);
  digitalWrite(SAVE_DATA, HIGH);
  delay(50);

}

void digitone(){

  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH); 
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

  digitalWrite(SAVE_DATA, LOW);
  delayMicroseconds(1);
  digitalWrite(SAVE_DATA, HIGH);
  delay(50);

}

void digittwo(){

  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW); 
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);

  digitalWrite(SAVE_DATA, LOW);
  delayMicroseconds(1);
  digitalWrite(SAVE_DATA, HIGH);
  delay(50);

}

void digitthree(){

  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW); 
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);

  digitalWrite(SAVE_DATA, LOW);
  delayMicroseconds(1);
  digitalWrite(SAVE_DATA, HIGH);
  delay(50);

}

void digitfour(){

  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH); 
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);

  digitalWrite(SAVE_DATA, LOW);
  delayMicroseconds(1);
  digitalWrite(SAVE_DATA, HIGH);
  delay(50);

}

void digitfive(){

  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW); 
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);

  digitalWrite(SAVE_DATA, LOW);
  delayMicroseconds(1);
  digitalWrite(SAVE_DATA, HIGH);
  delay(50);

}

void digitsix(){

  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW); 
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);

  digitalWrite(SAVE_DATA, LOW);
  delayMicroseconds(1);
  digitalWrite(SAVE_DATA, HIGH);
  delay(50);

}

void digitseven(){

  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH); 
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

  digitalWrite(SAVE_DATA, LOW);
  delayMicroseconds(1);
  digitalWrite(SAVE_DATA, HIGH);
  delay(50);

}

void digiteight(){

  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW); 
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);

  digitalWrite(SAVE_DATA, LOW);
  delayMicroseconds(1);
  digitalWrite(SAVE_DATA, HIGH);
  delay(50);

}

void digitnine(){

  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW); 
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);

  digitalWrite(SAVE_DATA, LOW);
  delayMicroseconds(1);
  digitalWrite(SAVE_DATA, HIGH);
  delay(50);

}

int a = 0;
int b = 0;
int c = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_DONE, OUTPUT);
  pinMode(DATA_SHIFT, OUTPUT);
  pinMode(CLOCK_SHIFT, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(SAVE_DATA, OUTPUT);

  shiftOut(DATA_SHIFT, CLOCK_SHIFT, LSBFIRST, 0);

  digitalWrite(SAVE_DATA, HIGH);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(b < 256){
    Serial.println(b);
    int c = b / 10;
    int a = c % 10;
    if(b < 10){
    Serial.println("null");
    digitnuill();
    } else if(a < 1){
    Serial.println(0);
    digitzero();      
    } else if(a < 2){
    Serial.println(1);
    digitone();
    } else if(a < 3){
    Serial.println(2);
    digittwo();
    } else if(a < 4){
    Serial.println(3);
    digitthree();
    } else if(a < 5){
    Serial.println(4);
    digitfour();
    } else if(a < 6){
    Serial.println(5);
    digitfive();
    } else if(a < 7){
    Serial.println(6);
    digitsix();
    } else if(a < 8){
    Serial.println(7);
    digitseven();
    } else if(a < 9){
    Serial.println(8);
    digiteight();
    } else if(a < 10){
    Serial.println(9);
    digitnine();
    }
    b = b + 1;
    shiftOut(DATA_SHIFT, CLOCK_SHIFT, LSBFIRST, b);
  }
  digitalWrite(LED_DONE, HIGH);
  delay(100000000);
}
