/*******************************************************************************
 * File Name    : DIO.c                                                        *
 * Description  : Source file for DIO pin description                          *
 * Created on   : 8/17/2019 11:42 AM                                           *
 * Author       : Saif El-Deen Moustafa                                        *
 *******************************************************************************/



/*******************************************************************************
 *                          Included Libraries                                 *
 *******************************************************************************/
#include "DIO.h"
#include "CommonMacros.h"
/*******************************************************************************/



/*******************************************************************************
 *                      Functions Implementation                               *
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
void DIO_Init (uint32_t u32PortBase , uint8_t u8Mask , uint32_t u32PinIO , uint8_t u8PinAlternate , uint8_t u8OpenDrain , uint8_t u8PullResistor)
{
    switch(u32PortBase)
    {
            case (uint32_t)GPIO_PORTA_BASE:
                /*Enable Clock Gate*/
                SET_BIT(SYSCTL_RCGCGPIO_R,PORTA);
                /*Wait till port be ready*/
                while(GET_BIT(SYSCTL_PRGPIO_R,PORTA) == LOW);
                /*Check pin alternate*/
                switch(u8PinAlternate)
                {
                    /*if GPIO*/
                    case GPIO_ALTERNATE_ENABLE:
                        /*Check I/O state*/
                        switch(u32PinIO)
                        {
                            /*if output*/
                            case OUTPUT:
                                /*Set the direction to Output*/
                                WRITE_REG(GPIO_PORTA_DIR_R,u8Mask,OUTPUT);
                                break;

                            /*if input*/
                            case INPUT:
                                /*Set the direction to Input*/
                                WRITE_REG(GPIO_PORTA_DIR_R,u8Mask,INPUT);

                            default:
                                /*Do Nothing*/
                                break;
                        }

                        /*Set the pin to GPIO alternate enable*/
                        WRITE_REG(GPIO_PORTA_AFSEL_R,u8Mask,GPIO_ALTERNATE_ENABLE);
                        
                        /*Select pull down or pull up resistor*/
                        switch(u8PullResistor)
                        {
                            /*if Pull Down*/
                            case PULLDOWN:
                                /*Set the pull down register*/
                                WRITE_REG(GPIO_PORTA_PDR_R,u8Mask,u8Mask);
                                break;

                            /*if Pull Up*/
                            case PULLUP:
                                /*Set the pull up register*/
                                WRITE_REG(GPIO_PORTA_PUR_R,u8Mask,u8Mask);

                            default:
                                /*Do Nothing*/
                                break;
                        }
                        break;

                    /*if peripheral pin*/
                    case GPIO_ALTERNATE_DISABLE:
                        /*Set the pin to GPIO alternate disable*/
                        WRITE_REG(GPIO_PORTA_AFSEL_R,u8Mask,GPIO_ALTERNATE_DISABLE);
                        break;

                    default:
                        /*Do Nothing*/
                        break;
                }                

                switch(u8OpenDrain)
                {
                    /*if open drain enable*/
                    case GPIO_OPEN_DRAIN_ENABLE:
                        /*Set the pin to open drain enable*/
                        WRITE_REG(GPIO_PORTA_ODR_R,u8Mask,GPIO_OPEN_DRAIN_ENABLE);
                        break;

                    /*if open drain disable*/
                    case GPIO_OPEN_DRAIN_DISABLE:
                        /*Set the pin to open drain disable*/
                        WRITE_REG(GPIO_PORTA_ODR_R,u8Mask,GPIO_OPEN_DRAIN_DISABLE);
                        break;

                    default:
                        /*Do Nothing*/
                        break;
                }
                /*select 2mA Current*/
                WRITE_REG(GPIO_PORTA_DR2R_R,u8Mask,u8Mask);
                /*enable the Digital function*/
                WRITE_REG(GPIO_PORTA_DEN_R,u8Mask,u8Mask);
                break;

            case (uint32_t)GPIO_PORTB_BASE:
                /*Enable Clock Gate*/
                SET_BIT(SYSCTL_RCGCGPIO_R,PORTB);
                /*Wait till port be ready*/
                while(GET_BIT(SYSCTL_PRGPIO_R,PORTB) == LOW);
                /*Check pin alternate*/
                switch(u8PinAlternate)
                {
                    /*if GPIO*/
                    case GPIO_ALTERNATE_ENABLE:
                        /*Check I/O state*/
                        switch(u32PinIO)
                        {
                            /*if output*/
                            case OUTPUT:
                                /*Set the direction to Output*/
                                WRITE_REG(GPIO_PORTB_DIR_R,u8Mask,OUTPUT);
                                break;

                            /*if input*/
                            case INPUT:
                                /*Set the direction to Input*/
                                WRITE_REG(GPIO_PORTB_DIR_R,u8Mask,INPUT);

                            default:
                                /*Do Nothing*/
                                break;
                        }

                        /*Set the pin to GPIO alternate enable*/
                        WRITE_REG(GPIO_PORTB_AFSEL_R,u8Mask,GPIO_ALTERNATE_ENABLE);
                        
                        /*Select pull down or pull up resistor*/
                        switch(u8PullResistor)
                        {
                            /*if Pull Down*/
                            case PULLDOWN:
                                /*Set the pull down register*/
                                WRITE_REG(GPIO_PORTB_PDR_R,u8Mask,u8Mask);
                                break;

                            /*if Pull Up*/
                            case PULLUP:
                                /*Set the pull up register*/
                                WRITE_REG(GPIO_PORTB_PUR_R,u8Mask,u8Mask);

                            default:
                                /*Do Nothing*/
                                break;
                        }
                        break;

                    /*if peripheral pin*/
                    case GPIO_ALTERNATE_DISABLE:
                        /*Set the pin to GPIO alternate disable*/
                        WRITE_REG(GPIO_PORTB_AFSEL_R,u8Mask,GPIO_ALTERNATE_DISABLE);
                        break;

                    default:
                        /*Do Nothing*/
                        break;
                }                

                switch(u8OpenDrain)
                {
                    /*if open drain enable*/
                    case GPIO_OPEN_DRAIN_ENABLE:
                        /*Set the pin to open drain enable*/
                        WRITE_REG(GPIO_PORTB_ODR_R,u8Mask,GPIO_OPEN_DRAIN_ENABLE);
                        break;

                    /*if open drain disable*/
                    case GPIO_OPEN_DRAIN_DISABLE:
                        /*Set the pin to open drain disable*/
                        WRITE_REG(GPIO_PORTB_ODR_R,u8Mask,GPIO_OPEN_DRAIN_DISABLE);
                        break;

                    default:
                        /*Do Nothing*/
                        break;
                }
                /*select 2mA Current*/
                WRITE_REG(GPIO_PORTB_DR2R_R,u8Mask,u8Mask);
                /*enable the Digital function*/
                WRITE_REG(GPIO_PORTB_DEN_R,u8Mask,u8Mask);
                break;

            case (uint32_t)GPIO_PORTC_BASE:
                /*Enable Clock Gate*/
                SET_BIT(SYSCTL_RCGCGPIO_R,PORTC);
                /*Wait till port be ready*/
                while(GET_BIT(SYSCTL_PRGPIO_R,PORTC) == LOW);
                /*Check pin alternate*/
                switch(u8PinAlternate)
                {
                    /*if GPIO*/
                    case GPIO_ALTERNATE_ENABLE:
                        /*Check I/O state*/
                        switch(u32PinIO)
                        {
                            /*if output*/
                            case OUTPUT:
                                /*Set the direction to Output*/
                                WRITE_REG(GPIO_PORTC_DIR_R,u8Mask,OUTPUT);
                                break;

                            /*if input*/
                            case INPUT:
                                /*Set the direction to Input*/
                                WRITE_REG(GPIO_PORTC_DIR_R,u8Mask,INPUT);

                            default:
                                /*Do Nothing*/
                                break;
                        }

                        /*Set the pin to GPIO alternate enable*/
                        WRITE_REG(GPIO_PORTC_AFSEL_R,u8Mask,GPIO_ALTERNATE_ENABLE);
                        
                        /*Select pull down or pull up resistor*/
                        switch(u8PullResistor)
                        {
                            /*if Pull Down*/
                            case PULLDOWN:
                                /*Set the pull down register*/
                                WRITE_REG(GPIO_PORTC_PDR_R,u8Mask,u8Mask);
                                break;

                            /*if Pull Up*/
                            case PULLUP:
                                /*Set the pull up register*/
                                WRITE_REG(GPIO_PORTC_PUR_R,u8Mask,u8Mask);

                            default:
                                /*Do Nothing*/
                                break;
                        }
                        break;

                    /*if peripheral pin*/
                    case GPIO_ALTERNATE_DISABLE:
                        /*Set the pin to GPIO alternate disable*/
                        WRITE_REG(GPIO_PORTC_AFSEL_R,u8Mask,GPIO_ALTERNATE_DISABLE);
                        break;

                    default:
                        /*Do Nothing*/
                        break;
                }                

                switch(u8OpenDrain)
                {
                    /*if open drain enable*/
                    case GPIO_OPEN_DRAIN_ENABLE:
                        /*Set the pin to open drain enable*/
                        WRITE_REG(GPIO_PORTC_ODR_R,u8Mask,GPIO_OPEN_DRAIN_ENABLE);
                        break;

                    /*if open drain disable*/
                    case GPIO_OPEN_DRAIN_DISABLE:
                        /*Set the pin to open drain disable*/
                        WRITE_REG(GPIO_PORTC_ODR_R,u8Mask,GPIO_OPEN_DRAIN_DISABLE);
                        break;

                    default:
                        /*Do Nothing*/
                        break;
                }
                /*select 2mA Current*/
                WRITE_REG(GPIO_PORTC_DR2R_R,u8Mask,u8Mask);
                /*enable the Digital function*/
                WRITE_REG(GPIO_PORTC_DEN_R,u8Mask,u8Mask);
                break;

            case (uint32_t)GPIO_PORTD_BASE:
                /*Enable Clock Gate*/
                SET_BIT(SYSCTL_RCGCGPIO_R,PORTD);
                /*Wait till port be ready*/
                while(GET_BIT(SYSCTL_PRGPIO_R,PORTD) == LOW);
                /*Check pin alternate*/
                switch(u8PinAlternate)
                {
                    /*if GPIO*/
                    case GPIO_ALTERNATE_ENABLE:
                        /*Check I/O state*/
                        switch(u32PinIO)
                        {
                            /*if output*/
                            case OUTPUT:
                                /*Set the direction to Output*/
                                WRITE_REG(GPIO_PORTD_DIR_R,u8Mask,OUTPUT);
                                break;

                            /*if input*/
                            case INPUT:
                                /*Set the direction to Input*/
                                WRITE_REG(GPIO_PORTD_DIR_R,u8Mask,INPUT);

                            default:
                                /*Do Nothing*/
                                break;
                        }

                        /*Set the pin to GPIO alternate enable*/
                        WRITE_REG(GPIO_PORTD_AFSEL_R,u8Mask,GPIO_ALTERNATE_ENABLE);
                        
                        /*Select pull down or pull up resistor*/
                        switch(u8PullResistor)
                        {
                            /*if Pull Down*/
                            case PULLDOWN:
                                /*Set the pull down register*/
                                WRITE_REG(GPIO_PORTD_PDR_R,u8Mask,u8Mask);
                                break;

                            /*if Pull Up*/
                            case PULLUP:
                                /*Set the pull up register*/
                                WRITE_REG(GPIO_PORTD_PUR_R,u8Mask,u8Mask);

                            default:
                                /*Do Nothing*/
                                break;
                        }
                        break;

                    /*if peripheral pin*/
                    case GPIO_ALTERNATE_DISABLE:
                        /*Set the pin to GPIO alternate disable*/
                        WRITE_REG(GPIO_PORTD_AFSEL_R,u8Mask,GPIO_ALTERNATE_DISABLE);
                        break;

                    default:
                        /*Do Nothing*/
                        break;
                }                

                switch(u8OpenDrain)
                {
                    /*if open drain enable*/
                    case GPIO_OPEN_DRAIN_ENABLE:
                        /*Set the pin to open drain enable*/
                        WRITE_REG(GPIO_PORTD_ODR_R,u8Mask,GPIO_OPEN_DRAIN_ENABLE);
                        break;

                    /*if open drain disable*/
                    case GPIO_OPEN_DRAIN_DISABLE:
                        /*Set the pin to open drain disable*/
                        WRITE_REG(GPIO_PORTD_ODR_R,u8Mask,GPIO_OPEN_DRAIN_DISABLE);
                        break;

                    default:
                        /*Do Nothing*/
                        break;
                }
                /*select 2mA Current*/
                WRITE_REG(GPIO_PORTD_DR2R_R,u8Mask,u8Mask);
                /*enable the Digital function*/
                WRITE_REG(GPIO_PORTD_DEN_R,u8Mask,u8Mask);
                break;

            case (uint32_t)GPIO_PORTE_BASE:
                /*Enable Clock Gate*/
                SET_BIT(SYSCTL_RCGCGPIO_R,PORTE);
                /*Wait till port be ready*/
                while(GET_BIT(SYSCTL_PRGPIO_R,PORTE) == LOW);
                /*Check pin alternate*/
                switch(u8PinAlternate)
                {
                    /*if GPIO*/
                    case GPIO_ALTERNATE_ENABLE:
                        /*Check I/O state*/
                        switch(u32PinIO)
                        {
                            /*if output*/
                            case OUTPUT:
                                /*Set the direction to Output*/
                                WRITE_REG(GPIO_PORTE_DIR_R,u8Mask,OUTPUT);
                                break;

                            /*if input*/
                            case INPUT:
                                /*Set the direction to Input*/
                                WRITE_REG(GPIO_PORTE_DIR_R,u8Mask,INPUT);

                            default:
                                /*Do Nothing*/
                                break;
                        }

                        /*Set the pin to GPIO alternate enable*/
                        WRITE_REG(GPIO_PORTE_AFSEL_R,u8Mask,GPIO_ALTERNATE_ENABLE);
                        
                        /*Select pull down or pull up resistor*/
                        switch(u8PullResistor)
                        {
                            /*if Pull Down*/
                            case PULLDOWN:
                                /*Set the pull down register*/
                                WRITE_REG(GPIO_PORTE_PDR_R,u8Mask,u8Mask);
                                break;

                            /*if Pull Up*/
                            case PULLUP:
                                /*Set the pull up register*/
                                WRITE_REG(GPIO_PORTE_PUR_R,u8Mask,u8Mask);

                            default:
                                /*Do Nothing*/
                                break;
                        }
                        break;

                    /*if peripheral pin*/
                    case GPIO_ALTERNATE_DISABLE:
                        /*Set the pin to GPIO alternate disable*/
                        WRITE_REG(GPIO_PORTE_AFSEL_R,u8Mask,GPIO_ALTERNATE_DISABLE);
                        break;

                    default:
                        /*Do Nothing*/
                        break;
                }                

                switch(u8OpenDrain)
                {
                    /*if open drain enable*/
                    case GPIO_OPEN_DRAIN_ENABLE:
                        /*Set the pin to open drain enable*/
                        WRITE_REG(GPIO_PORTE_ODR_R,u8Mask,GPIO_OPEN_DRAIN_ENABLE);
                        break;

                    /*if open drain disable*/
                    case GPIO_OPEN_DRAIN_DISABLE:
                        /*Set the pin to open drain disable*/
                        WRITE_REG(GPIO_PORTE_ODR_R,u8Mask,GPIO_OPEN_DRAIN_DISABLE);
                        break;

                    default:
                        /*Do Nothing*/
                        break;
                }
                /*select 2mA Current*/
                WRITE_REG(GPIO_PORTE_DR2R_R,u8Mask,u8Mask);
                /*enable the Digital function*/
                WRITE_REG(GPIO_PORTE_DEN_R,u8Mask,u8Mask);
                break;

            case (uint32_t)GPIO_PORTF_BASE:
                /*Enable Clock Gate*/
                SET_BIT(SYSCTL_RCGCGPIO_R,PORTF);
                /*Wait till port be ready*/
                while(GET_BIT(SYSCTL_PRGPIO_R,PORTF) == LOW);
                /*Check pin alternate*/
                switch(u8PinAlternate)
                {
                    /*if GPIO*/
                    case GPIO_ALTERNATE_ENABLE:
                        /*Check I/O state*/
                        switch(u32PinIO)
                        {
                            /*if output*/
                            case OUTPUT:
                                /*Set the direction to Output*/
                                WRITE_REG(GPIO_PORTF_DIR_R,u8Mask,OUTPUT);
                                break;

                            /*if input*/
                            case INPUT:
                                /*Set the direction to Input*/
                                WRITE_REG(GPIO_PORTF_DIR_R,u8Mask,INPUT);

                            default:
                                /*Do Nothing*/
                                break;
                        }

                        /*Set the pin to GPIO alternate enable*/
                        WRITE_REG(GPIO_PORTF_AFSEL_R,u8Mask,GPIO_ALTERNATE_ENABLE);
                        
                        /*Select pull down or pull up resistor*/
                        switch(u8PullResistor)
                        {
                            /*if Pull Down*/
                            case PULLDOWN:
                                /*Set the pull down register*/
                                WRITE_REG(GPIO_PORTF_PDR_R,u8Mask,u8Mask);
                                break;

                            /*if Pull Up*/
                            case PULLUP:
                                /*Set the pull up register*/
                                WRITE_REG(GPIO_PORTF_PUR_R,u8Mask,u8Mask);

                            default:
                                /*Do Nothing*/
                                break;
                        }
                        break;

                    /*if peripheral pin*/
                    case GPIO_ALTERNATE_DISABLE:
                        /*Set the pin to GPIO alternate disable*/
                        WRITE_REG(GPIO_PORTF_AFSEL_R,u8Mask,GPIO_ALTERNATE_DISABLE);
                        break;

                    default:
                        /*Do Nothing*/
                        break;
                }                

                switch(u8OpenDrain)
                {
                    /*if open drain enable*/
                    case GPIO_OPEN_DRAIN_ENABLE:
                        /*Set the pin to open drain enable*/
                        WRITE_REG(GPIO_PORTF_ODR_R,u8Mask,GPIO_OPEN_DRAIN_ENABLE);
                        break;

                    /*if open drain disable*/
                    case GPIO_OPEN_DRAIN_DISABLE:
                        /*Set the pin to open drain disable*/
                        WRITE_REG(GPIO_PORTF_ODR_R,u8Mask,GPIO_OPEN_DRAIN_DISABLE);
                        break;

                    default:
                        /*Do Nothing*/
                        break;
                }
                /*select 2mA Current*/
                WRITE_REG(GPIO_PORTF_DR2R_R,u8Mask,u8Mask);
                /*enable the Digital function*/
                WRITE_REG(GPIO_PORTF_DEN_R,u8Mask,u8Mask);
                break;

            default:
                break;
    }
}
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
void DIO_AlternateSelect (uint32_t u32PortBase , uint8_t u8PinsNum , uint8_t u32PinValue)
{
    DIO_Init(u32PortBase, u8PinsNum, NC, GPIO_ALTERNATE_DISABLE, NC, NC);
    WRITE_REG(u32PortBase , (0x0F << (u8PinsNum * 4)) , (u32PinValue << (u8PinsNum * 4)));
}
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
void DIO_WritePin (uint32_t u32PortBase , uint8_t u8Mask , uint8_t u32PinValue)
{
    switch(u32PinValue)
    {
        case HIGH:
            HW_REG(u32PortBase,u8Mask) = 0xFF;
            break;

        case LOW:
            HW_REG(u32PortBase,u8Mask) = 0x00;
            break;

        default:
            break;
    }
}
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
uint32_t DIO_ReadPin (uint32_t u32PortBase , uint8_t u8PinNum)
{
    uint32_t PinValue = 0;
    PinValue = /*(uint8_t)*/((HW_REG(u32PortBase,u8PinNum) & u8PinNum));
    return PinValue;
}
/*******************************************************************************/

