cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(uart)

# Add include directories (if headers are in include/)
target_include_directories(app PRIVATE include)

target_sources(app PRIVATE src/main.c src/uart.c)