project(SDKGEN)

set(SDK_SRC
    sdk/Enums.hpp
    sdk/ReClass.hpp
    sdk/ReClass_Internal.hpp
    sdk/TArray.hpp
    sdk/TypeRegistry.hpp
    sdk/TypeRegistry.cpp
    sdk/Pool.hpp
    sdk/Pool.cpp
)

set(UTILITY_SRC
    utility/Address.hpp
    utility/Address.cpp
    utility/Config.hpp
    utility/Config.cpp
    utility/Memory.hpp
    utility/Memory.cpp
    utility/Module.hpp
    utility/Module.cpp
    utility/Patch.hpp
    utility/Patch.cpp
    utility/Pattern.hpp
    utility/Pattern.cpp
    utility/Scan.hpp
    utility/Scan.cpp
    utility/String.hpp
    utility/String.cpp
)

source_group("SDK" FILES ${SDK_SRC})
source_group("Utility" FILES ${UTILITY_SRC})

add_library(SDKGEN SHARED 
    Main.cpp

    ${SDK_SRC}
    ${UTILITY_SRC}
)

add_definitions(-DSDK_OUTPUT="${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

target_compile_options(SDKGEN PUBLIC /GS-)
target_compile_features(SDKGEN PUBLIC cxx_std_17)
target_link_libraries(SDKGEN PUBLIC shlwapi)

include_directories(SDKGEN ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(PROPERTIES OUTPUT_NAME sdkgen)