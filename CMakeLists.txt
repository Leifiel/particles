cmake_minimum_required(VERSION 3.5)
project(zelda)

include_directories(sources)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include -std=c++2a -stdlib=libc++")

add_executable(zelda
        main.cpp
        sources/component/IComponent.h
        sources/entity/Entity.h
        sources/Core.h
        sources/entity/Entity.cpp
        sources/entity/EntityManager.cpp
        sources/entity/EntityManager.h
        sources/component/Position.cpp
        sources/component/Position.h
        sources/component/Velocity.cpp
        sources/component/Velocity.h
        sources/component/Color.cpp
        sources/component/Color.h
        )

target_link_libraries(zelda sfml-system sfml-graphics sfml-window)