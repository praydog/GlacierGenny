mkdir build64
cd build64
cmake .. -G "Visual Studio 16 2019" -A x64
cmake --build . --config Release
