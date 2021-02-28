#ifndef _FLASH_H_
#define _FLASH_H_

#include "common.h"

//����д�����������
typedef float FlashDataType;

#define FLASH_TEST_SECTOR (255) //дFlash�����һ������
#define FLASH_TEST_ADDR (FLASH_TEST_SECTOR * (2048))
#define FLASH_BUFFER_SIZE (100) //д��Flash�����ݻ������Ĵ�С��FLASH_BUFFER_SIZE*��sizeof(FlashData)��<2048

extern FlashDataType g_flashDataBuffer[FLASH_BUFFER_SIZE];

void flash_read(void);  //������
void flash_write(void); //д����

#endif