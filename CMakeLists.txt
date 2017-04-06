cmake_minimum_required(VERSION 3.1)
project(SimulatorGame)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED on)
# Cmake 3.8 isn't out yet so we need to require c++ 17 manually
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")
# Export a JSON file with information about our build for irony-mode
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

# Project-specific properties
set(BASE_TEST_DIR ${PROJECT_SOURCE_DIR}/test)
set(ENGINE_TEST_SOURCES
  ${BASE_TEST_DIR}/camera.cpp
  ${BASE_TEST_DIR}/entity.cpp
  ${BASE_TEST_DIR}/mesh.cpp
  ${BASE_TEST_DIR}/scene.cpp
  ${BASE_TEST_DIR}/shaders.cpp
  ${BASE_TEST_DIR}/space.cpp
  # ${BASE_TEST_DIR}/sugar.cpp
  # ${BASE_TEST_DIR}/transitions.cpp
)

option(USE_SYSTEM_GLEW "Use the GLEW library installed system-wide" ON)
option(USE_SYSTEM_GLFW "Use the GLFW library installed system-wide" ON)
option(USE_SYSTEM_GLM "Use the GLM library installed system-wide" OFF)

find_package(PkgConfig REQUIRED)
find_package (OpenGL REQUIRED)
#find_package (GLFW3 REQUIRED)


if (USE_SYSTEM_GLEW)
  find_package (GLEW REQUIRED)
  include_directories (${GLEW_INCLUDE_DIRS})
else (USE_SYSTEM_GLEW)
  add_subdirectory ("glew")
  include_directories ("glew/include")
  set (GLEW_LIBRARIES "glew ${GLEW_LIBRARIES}")
endif (USE_SYSTEM_GLEW)

if (USE_SYSTEM_GLFW)
  find_package (glfw3 REQUIRED)
  include_directories (${GLFW_INCLUDE_DIRS})
else (USE_SYSTEM_GLFW)
  add_subdirectory ("glfw")
  include_directories ("glfw/include")
  set (GLFW_LIBRARIES "glfw ${GLFW3_LIBRARIES}")
endif (USE_SYSTEM_GLFW)

if (USE_SYSTEM_GLM)
  find_package (glm 0.9.0 REQUIRED)
  include_directories (${GLM_INCLUDE_DIRS})
else (USE_SYSTEM_GLM)
  include_directories ("glm")
endif (USE_SYSTEM_GLM)

file(GLOB SOURCES
  "engine.hpp"
  "engine.cpp"
  "camera.hpp"
  "camera.cpp"
  "component.hpp"
  "component.cpp"
  "entity.hpp"
  "entity.cpp"
  "scene.hpp"
  "scene.cpp"
  "shaders.cpp"
  "shaders.hpp"
  #"*.hpp"
  #"*.cpp"
  )


if (APPLE)
  set(CMAKE_EXE_LINKER_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit -framework CoreFoundation -framework CoreVideo")
endif()

# Create the run game executable
add_library(Engine_Base ${SOURCES})
target_link_libraries(Engine_Base PUBLIC ${OPENGL_LIBRARY} glfw ${GLEW_LIBRARIES} ${GLFW_LIBRARIES} ${GLM_LIBRARIES})
add_executable(Run main.cpp)
target_link_libraries(Run Engine_Base)

# TODO make testing an option, see https://github.com/ComicSansMS/GhulbusBase/blob/master/CMakeLists.txt
enable_testing()
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${BASE_TEST_DIR}/include)

# Create the testing suite executable
add_executable(Test ${ENGINE_TEST_SOURCES})
target_link_libraries(Test Engine_Base Catch)
add_test(NAME TestBase COMMAND Test)
