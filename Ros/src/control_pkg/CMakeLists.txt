cmake_minimum_required(VERSION 3.8)
project(control_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Busca de bibliotecas
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(vida_interfaces)
find_library(WIRINGPI_LIB wiringPi)
find_library(WIRINGPI_DEV_LIB wiringPiDev)


#Executável Nó control
add_executable(control)

#vincula as dependencia do nó control
ament_target_dependencies(control rclcpp vida_interfaces) 
target_link_libraries(control    
    ${WIRINGPI_LIB}
    ${WIRINGPI_DEV_LIB}    
)

#faz ligação dos arquivos usados em control
target_sources(
  control

  PRIVATE

    src/Control/Control.cpp
    src/Control/Control.h

    ../../../Threads/src/Utils/Serial/Serial.h
    ../../../Threads/src/Utils/Serial/Serial.cpp
)

install(TARGETS
  control  
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
