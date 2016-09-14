cmake_minimum_required(VERSION 2.8)
project( testServer )
find_package( OpenCV REQUIRED )
add_executable( startServer server.cpp )
