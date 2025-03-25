#include "stm32f103xb.h"

void delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 800; i++) {
        __NOP();
    }
}

int main(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
    GPIOC->CRH |= GPIO_CRH_MODE13_1;

    while (1) {
        GPIOC->ODR ^= GPIO_ODR_ODR13;
        delay_ms(50);
    }
}
