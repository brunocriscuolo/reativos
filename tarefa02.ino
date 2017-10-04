#define LED_PIN 13
#define BTN1_PIN 2
#define BTN2_PIN 4

unsigned long time;
int time_controler = 1000;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN1_PIN, INPUT);
  pinMode(BTN2_PIN, INPUT);
}

void loop() {

  unsigned long current_time = millis();
  unsigned long led_time = 0;
  unsigned long time_button1;
  unsigned long time_button2;
  unsigned long pressed_button1 = 0;
  unsigned long pressed_button2 = 0;

  int button1 = digitalRead(BTN1_PIN);
  int button2 = digitalRead(BTN2_PIN);

  static int status_button1 = 0;
  static int status_button2 = 0;
  static int led = 0;

  digitalWrite(LED_PIN, led);

  if (current_time >= led_time) {
    if (!led) {
      led_time = current_time + 1000;
    }
    else {
      led_time = current_time + time_controler;
    }
    led = !led;                        
  }  

  if (!button1 && status_button1 && (current_time > pressed_button1) && !button2) {
    time_controler -= 300;
    pressed_button1 = current_time + 100;
  }
  status_button1 = button1;

  else if (!button2 && status_button2 && (current_time > pressed_button2) && !button1) {
    time_controler += 300;
    pressed_button2 = current_time + 100;
  }
  status_button2 = button2;

  if (button1) {
    time_button1 = current_time;
  }

  if (button2) {
    time_button2 = current_time;
  }

  time = abs(time_button1 - time_button2);
  
  if (time < 500){
    digitalWrite(LED_PIN, HIGH);
    while(1);
  }

} 