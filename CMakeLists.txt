cmake_minimum_required(VERSION 3.10)
project(COMP_GRAPHICS_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(COMP_GRAPHICS_2 main.cpp b_spline.cpp b_spline.h profile.h)

include_directories(c:/SFML/include)
link_directories(C:/SFML/include)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics )
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()
