################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/vinhv/Documents/Zalo\ Received\ Files/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/lightsensor.c \
C:/Users/vinhv/Documents/Zalo\ Received\ Files/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/temhumsensor.c 

OBJS += \
./shared/Middle/sensor/lightsensor.o \
./shared/Middle/sensor/temhumsensor.o 

C_DEPS += \
./shared/Middle/sensor/lightsensor.d \
./shared/Middle/sensor/temhumsensor.d 


# Each subdirectory must supply rules for building sources it contributes
shared/Middle/sensor/lightsensor.o: C:/Users/vinhv/Documents/Zalo\ Received\ Files/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/lightsensor.c shared/Middle/sensor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/vinhv/Documents/Zalo Received Files/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Source" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
shared/Middle/sensor/temhumsensor.o: C:/Users/vinhv/Documents/Zalo\ Received\ Files/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor/temhumsensor.c shared/Middle/sensor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/vinhv/Documents/Zalo Received Files/SDK_1.0.3_NUCLEO-F401RE/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Include" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/CMSIS/Source" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Drivers/STM32F401RE_StdPeriph_Driver/src" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/button" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/buzzer" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/led" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/rtos" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/sensor" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/serial" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Middle/ucglib" -I"E:/Library_Embedded/SDK_1.0.3_NUCLEO-F401RE/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-shared-2f-Middle-2f-sensor

clean-shared-2f-Middle-2f-sensor:
	-$(RM) ./shared/Middle/sensor/lightsensor.cyclo ./shared/Middle/sensor/lightsensor.d ./shared/Middle/sensor/lightsensor.o ./shared/Middle/sensor/lightsensor.su ./shared/Middle/sensor/temhumsensor.cyclo ./shared/Middle/sensor/temhumsensor.d ./shared/Middle/sensor/temhumsensor.o ./shared/Middle/sensor/temhumsensor.su

.PHONY: clean-shared-2f-Middle-2f-sensor

