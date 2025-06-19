#include "uart.h"
#define UART0_DEVICE_NODE DT_NODELABEL(uart0)
#define UART1_DEVICE_NODE DT_NODELABEL(uart1)

int main(void) {
    static const struct device *const uart0_dev = DEVICE_DT_GET(UART0_DEVICE_NODE);
    static const struct device *const uart1_dev = DEVICE_DT_GET(UART1_DEVICE_NODE);

    char *str=NULL;//,ch='A',msg[]="GHANSHYAM PATIDAR";

    if (!device_is_ready(uart0_dev)) {
        return 0;
    }
    if (!device_is_ready(uart1_dev)) {
        return 0;
    }

    //uart_transmit_char(uart0_dev,ch);
    //uart_transmit_string(uart0_dev,msg);
    
    //uart_receive_char(uart0_dev,&ch);
    //uart_transmit_char(uart0_dev,ch);
    
    printk("start....\n");

    do{
        free(str);
        
        uart_receive_string(uart0_dev,&str);  
        uart_transmit_string(uart1_dev,str);
        
        free(str);

        uart_receive_string(uart1_dev,&str);  
        uart_transmit_string(uart0_dev,str);

    }while(strcmp("quit",str));

    free(str);
    printk("completed.....\n");

    while(1);  
    
}