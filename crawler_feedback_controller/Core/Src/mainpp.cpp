/*
 * main.cpp

 *
 *  Created on: 2018/01/17
 *      Author: yoneken
 *
 *  *** Note: This core requires a bit big transmit buffer.                 ***
 *  ***       You have to enlarge the buffer in STM32FHardware.h like this. ***
 *  ***       l.55   const static uint16_t tbuflen = 512;                   ***
 */
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_conf.h"
#include <mainpp.h>
#include <ros.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/Bool.h>

extern TIM_HandleTypeDef htim2;

ros::NodeHandle nh;
TIM_OC_InitTypeDef sConfigOC = {0};

void pwm_l_cb(const std_msgs::UInt8& msg);
void pwm_r_cb(const std_msgs::UInt8& msg);
void dir_l_cb(const std_msgs::Bool& msg);
void dir_r_cb(const std_msgs::Bool& msg);

ros::Subscriber<std_msgs::UInt8> pwm_l_sub("pwm_l", &pwm_l_cb);
ros::Subscriber<std_msgs::UInt8> pwm_r_sub("pwm_r", &pwm_r_cb);
ros::Subscriber<std_msgs::Bool> dir_l_sub("dir_l", &dir_l_cb);
ros::Subscriber<std_msgs::Bool> dir_r_sub("dir_r", &dir_r_cb);

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}

void setup(void)
{
  nh.initNode();
  nh.subscribe(pwm_l_sub);
  nh.subscribe(pwm_r_sub);
  nh.subscribe(dir_l_sub);
  nh.subscribe(dir_r_sub);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
}

void loop(void)
{
  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);

  nh.spinOnce();

//  HAL_Delay(1000);
}
int pwm_l_g = 0;
int pwm_r_g = 0;
int last_pwm_l_g = 0;
int last_pwm_r_g = 0;
bool last_dir_l_g = false;
bool last_dir_r_g = false;

void pwm_l_cb(const std_msgs::UInt8& msg){
	unsigned char pwm_l = msg.data;//0~255
	int duty_l = pwm_l * (909.0f / 255.0f) + 909.0f;
	pwm_l_g = pwm_l;
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty_l);
}

void pwm_r_cb(const std_msgs::UInt8& msg){
	unsigned char pwm_r = msg.data;
	int duty_r = pwm_r * (909.0f / 255.0f) + 909.0f;
	pwm_r_g = pwm_r;
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, duty_r);
}

void dir_l_cb(const std_msgs::Bool& msg){
	bool dir_l = msg.data;
	if(!last_dir_l_g&&dir_l){
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 909.0f);
		HAL_Delay(200);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
		HAL_Delay(200);
	}
	else if(last_dir_l_g&&!dir_l){
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 909.0f);
		HAL_Delay(200);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
		HAL_Delay(200);
	}
	last_dir_l_g = dir_l;
	last_pwm_l_g = pwm_l_g;
}

void dir_r_cb(const std_msgs::Bool& msg){
	bool dir_r = msg.data;
	if(!last_dir_r_g&&dir_r){
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 909.0f);
		HAL_Delay(200);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
		HAL_Delay(200);
	}
	else if(last_dir_r_g&&!dir_r){
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 909.0f);
		HAL_Delay(200);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
		HAL_Delay(200);
	}
	last_dir_r_g = dir_r;
	last_pwm_r_g = pwm_r_g;
}