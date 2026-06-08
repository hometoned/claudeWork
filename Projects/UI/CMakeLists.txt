cmake_minimum_required(VERSION 3.5.1)

project(${UI_NAME})

if(QTPATH)
    set(CMAKE_PREFIX_PATH $ENV{QTDIR})
    find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
    #打开moc
    #set(CMAKE_AUTOMOC ON)
    #打开moc
    set(CMAKE_AUTOUIC ON)
    #打开rcc
    set(CMAKE_AUTORCC ON)
    #生成的文件与目录无关
    add_compile_options(-fPIC)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    #库文件.so的输出目录
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR})
endif()

#设置查找到的目录
set(UI_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../code/source/${UI_NAME})
set(UI_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../code/include)

#递归查找目录下所有的源文件
file(GLOB_RECURSE UI_SOURCE_FILES ${UI_SOURCE_DIR}/*.cpp)

# 添加 glad 源文件
#set(GLAD_SOURCE_FILE ${3DPATH}/src/glad.c)
#list(APPEND UI_SOURCE_FILES ${GLAD_SOURCE_FILE})

#递归查找目录下所有的头文件
file(GLOB_RECURSE UI_HEADER_FILES ${UI_INCLUDE_DIR}/${UI_NAME}/*.h)

#生成可执行程序
add_library(${UI_NAME} SHARED
            ${UI_HEADER_FILES}
            ${UI_SOURCE_FILES}
            )

#设置包含目录
target_include_directories(${UI_NAME} PUBLIC
                           ${QTPATH}/include
                           ${UI_INCLUDE_DIR}
#                           ${3DPATH}/include
                          )

#设置可执行文件的输出目录
set(EXECUTABLE_OUTPUT_PATH ${BIN_DIR})

target_compile_definitions(${UI_NAME}
                           PRIVATE -D${UI_NAME}_LIB
                          )

#设置vs的Qt属性
set_property(TARGET ${UI_NAME} PROPERTY FRAMEWORK_TYPE Qt)

#设置vs中DEBUG运行时的工作目录
set_target_properties(${UI_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BIN_DIR}/Debug/)

#设置vs中RELEASE运行时的工作目录
set_target_properties(${UI_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BIN_DIR}/Release/)

#设置DEBUG版本下的库文件后缀名
set_target_properties(${UI_NAME} PROPERTIES DEBUG_POSTFIX "d")

#库文件.dll的输出目录
set_target_properties(${UI_NAME} PROPERTIES LIBRARY_OUTPUT_PATH ${BIN_DIR})

#库文件.lib的输出目录
set_target_properties(${UI_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${LIB_DIR})

#打开AUTOMOC
set_target_properties(${UI_NAME} PROPERTIES AUTOMOC ON)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")

    #判断编译的类型debug/release
    set(TYPE $<IF:$<CONFIG:Debug>,debug,release>)
    #设置vs中调试时的工作目录
    set_property(TARGET ${UI_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}/${TYPE}/)

    #整理自动生成的文件
    source_group("Moc"  REGULAR_EXPRESSION "\\mocs*.cpp$|\\moc*.cpp")
    #source_group("Header Files" REGULAR_EXPRESSION "^$")
    #source_group("Source Files" REGULAR_EXPRESSION "^$")
    #source_group("zero"	REGULAR_EXPRESSION "\\.h$|\\.cpp$|\\.stamp$|\\.rule$")

    #依赖库
    target_link_libraries(${UI_NAME} PRIVATE
                          ${SCENE_NAME}
                          Qt5::Core
                          Qt5::Gui
                          Qt5::Widgets
                         )

    #add_custom_command(TARGET ${UI_NAME} POST_BUILD
    #COMMAND ${CMAKE_COMMAND} -E copy
    #${QTPATH}/bin/Qt5Core${DEBUG_POSTFIX}.dll
    #${BIN_DIR}/${TYPE}
    #)
    
    #依赖库的目录
    #target_link_directories(${UI_NAME} PRIVATE
    #                        ${QTPATH}/include
    #                        #${ALGORITHM_NAME}/*.LIB
    #                        ${OSGPATH}/include
    #                        )

elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    
    target_link_libraries(${UI_NAME} PRIVATE
                          ${SCENE_NAME}
                          Qt5::Core
                          Qt5::Gui
                          Qt5::Widgets
                         )

endif()
