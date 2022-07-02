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

extern TIM_HandleTypeDef htim2;

ros::NodeHandle nh;
TIM_OC_InitTypeDef sConfigOC = {0};

void pwm_l_cb(const std_msgs::UInt8& msg);
void pwm_r_cb(const std_msgs::UInt8& msg);
void led2_cb(const std_msgs::UInt8& msg);
void led3_cb(const std_msgs::UInt8& msg);

ros::Subscriber<std_msgs::UInt8> pwm_l_sub("pwm_l", &pwm_l_cb);
ros::Subscriber<std_msgs::UInt8> pwm_r_sub("pwm_r", &pwm_r_cb);
ros::Subscriber<std_msgs::UInt8> led2_sub("led2", &led2_cb);
ros::Subscriber<std_msgs::UInt8> led3_sub("led3", &led3_cb);

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
  nh.subscribe(led2_sub);
  nh.subscribe(led3_sub);
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
	unsigned char duty1 = msg.data;
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty1);
}

void pwm_r_cb(const std_msgs::UInt8& msg){
	unsigned char duty2 = msg.data;
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, duty2);
}

void led2_cb(const std_msgs::UInt8& msg){
	unsigned char duty3 = msg.data;
}

void led3_cb(const std_msgs::UInt8& msg){
	unsigned char duty4 = msg.data;
}
