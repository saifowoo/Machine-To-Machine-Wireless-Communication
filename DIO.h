/*******************************************************************************
 * File Name    : DIO.h                                                        *
 * Description  : header file for DIO pin Description                          *
 * Created on   : 8/17/2019 11:42 AM                                           *
 * Author       : Saif El-Deen Moustafa                                        *
 *******************************************************************************/

#ifndef DIO_H_
#define DIO_H_

/*******************************************************************************
 *                          Included Libraries                                 *
 *******************************************************************************/
//#include "StandardTypes.h"
#include "tm4c123gh6pm.h"
/*******************************************************************************/



/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/********** Ports Base Address **********/
#define GPIO_PORTA_BASE         0x40004000  /* GPIO Port A */
#define GPIO_PORTB_BASE         0x40005000  /* GPIO Port B */
#define GPIO_PORTC_BASE         0x40006000  /* GPIO Port C */
#define GPIO_PORTD_BASE         0x40007000  /* GPIO Port D */
#define GPIO_PORTE_BASE         0x40024000  /* GPIO Port E */
#define GPIO_PORTF_BASE         0x40025000  /* GPIO Port F */

/********** Pins mapping **********/
#define GPIO_PIN_0              0x00000001  /* GPIO pin 0 */
#define GPIO_PIN_1              0x00000002  /* GPIO pin 1 */
#define GPIO_PIN_2              0x00000004  /* GPIO pin 2 */
#define GPIO_PIN_3              0x00000008  /* GPIO pin 3 */
#define GPIO_PIN_4              0x00000010  /* GPIO pin 4 */
#define GPIO_PIN_5              0x00000020  /* GPIO pin 5 */
#define GPIO_PIN_6              0x00000040  /* GPIO pin 6 */
#define GPIO_PIN_7              0x00000080  /* GPIO pin 7 */

/********** Pins mapping **********/
//#define PIN0                    0x00000080  /* GPIO pin 7 */
//#define PIN1                    0x00000001  /* GPIO pin 0 */
//#define PIN2                    0x00000002  /* GPIO pin 1 */
//#define PIN3                    0x00000004  /* GPIO pin 2 */
//#define PIN4                    0x00000008  /* GPIO pin 3 */
//#define PIN5                    0x00000010  /* GPIO pin 4 */
//#define PIN6                    0x00000020  /* GPIO pin 5 */
//#define PIN7                    0x00000040  /* GPIO pin 6 */

/********** Ports Number **********/
#define PORTA                   0  /* GPIO pin 0 */
#define PORTB                   1  /* GPIO pin 1 */
#define PORTC                   2  /* GPIO pin 2 */
#define PORTD                   3  /* GPIO pin 3 */
#define PORTE                   4  /* GPIO pin 4 */
#define PORTF                   5  /* GPIO pin 5 */

/********** Hardware LEDs Number **********/
#define LED0
#define LED1
#define LED2
#define LED3

/********** Hardware PBs Number **********/
#define PushButton1
#define PushButton0

/********** Pin Directions **********/
#define INPUT                   0x00
#define OUTPUT                  0xFF

#define GPIO_ALTERNATE_ENABLE   0x00
#define GPIO_ALTERNATE_DISABLE  0xFF

#define GPIO_OPEN_DRAIN_ENABLE  0xFF
#define GPIO_OPEN_DRAIN_DISABLE 0x00

#define PULLDOWN                0x00
#define PULLUP                  0xFF

#define NC                      0xAA

/********** Pin Output/Input **********/
#define LOW         0
#define HIGH        1

/********** Hardware Keypad Pins **********/
#define ROW1
#define ROW2
#define ROW3
#define LINE1
#define LINE2
#define LINE3

/********** Hardware 7 Segment Pins **********/
#define SEGA
#define SEGB
#define SEGC
#define SEGD
#define SEGEN1
#define SEGEN2
#define SEGDP
/*******************************************************************************/



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:   DIO_Init
 * Description:     used to initialize hardware GPIO pins
 * parameters:
 *      Inputs:         1-
 *                      2-
 *                      3-
 *                      4-
 *                      5-
 *                      6-
 *      Outputs:        None
 * Return:          None
 *******************************************************************************/
void DIO_Init (uint32_t u32PortBase , uint8_t u8Mask , uint32_t u32PinIO , uint8_t u8PinAlternate , uint8_t u8OpenDrain , uint8_t u8PullResistor);
/*******************************************************************************/

/*******************************************************************************
 * Function Name:   DIO_AlternateSelect
 * Description:     used to write on alternate select
 * parameters:
 *      Inputs:         1-
 *                      2-
 *                      3-
 *      Outputs:        None
 * Return:          None
 *******************************************************************************/
void DIO_AlternateSelect (uint32_t u32PortBase , uint8_t u8PinsNum , uint8_t u32PinValue);
/*******************************************************************************/

/*******************************************************************************
 * Function Name:   DIO_WritePin
 * Description:     used to write on specific pin
 * parameters:
 *      Inputs:         1-
 *                      2-
 *                      3-
 *      Outputs:        None
 * Return:          None
 *******************************************************************************/
void DIO_WritePin (uint32_t u32PortBase , uint8_t u8Mask , uint8_t u32PinValue);
/*******************************************************************************/

/*******************************************************************************
 * Function Name:   DIO_ReadPin
 * Description:     used to read pin value
 * parameters:
 *      Inputs:         1- Port Base Address
 *                      2- Pin Number
 *      Outputs:        Pin Value
 * Return:          Pin value (High,Low)
 *******************************************************************************/
uint32_t DIO_ReadPin (uint32_t u32PortBase , uint8_t u8PinNum);
/*******************************************************************************/


#endif /* DIO_H_ */
