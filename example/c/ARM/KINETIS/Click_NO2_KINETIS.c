/*
Example for NO2 Click

    Date          : jul 2018.
    Author        : Katarina Perendic

Test configuration KINETIS :
    
    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C bus and set AN pin as INPUT and RST pin as OUTPUT.
- Application Initialization - Initializes I2C driver and device configuration.
- Application Task - (code snippet) - Gets NO2 (Nitrogen dioxide) data as ppm value and logs to USBUART every 500ms.

*/

#include "Click_NO2_types.h"
#include "Click_NO2_config.h"

float NO2_Value;
char demoText[ 50 ];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_i2cInit( _MIKROBUS1, &_NO2_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART, 115200 );
    mikrobus_logWrite( "--- System init ---", _LOG_LINE );
    Delay_ms( 100 );
}

void applicationInit()
{
    no2_i2cDriverInit( (T_NO2_P)&_MIKROBUS1_GPIO, (T_NO2_P)&_MIKROBUS1_I2C, 0x48 );
    Delay_ms( 200 );

    no2_writeByte( _NO2_MODECN_REG, _NO2_DEEP_SLEEP_MODE );
    no2_writeByte( _NO2_LOCK_REG,   _NO2_WRITE_MODE );
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