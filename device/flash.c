#include "flash.h"

float g_flashDataBuffer[FLASH_BUFFER_SIZE];

//������
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

//д����
void flash_write(void)
{
	//�Ȳ���
	LPLD_Flash_SectorErase(FLASH_TEST_ADDR);
	//��д��
	LPLD_Flash_ByteProgram((uint32)FLASH_TEST_ADDR, (uint32 *)g_flashDataBuffer, FLASH_BUFFER_SIZE * sizeof(FlashDataType));
}