cmake_minimum_required(VERSION 3.8)
project(proc_la)

set(CMAKE_C_STANDARD 99)

include_directories(platform dybuf ast_obj)

add_custom_command(OUTPUT proc.la.y.c
        PRE_BUILD
        COMMAND bison -r all -g -o proc.la.y.c proc.la.y
        DEPENDS proc.la.y
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "bison generate proc.la.y.c" )

add_custom_command(OUTPUT proc.la.l.c
        PRE_BUILD
        COMMAND flex -o proc.la.l.c proc.la.l
        DEPENDS proc.la.l
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "flex generate proc.la.l.c" )

add_custom_target(RunGenerator DEPENDS proc.la.l.c proc.la.y.c
        COMMENT "flex & bison")

set(SOURCE_FILES main.c platform ast_obj ast.c platform/mmo_pack.c platform/mmo_unittest.c)

add_executable(proc_la ${SOURCE_FILES})
add_dependencies(proc_la RunGenerator)