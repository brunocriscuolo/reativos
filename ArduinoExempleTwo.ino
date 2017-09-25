#define LED_PIN 13
#define BUT_PIN 2

void setup(){
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUT_PIN, INPUT);  
  }
  
void loop(){
  int t = 10;
  static int led = 1;
  static int cont = 0;
  
  if (cont == 1000) {
    digitalWrite(LED_PIN, led);
    led = !led;                        
    cont = 0;
  }
  
  delay(t);
  cont = cont + t;

  int button = digitalRead(BUT_PIN);
  if (button == LOW){
    digitalWrite(LED_PIN, HIGH);
    while(1);
  }
}         
