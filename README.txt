Build (on Mac CMake fail smh)
    g++ main.cpp sources/component/*.cpp sources/entity/*.cpp -I./sources -I./sources/component -I./sources/entity -I/usr/local/include -std=c++2a -lsfml-system -lsfml-graphics -lsfml-window

Otherwise
    mkdir build
    cd build
    cmake ..
    make
