cmake_minimum_required(VERSION 3.10)

project(DataStructure_tutorial
    VERSION 1.0.0
    LANGUAGES C CXX
    DESCRIPTION "Data Structure Tutorial")

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(SRC_FILES
    ${PROJECT_SOURCE_DIR}/main.c
    ${PROJECT_SOURCE_DIR}/src/SqList.c
    ${PROJECT_SOURCE_DIR}/src/FuncDemo.c
    ${PROJECT_SOURCE_DIR}/src/Stack.c
    ${PROJECT_SOURCE_DIR}/src/Queue.c)


# aux_source_directory(. DIR_SRCS)
# aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)

include_directories(${PROJECT_SOURCE_DIR}/inc)

add_executable(MyApp ${SRC_FILES})



