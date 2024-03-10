################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/BUZZER_Program.c \
../Src/DIO_Program.c \
../Src/LCD_Program.c \
../Src/LED_Program.c \
../Src/RELAY_Program.c \
../Src/TIMERS_Program.c \
../Src/UART_Prgoram.c \
../Src/app.c \
../Src/main.c 

OBJS += \
./Src/BUZZER_Program.o \
./Src/DIO_Program.o \
./Src/LCD_Program.o \
./Src/LED_Program.o \
./Src/RELAY_Program.o \
./Src/TIMERS_Program.o \
./Src/UART_Prgoram.o \
./Src/app.o \
./Src/main.o 

C_DEPS += \
./Src/BUZZER_Program.d \
./Src/DIO_Program.d \
./Src/LCD_Program.d \
./Src/LED_Program.d \
./Src/RELAY_Program.d \
./Src/TIMERS_Program.d \
./Src/UART_Prgoram.d \
./Src/app.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


