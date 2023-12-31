cmake_minimum_required(VERSION 3.16)
project(SFML-2D-Shapes-Renderer LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(SFML-2D-Shapes-Renderer src/main.cpp src/configurationLoader.cpp src/shapeManager.cpp)

target_link_libraries(SFML-2D-Shapes-Renderer PRIVATE sfml-graphics)
target_compile_features(SFML-2D-Shapes-Renderer PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET SFML-2D-Shapes-Renderer
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:SFML-2D-Shapes-Renderer>
        VERBATIM)
endif()

install(TARGETS SFML-2D-Shapes-Renderer)
