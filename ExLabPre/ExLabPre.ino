
#define MOTOR_PIN PD0 // Pino para controlar o motor da esteira
#define ALARME_PIN PD1 // Pino para controlar o alarme
#define LIGA_PIN PD2 // Pino para o botão LIGA (NA)
#define DESLIGA_PIN PD3 // Pino para o botão DESLIGA (NF)
#define S1_PIN PD4 // Pino para o sensor de amontoamento de peças

int main()
{
    // Configuração dos pinos como saídas ou entradas
    DDRD |= (1 << MOTOR_PIN) | (1 << ALARME_PIN); // Define os pinos MOTOR_PIN e ALARME_PIN como saídas
    PORTD |= (1 << LIGA_PIN) | (1 << DESLIGA_PIN) | (1 << S1_PIN); // Ativa o resistor de pull-up para os pinos LIGA_PIN, DESLIGA_PIN e S1_PIN

    for (;;)
    {
        if (!(PIND & (1 << LIGA_PIN))) // Se o botão LIGA (NA) for pressionado
        {
            PORTD |= (1 << MOTOR_PIN); // Liga o motor
        }
        else if (!(PIND & (1 << DESLIGA_PIN))) // Se o botão DESLIGA (NF) for pressionado
        {
            PORTD &= ~(1 << MOTOR_PIN); // Desliga o motor
        }

        if (!(PIND & (1 << S1_PIN))) // Se houver amontoamento de peças (S1 = HIGH)
        {
            PORTD |= (1 << ALARME_PIN); // Liga o alarme
            PORTD &= ~(1 << MOTOR_PIN); // Desliga o motor
            while (!(PIND & (1 << S1_PIN))) {} // Aguarda até as peças serem desamontoadas (S1 = LOW)
            PORTD &= ~(1 << ALARME_PIN); // Desliga o alarme
        }
    }

    return 0;
}
