
#include "JoeTest.h"
#include "stm32f401_discovery.h"
//#include <stdio.h>
#include <stm32f4xx_hal_uart.h>
#include <usart.h>

class JoeTest {
public:
    explicit JoeTest() {
        BSP_LED_Init(LED3);
        BSP_LED_On(LED3);
    }
    void doSomething() {

    }
};


JoeTest staticInstance;


void doJoeTest() {
    HAL_UART_Transmit(&huart2, (uint8_t*)"Hello World!\n", 13, 10000);
  //  printf("Hello World\n");
    BSP_LED_Init(LED3);
    BSP_LED_Init(LED4);
    BSP_LED_Init(LED5);
    BSP_LED_Init(LED6);
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

    for (;;) {
        if (BSP_PB_GetState(BUTTON_KEY) != 0) {
            BSP_LED_On(LED3);
            BSP_LED_On(LED4);
            BSP_LED_On(LED5);
            BSP_LED_On(LED6);
        } else {
            BSP_LED_Off(LED3);
            BSP_LED_Off(LED4);
            BSP_LED_Off(LED5);
            BSP_LED_Off(LED6);
        }
    }

}
