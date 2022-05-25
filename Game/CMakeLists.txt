set(HEADER_FILES
	Entity.h
	Character.h
	GameApp.h
	Projectile.h
)

set(SOURCE_FILES
	Entity.cpp
	Character.cpp
	GameApp.cpp
	main.cpp
	projectile.cpp
)

add_executable(Game ${HEADER_FILES} ${SOURCE_FILES})

include_directories(../Peng)

target_link_libraries(Game Peng)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Game)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)