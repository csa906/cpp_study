cmake_minimum_required(VERSION 3.0.0) # 최소요구버전
project(test_cmake VERSION 0.1.0) # PROJECT_NAME 과 PROJECT_VERSION
set(This UnitTester) # 빌드 타겟
set(SrcLib SrcLib) # cpp/src 라이브러리

# CTest 지원
enable_testing() # CTest 지원

# cpp/src 라이브러리 빌드
set(SrcFiles 
    cpp/src/Plus.cpp
    cpp/src/Minus.cpp
)
add_library(${SrcLib} STATIC ${SrcFiles})

# googletest 빌드
add_subdirectory(googletest-1.14.0)

# test 폴더 하위 테스트케이스 빌드
set(TestFiles
    test/TestPlus.cpp
    test/TestMinus.cpp
)

# 실행파일 구성
add_executable(${This} ${TestFiles}) 

# googletest와 SrcLib 포함
target_link_libraries(${This} 
    gtest_main 
    ${SrcLib}
)