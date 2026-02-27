cmake_minimum_required(VERSION 3.16)
project(kernel C ASM)

set(CMAKE_C_STANDARD 11)

# Tell CMake we are NOT building a hosted program
set(CMAKE_C_FLAGS
        "-ffreestanding -fno-stack-protector -fno-pic -m32 -Wall -Wextra"
)

set(CMAKE_ASM_FLAGS "-m32")

set(CMAKE_EXE_LINKER_FLAGS
        "-T ${CMAKE_SOURCE_DIR}/linker.ld -nostdlib -Wl,-m,elf_i386"
)

add_executable(kernel.elf
        boot.s
        kernel.c
        screen.c
        utils.c
)

# Make sure the linker script is considered a dependency
set_target_properties(kernel.elf PROPERTIES
        LINK_DEPENDS ${CMAKE_SOURCE_DIR}/linker.ld
)
