################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c 

OBJS += \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.o \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.o \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.o \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.o \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.o \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.o \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.o \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.o \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.o \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.o \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.o \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.o \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.o \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.o 

C_DEPS += \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.d \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.d \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.d \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.d \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.d \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.d \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.d \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.d \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.d \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.d \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.d \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.d \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.d \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.d \
./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/%.o Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/%.su: ../Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/%.c Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src

clean-Core-2f-Inc-2f-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src:
	-$(RM) ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.su ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.su ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.su ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.su ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.su ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.su ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.su ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.su ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.su ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.su ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.su ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.su ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.su ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.su ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.d ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.o ./Core/Inc/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.su

.PHONY: clean-Core-2f-Inc-2f-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src

