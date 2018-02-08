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

  randomSeed(analogRead(0)); //função para inicializar o gerador de números aleatórios: "random(min,max)".
 
}

void loop() {
  
  if(len == 1){  //Condiciona a chamada da função ao inicio do jogo, isto é, quando o tamanho da sequencia é igual a 1.
    waitStart(); //Função que acende todos os LEDs e aguarda entrada do jogador para iniciar. Qualquer botão inicia o jogo.
    delay(2000); //Aguarda 2s.    
  }
  
  sequence[len-1] = random(8, 12); //Sorteia o pino do LED que irá acender e memoriza na última posição válida do vetor.
  for(int i = 0; i < len; i++) { //Percorre a vetor até o tamanho atual.
    toneLed(sequence[i]); //Chama a funço para emitir o som referente ao pino do LED memorizado na posição "i" do vetor.
    blinkLed(sequence[i]); //Chama a função para piscar o LED cujo pino foi memorizado na posição "i" do vetor.
  }
  
  for(int j = 0; j < len; j++){ //Percorre a vetor até o tamanho atual.
    int button = input(); //Chama a função que lê o valor de entrada ao apertar o botão. 
    if(button == sequence[j]) {  //Condição que verifica se a sequencia de entradas nos botões corresponde a sequencia de acendimento dos LEDs. 
      continue; //Continua a execução do laço "for".
    }
    else { //Se, ao menos uma entrada estiver errada...
      error(); //Chama a função para alerta de erro.
    }
  }
  
  len++; //Incrementa o tamano da sequencia em caso de acerto.
  
}


void error() {
  while (true) {
    tone(BUZZER, ERROR_TONE, TONE_DURATION); //Aciona o BUZZER com som de erro por 200ms.
    digitalWrite(LED_RED, LOW); //Apaga o LED.
    delay(200); //Aguarda 200ms.
    digitalWrite(LED_RED, HIGH); //Acende o LED.
    delay(200); //Aguarda 200ms
  }
}


void waitStart(){
  bool start = false; //Flag para controle do inicio de jogo.
  while(start == false)  { 
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_GREEN, HIGH);
    if(digitalRead(BUTTON_RED) == HIGH || digitalRead(BUTTON_BLUE) == HIGH || digitalRead(BUTTON_YELLOW) == HIGH || digitalRead(BUTTON_GREEN) == HIGH) { //Caso qualquer um dos 4 botões seja pressionado...
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
    tone(BUZZER, RED_TONE, TONE_DURATION); //Emite o som correspondente a cor do LED durante 200ms.
  }
  else if(ledPin == LED_BLUE) {
    tone(BUZZER, BLUE_TONE, TONE_DURATION); //Emite o som correspondente a cor do LED durante 200ms.
  }
  else if(ledPin == LED_YELLOW) {
    tone(BUZZER, YELLOW_TONE, TONE_DURATION); //Emite o som correspondente a cor do LED durante 200ms.
  }
  else if(ledPin == LED_GREEN) {
    tone(BUZZER, GREEN_TONE, TONE_DURATION); //Emite o som correspondente a cor do LED durante 200ms.
  } 
}


int input() {
  int pin = -1;
  while(pin == -1) { //Aguarda a entrada do jogador através do botão.
    if(digitalRead(BUTTON_RED) == HIGH) { //Condição que verifica se o botão correspondente ao LED vermelho foi pressionado.
      pin = LED_RED; //Atribui o pino do LED vermelho.
      tone(BUZZER, RED_TONE, TONE_DURATION); //Emite o som correspondente a cor de entrada.
      blinkLed(pin); //Permite que o LED pisque assim que a entrada for setada.
    }
    else if(digitalRead(BUTTON_BLUE) == HIGH) { //Condição que verifica se o botão correspondente ao LED azul foi pressionado.
      pin = LED_BLUE; //Atribui o pino do LED Azul.
      tone(BUZZER, BLUE_TONE, TONE_DURATION); //Emite o som correspondente a cor de entrada.
      blinkLed(pin); //Permite que o LED pisque assim que a entrada for setada.
    }
    else if(digitalRead(BUTTON_YELLOW) == HIGH) { //Condição que verifica se o botão correspondente ao LED amarelo foi pressionado.
      pin = LED_YELLOW; //Atribui o pino do LED amarelo.
      tone(BUZZER, YELLOW_TONE, TONE_DURATION); //Emite o som correspondente a cor de entrada.
      blinkLed(pin); //Permite que o LED pisque assim que a entrada for setada.
    }
    else if(digitalRead(BUTTON_GREEN) == HIGH) { //Condição que verifica se o botão correspondente ao LED verde foi pressionado.
      pin = LED_GREEN; //Atribui o pino do LED verde.
      tone(BUZZER, GREEN_TONE, TONE_DURATION); //Emite o som correspondente a cor de entrada.
      blinkLed(pin); //Permite que o LED pisque assim que a entrada for setada.
    }
  } 
return pin; //Retorna um número interio correspondente ao pino do LED
}
