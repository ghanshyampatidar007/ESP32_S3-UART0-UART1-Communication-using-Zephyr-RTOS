#include "uart.h"

void uart_transmit_char(const struct device *const uart0_dev,char ch){
        uart_poll_out(uart0_dev, ch);
    return;
}
void uart_transmit_string(const struct device *const uart0_dev,char *msg){   

    for (int i = 0; msg[i]; i++) {
        uart_poll_out(uart0_dev, msg[i]);
    }
    return;
}

void uart_receive_char(const struct device *const uart0_dev,char *ch){
        while(uart_poll_in(uart0_dev, ch)!=0){
                k_msleep(50);
        }
    return;
}

void uart_receive_string(const struct device *const uart0_dev,char **str){   
    char *msg=NULL;
    int i=0;
    do{
            msg=realloc(msg,i+1);
            if(msg==NULL){
                break;
            }
            while(uart_poll_in(uart0_dev, msg+i)!=0){
                k_msleep(50);
            }
    }while(msg[i++]!=';');
    msg[i-1]='\0';
    *str=msg;
    return;
}
