project(SDKGEN)

add_library(SDKGEN SHARED 
    Main.cpp

    Enums.hpp
    ReClass.hpp
    ReClass_Internal.hpp

    TypeRegistry.hpp
    TypeRegistry.cpp
)

add_definitions(-DSDK_OUTPUT="${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

target_compile_options(SDKGEN PUBLIC /GS-)
target_compile_features(SDKGEN PUBLIC cxx_std_17)

include_directories(SDKGEN ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(PROPERTIES OUTPUT_NAME sdkgen)