*Example_Thread_Semaphore_SharedMemory:*

Video: https://youtu.be/gFds-Ci4kwE

Instruções para uso do CMake:
Caso não funcione é so excluir a pasta build da seguinte maneira:
rm -rf build --------------------------excluir a build


1- cmake -S src -B build -----------Construir a build e cMakeFiles
2- cd build ------------------------Entra na pasta build
3- make ----------------------------Compilar
4- ./vida --------------------------Executar


Instuções para installar biblioteca wiringPi

1- sudo apt update
2- sudo apt install git build-essential cmake
3- git clone https://github.com/WiringPi/WiringPi.git
4- cd WiringPi/
5- ./build
