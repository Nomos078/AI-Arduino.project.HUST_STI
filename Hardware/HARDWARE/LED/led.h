#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

#define LED PCout(13) = !PCin(13)


#define OUT1 PAout(15)
#define OUT2 PBout(3)
#define OUT3 PBout(4)
#define OUT4 PAout(6)
#define OUT5 PAout(7)
#define OUT6 PAout(8)

#define KEY_1 PBin(15)
#define KEY_2 PBin(14)
#define KEY_3 PBin(13)
#define KEY_4 PBin(12)
#define KEY_5 PBin(1)
#define QX PAin(1)

#define IN1 PCin(14)
#define IN2 PCin(15)

void LED_Init(void);//≥ı ºªØ

		 				    
#endif
