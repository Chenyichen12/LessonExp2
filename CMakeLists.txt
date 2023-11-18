cmake_minimum_required(VERSION 3.26)
project(LessonExp2)

set(CMAKE_CXX_STANDARD 17)
add_executable(LessonExp2 main.cpp
        GuessGame.cpp
        AutoPaper.cpp
        MoveNumber.cpp
        MoveBlackAndWhite.cpp
        ReadFile.cpp
)
file(COPY file.txt DESTINATION ${CMAKE_BINARY_DIR})

