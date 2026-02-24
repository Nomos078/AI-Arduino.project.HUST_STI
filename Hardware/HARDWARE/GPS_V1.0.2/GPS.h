#ifndef _GPS_H_
#define _GPS_H_

#include <stdint.h>

extern char GPS_rxBuf_lon[14];	// 经度 dddmm.mmmm,E
extern char GPS_rxBuf_lat[13];	// 纬度 ddmm.mmmm,N
extern char GPS_rxBuf_HH;
extern char GPS_rxBuf_MM;
extern char GPS_rxBuf_SS;
extern char GPS_location;		// 是否有效

void GPS_readData(uint8_t data);

#endif
