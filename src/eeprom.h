/*
 * eeprom.h
 *
 *  Created on: Jan 25, 2017
 *      Author: user
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_conf.h"
#include <stm32f4xx_hal_i2c.h>
#include <stm32f4xx.h>

#define HAL_I2C_MODULE_ENABLED
#define HAL_TIM_MODULE_ENABLED

#define EEPROM_ADDRESS              0xA0
#define EEPROM_MAXPKT             32              //(page size)
#define EEPROM_WRITE              10              //time to wait in ms
#define EEPROM_TIMEOUT             5*EEPROM_WRITE  //timeout while writing
#define EEPROM_SECTIONSIZE			64

class Eeprom {
public:
	Eeprom();
	virtual ~Eeprom();
	HAL_StatusTypeDef writeEEPROM(uint16_t address, uint8_t* MemTarget,
			uint16_t Size);
	HAL_StatusTypeDef readEEPROM(uint16_t address, uint8_t* MemTarget,
			uint16_t Size);
	void begin(I2C_HandleTypeDef* i2cPort);
//	void readObject(structObject* settings, int section);
//	void saveObject(structObject* settings, int section);

	I2C_HandleTypeDef* i2c_port;
};

#endif /* EEPROM_H_ */