 #define LED_GPIO 2  

 #define DR_REG_GPIO_BASE 0x3FF44000
 #define GPIO_ENABLE_REG (DR_REG_GPIO_BASE + 0x20)
 #define GPIO_OUT_REG (DR_REG_GPIO_BASE + 0x04)

 void delay(int cycles) {
     for (volatile int i = 0; i < cycles; i++);
 }

 void app_main(void) {
     *(volatile unsigned int*)GPIO_ENABLE_REG |= (1 << LED_GPIO);

     while (1) {
         *(volatile unsigned int*)GPIO_OUT_REG |= (1 << LED_GPIO);
         delay(1000000);

         *(volatile unsigned int*)GPIO_OUT_REG &= ~(1 << LED_GPIO);
         delay(1000000);
     }
 }
