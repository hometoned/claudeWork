#指定版本
cmake_minimum_required(VERSION 3.15.1)

#指定c++版本
set(CMAKE_CXX_STANDARD 11)

#设置工程名PROJECT_NAME的值为SituationSimulation
set(PROJECT_NAME project)

#设置可执行程序名和文件夹变量EXECUTABLE_NAME的值为Situation
set(EXECUTABLE_NAME demo)

#设置UI依赖库的名称和文件夹的名称为U
set(UI_NAME UI)

#设置Scene依赖库的名称和文件夹的名称为Scene
set(SCENE_NAME Scene)

#设置Base依赖库的名称和文件夹的名称为Base
#set(BASE_NAME Base)

#设置Plugins文件夹的名称为Plugins
set(PLUGINS_NAME Plugins)

#本工程的名称。
project(${PROJECT_NAME})

#bin dir
set(BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

#lib dir
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)

#判断是否为Linux
if (CMAKE_SYSTEM_NAME MATCHES "Linux")

    #添加LINUX的宏定义
    add_definitions(-DLINUX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")

#windows操作系统
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")

    #添加宏定义WINDOWS
    add_definitions(-DWINDOWS)
	#编译时关闭C4828警告
    add_compile_options(/wd4828)
	
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/execution-charset:gbk>")
endif()

#设置DEBUG版本下的库文件后缀名
set(CMAKE_DEBUG_POSTFIX "d")

#读取环境变量QTDIR
set(QTPATH $ENV{QTDIR})

#读取环境变量OSGDIR
#set(OSGPATH $ENV{OSGDIR})
set(3DPATH ${CMAKE_CURRENT_SOURCE_DIR}/3fangku)

#add_subdirectory(Projects/${BASE_NAME})

add_subdirectory(Projects/${SCENE_NAME})

add_subdirectory(Projects/${UI_NAME})

add_subdirectory(Projects/${PLUGINS_NAME})

add_subdirectory(Projects/${EXECUTABLE_NAME})
