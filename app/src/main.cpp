/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss.h>
#include <bsp.h>
#include <yss/debug.h>
#include <util/runtime.h>
#include <std_ext/string.h>

void thread_testUart(void);

const char *gHelloWord = "Hello World!!\n\r";
uint32_t gSize = strlen(gHelloWord);

int main(void)
{
	// 운영체체 초기화
	initializeYss();

	// 보드 초기화
	initializeBoard();

	thread::add(thread_testUart, 512);
	
	while(1)
	{
		if(uart0.getRxCount() > 0)
		{
			debug_printf("%c\r\n", uart0.getRxByte());
		}
		thread::yield();
	}
}

void thread_testUart(void)
{
	while(1)
	{
		uart0.send(gHelloWord, gSize);
	}
}

