cmake_minimum_required(VERSION 3.5.1)

project(${EXECUTABLE_NAME})

set(CMAKE_CXX_STANDARD 11)

if(QTPATH)
    set(CMAKE_PREFIX_PATH $ENV{QTDIR})
    find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
    #生成的文件与目录无关
    add_compile_options(-fPIC)
endif()

#设置可执行文件的输出目录
set(EXECUTABLE_OUTPUT_PATH ${BIN_DIR})

set(EXE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../code/include)

#递归查找目录下所有的头文件
file(GLOB_RECURSE HEADER_FILES ${EXE_INCLUDE_DIR}/${EXECUTABLE_NAME}/*.h)

#设置查找到的目录
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../code/source/${EXECUTABLE_NAME})

#递归查找目录下所有的文件
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}/*.cpp)

#生成可执行程序
add_executable(${EXECUTABLE_NAME} ${HEADER_FILES} ${SOURCE_FILES})

#设置vs中DEBUG运行时的工作目录
set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BIN_DIR})

#设置vs中RELEASE运行时的工作目录
set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BIN_DIR})

#设置DEBUG版本下的库文件后缀名
set_target_properties(${EXECUTABLE_NAME} PROPERTIES DEBUG_POSTFIX "d")

#库文件的输出目录
#set(LIBRARY_OUTPUT_PATH ${LIB_DIR})

target_link_libraries(${EXECUTABLE_NAME} PRIVATE
                      Qt5::Core
                      Qt5::Gui
                      Qt5::Widgets
                      ${UI_NAME}
                     )

if(CMAKE_SYSTEM_NAME MATCHES "Windows")


    #判断编译的类型debug/release
    set(TYPE $<IF:$<CONFIG:Debug>,debug,release>)
    #设置vs中调试时的工作目录
    set_property(TARGET ${EXECUTABLE_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}/${TYPE}/)

    #设置包含目录
    target_include_directories(${EXECUTABLE_NAME} PRIVATE
                               ${CMAKE_CURRENT_SOURCE_DIR}/../../code/include
                               ${QTPATH}/include
                               ${3DPATH}/include
                              )


elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")

    #设置包含目录
    target_include_directories(${EXECUTABLE_NAME} PRIVATE
                               ${CMAKE_CURRENT_SOURCE_DIR}/../../code/include
                               ${QTPATH}/../include
                               ${3DPATH}/../include
                              )

endif()