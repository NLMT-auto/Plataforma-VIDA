cmake_minimum_required(VERSION 3.15) #versão minima do CMake necessária para construir o projeto
project(nlmt CXX) #define o nome do projeto como nlmt e especifica que será escrito em c++

add_executable(vida) #cria o executável vida

#Procura pelo pacote Threads. Este pacote fornece suporte para multithreading em projetos CMake.
find_package (Threads)
find_library(WIRINGPI_LIB wiringPi)
find_library(WIRINGPI_DEV_LIB wiringPiDev)

#Liga as bibliotecas Threads e "rt" ao executável "vida".
target_link_libraries(vida
    ${CMAKE_THREAD_LIBS_INIT}
    rt
    ${WIRINGPI_LIB}
    ${WIRINGPI_DEV_LIB}
    crypt
)

#associa os arquivos fontes um ao execultavel vida
target_sources(
    vida

    PRIVATE
        
        main.cpp        

        #Files
        Files/DefinePin.h
        Files/Struct_sensors.h

        #Encoder
        Containers/Encoder/Encoder.cpp
        Containers/Encoder/Encoder.h

        #Steering
        Containers/Steering/Steering.cpp
        Containers/Steering/Steering.h

        #Control
        Containers/Control/Control.cpp
        Containers/Control/Control.h      

        #Record
        Containers/Record/Record.cpp
        Containers/Record/Record.h

        #memoria compartilhada
        Utils/PosixShMem/PosixShMem.cpp
        Utils/PosixShMem/PosixShMem.h

        #Comunicação serial
        Utils/Serial/Serial.h
        Utils/Serial/Serial.cpp

        #ThreadBase
        Utils/ThreadBase/ThreadBase.cpp
        Utils/ThreadBase/ThreadBase.h

        #Comunicação UDP
        Utils/UDP/UDP.cpp
        Utils/UDP/UDP.h

        #Tempo
        Utils/road_time.h

        
)