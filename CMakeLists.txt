cmake_minimum_required(VERSION 3.10.0)
project(laba2 VERSION 0.1.0 LANGUAGES C CXX)

# Указываем где искать заголовочные файлы для этого таргета
include_directories(headers)
include_directories(sources)

# Явно перечисляем исходные файлы
set(SRC
    main.cpp
    sources/Note.cpp
    sources/NoteList.cpp
)

add_executable(${PROJECT_NAME} ${SRC})

# Добавляем заголовочные файлы
set(HEADERS
    headers/Note.h
    headers/NoteList.h
)

# Связываем заголовки с исполняемым файлом (для IDE)
target_sources(${PROJECT_NAME} PRIVATE ${HEADERS})