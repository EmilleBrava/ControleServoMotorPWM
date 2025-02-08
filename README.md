# ControleServoMotorPWM
Com o emprego do módulo PWM (Pulse Width Modulation),  presente no microcontrolador RP2040, projete um sistema com a  ferramenta Pico SDK para simular o controle do ângulo de um  servomotor. 
![image](https://github.com/user-attachments/assets/827ef319-224c-432b-908d-5a6e88b36d13)

Os requisitos para a realização desta atividade são: 
1) Considerando a GPIO 22, defina a sua frequência de PWM para, aproximadamente, 50Hz – período de 20ms. 
2) Defina o ciclo ativo do módulo PWM para 2.400µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,12%. isto ajustará a flange (braço) do servomotor para a posição de, aproximadamente, 180 graus. Aguarde 05 segundos nesta posição.  
3) Defina o ciclo ativo do módulo PWM para 1.470µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,0735%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 90 graus. Aguarde 05 segundos nesta posição. 
4) Defina o ciclo ativo do módulo PWM para 500µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,025%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 0 graus. Aguarde 05 segundos nesta posição.
5) Após a realização das proposições anteriores, crie uma rotina para movimentação periódica do braço do servomotor entre os ângulos de 0 e 180 graus.  Obs.: a movimentação da flange deve ser suave, recomenda-se o incremento de ciclo ativo de ±5µs, com um atraso de ajuste de 10ms.
6) Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIO 12.

   Para se fazer ciclos ativos foram empregados for (laço de repetição em C )
   ![image](https://github.com/user-attachments/assets/dd60c258-ffa0-46d7-a72a-c062d497199f)

Empregando atalhos da biblioteca hardware/pwm.h
  #define SERVO_PIN 22    // Define o pino GPIO onde o servo motor está conectado (pino 22).
  #define PWM_FREQ 50 //Define a frequência do PWM (50 Hz, típico para servo motores).
  #define PWM_WRAP 20000 // Define o valor máximo do contador do PWM. Esse valor é usado para configurar a largura de pulso.
  #define LED_PIN 12 // Define o pino GPIO 12, que não é usado diretamente no código, mas foi configurado como PWM.

CONCLUSÃO

Este código controla um servo motor usando PWM. O motor é movido para três posições fixas e depois faz um movimento suave entre esses valores, o que permite ao servo motor se mover de forma fluida entre essas posições.

REFERÊNCIAS
https://github.com/jordeam/Servo_Control/tree/main
  



O que o discente observou no comportamento 
da iluminação do referido LED?
