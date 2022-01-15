//
// LED: Handles blinking of status light
//

#include "stm32f0xx_hal.h"
#include "led.h"

static uint32_t led1_laston = 0;
static uint32_t led1_lastoff = 0;
static uint32_t led2_laston = 0;
static uint32_t led2_lastoff = 0;

// Attempt to turn on status LED
void led_on1(void)
{
	// Make sure the LED has been off for at least LED_DURATION before turning on again
	// This prevents a solid status LED on a busy canbus
	if(led1_laston == 0 && HAL_GetTick() - led1_lastoff > LED_DURATION)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
		led1_laston = HAL_GetTick();
	}
}

void led_on2(void)
{
	// Make sure the LED has been off for at least LED_DURATION before turning on again
	// This prevents a solid status LED on a busy canbus
	if(led2_laston == 0 && HAL_GetTick() - led2_lastoff > LED_DURATION)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
		led2_laston = HAL_GetTick();
	}
}


// Process time-based LED events
void led_process(void)
{
	// If LED has been on for long enough, turn it off
	if(led1_laston > 0 && HAL_GetTick() - led1_laston > LED_DURATION)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
		led1_laston = 0;
		led1_lastoff = HAL_GetTick();
	}
	if(led2_laston > 0 && HAL_GetTick() - led2_laston > LED_DURATION)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
		led2_laston = 0;
		led2_lastoff = HAL_GetTick();
	}
}

