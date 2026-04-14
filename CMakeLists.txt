# Setting Cmake Version
cmake_minimum_required(VERSION 3.16)
project(Game)

# Setting C++ Version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding the SFML Paths
set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SFML/include")
set(SFML_LIB_DIR     "${CMAKE_SOURCE_DIR}/SFML/lib")
set(SFML_BIN_DIR     "${CMAKE_SOURCE_DIR}/SFML/bin")

include_directories(${SFML_INCLUDE_DIR})

# Make Cmake Find The Source Code
file(GLOB SOURCES 
    "${CMAKE_SOURCE_DIR}/*.cpp"
    "${CMAKE_SOURCE_DIR}/Src/*.cpp"
)

add_executable(Game ${SOURCES})

# Link Directiories
target_link_directories(Game PRIVATE ${SFML_LIB_DIR})

# Link SFML
target_link_libraries(Game PRIVATE 
    sfml-system
    sfml-window
    sfml-graphics
)

# Copy DLLs After Build
add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${SFML_BIN_DIR}
            $<TARGET_FILE_DIR:Game>
)

message(STATUS "SFML Include: ${SFML_INCLUDE_DIR}")
message(STATUS "Sources: ${SOURCES}")
