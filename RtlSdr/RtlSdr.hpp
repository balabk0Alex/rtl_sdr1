#ifndef RTLSDR_HPP
#define RTLSDR_HPP

#include <iostream>
#include <fstream>
#include <vector>

#include <signal.h>
#include "include/rtl-sdr.h"
#include "include/convenience.h"
#include <cmath>


#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "getopt/getopt.h"
#endif

#define DEFAULT_SAMPLE_RATE		2048000
#define DEFAULT_BUF_LENGTH		(16 * 16384)
#define MINIMAL_BUF_LENGTH		512
#define MAXIMAL_BUF_LENGTH		(256 * 16384)






struct set_radio
{
    uint32_t frequency;
    int gain;
    uint32_t samp_rate;
    int ppm_error;
    bool direct_sampling ;
    uint32_t out_block_size;
};

class RtlSdr
{
public:
    RtlSdr(set_radio * init);/*fix ptr*/
    ~RtlSdr();

   // void sync_read_in_file(const char * namefile, int bytes_to_read);
    std::vector<double> sync_read_in_vector();

private:
    void convert_to_real_value(std::vector<double> & out_signal, uint8_t * data, int size);

    uint8_t * buffer;/*fix ptr*/
    rtlsdr_dev_t *dev;/*fix ptr*/

    std::vector<double> CONVERT_SIGNAL_ADC;

    uint32_t frequency;
    int gain;
    uint32_t samp_rate;
    int ppm_error;
    bool direct_sampling ;
    uint32_t out_block_size;
};

#endif // RTLSDR_HPP
