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

int main(void)
{
	uint8_t sa[32], da[32];

	for(uint32_t i = 0; i < 32; i++)
	{
		sa[i] = i;
		da[i] = 0;
	}
		// 운영체체 초기화
	initializeYss();

	// 보드 초기화
	initializeBoard();

	// DMA memory to memory Test
	memcpyd(da, sa, 32);

	memsetd(da, 0xAA, 32);

	memsethwd(da, 0xBBCC, 16);

	memsetwd(da, 0x12345678, 8);

	while(1)
	{
		debug_printf("%d\r", (uint32_t)runtime::getMsec());
		thread::yield();
	}
}

