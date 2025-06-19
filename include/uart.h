#ifndef UART_H
#define UART_H

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <string.h>
#include <stdlib.h>

void uart_transmit_char(const struct device *const,char);
void uart_transmit_string(const struct device *const ,char *);
void uart_receive_char(const struct device *const,char *);
void uart_receive_string(const struct device *const,char **);

#endif