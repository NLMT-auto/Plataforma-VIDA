cmake_minimum_required(VERSION 3.15)
project(nlmt CXX)

add_executable(nlmt)
find_package (Threads)
target_link_libraries(nlmt ${CMAKE_THREAD_LIBS_INIT} rt)
target_sources(
    nlmt

    PRIVATE
        Containers/Control/Control.cpp
        Containers/Control/Control.h
        Containers/files/general_defines.h
        Containers/files/shmem_struct.h
        Containers/files/test_struct.h
        Containers/Estecamento/poten/poten_struct.h
        Containers/Estecamento/poten/poten.cpp
        Containers/Estecamento/poten/poten.h
        Containers/Encoder/ReadMem/ReadMem.cpp
        Containers/Encoder/ReadMem/ReadMem.h
        Containers/Encoder/SetPoint/SetPoint.cpp
        Containers/Encoder/SetPoint/SetPoint.h
        Containers/Encoder/WriteMem/WriteMem.cpp
        Containers/Encoder/WriteMem/WriteMem.h
        Utils/PosixShMem/PosixShMem.cpp
        Utils/PosixShMem/PosixShMem.h
        Utils/ThreadBase/ThreadBase.cpp
        Utils/ThreadBase/ThreadBase.h
        Utils/road_time.h
        main.cpp
)