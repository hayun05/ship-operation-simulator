cmake_minimum_required(VERSION 3.16)

project(ShipSimulator VERSION 0.1 LANGUAGES CXX)

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt 자동 처리
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Qt6 찾기 (Widgets + OpenGLWidgets)
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets OpenGL)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGL OpenGLWidgets)

# OpenGL 라이브러리
find_package(OpenGL REQUIRED)

# 소스와 헤더 파일
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    openglwidget.cpp
    openglwidget.h
    ship.cpp
    ship.h
    shipmodel.cpp
    shipmodel.h
)

# 실행 파일 생성
qt_add_executable(ShipSimulator
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

# 라이브러리 링크
target_link_libraries(ShipSimulator PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::OpenGLWidgets
    OpenGL::GL
)

# Qt6 전용 마무리
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ShipSimulator)
endif()
