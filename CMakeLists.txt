cmake_minimum_required(VERSION 3.8)
project(proc_la)

set(CMAKE_C_STANDARD 99)

include_directories(. clibs/platform clibs/dybuf clibs/mmo ast_obj)

set(AUTO_GEN_DIR ${CMAKE_SOURCE_DIR}/autogen)

add_custom_command(OUTPUT ${AUTO_GEN_DIR}/proc.la.y.c
        PRE_BUILD
        COMMAND bison #[[-r all -g]] -v -o ${AUTO_GEN_DIR}/proc.la.y.c proc.la.y
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

set(SOURCE_FILES clibs/platform clibs/dybuf clibs/mmo clibs/mmo/mmo_pack.c clibs/mmo/mmo_unittest.c ast_obj ast_obj/ast_optimization.c ast.c main.c )

add_executable(proc_la ${SOURCE_FILES})
add_dependencies(proc_la RunGenerator)