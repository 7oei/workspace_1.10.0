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
}

void loop(void)
{
  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);

  nh.spinOnce();

//  HAL_Delay(1000);
}

void pwm_l_cb(const std_msgs::UInt8& msg){
	unsigned char pwm_l = msg.data;
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pwm_l);
}

void pwm_r_cb(const std_msgs::UInt8& msg){
	unsigned char pwm_r = msg.data;
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, pwm_r);
}

void dir_l_cb(const std_msgs::Bool& msg){
	bool dir_l = msg.data;
	if(dir_l) HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
}

void dir_r_cb(const std_msgs::Bool& msg){
	bool dir_r = msg.data;
	if(dir_r) HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
}
