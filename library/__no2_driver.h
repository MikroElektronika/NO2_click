/*
    __no2_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __no2_driver.h
@brief    NO2 Driver
@mainpage NO2 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   NO2
@brief      NO2 Click Driver
@{

| Global Library Prefix | **NO2** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **jul 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _NO2_H_
#define _NO2_H_

/** 
 * @macro T_NO2_P
 * @brief Driver Abstract type 
 */
#define T_NO2_P    const uint8_t*

/** @defgroup NO2_COMPILE Compilation Config */              /** @{ */

//  #define   __NO2_DRV_SPI__                            /**<     @macro __NO2_DRV_SPI__  @brief SPI driver selector */
   #define   __NO2_DRV_I2C__                            /**<     @macro __NO2_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __NO2_DRV_UART__                           /**<     @macro __NO2_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup NO2_VAR Variables */                           /** @{ */

extern const uint8_t _NO2_STATUS_REG ;
extern const uint8_t _NO2_LOCK_REG   ;
extern const uint8_t _NO2_TIACN_REG  ;
extern const uint8_t _NO2_REFCN_REG  ;
extern const uint8_t _NO2_MODECN_REG ;
              
extern const uint8_t _NO2_WRITE_MODE    ;
extern const uint8_t _NO2_READ_ONLY_MODE;
               
extern const uint8_t _NO2_EXT_TIA_RES      ;
extern const uint8_t _NO2_2750_OHM_TIA_RES ;
extern const uint8_t _NO2_3500_OHM_TIA_RES ;
extern const uint8_t _NO2_7K_OHM_TIA_RES   ;
extern const uint8_t _NO2_14K_OHM_TIA_RES  ;
extern const uint8_t _NO2_35K_OHM_TIA_RES  ;
extern const uint8_t _NO2_120K_OHM_TIA_RES ;
extern const uint8_t _NO2_350K_OHM_TIA_RES ;
extern const uint8_t _NO2_10_OHM_LOAD_RES  ;
extern const uint8_t _NO2_33_OHM_LOAD_RES  ;
extern const uint8_t _NO2_50_OHM_LOAD_RES  ;
extern const uint8_t _NO2_100_OHM_LOAD_RES ;
               
extern const uint8_t _NO2_VREF_INT             ;
extern const uint8_t _NO2_VREF_EXT             ;
extern const uint8_t _NO2_20_PERCENTS_INT_ZERO ;
extern const uint8_t _NO2_50_PERCENTS_INT_ZERO ;
extern const uint8_t _NO2_67_PERCENTS_INT_ZERO ;
extern const uint8_t _NO2_INT_ZERO_BYPASSED    ;
extern const uint8_t _NO2_BIAS_POL_NEGATIVE    ;
extern const uint8_t _NO2_BIAS_POL_POSITIVE    ;
extern const uint8_t _NO2_0_PERCENTS_BIAS      ;
extern const uint8_t _NO2_1_PERCENT_BIAS       ;
extern const uint8_t _NO2_2_PERCENTS_BIAS      ;
extern const uint8_t _NO2_4_PERCENTS_BIAS      ;
extern const uint8_t _NO2_6_PERCENTS_BIAS      ;
extern const uint8_t _NO2_8_PERCENTS_BIAS      ;
extern const uint8_t _NO2_10_PERCENTS_BIAS     ;
extern const uint8_t _NO2_12_PERCENTS_BIAS     ;
extern const uint8_t _NO2_14_PERCENTS_BIAS     ;
extern const uint8_t _NO2_16_PERCENTS_BIAS     ;
extern const uint8_t _NO2_18_PERCENTS_BIAS     ;
extern const uint8_t _NO2_20_PERCENTS_BIAS     ;
extern const uint8_t _NO2_22_PERCENTS_BIAS     ;
extern const uint8_t _NO2_24_PERCENTS_BIAS     ;
              
extern const uint8_t _NO2_FET_DIS           ;
extern const uint8_t _NO2_FET_EN            ;
extern const uint8_t _NO2_DEEP_SLEEP_MODE   ;
extern const uint8_t _NO2_2_LEAD_MODE       ;
extern const uint8_t _NO2_STANDBY_MODE      ;
extern const uint8_t _NO2_3_LEAD_MODE       ;
extern const uint8_t _NO2_TEMP_MODE_TIA_OFF ;
extern const uint8_t _NO2_TEMP_MODE_TIA_ON  ;
              
extern const uint8_t _NO2_DEVICE_EN         ;
extern const uint8_t _NO2_DEVICE_DIS        ;

extern const uint8_t ADC_DEVICE_ADDR        ;

                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup NO2_INIT Driver Initialization */              /** @{ */

#ifdef   __NO2_DRV_SPI__
void no2_spiDriverInit(T_NO2_P gpioObj, T_NO2_P spiObj);
#endif
#ifdef   __NO2_DRV_I2C__
void no2_i2cDriverInit(T_NO2_P gpioObj, T_NO2_P i2cObj, uint8_t slave);
#endif
#ifdef   __NO2_DRV_UART__
void no2_uartDriverInit(T_NO2_P gpioObj, T_NO2_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void no2_gpioDriverInit(T_NO2_P gpioObj);
                                                                       /** @} */
/** @defgroup NO2_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Function writes one byte to the register.
 *
 * @param[in] reg       Address where data be written
 * @param[in] _data     Data to be written
 */
void no2_writeByte( uint8_t reg, uint8_t _data );

/**
 * @brief Function reads one byte from the register.
 *
 * @param[in] reg              Address which from data be read
 *
 * @retval data that is read from the registry
 */
uint8_t no2_readByte( uint8_t reg );

/**
 * @brief Function waits until I2C is ready for the next command.
 */
void no2_waitReady( void );

/**
 * @brief Device Enable function
 */
void no2_enable( uint8_t state );

/**
 * @brief Function for read ADC sensor data
 *
 * @retval 12bit ADC value   
 */
uint16_t no2_readADC();

/**
 * @brief Get NO2 Data function
 *
 * @retval NO2 data in ppm.
 */
float no2_getNO2ppm();




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_NO2_STM.c
    @example Click_NO2_TIVA.c
    @example Click_NO2_CEC.c
    @example Click_NO2_KINETIS.c
    @example Click_NO2_MSP.c
    @example Click_NO2_PIC.c
    @example Click_NO2_PIC32.c
    @example Click_NO2_DSPIC.c
    @example Click_NO2_AVR.c
    @example Click_NO2_FT90x.c
    @example Click_NO2_STM.mbas
    @example Click_NO2_TIVA.mbas
    @example Click_NO2_CEC.mbas
    @example Click_NO2_KINETIS.mbas
    @example Click_NO2_MSP.mbas
    @example Click_NO2_PIC.mbas
    @example Click_NO2_PIC32.mbas
    @example Click_NO2_DSPIC.mbas
    @example Click_NO2_AVR.mbas
    @example Click_NO2_FT90x.mbas
    @example Click_NO2_STM.mpas
    @example Click_NO2_TIVA.mpas
    @example Click_NO2_CEC.mpas
    @example Click_NO2_KINETIS.mpas
    @example Click_NO2_MSP.mpas
    @example Click_NO2_PIC.mpas
    @example Click_NO2_PIC32.mpas
    @example Click_NO2_DSPIC.mpas
    @example Click_NO2_AVR.mpas
    @example Click_NO2_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __no2_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */