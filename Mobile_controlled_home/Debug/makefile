################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Src/subdir.mk
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
Mobile_controlled_home.lss \

FLASH_IMAGE += \
Mobile_controlled_home.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Mobile_controlled_home.elf secondary-outputs

# Tool invocations
Mobile_controlled_home.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Mobile_controlled_home.map -mmcu=atmega32 -o "Mobile_controlled_home.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Mobile_controlled_home.lss: Mobile_controlled_home.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Mobile_controlled_home.elf  >"Mobile_controlled_home.lss"
	@echo 'Finished building: $@'
	@echo ' '

Mobile_controlled_home.hex: Mobile_controlled_home.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Mobile_controlled_home.elf  "Mobile_controlled_home.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Mobile_controlled_home.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Mobile_controlled_home.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Mobile_controlled_home.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
