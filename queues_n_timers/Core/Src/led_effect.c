/*
 * led_effect.c
 *
 *  Created on: Feb 27, 2026
 *      Author: ssingh
 */

#include "main.h"

void led_effect_stop(void)
{
	for(int i = 0 ; i < 4 ; i++)
		xTimerStop(handle_led_timer[i],portMAX_DELAY);
}

void led_effect(int n )
{
	led_effect_stop();
	xTimerStart(handle_led_timer[n-1], portMAX_DELAY);
}

void LED_effect1(void)
{
	static int flag = 1;
	if(flag ^= 1)
	{
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14,GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14,GPIO_PIN_RESET);
	}
}

void LED_effect2(void)
{
	HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_13);
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14,GPIO_PIN_RESET);
}

void LED_effect3(void)
{
	HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_14);
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13,GPIO_PIN_RESET);
}

void LED_effect4(void)
{
	static int flag = 1;
	if(flag ^= 1)
	{
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14,GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14,GPIO_PIN_SET);
	}
}

