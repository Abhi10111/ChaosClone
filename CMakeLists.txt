cmake_minimum_required(VERSION 3.16)

# Project name and language
project(ChaosClone
    VERSION 1.0
    LANGUAGES CXX
)

# -------------------------
# C++ standard
# -------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 REQUIRED)

# -------------------------
# Source files
# -------------------------
set(SOURCES
    src/Chaos/ChaosEngineInterface.cpp
    src/Chaos/ChaosScene.cpp
    src/Chaos/Solver.cpp
    src/Components/PrimitiveComponent.cpp
    src/BodyInstance.cpp
    src/World.cpp
    src/main.cpp
    # add more .cpp files here
)

# -------------------------
# Target
# -------------------------
add_executable(${PROJECT_NAME}
${SOURCES}
)

# -------------------------
# Include directories
# -------------------------
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/Chaos
        ${PROJECT_SOURCE_DIR}/include/Components
)

target_link_libraries(ChaosClone PRIVATE ${SDL2_LIBRARIES})

# -------------------------
# Compiler warnings
# -------------------------
if (MSVC)
target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

# -------------------------
# Build type defaults
# -------------------------
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# -------------------------
# Optional: enable sanitizers (GCC/Clang)
# -------------------------
option(ENABLE_SANITIZERS "Enable address/undefined sanitizers" OFF)

if (ENABLE_SANITIZERS AND NOT MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
    target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
endif()
