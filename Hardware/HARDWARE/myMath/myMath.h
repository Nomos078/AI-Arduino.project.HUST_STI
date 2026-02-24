#ifndef _MYMATH_H_
#define _MYMATH_H_


/*

    char* my_intToStr(int num, char* buffer, int base)
    
    非标准C函数itoa的人工替代版
    
    功能   : 将整数按照指定的基数转换为字符串
    
    输入参数
        num    : 待转换的整数
        buffer : 要转换到的字符串
        base   : 转换的基数  如 10 则是转换为10进制数
        
    返回值 : 转换后的字符串首地址 若转换失败则为空
    
*/

char* my_intToStr(int num, char* buffer, int base);
char* my_intToCnStr(int num, char* buffer, const char* unit);

#endif
