#define LED_PIN 13
#define BUT_PIN 2

int base;

void setup(){
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUT_PIN, INPUT);  
  base = millis();
}

void loop(){
  int atual;
  static int led = 1;

  atual = millis();
  if (atual - base >= 1000) {
    digitalWrite(LED_PIN, led);
    led = !led;
    base = atual;                        
  }  

  int button = digitalRead(BUT_PIN);
  if (button == LOW){
    digitalWrite(LED_PIN, HIGH);
    while(1);
  }
}         
