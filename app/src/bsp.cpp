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
}

