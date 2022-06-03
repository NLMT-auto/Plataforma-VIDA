cmake_minimum_required(VERSION 3.15)
project(nlmt CXX)

add_executable(vida)
find_package (Threads)
target_link_libraries(vida ${CMAKE_THREAD_LIBS_INIT} rt)
target_sources(
    vida

    PRIVATE
        Containers/Control/Control.cpp
        Containers/Control/Control.h
        Containers/files/general_defines.h
        Containers/files/shmem_struct.h
        Containers/files/test_struct.h
        Utils/PosixShMem/PosixShMem.cpp
        Utils/PosixShMem/PosixShMem.h
        Utils/ThreadBase/ThreadBase.cpp
        Utils/ThreadBase/ThreadBase.h
        Utils/road_time.h
        main.cpp
)