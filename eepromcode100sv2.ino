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
  while(a < 256){
    if(a < 100){
      digitnuill();
      Serial.println("null");
    } else if(a < 200){
      digitone();
      Serial.println(1);
    } else{
      digittwo();
      Serial.println(2);
    }
    Serial.println(a);
    a++;
    shiftOut(DATA_SHIFT, CLOCK_SHIFT, LSBFIRST, a);
  }
  digitalWrite(LED_DONE, HIGH);
  delay(100000000);
}
