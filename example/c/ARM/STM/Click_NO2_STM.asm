_systemInit:
;Click_NO2_STM.c,32 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_NO2_STM.c,34 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #0
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_NO2_STM.c,35 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_NO2_STM.c,36 :: 		mikrobus_i2cInit( _MIKROBUS1, &_NO2_I2C_CFG[0] );
MOVW	R0, #lo_addr(__NO2_I2C_CFG+0)
MOVT	R0, #hi_addr(__NO2_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_NO2_STM.c,37 :: 		mikrobus_logInit( _LOG_USBUART_A, 115200 );
MOV	R1, #115200
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_NO2_STM.c,38 :: 		mikrobus_logWrite( "--- System init ---", _LOG_LINE );
MOVW	R0, #lo_addr(?lstr1_Click_NO2_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_NO2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_NO2_STM.c,39 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_NO2_STM.c,40 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_NO2_STM.c,42 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_NO2_STM.c,44 :: 		no2_i2cDriverInit( (T_NO2_P)&_MIKROBUS1_GPIO, (T_NO2_P)&_MIKROBUS1_I2C, 0x48 );
MOVS	R2, #72
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_no2_i2cDriverInit+0
;Click_NO2_STM.c,45 :: 		Delay_ms( 200 );
MOVW	R7, #40703
MOVT	R7, #36
NOP
NOP
L_applicationInit2:
SUBS	R7, R7, #1
BNE	L_applicationInit2
NOP
NOP
NOP
;Click_NO2_STM.c,47 :: 		no2_writeByte( _NO2_MODECN_REG, _NO2_DEEP_SLEEP_MODE );
MOVS	R1, __NO2_DEEP_SLEEP_MODE
MOVS	R0, __NO2_MODECN_REG
BL	_no2_writeByte+0
;Click_NO2_STM.c,48 :: 		no2_writeByte( _NO2_LOCK_REG,   _NO2_WRITE_MODE );
MOVS	R1, __NO2_WRITE_MODE
MOVS	R0, __NO2_LOCK_REG
BL	_no2_writeByte+0
;Click_NO2_STM.c,49 :: 		no2_writeByte( _NO2_TIACN_REG, _NO2_EXT_TIA_RES | _NO2_100_OHM_LOAD_RES );
MOVS	R0, __NO2_EXT_TIA_RES
ORR	R0, R0, __NO2_100_OHM_LOAD_RES
UXTB	R1, R0
MOVS	R0, __NO2_TIACN_REG
BL	_no2_writeByte+0
;Click_NO2_STM.c,50 :: 		no2_writeByte( _NO2_REFCN_REG, _NO2_VREF_INT | _NO2_50_PERCENTS_INT_ZERO | _NO2_BIAS_POL_NEGATIVE | _NO2_0_PERCENTS_BIAS );
MOVS	R0, __NO2_VREF_INT
ORR	R0, R0, __NO2_50_PERCENTS_INT_ZERO
UXTB	R0, R0
ORR	R0, R0, __NO2_BIAS_POL_NEGATIVE
UXTB	R0, R0
ORR	R0, R0, __NO2_0_PERCENTS_BIAS
UXTB	R1, R0
MOVS	R0, __NO2_REFCN_REG
BL	_no2_writeByte+0
;Click_NO2_STM.c,51 :: 		mikrobus_logWrite( "NO2 is initialized", _LOG_LINE );
MOVW	R0, #lo_addr(?lstr2_Click_NO2_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_NO2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_NO2_STM.c,52 :: 		Delay_ms( 300 );
MOVW	R7, #61055
MOVT	R7, #54
NOP
NOP
L_applicationInit4:
SUBS	R7, R7, #1
BNE	L_applicationInit4
NOP
NOP
NOP
;Click_NO2_STM.c,53 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_NO2_STM.c,55 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_NO2_STM.c,57 :: 		NO2_Value = no2_getNO2ppm();
BL	_no2_getNO2ppm+0
MOVW	R1, #lo_addr(_NO2_Value+0)
MOVT	R1, #hi_addr(_NO2_Value+0)
STR	R0, [R1, #0]
;Click_NO2_STM.c,58 :: 		FloatToStr( NO2_Value, demoText );
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_NO2_STM.c,59 :: 		mikrobus_logWrite( "NO2 value : ", _LOG_TEXT );
MOVW	R0, #lo_addr(?lstr3_Click_NO2_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_NO2_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_NO2_STM.c,60 :: 		mikrobus_logWrite( demoText, _LOG_TEXT );
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_NO2_STM.c,61 :: 		mikrobus_logWrite( " ppm", _LOG_LINE );
MOVW	R0, #lo_addr(?lstr4_Click_NO2_STM+0)
MOVT	R0, #hi_addr(?lstr4_Click_NO2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_NO2_STM.c,62 :: 		Delay_ms( 500 );
MOVW	R7, #36223
MOVT	R7, #91
NOP
NOP
L_applicationTask6:
SUBS	R7, R7, #1
BNE	L_applicationTask6
NOP
NOP
NOP
;Click_NO2_STM.c,63 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_NO2_STM.c,65 :: 		void main()
;Click_NO2_STM.c,67 :: 		systemInit();
BL	_systemInit+0
;Click_NO2_STM.c,68 :: 		applicationInit();
BL	_applicationInit+0
;Click_NO2_STM.c,70 :: 		while (1)
L_main8:
;Click_NO2_STM.c,72 :: 		applicationTask();
BL	_applicationTask+0
;Click_NO2_STM.c,73 :: 		}
IT	AL
BAL	L_main8
;Click_NO2_STM.c,74 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
