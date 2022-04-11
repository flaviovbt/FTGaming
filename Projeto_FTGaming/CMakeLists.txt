cmake_minimum_required(VERSION 3.17)
project(Projeto_FTGaming C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projeto_FTGaming
        cliente.c
        cliente.h
        interface.c
        interface.h
        main.c
        produto.c
        produto.h
        venda.c
        venda.h)
