#ifndef __OLED_H
#define __OLED_H

/**
 * @brief 初始化OLED显示屏
 */
void OLED_Init(void);

/**
 * @brief 清空OLED显示屏
 */
void OLED_Clear(void);

/**
 * @brief 在指定行和列显示一个字符
 * @param Line 行号 (0-7)
 * @param Column 列号 (0-127)
 * @param Char 要显示的字符
 */
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);

/**
 * @brief 在指定行和列显示一个字符串
 * @param Line 行号 (0-7)
 * @param Column 列号 (0-127)
 * @param String 要显示的字符串
 */
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);

/**
 * @brief 在指定行和列显示一个无符号数字
 * @param Line 行号 (0-7)
 * @param Column 列号 (0-127)
 * @param Number 要显示的无符号数字
 * @param Length 显示长度
 */
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

/**
 * @brief 在指定行和列显示一个有符号数字
 * @param Line 行号 (0-7)
 * @param Column 列号 (0-127)
 * @param Number 要显示的有符号数字
 * @param Length 显示长度
 */
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);

/**
 * @brief 在指定行和列显示一个十六进制数字
 * @param Line 行号 (0-7)
 * @param Column 列号 (0-127)
 * @param Number 要显示的十六进制数字
 * @param Length 显示长度
 */
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

/**
 * @brief 在指定行和列显示一个二进制数字
 * @param Line 行号 (0-7)
 * @param Column 列号 (0-127)
 * @param Number 要显示的二进制数字
 * @param Length 显示长度
 */
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

#endif
