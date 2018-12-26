cmake_minimum_required(VERSION 3.10)
project(czz_serv)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/include/libxml2)

#link_libraries(/usr/lib/x86_64-linux-gnu/libxml2.a)

add_executable(czz_serv main.cpp prxml.cpp thpool.cpp tcpserv.cpp userdeal.cpp protocol.cpp prmysql.cpp prmysql.h)

link_directories(/usr/lib/x86_64-linux-gnu/)

target_link_libraries(czz_serv libxml2.so pthread mysqlclient)