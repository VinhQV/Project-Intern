################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/vinhv/Documents/Zalo\ Received\ Files/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Source/system_stm32f4xx.c 

OBJS += \
./shared/Drivers/CMSIS/Source/system_stm32f4xx.o 

C_DEPS += \
./shared/Drivers/CMSIS/Source/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
shared/Drivers/CMSIS/Source/system_stm32f4xx.o: C:/Users/vinhv/Documents/Zalo\ Received\ Files/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Source/system_stm32f4xx.c shared/Drivers/CMSIS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/vinhv/Documents/Zalo Received Files/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Source" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-shared-2f-Drivers-2f-CMSIS-2f-Source

clean-shared-2f-Drivers-2f-CMSIS-2f-Source:
	-$(RM) ./shared/Drivers/CMSIS/Source/system_stm32f4xx.cyclo ./shared/Drivers/CMSIS/Source/system_stm32f4xx.d ./shared/Drivers/CMSIS/Source/system_stm32f4xx.o ./shared/Drivers/CMSIS/Source/system_stm32f4xx.su

.PHONY: clean-shared-2f-Drivers-2f-CMSIS-2f-Source

