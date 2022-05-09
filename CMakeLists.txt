cmake_minimum_required(VERSION 3.21)
project(lab88888I)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab88888I main.cpp console/console.cpp console/console.h Entity/Entity.cpp Entity/Entity.h Repo/Repo.cpp Repo/Repo.h Service/Service.cpp Service/Service.h Tests/tests.cpp Tests/tests.h)
