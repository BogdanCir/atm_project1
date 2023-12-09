cmake_minimum_required(VERSION 3.24)
project(Lab9)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab9 main.cpp Entitate.h EntitateRepository.h Tests.h EntitateService.h UI.h FileEntitateRepository.h DublareEntitateException.h Validator.h CodEntitateException.h)
