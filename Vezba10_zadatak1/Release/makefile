################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
Vezba10_zadatak1.lss \

FLASH_IMAGE += \
Vezba10_zadatak1.hex \

EEPROM_IMAGE += \
Vezba10_zadatak1.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Vezba10_zadatak1.elf secondary-outputs

# Tool invocations
Vezba10_zadatak1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Vezba10_zadatak1.map -L"C:\milos\letnji semstar\Razvoj softvera za digitalne mikrokontrolere\git repository\RSZDMK\pin_driver\Release" -L"C:\milos\letnji semstar\Razvoj softvera za digitalne mikrokontrolere\git repository\RSZDMK\timer0\Release" -L"C:\milos\letnji semstar\Razvoj softvera za digitalne mikrokontrolere\git repository\RSZDMK\usart\Release" -mmcu=atmega328p -o "Vezba10_zadatak1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Vezba10_zadatak1.lss: Vezba10_zadatak1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Vezba10_zadatak1.elf  >"Vezba10_zadatak1.lss"
	@echo 'Finished building: $@'
	@echo ' '

Vezba10_zadatak1.hex: Vezba10_zadatak1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Vezba10_zadatak1.elf  "Vezba10_zadatak1.hex"
	@echo 'Finished building: $@'
	@echo ' '

Vezba10_zadatak1.eep: Vezba10_zadatak1.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Vezba10_zadatak1.elf  "Vezba10_zadatak1.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Vezba10_zadatak1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p Vezba10_zadatak1.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Vezba10_zadatak1.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm328p -carduino -PCOM3 -Uflash:w:Vezba10_zadatak1.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Vezba10_zadatak1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
