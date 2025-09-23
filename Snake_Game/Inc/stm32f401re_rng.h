/*
 * stm32f401re_rng.h
 *
 *  Created on: Apr 6, 2025
 *      Author: vinhv
 */

#ifndef STM32F401RE_RNG_H_
#define STM32F401RE_RNG_H_

void RNG_Config(void) {
  /* Enable RNG clock */
  RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_RNG, ENABLE);

  /* Initialize RNG */
  RNG_InitTypeDef RNG_InitStructure;
  RNG_InitStructure.RNG_ClockDiv = RNG_ClockDiv_2; // Ví dụ clock division
  RNG_Init(RNG);

  /* Enable RNG */
  RNG_Cmd(RNG, ENABLE);
}


int main(void) {
  SystemInit(); // Khởi tạo hệ thống

  RNG_Config(); // Cấu hình RNG

  while (1) {
    if (RNG_GetFlagStatus(RNG, RNG_FLAG_DRDY) != RESET) {
      uint32_t randomNumber = RNG_GetRandomNumber(RNG);
      printf("Random Number: %lu\n", randomNumber);
    }
    // Delay hoặc thực hiện các công việc khác
    for (volatile int i = 0; i < 100000; i++); // Simple delay
  }

#endif /* STM32F401RE_RNG_H_ */
