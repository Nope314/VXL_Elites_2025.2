#include <stdint.h>
#include "reg.h"

//câu 4 : Lập trình đọc(dạng polling) trạng thái nút bấm trên blue pill và điều khiển đèn LED tương ứng. Cụ thể, khi nút bấm được nhấn thì đèn LED sẽ sáng, khi nút bấm được thả ra thì đèn LED sẽ tắt. Sử dụng các thanh ghi đã định nghĩa ở trên để thực hiện việc này.
void GPIO_clock_enable()
{
    // Cấu hình thanh ghi RCC_APB2ENR để cấp xung cho GPIOA
    volatile uint32_t *RCC_APB2ENR = (volatile uint32_t *)0x40021018; // Địa chỉ của thanh ghi RCC_APB2ENR, thanh ghi RCC_APB2ENR là thanh ghi dùng để cấp xung cho các thiết bị ngoại vi trên bus APB2, trong đó có GPIOA
    *RCC_APB2ENR |= (1 << 2); 
    *RCC_APB2ENR |= (1 << 3); 
}

void GPIO_Init()
{
    //PA0: intput pull-up, PB13: output push-pull
    GPIOA->CRL.bits.mode0 = 0; //input 
    GPIOA->CRL.bits.cnf0 = 2; //pull-up/pull-down
    
    GPIOA->ODR.bits.odr0 = 1; //pull-up 

    GPIOB->CRH.bits.mode13 = 1; //output 10MHz
    GPIOB->CRH.bits.cnf13 = 0; //push-pull
}

void delay_ms(uint32_t ms)
{
    uint32_t i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 1000; j++);
}


uint8_t Button_Read()
{
    if(GPIOA->IDR.bits.idr0 == 0)
    {
        delay_ms(20); // debounce

        if(GPIOA->IDR.bits.idr0 == 0)
        {
            while(GPIOA->IDR.bits.idr0 == 0); // đợi nhả nút
            return 1;
        }
    }
    return 0;
}
int main()
{
    GPIO_clock_enable();
    GPIO_Init();

    static uint8_t led_state = 0;

    while (1)
    {
        if(Button_Read())
        {
            led_state = !led_state; // đảo trạng thái
        }

        if(led_state)
        {
            GPIOB->BSRR.bits.bs13 = 1;
        }
        else
        {
            GPIOB->BRR.bits.br13 = 1;
        }
    }
}
