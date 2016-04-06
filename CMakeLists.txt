cmake_minimum_required(VERSION 3.3)
project(raytracer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Vector3D.h Vector3D.cpp Color.h Ray.cpp Ray.h Shape.h Sphere.h Sphere.cpp Scene.h
        Scene.cpp ImageOutput.cpp ImageOutput.h EasyBMP.h EasyBMP.cpp Plane.cpp Plane.h Compare.cpp Compare.h Disk.h Disk.cpp Box.cpp Box.h
        Light.h Light.cpp Options.h Options.cpp  Shadow.cpp Shadow.h PointLight.h PointLight.cpp DirectionalLight.h DirectionalLight.cpp Camera.h Camera.cpp)
add_executable(raytracer ${SOURCE_FILES})
