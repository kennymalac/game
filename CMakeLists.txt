cmake_minimum_required(VERSION 3.1)
project(SimulatorGame)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
# Export a JSON file with information about our build for irony-mode
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

option(USE_SYSTEM_GLEW "Use the GLEW library installed system-wide" ON)
option(USE_SYSTEM_GLFW "Use the GLFW library installed system-wide" ON)
option(USE_SYSTEM_GLM "Use the GLM library installed system-wide" OFF)

find_package(PkgConfig REQUIRED)
#find_package (OPENGL REQUIRED)
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
  find_package (GLFW3 REQUIRED)
  include_directories (${GLFW_INCLUDE_DIRS})
else (USE_SYSTEM_GLFW)
  add_subdirectory ("glfw")
  include_directories ("glfw/include")
  set (GLFW_LIBRARIES "glfw ${GLFW3_LIBRARIES}")
endif (USE_SYSTEM_GLFW)

if (USE_SYSTEM_GLM)
  find_package (GLM 0.9.0 REQUIRED)
  include_directories (${GLM_INCLUDE_DIRS})
else (USE_SYSTEM_GLM)
  include_directories ("glm")
endif (USE_SYSTEM_GLM)

file(GLOB SOURCES
  "engine.hpp"
  "engine.cpp"
  #"*.hpp"
  #"*.cpp"
  )


if (APPLE)
  set(CMAKE_EXE_LINKER_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit -framework CoreFoundation -framework CoreVideo")
endif()

# Create the run game executable
add_executable(Run main.cpp)
target_link_libraries(Run glfw3 ${GLEW_LIBRARIES} ${GLFW_LIBRARIES} ${GLM_LIBRARIES})
target_sources(Run PUBLIC ${SOURCES})

