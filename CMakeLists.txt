cmake_minimum_required(VERSION 3.3)

project(raytracer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp EasyBMP/EasyBMP.h EasyBMP/EasyBMP.cpp Vector3D.h Vector3D.cpp Color.h Ray.h Shape.h Sphere.h Sphere.cpp Scene.h
        Scene.cpp ImageOutput.cpp ImageOutput.h Plane.cpp Plane.h Compare.cpp Compare.h Disk.h Disk.cpp Box.cpp Box.h
        Light.h Light.cpp Options.h Options.cpp Shadow.h PointLight.h PointLight.cpp DirectionalLight.h DirectionalLight.cpp Camera.h Camera.cpp Matrix.h Matrix.cpp
       Triangle.h Triangle.cpp Matrix3X3.h Matrix3X3.cpp)


add_executable(raytracer ${SOURCE_FILES})

