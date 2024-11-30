#define PD0_PIN 0
#define PD4_PIN 4
#define PD5_PIN 5
#define PB0_PIN 0
#define PC3_PIN 3
#define PB1_PIN 1
#define PD7_PIN 7

void setup() {
  // Configuração dos pinos como saídas
  DDRD |= (1 << PD0_PIN) | (1 << PD4_PIN) | (1 << PD5_PIN);
  DDRB |= (1 << PB0_PIN);

  // Configuração dos pinos como entradas com pull-up para botões NF
  pinMode(PC3_PIN, INPUT);
  pinMode(PB1_PIN, INPUT);
  pinMode(PD7_PIN, INPUT);

  // Outras inicializações, se necessário
}

void loop() {
  // Seu código de operação aqui
}
