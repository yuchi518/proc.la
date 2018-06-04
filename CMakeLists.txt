cmake_minimum_required(VERSION 3.8)
project(proc_la)

set(CMAKE_C_STANDARD 99)

include_directories(. platform dybuf mmo ast_obj)

set(AUTO_GEN_DIR ${CMAKE_SOURCE_DIR}/autogen)

add_custom_command(OUTPUT ${AUTO_GEN_DIR}/proc.la.y.c
        PRE_BUILD
        COMMAND bison #[[-r all -g]] -o ${AUTO_GEN_DIR}/proc.la.y.c proc.la.y
        DEPENDS proc.la.y
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "bison generate proc.la.y.c" )

add_custom_command(OUTPUT ${AUTO_GEN_DIR}/proc.la.l.c
        PRE_BUILD
        COMMAND flex -o ${AUTO_GEN_DIR}/proc.la.l.c proc.la.l
        DEPENDS proc.la.l
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "flex generate proc.la.l.c" )

add_custom_target(RunGenerator DEPENDS ${AUTO_GEN_DIR}/proc.la.l.c ${AUTO_GEN_DIR}/proc.la.y.c
        COMMENT "flex & bison")

set(SOURCE_FILES main.c platform ast_obj ast_obj/ast_optimization.c ast.c mmo/mmo_pack.c mmo/mmo_unittest.c)

add_executable(proc_la ${SOURCE_FILES})
add_dependencies(proc_la RunGenerator)