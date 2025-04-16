# Wrapper for TMC-API

Integration of TRINAMIC's driver IC the CMAKE toolchain.

## Installation

Install submodule

```sh
git submodule update --init --recursive
```

Add library your CMakeLists.txt

```cmake
add_subdirectory(<path_to_module>/TMC_DRIVER_WRAPPER)
target_link_libraries(${CMAKE_PROJECT_NAME}
    ...
    # link library
    TMC_API
)
```

## Configruation

### Options

- Include build in ramp feature 
     `option(ENABLE_RAMP "Enable ramp" ON)`

### Selecting IC

```cmake
option(TMC_API_ENABLE_<ic_name> "TMC_API_ENABLE_<ic_name>" ON)

#example
option(TMC_API_ENABLE_TMC2209 "TMC_API_ENABLE_TMC2209" ON)
```

### Platform

You can write your own low level driver.  

**OR**  

Use premade platform tool

```cmake
# example for STM32_HAL
option(USE_HAL_DRIVER "Use STM32 HAL" ON)
```

#### Available platforms

- STM32 HAL
- *you can write your own and merge <3*
