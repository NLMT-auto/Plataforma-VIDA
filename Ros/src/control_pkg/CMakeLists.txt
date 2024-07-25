cmake_minimum_required(VERSION 3.15)
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

    ../../../Utils/Serial/Serial.h
    ../../../Utils/Serial/Serial.cpp
    ../../../Utils/road_time.h
)

add_executable(sensors)

#vincula as dependencia do nó sensors
ament_target_dependencies(sensors rclcpp vida_interfaces) 
target_link_libraries(sensors    
    ${WIRINGPI_LIB}
    ${WIRINGPI_DEV_LIB}    
)

#faz ligação dos arquivos usados em sensors
target_sources(
  sensors

  PRIVATE

    src/Sensors/Sensors.cpp
    src/Sensors/Sensors.h

    ../../../Utils/Serial/Serial.h
    ../../../Utils/Serial/Serial.cpp

    ../../../Utils/Files/DefinePin.h
    ../../../Utils/road_time.h
)


add_executable(record)
ament_target_dependencies(record rclcpp vida_interfaces) 

target_sources(
  record

  PRIVATE

    src/Record/Record.cpp
    src/Record/Record.h  
)



install(TARGETS
  control 
  sensors 
  record
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
