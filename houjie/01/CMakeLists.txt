set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(03-ctors-initialization 03-ctors-initialization.cpp)

#add_executable(04-ctors-singleton 04-ctors-singleton.cpp)

add_executable(05-const-member-functions 05-const-member-functions.cpp)

add_executable(06-class-friend 06-class-friend.cpp)

add_executable(07-complex-operator 07-complex-operator.cpp)

add_subdirectory(string/)

add_executable(oop-composition oop-composition.cpp)

add_executable(oop-delegation oop-delegation.cpp)

add_executable(oop-inheritance oop-inheritance.cpp)

add_executable(oop-template oop-template)

add_executable(oop-observer oop-observer.cpp)
