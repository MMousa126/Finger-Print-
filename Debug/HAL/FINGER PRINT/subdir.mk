################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/FINGER\ PRINT/FIGER_PRINT_Programe.c 

OBJS += \
./HAL/FINGER\ PRINT/FIGER_PRINT_Programe.o 

C_DEPS += \
./HAL/FINGER\ PRINT/FIGER_PRINT_Programe.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/FINGER\ PRINT/FIGER_PRINT_Programe.o: ../HAL/FINGER\ PRINT/FIGER_PRINT_Programe.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"HAL/FINGER PRINT/FIGER_PRINT_Programe.d" -MT"HAL/FINGER\ PRINT/FIGER_PRINT_Programe.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


