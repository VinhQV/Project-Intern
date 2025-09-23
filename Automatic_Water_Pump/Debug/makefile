################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Utilities/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/ucglib/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/serial/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/sensor/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/rtos/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/led/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/buzzer/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Middle/button/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/subdir.mk
-include SDK_1.0.3_NUCLEO-F401RE\ Old/shared/Drivers/CMSIS/Source/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Automatic_Water_Pump
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Automatic_Water_Pump.elf \

MAP_FILES += \
Automatic_Water_Pump.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Automatic_Water_Pump.list \


# All Target
all: main-build

# Main-build Target
main-build: Automatic_Water_Pump.elf secondary-outputs

# Tool invocations
Automatic_Water_Pump.elf Automatic_Water_Pump.map: $(OBJS) $(USER_OBJS) E:\Embedded-C\My_workspace\IoT_303x\Automatic_Water_Pump\STM32F401RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Automatic_Water_Pump.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"E:\Embedded-C\My_workspace\IoT_303x\Automatic_Water_Pump\STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Automatic_Water_Pump.map" -Wl,--gc-sections -static -L"E:\Library_Embedded\SDK_1.0.3_NUCLEO-F401RE\lib_stm" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Automatic_Water_Pump.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Automatic_Water_Pump.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Automatic_Water_Pump.elf Automatic_Water_Pump.list Automatic_Water_Pump.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
