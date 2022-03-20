add_library(Peng SHARED Peng.h PengApp.h PengUtil.h PengApp.cpp)

add_definitions(-DPENG_LIB)
add_definitions(-DPENG_DEBUG)

target_precompile_headers(Peng PRIVATE pch.h)