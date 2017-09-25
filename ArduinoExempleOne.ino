#define LED_PIN 13
#define BUT_PIN 2

void setup(){
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUT_PIN, INPUT);  
  }
  
void loop(){
  digitalWrite(LED_PIN, HIGH);   
  delay(1000);                       
  digitalWrite(LED_PIN, LOW);
  delay(1000);
  
  int button = digitalRead(BUT_PIN);
  if (button == LOW){
    digitalWrite(LED_PIN, HIGH);
    while(1);
  }
}         
