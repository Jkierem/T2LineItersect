cmake_minimum_required(VERSION 2.8)

PROJECT("Interseccion de Lineas")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

find_package(CGAL REQUIRED)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLU REQUIRED)
include(${CGAL_USE_FILE} ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLU_INCLUDE_DIRS})
add_executable(lineintersect main.cxx ./src/Juan/Juan.cxx ./src/GEngine/GEngine.cxx ./src/Core/Core.cxx)

target_link_libraries(lineintersect ${CGAL_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLU_LIBRARIES})
