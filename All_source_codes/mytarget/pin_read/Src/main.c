/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//User LED2 on PA5

//Steps
//1. Enable RCC Periph Clock - AHB1 For GPIO
//2. Configure GPIOA Pin 5 as output, push-pull
//3. Set GPIOA Pin 5 high

#define N64_LED2	5 //GPIOA Pin 5
#define N64_BTN1	13//GPIOC Pin 13

#define RCC_BASE	 0x40023800
#define RCC_AHB1ENR  (RCC_BASE + 0x30)
#define RCC_AHB1ENR_GPIOA_EN (1<<0)
#define RCC_AHB1ENR_GPIOC_EN (1<<2)


#define GPIO_MODE_IN 	0x0
#define GPIO_MODE_OUT 	0x1
#define GPIO_MODE_ALT	0x2
#define GPIO_MODE_ANLG	0x3

#define GPIOA_BASE	 	0x40020000
#define GPIOA_MODER		(GPIOA_BASE + 0x00)
#define GPIOA_OTYPER	(GPIOA_BASE + 0x04)
#define GPIOA_OSPEEDR	(GPIOA_BASE + 0x08)
#define GPIOA_PUPDR		(GPIOA_BASE + 0x0C)
#define GPIOA_IDR		(GPIOA_BASE + 0x10)
#define GPIOA_ODR		(GPIOA_BASE + 0x14)
#define GPIOA_BSRR		(GPIOA_BASE + 0x18)
#define GPIOA_LCKR		(GPIOA_BASE + 0x1C)
#define GPIOA_ARFH		(GPIOA_BASE + 0x20)
#define GPIOA_ARFL		(GPIOA_BASE + 0x24)

#define GPIOC_BASE	 	0x40020800
#define GPIOC_MODER		(GPIOC_BASE + 0x00)
#define GPIOC_OTYPER	(GPIOC_BASE + 0x04)
#define GPIOC_OSPEEDR	(GPIOC_BASE + 0x08)
#define GPIOC_PUPDR		(GPIOC_BASE + 0x0C)
#define GPIOC_IDR		(GPIOC_BASE + 0x10)
#define GPIOC_ODR		(GPIOC_BASE + 0x14)
#define GPIOC_BSRR		(GPIOC_BASE + 0x18)
#define GPIOC_LCKR		(GPIOC_BASE + 0x1C)
#define GPIOC_ARFH		(GPIOC_BASE + 0x20)
#define GPIOC_ARFL		(GPIOC_BASE + 0x24)

volatile uint32_t *pRCC_AHB1ENR 	= (uint32_t*)RCC_AHB1ENR;
volatile uint32_t *pGPIOA_MODER  = (uint32_t*)GPIOA_MODER;
volatile uint32_t *pGPIOA_ODR  	= (uint32_t*)GPIOA_ODR;
volatile uint32_t *pGPIOC_MODER  = (uint32_t*)GPIOC_MODER;
volatile uint32_t *pGPIOC_IDR  	= (uint32_t*)GPIOC_IDR;

void delay_cnt(uint32_t cnt){
	while(cnt-- > 0);
}

void init_hw(){



	*pRCC_AHB1ENR |= (RCC_AHB1ENR_GPIOA_EN | RCC_AHB1ENR_GPIOC_EN); //Enable RCC Periph Clock to AHB1 -> GPIOA

	*pGPIOA_MODER &= ~(3 << (N64_LED2 * 2)); //Clear Mode before setting
	*pGPIOA_MODER |= (GPIO_MODE_OUT << (N64_LED2 * 2)); //Enable PA4 as OUT, MODE Field is 2 bits wide

	*pGPIOA_ODR   |= (1 << N64_LED2); // Set PA4 High - LED2 OFF

	*pGPIOC_MODER &= ~(3 << (N64_BTN1 * 2)); //Clear Mode before setting
	*pGPIOC_MODER |= (GPIO_MODE_IN << (N64_BTN1 * 2)); //Enable PC13 as IN, MODE Field is 2 bits wide

}


int main(void)
{
	init_hw();


	/* Loop forever */
	for(;;){

		if(*pGPIOC_IDR & (1<< N64_BTN1) ){
			*pGPIOA_ODR |= (1 << N64_LED2);
		}else{
			*pGPIOA_ODR &= ~(1 << N64_LED2);
		}


	};

}
