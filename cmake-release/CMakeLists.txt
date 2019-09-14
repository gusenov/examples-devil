cmake_minimum_required(VERSION 3.14)
project(CMakeRelease)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        CMakeRelease
        main.cc
)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/../devil/1.8.0_1/include)

target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/../devil/1.8.0_1/relink/libIL.dylib)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/../devil/1.8.0_1/relink/libILU.dylib)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/../devil/1.8.0_1/relink/libILUT.dylib)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/../devil/1.8.0_1/relink/libjasper.4.dylib)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/../devil/1.8.0_1/relink/libjpeg.9.dylib)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/../devil/1.8.0_1/relink/liblcms2.2.dylib)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/../devil/1.8.0_1/relink/libpng16.16.dylib)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/../devil/1.8.0_1/relink/libtiff.5.dylib)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/42454-globe-with-meridians-icon.png
        ${CMAKE_CURRENT_BINARY_DIR}/42454-globe-with-meridians-icon.png)
