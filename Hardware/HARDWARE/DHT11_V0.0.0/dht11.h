#ifndef __DHT11_H
#define __DHT11_H 
#include "sys.h"   

									   
#define	DHT11_DQ_OUT PAout(4) 			//数据端口	PB5
#define	DHT11_DQ_IN  PAin(4)  			//数据端口	PB5

void DHT11_IO_IN(void);					//数据端口输入
void DHT11_IO_OUT(void);				//数据端口输出
u8 DHT11_Init(void);					//初始化DHT11
u8 DHT11_Read_Data(u8 *temp,u8 *humi);	//读取温湿度
u8 DHT11_Read_Byte(void);				//读出一个字节
u8 DHT11_Read_Bit(void);				//读出一个位
u8 DHT11_Check(void);					//检测是否存在DHT11
void DHT11_Rst(void);					//复位DHT11    
#endif















