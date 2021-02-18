project(SDKGEN)


add_library(SDKGEN SHARED 
    Main.cpp
)

add_definitions(-DSDK_OUTPUT="${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

target_compile_options(SDKGEN PUBLIC /GS-)
target_compile_features(SDKGEN PUBLIC cxx_std_17)
target_link_libraries(SDKGEN PUBLIC shlwapi SDKSHARED)

include_directories(SDKGEN ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(SDKGEN ${CMAKE_SOURCE_DIR}/shared)
set_target_properties(PROPERTIES OUTPUT_NAME sdkgen)