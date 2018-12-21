#line 1 "D:/Clicks_git/NO2_Click/SW/example/c/ARM/STM/Click_NO2_STM.c"
#line 1 "d:/clicks_git/no2_click/sw/example/c/arm/stm/click_no2_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/no2_click/sw/example/c/arm/stm/click_no2_config.h"
#line 1 "d:/clicks_git/no2_click/sw/example/c/arm/stm/click_no2_types.h"
#line 19 "d:/clicks_git/no2_click/sw/example/c/arm/stm/click_no2_config.h"
const uint32_t _NO2_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "d:/clicks_git/no2_click/sw/library/__no2_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 57 "d:/clicks_git/no2_click/sw/library/__no2_driver.h"
extern const uint8_t _NO2_STATUS_REG ;
extern const uint8_t _NO2_LOCK_REG ;
extern const uint8_t _NO2_TIACN_REG ;
extern const uint8_t _NO2_REFCN_REG ;
extern const uint8_t _NO2_MODECN_REG ;

extern const uint8_t _NO2_WRITE_MODE ;
extern const uint8_t _NO2_READ_ONLY_MODE;

extern const uint8_t _NO2_EXT_TIA_RES ;
extern const uint8_t _NO2_2750_OHM_TIA_RES ;
extern const uint8_t _NO2_3500_OHM_TIA_RES ;
extern const uint8_t _NO2_7K_OHM_TIA_RES ;
extern const uint8_t _NO2_14K_OHM_TIA_RES ;
extern const uint8_t _NO2_35K_OHM_TIA_RES ;
extern const uint8_t _NO2_120K_OHM_TIA_RES ;
extern const uint8_t _NO2_350K_OHM_TIA_RES ;
extern const uint8_t _NO2_10_OHM_LOAD_RES ;
extern const uint8_t _NO2_33_OHM_LOAD_RES ;
extern const uint8_t _NO2_50_OHM_LOAD_RES ;
extern const uint8_t _NO2_100_OHM_LOAD_RES ;

extern const uint8_t _NO2_VREF_INT ;
extern const uint8_t _NO2_VREF_EXT ;
extern const uint8_t _NO2_20_PERCENTS_INT_ZERO ;
extern const uint8_t _NO2_50_PERCENTS_INT_ZERO ;
extern const uint8_t _NO2_67_PERCENTS_INT_ZERO ;
extern const uint8_t _NO2_INT_ZERO_BYPASSED ;
extern const uint8_t _NO2_BIAS_POL_NEGATIVE ;
extern const uint8_t _NO2_BIAS_POL_POSITIVE ;
extern const uint8_t _NO2_0_PERCENTS_BIAS ;
extern const uint8_t _NO2_1_PERCENT_BIAS ;
extern const uint8_t _NO2_2_PERCENTS_BIAS ;
extern const uint8_t _NO2_4_PERCENTS_BIAS ;
extern const uint8_t _NO2_6_PERCENTS_BIAS ;
extern const uint8_t _NO2_8_PERCENTS_BIAS ;
extern const uint8_t _NO2_10_PERCENTS_BIAS ;
extern const uint8_t _NO2_12_PERCENTS_BIAS ;
extern const uint8_t _NO2_14_PERCENTS_BIAS ;
extern const uint8_t _NO2_16_PERCENTS_BIAS ;
extern const uint8_t _NO2_18_PERCENTS_BIAS ;
extern const uint8_t _NO2_20_PERCENTS_BIAS ;
extern const uint8_t _NO2_22_PERCENTS_BIAS ;
extern const uint8_t _NO2_24_PERCENTS_BIAS ;

extern const uint8_t _NO2_FET_DIS ;
extern const uint8_t _NO2_FET_EN ;
extern const uint8_t _NO2_DEEP_SLEEP_MODE ;
extern const uint8_t _NO2_2_LEAD_MODE ;
extern const uint8_t _NO2_STANDBY_MODE ;
extern const uint8_t _NO2_3_LEAD_MODE ;
extern const uint8_t _NO2_TEMP_MODE_TIA_OFF ;
extern const uint8_t _NO2_TEMP_MODE_TIA_ON ;

extern const uint8_t _NO2_DEVICE_EN ;
extern const uint8_t _NO2_DEVICE_DIS ;

extern const uint8_t ADC_DEVICE_ADDR ;
#line 127 "d:/clicks_git/no2_click/sw/library/__no2_driver.h"
void no2_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 134 "d:/clicks_git/no2_click/sw/library/__no2_driver.h"
void no2_gpioDriverInit( const uint8_t*  gpioObj);
#line 145 "d:/clicks_git/no2_click/sw/library/__no2_driver.h"
void no2_writeByte( uint8_t reg, uint8_t _data );
#line 154 "d:/clicks_git/no2_click/sw/library/__no2_driver.h"
uint8_t no2_readByte( uint8_t reg );
#line 159 "d:/clicks_git/no2_click/sw/library/__no2_driver.h"
void no2_waitReady( void );
#line 164 "d:/clicks_git/no2_click/sw/library/__no2_driver.h"
void no2_enable( uint8_t state );
#line 171 "d:/clicks_git/no2_click/sw/library/__no2_driver.h"
uint16_t no2_readADC();
#line 178 "d:/clicks_git/no2_click/sw/library/__no2_driver.h"
float no2_getNO2ppm();
#line 29 "D:/Clicks_git/NO2_Click/SW/example/c/ARM/STM/Click_NO2_STM.c"
float NO2_Value;
char demoText[ 50 ];

void systemInit()
{
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
 mikrobus_i2cInit( _MIKROBUS1, &_NO2_I2C_CFG[0] );
 mikrobus_logInit( _LOG_USBUART_A, 115200 );
 mikrobus_logWrite( "--- System init ---", _LOG_LINE );
 Delay_ms( 100 );
}

void applicationInit()
{
 no2_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, 0x48 );
 Delay_ms( 200 );

 no2_writeByte( _NO2_MODECN_REG, _NO2_DEEP_SLEEP_MODE );
 no2_writeByte( _NO2_LOCK_REG, _NO2_WRITE_MODE );
 no2_writeByte( _NO2_TIACN_REG, _NO2_EXT_TIA_RES | _NO2_100_OHM_LOAD_RES );
 no2_writeByte( _NO2_REFCN_REG, _NO2_VREF_INT | _NO2_50_PERCENTS_INT_ZERO | _NO2_BIAS_POL_NEGATIVE | _NO2_0_PERCENTS_BIAS );
 mikrobus_logWrite( "NO2 is initialized", _LOG_LINE );
 Delay_ms( 300 );
}

void applicationTask()
{
 NO2_Value = no2_getNO2ppm();
 FloatToStr( NO2_Value, demoText );
 mikrobus_logWrite( "NO2 value : ", _LOG_TEXT );
 mikrobus_logWrite( demoText, _LOG_TEXT );
 mikrobus_logWrite( " ppm", _LOG_LINE );
 Delay_ms( 500 );
}

void main()
{
 systemInit();
 applicationInit();

 while (1)
 {
 applicationTask();
 }
}
