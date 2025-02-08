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
   ![image](https://github.com/user-attachments/assets/0ab1e186-4547-4746-8fc2-a9a918fc876b)

   e o laço utilizado foi o do{}while(1)
   para garantia que nosso codigo mesmo que se houver erro , faça uma vez a execução
   Nosso processo contou com duas funções, void
   ![image](https://github.com/user-attachments/assets/5f38b697-2705-456e-9634-110aa8e27f5f)
   ![image](https://github.com/user-attachments/assets/2b3cdea7-8f6a-4c25-873e-f401b7c0edd1)




Empregando
  #define SERVO_PIN 22    // Define o pino GPIO onde o servo motor está conectado (pino 22).
  #define PWM_FREQ 50 //Define a frequência do PWM (50 Hz, típico para servo motores).
  #define PWM_WRAP 20000 // Define o valor máximo do contador do PWM. Esse valor é usado para configurar a largura de pulso.
  #define LED_PIN 12 // Define o pino GPIO 12, que não é usado diretamente no código, mas foi configurado como PWM.

Resultados:
No incio meu resultado no wokwi estava sem funcionar por completo e eu não conseguia entender o motivo , ele fazia 0 ---> 90 | 90---->180 |180 ---> 0 ,mas não fazia 360 graus
![image](https://github.com/user-attachments/assets/25f3adfb-6cc2-457d-af52-927e10ca4d66)
(imagem meramente para entendimento)

até que eu percebi que tinha feito um laço a mais para tentar forçar a dar a volta mas o próprio laço que fazia ele cumprir o trageto 
![image](https://github.com/user-attachments/assets/fda99534-d1d6-4e75-a08f-b928d392c756)

abaixo um vídeo do erro que estava surgindo 

https://github.com/user-attachments/assets/235b1925-722a-4ea0-8112-4340a3a30f8d

depois ainda coloquei nos laços a repetição que não levava até o fim , onde considerei 90 graus e 180 graus. Mas , ao corrigir percebi o problema.

e aqui está o resultado :


https://github.com/user-attachments/assets/fe4cc1ac-422a-435a-ad8a-535c342394fc


CONCLUSÃO

Este código controla um servo motor usando PWM. O motor é movido para três posições fixas e depois faz um movimento suave entre esses valores, o que permite ao servo motor se mover de forma fluida entre essas posições.

REFERÊNCIAS
https://github.com/jordeam/Servo_Control/tree/main
  



O que o discente observou no comportamento 
da iluminação do referido LED?

Uma variação do ciclo de trabalho de PWM controlará a intensidade de cada cor (vermelho, verde, azul) e criará uma mudança de cores no LED RGB. 
https://github.com/user-attachments/assets/c7582312-23b0-4826-b9cd-a8f08c6b2ca1


