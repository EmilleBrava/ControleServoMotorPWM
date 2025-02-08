#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"


#define SERVO_PIN 22    
#define PWM_FREQ 50
#define PWM_WRAP 24000
#define LED_PIN 12

void Controle_do_server(uint pin , uint16_t pulse_w);
void Posicoes_iniciais(uint pin);

int main (){
    stdio_init_all();
    sleep_ms(2000);//pequeno delei ao iniciar 
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    pwm_set_wrap(slice_num, PWM_WRAP);
    pwm_set_clkdiv(slice_num, 125.0f);
    pwm_set_enabled(slice_num, true);


    do{
        Posicoes_iniciais(SERVO_PIN);
    
       for(uint16_t i = 500; i <= 2400; i+=5){
        Controle_do_server(SERVO_PIN, i);
           sleep_ms(10);
       }
       
       for(uint16_t i = 2400; i >= 500; i-=5){
        Controle_do_server(SERVO_PIN, i);
           sleep_ms(10);
       }
       sleep_ms(1000);
    }while (1);
   
    
    return 0;
}

void Controle_do_server(uint pin , uint16_t pulse_w) {
    pwm_set_gpio_level(pin, pulse_w);
}

void Posicoes_iniciais(uint pin){
    Controle_do_server(pin, 2400);
    sleep_ms(5000);
    
    Controle_do_server(pin, 1470);
    sleep_ms(5000);
    
    Controle_do_server(pin, 500);
    sleep_ms(5000);
}