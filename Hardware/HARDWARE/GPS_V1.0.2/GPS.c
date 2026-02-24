#include "GPS.h"
#include "stm32f10x_usart.h"

/*
*/


char GPS_rxBuf_lon[14];	//  dddmm.mmmm,E
char GPS_rxBuf_lat[13];	//  ddmm.mmmm,N
char GPS_rxBuf_HH;
char GPS_rxBuf_MM;
char GPS_rxBuf_SS;

char GPS_rxBuf_time_HH;
char GPS_rxBuf_time_MM;
char GPS_rxBuf_time_SS;

char GPS_location			= 0;

unsigned char GPS_schedule	= 0;
unsigned char GPS_count		= 0;
const char protocolHeader[]	= "GLL";

void GPS_readData(uint8_t data)
{

	// 根据不同的GPS接收阶段进行处理
	switch(GPS_schedule)
	{
		// 0代表正在接收报文头
		case 0:
			if(data == protocolHeader[GPS_count])
			{
				GPS_count++;
				if(GPS_count == 3) GPS_schedule = 1;
				if(GPS_count >  3) GPS_count = 0;
			}
			else
			{
				GPS_count = 0;
			}
			break;
		case 1:
			GPS_schedule = 2;
			GPS_count = 0;
			break;
		case 2:
			if(data == ',')
			{
				// 结束当前GPS数据包的接收
				// 清空接收缓冲区
				GPS_location = 0;
				GPS_schedule = 0;
				GPS_rxBuf_lon[0] = '\0';
				GPS_rxBuf_lat[0] = '\0';
				break;
			}
			else
			{
				GPS_location = 1;
				GPS_schedule = 3;
			}
		case 3:
			GPS_rxBuf_lat[GPS_count++] = data;
			if(GPS_count == 12)
			{
				GPS_schedule = 4;
			}
			break;
		case 4:
			GPS_schedule = 5;
			GPS_count = 0;
			break;
		case 5:
			GPS_rxBuf_lon[GPS_count++] = data;
			if(GPS_count == 13)
			{
				GPS_schedule = 6;
			}
			break;
		case 6:
			GPS_schedule = 7;
			GPS_count = 0;
			GPS_rxBuf_time_HH = 0;
			break;
		case 7:
			GPS_rxBuf_time_HH = GPS_rxBuf_time_HH * 10 + data - '0';
			GPS_count++;
			if(GPS_count == 2)
			{
				GPS_rxBuf_time_HH = (GPS_rxBuf_time_HH + 8) % 24;
				GPS_rxBuf_time_MM = 0;
				GPS_count = 0;
				GPS_schedule = 8;
			}
			break;
		case 8:
			GPS_rxBuf_time_MM = GPS_rxBuf_time_MM * 10 + data - '0';
			GPS_count++;
			if(GPS_count == 2)
			{
				GPS_rxBuf_time_SS = 0;
				GPS_count = 0;
				GPS_schedule = 9;
			}
			break;
		case 9:
			GPS_rxBuf_time_SS = GPS_rxBuf_time_SS * 10 + data - '0';
			GPS_count++;
			if(GPS_count == 2)
			{
				GPS_count = 0;
				GPS_schedule = 0;
				
				GPS_rxBuf_HH = GPS_rxBuf_time_HH;
				GPS_rxBuf_MM = GPS_rxBuf_time_MM;
				GPS_rxBuf_SS = GPS_rxBuf_time_SS;
			}
			break;
	}

}
