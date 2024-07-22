

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/libs)


set(HEADER_FILE

    include/convenience.h
    include/reg_field.h
    include/rtl-sdr_export.h
    include/rtl-sdr.h
    include/rtlsdr_i2c.h
    include/tuner_e4k.h
    include/tuner_fc0012.h
    include/tuner_fc0013.h
    include/tuner_fc2580.h
    include/tuner_r82xx.h
    RtlSdr.hpp

    )
set(PROJECT_SOURCES
    RtlCSourse/convenience.c
    RtlCSourse/librtlsdr.c
    RtlCSourse/tuner_e4k.c
    RtlCSourse/tuner_fc0012.c
    RtlCSourse/tuner_fc0013.c
    RtlCSourse/tuner_fc2580.c
    RtlCSourse/tuner_r82xx.c
    RtlSdr.cpp
)


add_library(RtlSdrlib SHARED ${HEADER_FILE} ${PROJECT_SOURCES})

target_link_libraries(RtlSdrlib PRIVATE usb-1.0)
