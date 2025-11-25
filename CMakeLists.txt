cmake_minimum_required(VERSION 3.10)
project(Sokoban)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找必要的库
find_package(OpenGL REQUIRED)

# 根据平台查找库
if(UNIX AND NOT APPLE)
    # 在Linux上使用pkg-config
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GLFW3 REQUIRED glfw3)
    pkg_check_modules(DEVIL REQUIRED IL ILU ILUT)
    pkg_check_modules(OPENAL REQUIRED openal)
    
    # 包含头文件目录
    include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${OPENGL_INCLUDE_DIRS}
        ${GLFW3_INCLUDE_DIRS}
        ${DEVIL_INCLUDE_DIRS}
        ${OPENAL_INCLUDE_DIRS}
    )
    
    # 链接库
    set(LIBS
        ${OPENGL_LIBRARIES}
        ${GLFW3_LIBRARIES}
        ${DEVIL_LIBRARIES}
        ${OPENAL_LIBRARIES}
    )
elif(WIN32)
    # 在Windows上直接查找库
    set(LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libraries")
    
    # 直接设置包含目录，不使用find_path
    include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${OPENGL_INCLUDE_DIRS}
        "${LIBRARY_DIR}/OpenAL 1.1 SDK/include"
        "${LIBRARY_DIR}/freealut-1.1.0-bin/include"
        "${LIBRARY_DIR}/DevIL-SDK-x86-1.7.8/include"
        # 额外添加嵌套目录以支持直接包含al.h、al/alut.h和IL/il.h
        "${LIBRARY_DIR}/OpenAL 1.1 SDK/include"
        "${LIBRARY_DIR}/freealut-1.1.0-bin/include"
        "${LIBRARY_DIR}/DevIL-SDK-x86-1.7.8/include"
    )
    
    # 链接库目录
    link_directories(
        "${LIBRARY_DIR}/OpenAL 1.1 SDK/libs/Win32"
        "${LIBRARY_DIR}/freealut-1.1.0-bin/lib"
        "${LIBRARY_DIR}/DevIL-SDK-x86-1.7.8/lib"
    )
    
    # 直接设置链接库，不使用find_library
    set(LIBS
        ${OPENGL_LIBRARIES}
        OpenAL32
        alut
        DevIL
        ILU
        ILUT
        gdi32
        user32
        kernel32
    )
else()
    message(WARNING "未明确识别的平台，尝试使用默认配置")
    # 提供默认配置
    include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${OPENGL_INCLUDE_DIRS}
    )
    set(LIBS ${OPENGL_LIBRARIES})
endif()

# 收集所有源文件
file(GLOB SOURCES "*.cpp" "*.h")

# 排除可能存在的不需要的文件
list(FILTER SOURCES EXCLUDE REGEX "_Main_File.cpp")

# 确保Platform.h被包含
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Platform.h")
    list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Platform.h")
endif()

# 确保main.cpp被包含
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
endif()

# 添加主程序源文件
add_executable(sokoban
    ${SOURCES}
    main.cpp  # 我们将创建一个新的main.cpp作为入口点
)

# 链接库
target_link_libraries(sokoban ${LIBS})

# 在Linux上链接数学库
if(UNIX AND NOT APPLE)
    target_link_libraries(sokoban -lm)
endif()

# 平台特定的编译选项
if(WIN32)
    target_compile_definitions(sokoban PRIVATE -D_WIN32)
    target_link_libraries(sokoban gdi32 user32 kernel32)
elseif(UNIX)
    target_compile_definitions(sokoban PRIVATE -D_UNIX)
endif()

# 安装目标
install(TARGETS sokoban DESTINATION bin)
