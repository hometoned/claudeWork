cmake_minimum_required(VERSION 3.5.1)

project(${PLUGINNETDATA_NAME})

if(QTPATH)
    set(CMAKE_PREFIX_PATH $ENV{QTDIR})
    find_package(Qt5 COMPONENTS Core Gui Widgets Network REQUIRED)
    #打开moc
    #set(CMAKE_AUTOMOC ON)
    #打开moc
    set(CMAKE_AUTOUIC ON)
    #打开rcc
    set(CMAKE_AUTORCC ON)
    #生成的文件与目录无关
    add_compile_options(-fPIC)
endif()

#设置查找到的目录
set(PLUGINNETDATA_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../code/source/Plugins)
set(PLUGINNETDATA_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../code/include/Plugins)

#递归查找目录下所有的源文件
file(GLOB_RECURSE PLUGINNETDATA_SOURCE_FILES ${PLUGINNETDATA_SOURCE_DIR}/${PLUGINNETDATA_NAME}/*.cpp)

#递归查找目录下所有的头文件
file(GLOB_RECURSE PLUGINNETDATA_HEADER_FILES ${PLUGINNETDATA_INCLUDE_DIR}/${PLUGINNETDATA_NAME}/*.h)

#生成可执行程序
add_library(${PLUGINNETDATA_NAME} SHARED
            ${PLUGINNETDATA_HEADER_FILES}
            ${PLUGINNETDATA_SOURCE_FILES}
            )

#设置包含目录
target_include_directories(${PLUGINNETDATA_NAME} PUBLIC
                           ${QTPATH}/include
                           ${PLUGINNETDATA_INCLUDE_DIR}
                           ${OSGPATH}/include
                          )

#设置可执行文件的输出目录
set(EXECUTABLE_OUTPUT_PATH ${BIN_DIR}/${PLUGINS_NAME})

target_compile_definitions(${PLUGINNETDATA_NAME}
                           PRIVATE -D${PLUGINNETDATA_NAME}_LIB
                          )


#设置vs中DEBUG运行时的输出目录
set_target_properties(${PLUGINNETDATA_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BIN_DIR}/Debug/Plugins)

#设置vs中RELEASE运行时的输出目录
set_target_properties(${PLUGINNETDATA_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BIN_DIR}/Release/Plugins)

#设置DEBUG版本下的库文件后缀名
set_target_properties(${PLUGINNETDATA_NAME} PROPERTIES DEBUG_POSTFIX "d")

#库文件.lib的工作目录目录
set_target_properties(${PLUGINNETDATA_NAME} PROPERTIES LIBRARY_OUTPUT_PATH ${LIB_DIR}/)

#针对这个库打开AUTOMOC
set_target_properties(${PLUGINNETDATA_NAME} PROPERTIES AUTOMOC ON)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")

    #判断编译的类型debug/release
    set(TYPE $<IF:$<CONFIG:Debug>,debug,release>)
    #设置vs中调试时的工作目录
    set_property(TARGET ${PLUGINNETDATA_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${BIN_DIR}/${TYPE}/)

    #整理自动生成的文件
    source_group("Moc"  REGULAR_EXPRESSION "\\mocs*.cpp$|\\moc*.cpp")
    #source_group("Header Files" REGULAR_EXPRESSION "^$")
    #source_group("Source Files" REGULAR_EXPRESSION "^$")
    #source_group("zero"	REGULAR_EXPRESSION "\\.h$|\\.cpp$|\\.stamp$|\\.rule$")

    #依赖库
    target_link_libraries(${PLUGINNETDATA_NAME} PRIVATE
                          Qt5::Core
                          Qt5::Gui
                          Qt5::Widgets
                          Qt5::Network
                          ${OSGPATH}/lib/osg.lib
                          ${OSGPATH}/lib/osgDB.lib
                          ${OSGPATH}/lib/osgViewer.lib
                          ${OSGPATH}/lib/osgGA.lib
                          ${OSGPATH}/lib/Openthreads.lib
                          ${OSGPATH}/lib/osgEarth.lib
                          ${SCENE_NAME}
                          ${UI_NAME}
                          ${BASE_NAME}
                          ${LIB_DIR}/Release/IDSAPI_x64.lib
                          ${LIB_DIR}/Release/TerminalEffect.lib
                         )


elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_link_libraries(${PLUGINNETDATA_NAME} PRIVATE
                          Qt5::Core
                          Qt5::Gui
                          Qt5::Widgets
                          Qt5::Network
                          ${SCENE_NAME}
                          ${UI_NAME}
                          ${BASE_NAME}
                          ${BIN_DIR}/libIDSAPI.so.1.0.0
                         )

endif()

