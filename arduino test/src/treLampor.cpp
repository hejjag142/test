//lägger till ett biblotek av komandos som liknar arduino ide. och gör det enklare
#include <Arduino.h>

// pins för alla lampor
const byte rod = 2;
const byte gron = 3;
const byte bla = 4;

void setup() {
  
  //säger att alla pins med lampa kopplad är output
  pinMode(rod, OUTPUT);
  pinMode(gron, OUTPUT);
  pinMode(bla, OUTPUT);

  digitalWrite(rod, LOW);
  digitalWrite(gron, LOW);
  digitalWrite(bla, LOW);


  //startar serial cominication med hastighet av 9600
  Serial.begin(9600);
}

void allaPa(){
  digitalWrite(rod, HIGH);
  digitalWrite(gron, HIGH);
  digitalWrite(bla, HIGH);
}

void allaAv(){
  digitalWrite(rod, LOW);
  digitalWrite(gron, LOW);
  digitalWrite(bla, LOW);
}

void loop() {

  //kollar om det finns något i serial monitor
  if (Serial.available()>0){

    //gör at variabel av det som stod i serial med bara ett tecken(char)
    char status = Serial.read();

    //den kollar och jemför status med dessa sifror. om den hittar matching kör den samma kod som är efter : täknet
    switch(status){
      case '0': digitalWrite(rod, LOW); break;
      case '1': digitalWrite(rod, HIGH); break;
      case '2': digitalWrite(gron, LOW); break;
      case '3': digitalWrite(gron, HIGH); break;
      case '4': digitalWrite(bla, LOW); break;
      case '5': digitalWrite(bla, HIGH); break;
      case '8': allaAv(); break;
      case '9': allaPa(); break;
    }
  }
}