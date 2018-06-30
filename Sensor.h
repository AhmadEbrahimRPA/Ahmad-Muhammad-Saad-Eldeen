#ifndef _SENSOR_H_
#define _SENSOR_H_

#include "Main.h"

#define  SENSE_MAX_READING     (1000)

void sensor_init(void);
void sensor_update(void);
tWord get_sensor(void);

#endif // _SENSOR_H_
