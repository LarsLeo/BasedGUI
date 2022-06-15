if(MSVC AND NOT "${MSVC_VERSION}" LESS 1400)
	add_definitions( "/MP" )
endif()

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

### GLFW ###
add_subdirectory (${GLFW_LIB})

include_directories(
	${GLFW_LIB}/include/GLFW/
	${GLEW_LIB}/include/
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set(OPENGL_LIBRARY
	${OPENGL_LIBRARY}
	-lGL -lGLU -lXrandr -lXext -lX11 -lrt
	${CMAKE_DL_LIBS}
	${GLFW_LIBRARIES}
)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
set(OPENGL_LIBRARY
	${OPENGL_LIBRARY}
	${CMAKE_DL_LIBS}
	${GLFW_LIBRARIES}
)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

### GLEW ###
set(GLEW_SOURCE
	${GLEW_LIB}/src/glew.c
)

set(GLEW_HEADERS
)

add_library( GLEW_210 STATIC
	${GLEW_SOURCE}
	${GLEW_INCLUDE}
)

target_link_libraries(GLEW_210
	${OPENGL_LIBRARY}
	${EXTRA_LIBS}
)

### ASSIMP ###
include(CheckIncludeFile)
include(CheckTypeSize)
include(CheckFunctionExists)
add_subdirectory( ${ASSIMP_LIB}/contrib/zlib )

set(ZLIB_LIBRARIES zlibstatic)
set(ENABLE_BOOST_WORKAROUND ON)
set(BUILD_STATIC_LIB ON)
set(BUILD_ASSIMP_TOOLS  ON)
set(ASSIMP_BUILD_STATIC_LIB ON)

add_subdirectory( ${ASSIMP_LIB} )

### BULLET ###
include_directories(
	${BULLET_LIB}/src
)
add_subdirectory( ${BULLET_LIB}/src/BulletSoftBody )
add_subdirectory( ${BULLET_LIB}/src/BulletCollision )
add_subdirectory( ${BULLET_LIB}/src/BulletDynamics )
add_subdirectory( ${BULLET_LIB}/src/LinearMath )
