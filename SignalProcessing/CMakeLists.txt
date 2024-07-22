link_directories(${CMAKE_SOURCE_DIR}/libs)


set(HEADER_FILE
SignalProcessing.hpp
    )
set(PROJECT_SOURCES
SignalProcessing.cpp
)

#find_library(EXTERNAL_LIB NAMES fftw3 PATHS /usr/lib)

#if(NOT EXTERNAL_LIB)
#    message(FATAL_ERROR "External library not found")
#3endif()



add_library(SignalProcessinglib SHARED ${HEADER_FILE} ${PROJECT_SOURCES})
target_link_libraries(SignalProcessinglib PRIVATE fftw3)



