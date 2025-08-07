/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <bsp.h>
#include <yss/instance.h>

void initializeBoard(void)
{
	// UART0 초기화
	Uart::config_t uart0Config =
	{
		Uart::MODE_NORMAL,	//mode_t mode;			// 동작 모드의 종류를 설정합니다.
		115200,				//uint32_t baudrate;		// 보레이트를 설정합니다.
		Uart::STOP_1BIT,	//stopbit_t stopbit;		// Stop Bit의 종류를 설정합니다.
		nullptr,			//void *rcvBuf;			// 수신 버퍼를 지정합니다.
		128				//uint32_t rcvBufSize;	// 수신 버퍼의 크기를 지정합니다.
	};

	gpioB.setAsAltFunc(12, Gpio::PB12_UART0_RXD);
	gpioB.setAsAltFunc(13, Gpio::PB13_UART0_TXD);

	uart0.enableClock();
	uart0.initialize(uart0Config);
	uart0.enableInterrupt();

	// bpwm0 초기화
	gpioA.setAsAltFunc(11, Gpio::PA11_BPWM0_CH0);	// PA11을 BPWM0 CH0으로 설정
	gpioA.setAsAltFunc(10, Gpio::PA10_BPWM0_CH1);	// PA10을 BPWM0 CH1으로 설정
	gpioA.setAsAltFunc(9, Gpio::PA9_BPWM0_CH2);		// PA9을 BPWM0 CH2으로 설정
	gpioA.setAsAltFunc(8, Gpio::PA8_BPWM0_CH3);		// PA8을 BPWM0 CH3으로 설정
	gpioA.setAsAltFunc(4, Gpio::PA4_BPWM0_CH4);		// PA8을 BPWM0 CH4으로 설정
	gpioA.setAsAltFunc(5, Gpio::PA5_BPWM0_CH5);		// PA8을 BPWM0 CH5으로 설정

	bpwm0.enableClock();							// BPWM0의 클럭 활성화
	bpwm0.initialize(1000);							// BPWM0의 출력 주기를 1kHz로 초기화
	bpwm0.setAsPwmOutput(0, true);					// BPWM0의 CH0을 PWM 반전 출력으로 설정
	bpwm0.setAsPwmOutput(1);						// BPWM0의 CH1을 PWM 비반전 출력으로 설정
	bpwm0.setAsPwmOutput(2);						// BPWM0의 CH2를 PWM 비반전 출력으로 설정
	bpwm0.setAsPwmOutput(3);						// BPWM0의 CH3을 PWM 비반전 출력으로 설정
	bpwm0.setAsPwmOutput(4);						// BPWM0의 CH4를 PWM 비반전 출력으로 설정
	bpwm0.setAsPwmOutput(5);						// BPWM0의 CH5를 PWM 비반전 출력으로 설정
	bpwm0.start();									// 타이머 카운터 시작

	bpwm0.setDutyRatio(0, 0.1);						// BPWM0 CH0의 출력 듀티비를 10%로 설정
	bpwm0.setDutyRatio(1, 0.2);						// BPWM0 CH1의 출력 듀티비를 20%로 설정
	bpwm0.setDutyRatio(2, 0.3);						// BPWM0 CH2의 출력 듀티비를 30%로 설정
	bpwm0.setDutyRatio(3, 0.4);						// BPWM0 CH3의 출력 듀티비를 40%로 설정
	bpwm0.setDutyRatio(4, 0.5);						// BPWM0 CH4의 출력 듀티비를 50%로 설정
	bpwm0.setDutyRatio(5, 0.6);						// BPWM0 CH5의 출력 듀티비를 60%로 설정

}

