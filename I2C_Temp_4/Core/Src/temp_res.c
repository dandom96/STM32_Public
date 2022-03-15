#include <temp_res.h>
#include <stdint.h>
#include <main.h>

//I2C_HandleTypeDef hi2c1;

float temperature(uint8_t buf[6])
{
	  float t, t_raw;
	  t_raw = (uint16_t)((((uint16_t)buf[0])<<8) | (uint16_t)buf[1]);
	  t = -45 + 175*t_raw/65535;
	  return t;
}

float humidity(uint8_t buf[6])
{
	  float h, h_raw;
	  h_raw = (uint16_t)((((uint16_t)buf[3])<<8) | (uint16_t)buf[4]);
	  h = 100 * h_raw/65535;
	  return h;
}

//rawHum = (float)rawHum;
//rawTemp = (float)rawTemp;
