/*******************************************************************************************************************
 * Keypad.h
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia - Taha Gamal
 *******************************************************************************************************************/
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "Keypad.h"
/*******************************************************************************************************************
 * shared global variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * static global variable(s)
 *******************************************************************************************************************/
static Keypad_enmButtonState_t Keypad_g_enmButtonState[KEYPAD_NUMBER_OF_KEYS];
static uint8_t Keypad_g_u8ButtonSample[KEYPAD_NUMBER_OF_KEYS];
/*******************************************************************************************************************
 * ISR & static function prototype(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * shared function definition(s)
 *******************************************************************************************************************/
/*......................................................................................
 * name:                Keypad_vInit
 * description:         intialize keypad pins
 * sync/async:          synchronous
 * reentrancy:          non reentrant
 * parameters (in):     none
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *......................................................................................*/
void Keypad_vInit(void)
{
	uint8_t Init_l_u8Counter;
	
	for(Init_l_u8Counter = 0; Init_l_u8Counter < KEYPAD_NUMBER_OF_ROWS; Init_l_u8Counter++)
	{
		DIO_Init(Keypad_u8RowPorts[Init_l_u8Counter], Keypad_u8RowPins[Init_l_u8Counter] , OUTPUT, GPIO_ALTERNATE_ENABLE, GPIO_OPEN_DRAIN_DISABLE, PULLDOWN);
	}

	for(Init_l_u8Counter = 0; Init_l_u8Counter < KEYPAD_NUMBER_OF_COLUMNS; Init_l_u8Counter++)
	{
		DIO_Init(Keypad_u8ColumnPorts[Init_l_u8Counter], Keypad_u8ColumnPins[Init_l_u8Counter] , INPUT, GPIO_ALTERNATE_ENABLE, GPIO_OPEN_DRAIN_DISABLE, PULLDOWN);
	}

	for(Init_l_u8Counter = 0; Init_l_u8Counter < KEYPAD_NUMBER_OF_KEYS; Init_l_u8Counter++)
	{
		Keypad_g_enmButtonState[Init_l_u8Counter] = BUTTON_STATE_RELEASED;
		Keypad_g_u8ButtonSample[Init_l_u8Counter] = 0u;
	}
}
/*......................................................................................
 * name:                Keypad_vCheckKeyState
 * description:         set the pins status to (pressed or released)
 * sync/async:          synchronous
 * reentrancy:          non reentrant
 * parameters (in):     none
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *......................................................................................*/
void Keypad_vCheckKeyState(void)
{
	uint8_t CheckKeyState_l_u8Row;
	uint8_t CheckKeyState_l_u8Column;
	uint8_t CheckKeyState_l_u8Key;
	
	for(CheckKeyState_l_u8Row = 0; CheckKeyState_l_u8Row < KEYPAD_NUMBER_OF_ROWS; CheckKeyState_l_u8Row++)
	{
		DIO_WritePin(Keypad_u8RowPorts[CheckKeyState_l_u8Row], Keypad_u8RowPins[CheckKeyState_l_u8Row], HIGH);
		for(CheckKeyState_l_u8Column = 0; CheckKeyState_l_u8Column < KEYPAD_NUMBER_OF_COLUMNS; CheckKeyState_l_u8Column++)
		{
			CheckKeyState_l_u8Key = (CheckKeyState_l_u8Row * KEYPAD_NUMBER_OF_COLUMNS) + CheckKeyState_l_u8Column;
			switch(Keypad_g_enmButtonState[CheckKeyState_l_u8Key])
			{
			case BUTTON_STATE_PRESSED:
				/* output */
				if(DIO_ReadPin(Keypad_u8ColumnPorts[CheckKeyState_l_u8Column],Keypad_u8ColumnPins[CheckKeyState_l_u8Column]) == HIGH)
				{
					Keypad_g_u8ButtonSample[CheckKeyState_l_u8Key] = 0u;
				}
				else
				{
					Keypad_g_u8ButtonSample[CheckKeyState_l_u8Key]++;
				}
				/* next state */
				if(Keypad_g_u8ButtonSample[CheckKeyState_l_u8Key] >= KEYPAD_NUMBER_OF_SAMPLES)
				{
					Keypad_g_enmButtonState[CheckKeyState_l_u8Key] = BUTTON_STATE_RELEASED;
					Keypad_g_u8ButtonSample[CheckKeyState_l_u8Key] = 0;
				}
				break;
			case BUTTON_STATE_RELEASED:
				/* output */
				if(DIO_ReadPin(Keypad_u8ColumnPorts[CheckKeyState_l_u8Column],Keypad_u8ColumnPins[CheckKeyState_l_u8Column]) == LOW)
				{
					Keypad_g_u8ButtonSample[CheckKeyState_l_u8Key] = 0u;
				}
				else
				{
					Keypad_g_u8ButtonSample[CheckKeyState_l_u8Key]++;
				}
				/* next state */
				if(Keypad_g_u8ButtonSample[CheckKeyState_l_u8Key] >= KEYPAD_NUMBER_OF_SAMPLES)
				{
					Keypad_g_enmButtonState[CheckKeyState_l_u8Key] = BUTTON_STATE_PRESSED;
					Keypad_g_u8ButtonSample[CheckKeyState_l_u8Key] = 0;
				}
				break;
			default :
				/* do nothing */
				break;
			}
		}
		DIO_WritePin(Keypad_u8RowPorts[CheckKeyState_l_u8Row], Keypad_u8RowPins[CheckKeyState_l_u8Row], LOW);
	}
}
/*......................................................................................
 * name:                Keypad_enmKeyState
 * description:         check the state of a specific pin
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     none
 * parameters (inout):  none
 * parameters (out):    none
 * return:              the pin state
 * remarks:             none
 * example:             none
 *......................................................................................*/
Keypad_enmButtonState_t Keypad_enmKeyState(Keypad_enmKeyName a_enmKeyName)
{
	Keypad_enmButtonState_t KeyIsPressed_l_ReturnValue;
	if(Keypad_g_enmButtonState[a_enmKeyName] == BUTTON_STATE_PRESSED)
	{
		KeyIsPressed_l_ReturnValue = BUTTON_STATE_PRESSED;
	}
	else
	{
		KeyIsPressed_l_ReturnValue = BUTTON_STATE_RELEASED;
	}
	return KeyIsPressed_l_ReturnValue;
}
/*******************************************************************************************************************
 * ISR & static function definition(s)
 *******************************************************************************************************************/
