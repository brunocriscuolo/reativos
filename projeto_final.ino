#define BUZZER 12

#define LED_RED    11
#define LED_BLUE   10
#define LED_YELLOW 9
#define LED_GREEN  8
 
#define BUTTON_RED    7
#define BUTTON_BLUE   6
#define BUTTON_YELLOW 5 
#define BUTTON_GREEN  4
 
#define RED_TONE      1200
#define BLUE_TONE     1600
#define YELLOW_TONE   2000
#define GREEN_TONE    2400
#define TONE_DURATION 200
#define ERROR_TONE    400

int sequence[100]; //Declaração do vetor que guarda a sequência em que cada LED acende.
int len = 1; //Variável que controla o tamanho da sequência.
  
void setup() {
   
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  pinMode(BUTTON_RED, INPUT);
  pinMode(BUTTON_BLUE, INPUT);
  pinMode(BUTTON_YELLOW, INPUT);
  pinMode(BUTTON_GREEN, INPUT);
 
  pinMode(BUZZER, OUTPUT);

  randomSeed(analogRead(0));
 
}

void loop() {
  
  if(len == 1){
    waitStart(); //Função que acende todos os LEDs e aguarda entrada do jogador para iniciar. Qualquer botão inicia o jogo.
    delay(2000); //Aguarda 2s.    
  }
  
  sequence[len-1] = random(8, 12);
  for(int i = 0; i < len; i++) {
    toneLed(sequence[i]);
    blinkLed(sequence[i]);
  }
  
  for(int j = 0; j < len; j++){
    int button = input();
    if(button == sequence[j]) {
      continue;
    }
    else {
      error();
    }
  }
  
  len++;
  
}


void error() {
  while (true) {
    tone(BUZZER, ERROR_TONE, TONE_DURATION);
    digitalWrite(LED_RED, LOW);
    delay(200);
    digitalWrite(LED_RED, HIGH);
    delay(200);
  }
}


void waitStart(){
  bool start = false; //Flag para controle do inicio de jogo.
  while(start == false)  { 
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_GREEN, HIGH);
    if(digitalRead(BUTTON_RED) == HIGH || digitalRead(BUTTON_BLUE) == HIGH || digitalRead(BUTTON_YELLOW) == HIGH || digitalRead(BUTTON_GREEN) == HIGH) {
      start = true; //Dá inicio ao jogo
    }
  }
  // Apaga todos os LEDs preparando para o inicio do jogo.
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
}


void blinkLed(int ledPin) {
  digitalWrite(ledPin, HIGH); //Acende o LED.
  delay(500); //Aguarda 500ms.
  digitalWrite(ledPin, LOW); //Apaga o LED.
  delay(500); //Aguarda 500ms.
}


void toneLed(int ledPin) {
  if(ledPin == LED_RED) {
    tone(BUZZER, RED_TONE, TONE_DURATION); //Emite o som correspondente a cor do LED.
  }
  else if(ledPin == LED_BLUE) {
    tone(BUZZER, BLUE_TONE, TONE_DURATION); //Emite o som correspondente a cor do LED.
  }
  else if(ledPin == LED_YELLOW) {
    tone(BUZZER, YELLOW_TONE, TONE_DURATION); //Emite o som correspondente a cor do LED.
  }
  else if(ledPin == LED_GREEN) {
    tone(BUZZER, GREEN_TONE, TONE_DURATION); //Emite o som correspondente a cor do LED.
  } 
}


int input() {
  int pin = -1;
  while(pin == -1) { //Aguarda a entrada do jogador através do botão.
    if(digitalRead(BUTTON_RED) == HIGH) {
      pin = LED_RED;
      tone(BUZZER, RED_TONE, TONE_DURATION); //Emite o som correspondente a cor de entrada.
      blinkLed(pin); //Permite que o LED pisque assim que a entrada for setada.
    }
    else if(digitalRead(BUTTON_BLUE) == HIGH) {
      pin = LED_BLUE;
      tone(BUZZER, BLUE_TONE, TONE_DURATION); //Emite o som correspondente a cor de entrada.
      blinkLed(pin); //Permite que o LED pisque assim que a entrada for setada.
    }
    else if(digitalRead(BUTTON_YELLOW) == HIGH) {
      pin = LED_YELLOW;
      tone(BUZZER, YELLOW_TONE, TONE_DURATION); //Emite o som correspondente a cor de entrada.
      blinkLed(pin); //Permite que o LED pisque assim que a entrada for setada.
    }
    else if(digitalRead(BUTTON_GREEN) == HIGH) {
      pin = LED_GREEN;
      tone(BUZZER, GREEN_TONE, TONE_DURATION); //Emite o som correspondente a cor de entrada.
      blinkLed(pin); //Permite que o LED pisque assim que a entrada for setada.
    }
  } 
return pin;
}
