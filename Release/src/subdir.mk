################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ARDroneDemo1.c 

OBJS += \
./src/ARDroneDemo1.o 

C_DEPS += \
./src/ARDroneDemo1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -I/usr/include/libxml2 -I"/home/marioc/Projects/ARDrone_SDK_2_0_1/ARDroneLib/Soft/Common" -I"/home/marioc/Projects/ARDrone_SDK_2_0_1/ARDroneLib/Soft/Lib" -I"/home/marioc/Projects/ARDrone_SDK_2_0_1/ARDroneLib/VP_SDK" -I"/home/marioc/Projects/ARDrone_SDK_2_0_1/ARDroneLib/VP_SDK/VP_Os/linux" -I"/home/marioc/Projects/ARDrone_SDK_2_0_1/ARDroneLib" -O3 -Wall -c -fmessage-length=0 `pkg-config --cflags glib-2.0` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


