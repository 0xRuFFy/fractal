cmake_minimum_required(VERSION 3.12)

project(fractal VERSION 0.0.1 LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 11)

# Add header files
file(GLOB_RECURSE HEADER_FILES "include/*.h" "src/*.h")
include_directories(include)

# Add source files
file(GLOB_RECURSE SOURCE_FILES "src/*.c")

# Add clang-format target
#find_program(CLANG_FORMAT "clang-format")
#if(CLANG_FORMAT)
#	add_custom_target(
#		fmt
#		COMMAND ${CLANG_FORMAT}
#		-i
#		-style=file
#		${SOURCE_FILES}
#		${HEADER_FILES}
#	)
#endif()

find_program(CLANG_TIDY "clang-tidy")
if(CLANG_TIDY)
	add_custom_target(
		tidy
		COMMAND ${CLANG_TIDY}
		-config=''
		--
		-std=c11
		${SOURCE_FILES}
		${HEADER_FILES}
	)
endif()

# Create executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
