#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define LED_R_PIN 12
#define LED_G_PIN 13
#define LED_B_PIN 14
#define PWM_FREQ 50
#define PWM_WRAP 24000

void Controle_do_led(uint pin , uint16_t pulse_w);
void Posicoes_iniciais(uint pin);

int main() {
    stdio_init_all();
    sleep_ms(2000); // pequeno delay ao iniciar

    gpio_set_function(LED_R_PIN, GPIO_FUNC_PWM);
    gpio_set_function(LED_G_PIN, GPIO_FUNC_PWM);
    gpio_set_function(LED_B_PIN, GPIO_FUNC_PWM);

    uint slice_num_r = pwm_gpio_to_slice_num(LED_R_PIN);
    uint slice_num_g = pwm_gpio_to_slice_num(LED_G_PIN);
    uint slice_num_b = pwm_gpio_to_slice_num(LED_B_PIN);

    pwm_set_wrap(slice_num_r, PWM_WRAP);
    pwm_set_wrap(slice_num_g, PWM_WRAP);
    pwm_set_wrap(slice_num_b, PWM_WRAP);

    pwm_set_clkdiv(slice_num_r, 125.0f);
    pwm_set_clkdiv(slice_num_g, 125.0f);
    pwm_set_clkdiv(slice_num_b, 125.0f);

    pwm_set_enabled(slice_num_r, true);
    pwm_set_enabled(slice_num_g, true);
    pwm_set_enabled(slice_num_b, true);

    do {
        Posicoes_iniciais(LED_R_PIN);
        Posicoes_iniciais(LED_G_PIN);
        Posicoes_iniciais(LED_B_PIN);

        for (uint16_t i = 500; i <= 2400; i += 5) {
            Controle_do_led(LED_R_PIN, i);
            Controle_do_led(LED_G_PIN, i);
            Controle_do_led(LED_B_PIN, i);
            sleep_ms(10);
        }

        for (uint16_t i = 2400; i >= 500; i -= 5) {
            Controle_do_led(LED_R_PIN, i);
            Controle_do_led(LED_G_PIN, i);
            Controle_do_led(LED_B_PIN, i);
            sleep_ms(10);
        }

        sleep_ms(1000);
    } while (1);

    return 0;
}

void Controle_do_led(uint pin , uint16_t pulse_w) {
    pwm_set_gpio_level(pin, pulse_w);
}

void Posicoes_iniciais(uint pin) {
    pwm_set_gpio_level(pin, 1500); // valor inicial do pulso
}
