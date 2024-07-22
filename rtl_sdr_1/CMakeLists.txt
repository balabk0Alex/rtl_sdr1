
include_directories(../RtlSdr)

include_directories(../SignalProcessing)

add_executable(rtl_sdr_1 main.cpp)


target_link_libraries(rtl_sdr_1 RtlSdrlib SignalProcessinglib)
