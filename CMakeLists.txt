cmake_minimum_required(VERSION 3.0)

set(project_name "ambimorse")
project(${project_name})

set(project_inc
   "include/ambimorse.h"
   "include/morse.h"
)

set(project_src
   "src/morse.c"
   "src/ambimorse.c"
   "src/main.c"
)

add_executable(${project_name}
   ${project_inc}
   ${project_src}
)

target_include_directories(${project_name}
   PUBLIC "include/"
)
