#include "flash.h"

float g_flashDataBuffer[FLASH_BUFFER_SIZE];

//读数据
void flash_read(void)
{
	FlashDataType *pTemp = NULL;
	uint8 len = 0;

	pTemp = (FlashDataType *)FLASH_TEST_ADDR;

	for (len = 0; len < FLASH_BUFFER_SIZE; len++)
	{
		g_flashDataBuffer[len] = *(pTemp + len);
	}
}

//写数据
void flash_write(void)
{
	//先擦除
	LPLD_Flash_SectorErase(FLASH_TEST_ADDR);
	//再写入
	LPLD_Flash_ByteProgram((uint32)FLASH_TEST_ADDR, (uint32 *)g_flashDataBuffer, FLASH_BUFFER_SIZE * sizeof(FlashDataType));
}