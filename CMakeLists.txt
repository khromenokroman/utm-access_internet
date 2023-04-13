cmake_minimum_required(VERSION 3.5)

project(update_config_utm)

add_executable(update_config_utm 
    main.cpp
    get_info.cpp
    os.cpp
    in.cpp
    header.h
)

set_target_properties(update_config_utm PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)