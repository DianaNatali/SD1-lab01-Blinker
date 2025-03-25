#include <stdint.h>

#define GPIO_OUT_REG  (*((volatile uint32_t *)0x3FF44004)) 
#define GPIO_ENABLE_REG (*((volatile uint32_t *)0x3FF44020)) 
#define LED_PIN 2  

void delay(volatile uint32_t time) {
    while (time--) {
        for (volatile uint32_t i = 0; i < 1000; i++);
    }
}

int main(void) {
    GPIO_ENABLE_REG |= (1 << LED_PIN);

    while (1) {
        GPIO_OUT_REG |= (1 << LED_PIN);
        delay(1000000);

        GPIO_OUT_REG &= ~(1 << LED_PIN);
        delay(1000000);
    }

    return 0;
}
