![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# NO2 Click

- **CIC Prefix**  : NO2
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : jul 2018.

---

### Software Support

We provide a library for the NO2 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2484/no2-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus driver and drivers that offer a choice for writing data in register.
The library includes function for read NO2 data in ppm and function for read ADC data.

Key functions :

- ``` float no2_getNO2ppm() ``` - Function for read NO2 Data in ppm
- ``` uint16_t no2_readADC() ``` - Function for read ADC sensor data
- ``` void no2_writeByte( uint8_t reg, uint8_t _data ) ``` - Function writes one byte to the register.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C bus and set AN pin as INPUT and RST pin as OUTPUT.
- Application Initialization - Initializes I2C driver and device configuration.
- Application Task - (code snippet) - Gets NO2 (Nitrogen dioxide) data as ppm value and logs to USBUART every 500ms.


```.c
void applicationTask()
{
    NO2_Value = no2_getNO2ppm();
    FloatToStr( NO2_Value, demoText );
    mikrobus_logWrite( "NO2 value : ", _LOG_TEXT );
    mikrobus_logWrite( demoText, _LOG_TEXT );
    mikrobus_logWrite( " ppm", _LOG_LINE );
    Delay_ms( 500 );
}
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2484/no2-click) page.

Other mikroE Libraries used in the example:

- I2C
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
