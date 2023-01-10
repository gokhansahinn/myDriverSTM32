################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../myDriver/Src/EXTI.c \
../myDriver/Src/GPIO.c \
../myDriver/Src/RCC.c \
../myDriver/Src/SPI.c 

OBJS += \
./myDriver/Src/EXTI.o \
./myDriver/Src/GPIO.o \
./myDriver/Src/RCC.o \
./myDriver/Src/SPI.o 

C_DEPS += \
./myDriver/Src/EXTI.d \
./myDriver/Src/GPIO.d \
./myDriver/Src/RCC.d \
./myDriver/Src/SPI.d 


# Each subdirectory must supply rules for building sources it contributes
myDriver/Src/%.o myDriver/Src/%.su: ../myDriver/Src/%.c myDriver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"C:/Users/gokhan.sahin/STM32CubeIDE/workspace_1.9.0/driverDevolopment/myDriver/Inc" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-myDriver-2f-Src

clean-myDriver-2f-Src:
	-$(RM) ./myDriver/Src/EXTI.d ./myDriver/Src/EXTI.o ./myDriver/Src/EXTI.su ./myDriver/Src/GPIO.d ./myDriver/Src/GPIO.o ./myDriver/Src/GPIO.su ./myDriver/Src/RCC.d ./myDriver/Src/RCC.o ./myDriver/Src/RCC.su ./myDriver/Src/SPI.d ./myDriver/Src/SPI.o ./myDriver/Src/SPI.su

.PHONY: clean-myDriver-2f-Src

