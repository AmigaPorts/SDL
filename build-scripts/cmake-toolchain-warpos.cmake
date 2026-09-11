set(CMAKE_SYSTEM_NAME WarpOS)
set(CMAKE_SYSTEM_PROCESSOR ppc)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../cmake;${CMAKE_MODULE_PATH}")

find_program(CMAKE_C_COMPILER NAMES ppc-morphos-gcc-9.2.0 ppc-morphos-gcc
  HINTS "$ENV{AMIGA_TOOLCHAIN_BIN}" /opt/ppc-morphos/bin)
find_program(CMAKE_AR NAMES ppc-morphos-ar
  HINTS "$ENV{AMIGA_TOOLCHAIN_BIN}" /opt/ppc-morphos/bin)
find_program(CMAKE_RANLIB NAMES ppc-morphos-ranlib ppc-morphos-gcc-ranlib
  HINTS "$ENV{AMIGA_TOOLCHAIN_BIN}" /opt/ppc-morphos/bin)
find_program(CMAKE_STRIP NAMES ppc-morphos-strip
  HINTS "$ENV{AMIGA_TOOLCHAIN_BIN}" /opt/ppc-morphos/bin)

if(NOT CMAKE_C_COMPILER)
  message(FATAL_ERROR "Failed to find a ppc-morphos-gcc compiler")
endif()

set(WARPUP TRUE CACHE BOOL "Build the AmigaOS 3 WarpOS target")
set(CMAKE_C_FLAGS_INIT "--specs=warpup -mcpu=603e -noixemul -mhard-float -ffast-math")
set(CMAKE_EXE_LINKER_FLAGS_INIT "--specs=warpup -mcpu=603e -noixemul -mhard-float")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
