set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(01-operator-conversion-function 01-operator-conversion-function.cpp)

add_executable(02-explicit-constructor 02-explicit-constructor.cpp)

add_executable(03-shared-ptr 03-shared-ptr.cpp)

add_executable(04-pointer-like-classes 04-pointer-like-classes.cpp)

add_executable(05-function-like-classes 05-function-like-classes.cpp)

add_executable(17-about-vptr-vtbl 17-about-vptr-vtbl.cpp)

#add_executable(18-about-this 18-about-this.cpp)

add_executable(20-operator-new-delete 20-operator-new-delete.cpp)

add_executable(21-operator-new-delete-placement-arguments 21-operator-new-delete-placement-arguments.cpp)

add_subdirectory(./template)