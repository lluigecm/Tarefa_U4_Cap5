#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define RED_PIN 13
#define GREEN_PIN 11
#define BLUE_PIN 12

int i = 0;
const uint32_t led_pins[] = {RED_PIN, BLUE_PIN, GREEN_PIN};

void setup(){
    gpio_init(RED_PIN);
    gpio_set_dir(RED_PIN, GPIO_OUT);
    gpio_init(GREEN_PIN);
    gpio_set_dir(GREEN_PIN, GPIO_OUT);
    gpio_init(BLUE_PIN);
    gpio_set_dir(BLUE_PIN, GPIO_OUT);
}

bool repeating_timer_callback(struct repeating_timer *timer) {
    gpio_put(led_pins[i], 0);
    i = (i + 1) % 3;
    gpio_put(led_pins[i], 1);
    return true;
}

int main()
{
    stdio_init_all();
    setup();

    gpio_put(led_pins[i], 1);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        sleep_ms(1000);
        printf("Implemetação da tarefa 1 (29/01)\n");
    }
}
