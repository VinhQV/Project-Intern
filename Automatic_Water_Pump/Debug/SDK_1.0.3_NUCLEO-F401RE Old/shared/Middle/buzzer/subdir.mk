################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/buzzer.c 

OBJS += \
./SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/buzzer/buzzer.o 

C_DEPS += \
./SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/buzzer/buzzer.d 


# Each subdirectory must supply rules for building sources it contributes
SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/buzzer/buzzer.o: E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer/buzzer.c SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/buzzer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"SDK_1.0.3_NUCLEO-F401RE Old/shared/Middle/buzzer/buzzer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-20-Old-2f-shared-2f-Middle-2f-buzzer

clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-20-Old-2f-shared-2f-Middle-2f-buzzer:
	-$(RM) ./SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/buzzer/buzzer.cyclo ./SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/buzzer/buzzer.d ./SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/buzzer/buzzer.o ./SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/buzzer/buzzer.su

.PHONY: clean-SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-20-Old-2f-shared-2f-Middle-2f-buzzer

