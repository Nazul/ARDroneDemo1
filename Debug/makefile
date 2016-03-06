################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/UI/subdir.mk
-include src/Navdata/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ARDroneDemo1

# Tool invocations
ARDroneDemo1: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -L/home/marioc/Projects/ARDroneDemo1/lib -pthread -o "ARDroneDemo1" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) ARDroneDemo1
	-@echo ' '

post-build:
	-@echo 'Update Gamepad mapping file'
	-cp -n /home/marioc/Projects/ARDroneDemo1/src/XML_Files/ardrone_default.xml /home/marioc/Projects/ARDroneDemo1/Debug/ardrone.xml
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
