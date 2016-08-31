cmake_minimum_required(VERSION 2.8)
project( testClient )
find_package( OpenCV REQUIRED )
add_executable( startClient clientTest.c )
