cmake_minimum_required(VERSION 3.15)
project(user_testapp_protobuf LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Protobuf REQUIRED)

include_directories(
    ${Protobuf_INCLUDE_DIRS}
    generated
    src
)

set(SRC_FILES
    src/main.cpp
    src/User.cpp
    src/UserRepository.cpp
    generated/users.pb.cc
)

add_executable(user_testapp_protobuf ${SRC_FILES})

target_link_libraries(user_testapp_protobuf
    ${Protobuf_LIBRARIES}
    absl_log_internal_check_op
    absl_strings
    absl_base
    absl_log_internal_conditions
    absl_log_internal_format
    absl_log_internal_globals
    absl_log_internal_proto
    absl_log_internal_message
    absl_log_internal_log_sink_set
    absl_log_internal_nullguard
    absl_time
    absl_civil_time
    absl_time_zone
    pthread
)
