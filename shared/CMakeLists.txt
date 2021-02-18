project(SDKSHARED)

set(SDK_SRC
    sdk/Enums.hpp
    sdk/GlacierModuleManager.hpp
    sdk/GlacierModuleManager.cpp
    sdk/ReClass.hpp
    sdk/ReClass_Internal.hpp
    sdk/TArray.hpp
    sdk/TEntityRef.hpp
    sdk/TypeRegistry.hpp
    sdk/TypeRegistry.cpp
    sdk/Pool.hpp
    sdk/Pool.cpp
    sdk/ZString.hpp
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

add_library(SDKSHARED STATIC 
    ${SDK_SRC}
    ${UTILITY_SRC}
)

target_compile_options(SDKSHARED PUBLIC /GS-)
target_compile_features(SDKSHARED PUBLIC cxx_std_17)
target_link_libraries(SDKSHARED PUBLIC shlwapi)

include_directories(SDKSHARED ${CMAKE_CURRENT_SOURCE_DIR})
