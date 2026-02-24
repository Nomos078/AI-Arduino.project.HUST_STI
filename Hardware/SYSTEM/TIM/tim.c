#include "tim.h"

/*
	tim1_init(1000-1,72-1);	// 定时器初始化
	tim2_init(1000-1,72-1);	// 定时器初始化
	tim3_init(1000-1,72-1);	// 定时器初始化
	tim4_init(1000-1,72-1);	// 定时器初始化
*/

WEAK	// 预定义的中断回调函数
void tim1_IRQ(void)
{

}

WEAK	// 预定义的中断回调函数
void tim2_IRQ(void)
{

}

WEAK	// 预定义的中断回调函数
void tim3_IRQ(void)
{

}

WEAK	// 预定义的中断回调函数
void tim4_IRQ(void)
{

}


#if TIM1_enable
void tim1_init(uint16_t Pre,uint16_t Psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);				// 使能对应时钟
	
	TIM_TimeBaseInitStruct.TIM_Period			= Pre;					// 重装载值
	TIM_TimeBaseInitStruct.TIM_Prescaler		= Psc;					// 预分频值，定时时间
	TIM_TimeBaseInitStruct.TIM_ClockDivision	= TIM_CKD_DIV1;			// 系统时钟分频系数
	TIM_TimeBaseInitStruct.TIM_CounterMode		= TIM_CounterMode_Up;	// 向上计数模式
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStruct);					// 定时器初始化
	
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);							// 选择中断类型并使能
	
	NVIC_InitStruct.NVIC_IRQChannel 					= TIM1_UP_IRQn;	// stm32f103.h文件里
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= 0;			// 抢占式优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority			= 1;			// 响应式优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd					= ENABLE;		// 使能通道
	NVIC_Init(&NVIC_InitStruct);										// NVIC初始化
	
	TIM_Cmd(TIM1,ENABLE);												// 定时器使能
}

void TIM1_UP_IRQHandler()
{
	if(TIM_GetITStatus(TIM1,TIM_IT_Update) == 1)
	{
		tim1_IRQ();
	}
	TIM_ClearITPendingBit(TIM1,TIM_IT_Update);
}
#endif

#if TIM2_enable
void tim2_init(uint16_t Pre,uint16_t Psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);				// 使能对应时钟
	
	TIM_TimeBaseInitStruct.TIM_Period			= Pre;					// 重装载值
	TIM_TimeBaseInitStruct.TIM_Prescaler		= Psc;					// 预分频值，定时时间
	TIM_TimeBaseInitStruct.TIM_ClockDivision	= TIM_CKD_DIV1;			// 系统时钟分频系数
	TIM_TimeBaseInitStruct.TIM_CounterMode		= TIM_CounterMode_Up;	// 向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);					// 定时器初始化
	
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);							// 选择中断类型并使能
	
	NVIC_InitStruct.NVIC_IRQChannel 					= TIM2_IRQn;	// stm32f103.h文件里
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= 0;			// 抢占式优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority			= 1;			// 响应式优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd					= ENABLE;		// 使能通道
	NVIC_Init(&NVIC_InitStruct);										// NVIC初始化
	
	TIM_Cmd(TIM2,ENABLE);												// 定时器使能
}

void TIM2_IRQHandler()
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update) == 1)
	{
		tim2_IRQ();
	}
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
}
#endif

#if TIM3_enable
void tim3_init(uint16_t Pre,uint16_t Psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);				// 使能对应时钟
	
	TIM_TimeBaseInitStruct.TIM_Period			= Pre;					// 重装载值
	TIM_TimeBaseInitStruct.TIM_Prescaler		= Psc;					// 预分频值，定时时间
	TIM_TimeBaseInitStruct.TIM_ClockDivision	= TIM_CKD_DIV1;			// 系统时钟分频系数
	TIM_TimeBaseInitStruct.TIM_CounterMode		= TIM_CounterMode_Up;	// 向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);					// 定时器初始化
	
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);							// 选择中断类型并使能
	
	NVIC_InitStruct.NVIC_IRQChannel						= TIM3_IRQn;	// stm32f103.h文件里
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= 1;			// 抢占式优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority			= 1;			// 响应式优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd					= ENABLE;		// 使能通道
	NVIC_Init(&NVIC_InitStruct);										// NVIC初始化
	
	TIM_Cmd(TIM3,ENABLE);												// 定时器使能
}

void TIM3_IRQHandler()
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) == 1)
	{
		tim3_IRQ();
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
}
#endif

#if TIM4_enable
void tim4_init(uint16_t Pre,uint16_t Psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);				// 使能对应时钟
	
	TIM_TimeBaseInitStruct.TIM_Period			= Pre;					// 重装载值
	TIM_TimeBaseInitStruct.TIM_Prescaler		= Psc;					// 预分频值，定时时间
	TIM_TimeBaseInitStruct.TIM_ClockDivision	= TIM_CKD_DIV1;			// 系统时钟分频系数
	TIM_TimeBaseInitStruct.TIM_CounterMode		= TIM_CounterMode_Up;	// 向上计数模式
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStruct);					// 定时器初始化
	
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);							// 选择中断类型并使能
	
	NVIC_InitStruct.NVIC_IRQChannel						= TIM4_IRQn;	// stm32f103.h文件里
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= 0;			// 抢占式优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority			= 1;			// 响应式优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd					= ENABLE;		// 使能通道
	NVIC_Init(&NVIC_InitStruct);										// NVIC初始化
	
	TIM_Cmd(TIM4,ENABLE);												// 定时器使能
}

void TIM4_IRQHandler()
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update) == 1)
	{
		tim4_IRQ();
	}
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
}
#endif
