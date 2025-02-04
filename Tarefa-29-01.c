// Acho que o código não está otimizadp, está rodando devagar no wokwi.
// Mas funciona normalmente na placa BitDogLab.

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define RED_PIN 13
#define GREEN_PIN 11
#define BLUE_PIN 12
#define BUTTON 5

int i = 0;
int lasttime = 0;
const uint32_t led_pins[] = {RED_PIN, BLUE_PIN, GREEN_PIN};

void setup(){   // Configuração dos pinos
    gpio_init(RED_PIN);
    gpio_set_dir(RED_PIN, GPIO_OUT);

    gpio_init(GREEN_PIN);
    gpio_set_dir(GREEN_PIN, GPIO_OUT);

    gpio_init(BLUE_PIN);
    gpio_set_dir(BLUE_PIN, GPIO_OUT);

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
}

int64_t turn_off_callback(alarm_id_t id, void *user_data){  // Função callback para desligar os leds
    gpio_put(led_pins[i%3], 0); 
    i++;

    return 0;   // retorna 0 para não repetir o alarme
}

bool all_leds_off(){    // Verifica se todos os leds estão desligados
    return gpio_get(RED_PIN) == 0 && gpio_get(GREEN_PIN) == 0 && gpio_get(BLUE_PIN) == 0;
}

void turn_leds_on(){    // Liga todos os leds
    for(int j = 0; j < 3; j++){
        gpio_put(led_pins[j], 1);
    }
}

bool debounce(){    // Função para debounce do botão
    int time = to_ms_since_boot(get_absolute_time());
    if(time - lasttime > 200){  // 200ms de debounce
        lasttime = time;
        return true;
    }
    return false;
}

int main()
{
    stdio_init_all();
    setup();

    while (true) {
        if(gpio_get(BUTTON) == 0 && all_leds_off() && debounce()){  // Verifica se o botão foi pressionado e se os leds estão desligados
            sleep_ms(50);
            turn_leds_on();

            add_alarm_in_ms(3000, turn_off_callback, NULL, false);  //alarme para o primeiro led
            add_alarm_in_ms(6000, turn_off_callback, NULL, false);  //alarme para o segundo led
            add_alarm_in_ms(9000, turn_off_callback, NULL, false);  //alarme para o terceiro led
        }
    }
    
}