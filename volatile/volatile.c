#include <stdint.h>

volatile int flag = 0;
volatile int v; 
int n;

void test(void)
{
    // 1. polling loop 
    while (flag == 0); // Vòng lặp chờ cho đến khi flag được đặt thành 1 bởi một tác vụ khác (ví dụ: trong main)

    // 2. đọc nhiều lần volatile
    if (flag == 1) // Đọc biến volatile nhiều lần để kiểm tra xem trình biên dịch có tối ưu hóa hay không
        v++;

    if (flag == 1) 
        v++;

    // 3. đọc nhiều lần biến thường để thấy sự khác biệt với volatile
    if (n == 0) 
        n++;

    if (n == 0) 
        n++;

}

int main(void)
{
    test();

    while (1)
    {
        flag = 1;
    }
}
//phần code volatile này cho vào cpu.simu để step và quan sát các hành vi của volatile trong quá trình thực thi.
//volatile sẽ đảm bảo mỗi lần đọc hoặc ghi biến volatile sẽ thực hiện trực tiếp trên bộ nhớ, không bị tối ưu hóa bởi trình biên dịch, giúp đảm bảo rằng các tác vụ khác có thể thấy được sự thay đổi của biến volatile ngay lập tức.