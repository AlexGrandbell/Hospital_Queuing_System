cmake_minimum_required(VERSION 3.25)
project(Hospital_Queuing_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hospital_Queuing_System Main.cpp Exception.h Tool.h Tool.cpp Patient.cpp Patient.h Record.cpp Record.h SqQueue.h LinkQueue.h QueueSystem.cpp QueueSystem.h)
