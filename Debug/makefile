################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/FINGER\ PRINT/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
FinPrint.lss \

FLASH_IMAGE += \
FinPrint.hex \

EEPROM_IMAGE += \
FinPrint.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: FinPrint.elf secondary-outputs

# Tool invocations
FinPrint.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,FinPrint.map -mmcu=atmega32 -o "FinPrint.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

FinPrint.lss: FinPrint.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S FinPrint.elf  >"FinPrint.lss"
	@echo 'Finished building: $@'
	@echo ' '

FinPrint.hex: FinPrint.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex FinPrint.elf  "FinPrint.hex"
	@echo 'Finished building: $@'
	@echo ' '

FinPrint.eep: FinPrint.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex FinPrint.elf  "FinPrint.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: FinPrint.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 FinPrint.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) FinPrint.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
