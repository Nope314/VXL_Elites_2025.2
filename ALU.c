//input: 2 số 4 bit : A: PA0-PA3, B: PA4-PA7
//Chọn phép tính : PB0-PB1(00: AND, 01: OR, 10: XOR, 11: NOT A)
//Output:5 LED:  PB10-PB14 (5 bit vì phép cộng có thể tối đa 31)
#include "stm32f10x.h"
#include <stdint.h>
#include "reg.h"

void GPIO_clock_enable()
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN ;
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN ;
}

void GPIO_Init()
{
    //Input (2 số 4 bit): A: PA0-PA3, B: PA4-PA7
    GPIOA->CRL.bits.mode0 = 0; //input //PA0
    GPIOA->CRL.bits.cnf0 = 2; //pull-up/pull-down

    GPIOA->CRL.bits.mode1 = 0; //input //PA1
    GPIOA->CRL.bits.cnf1 = 2; //pull-up/pull-down

    GPIOA->CRL.bits.mode2 = 0; //input //PA2
    GPIOA->CRL.bits.cnf2 = 2; //pull-up/pull-down

    GPIOA->CRL.bits.mode3 = 0; //input //PA3
    GPIOA->CRL.bits.cnf3 = 2; //pull-up/pull-down

    GPIOA->CRL.bits.mode4 = 0; //input //PA4
    GPIOA->CRL.bits.cnf4 = 2; //pull-up/pull-down

    GPIOA->CRL.bits.mode5 = 0; //input //PA5
    GPIOA->CRL.bits.cnf5 = 2; //pull-up/pull-down

    GPIOA->CRL.bits.mode6 = 0; //input //PA6
    GPIOA->CRL.bits.cnf6 = 2; //pull-up/pull down

    GPIOA->CRL.bits.mode7 = 0; //input //PA7
    GPIOA->CRL.bits.cnf7 = 2; //pull-up/pull-down


    GPIOA->ODR.bits.odr0 = 0; //pull-down
    GPIOA->ODR.bits.odr1 = 0; //pull-down 
    GPIOA->ODR.bits.odr2 = 0; //pull-down
    GPIOA->ODR.bits.odr3 = 0; //pull-down
    
    GPIOA->ODR.bits.odr4 = 0; //pull-down
    GPIOA->ODR.bits.odr5 = 0; //pull-down
    GPIOA->ODR.bits.odr6 = 0; //pull-down
    GPIOA->ODR.bits.odr7 = 0; //pull-down

//Input: Chọn phép tính : PB0-PB1(00: AND, 01: OR, 10: XOR, 11: NOT A)
    GPIOB->CRL.bits.mode0 = 0; //input 
    GPIOB->CRL.bits.cnf0 = 2; //pull-up/pull-down
    
    GPIOB->CRL.bits.mode1 = 0; //input 
    GPIOB->CRL.bits.cnf1 = 2; //pull-up/pull-down
    
    GPIOB->ODR.bits.odr0 = 0; //pull-down
    GPIOB->ODR.bits.odr1 = 0; //pull-down

//Output
    GPIOB->CRH.bits.mode10 = 1; //output 10MHz
    GPIOB->CRH.bits.cnf10 = 0; //push-pull

    GPIOB->CRH.bits.mode11 = 1; //output 10MHz
    GPIOB->CRH.bits.cnf11 = 0; //push-pull

    GPIOB->CRH.bits.mode12 = 1; //output 10MHz
    GPIOB->CRH.bits.cnf12 = 0; //push-pull

    GPIOB->CRH.bits.mode13 = 1; //output 10MHz
    GPIOB->CRH.bits.cnf13 = 0; //push-pull

    GPIOB->CRH.bits.mode14 = 1; //output 10MHz
    GPIOB->CRH.bits.cnf14 = 0; //push-pull
}

uint8_t Read_InputA()
{
    return (GPIOA->IDR & 0x0F); //đọc 4 bit thấp của GPIOA
}

uint8_t Read_InputB()
{
    return (GPIOA->IDR & 0xF0) >> 4; //đọc 4 bit cao của GPIOA
}

uint8_t Read_Operation()
{
    return (GPIOB->IDR & 0x03); //đọc 2 bit thấp của GPIOB
}

uint8_t ALU_Compute(uint8_t A, uint8_t B, uint8_t operation)
{
    switch(operation)
    {
        case 0: //AND
            return A & B;
        case 1: //OR
            return A | B;
        case 2: //XOR
            return A ^ B;
        case 3: //NOT A
            return ~A & 0x0F; //chỉ lấy 4 bit thấp của kết quả NOT
        default:
            return 0; //trường hợp không hợp lệ
    }
}

void LED_Output(uint8_t result)
{
    GPIOB->BRR=(0x1F << 10); //tắt tất cả LED trước khi hiển thị kết quả
    GPIOB->BSRR=((result & 0x1F) << 10); //hiển thị kết quả lên
}

int main()
{
    GPIO_clock_enable();
    GPIO_Init();

    while(1)
    {
        uint8_t A = Read_InputA();
        uint8_t B = Read_InputB();
        uint8_t operation = Read_Operation();
        uint8_t result = ALU_Compute(A, B, operation);
        LED_Output(result);
    }
}