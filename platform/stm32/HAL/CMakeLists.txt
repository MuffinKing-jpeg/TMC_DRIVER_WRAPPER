cmake_minimum_required(VERSION 3.22)

project(TMC_API_STM32_HAL)
add_library(TMC_API_STM32_HAL INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

if(TMC_API_ENABLE_TMC2209)
    file(GLOB TMC_API_STM32_HAL_TMC2208_SRC ${CMAKE_CURRENT_SOURCE_DIR}/TMC2209/*.c)
    list(APPEND TMC_API_STM32_HAL_SRC_FILES ${TMC_API_STM32_HAL_TMC2208_SRC})
    list(APPEND TMC_API_STM32_HAL_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/TMC2209)
endif()

target_include_directories(TMC_API INTERFACE
    ${TMC_API_STM32_HAL_INCLUDES}
)

target_sources(TMC_API PUBLIC
    ${TMC_API_STM32_HAL_SRC_FILES}
    # Add user sources here
)

target_link_directories(TMC_API INTERFACE
)

target_link_libraries(TMC_API INTERFACE
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()