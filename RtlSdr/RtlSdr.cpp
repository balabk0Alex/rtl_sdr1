#include "RtlSdr.hpp"



RtlSdr::RtlSdr(set_radio * init):buffer(NULL), dev(NULL)
{
	int r;
	for (unsigned int i = 0; i < 0x100; i++)
		CONVERT_SIGNAL_ADC.push_back( (i - 127.4f) / 128.0f);

	direct_sampling = init->direct_sampling;
	samp_rate = init->samp_rate;
	frequency = init->frequency;
	gain = init->gain * 10;
	ppm_error = init->ppm_error;
	out_block_size = init->out_block_size * 2;

    r = rtlsdr_open(&dev, 0);
    if (r < 0 ) {
        std::cout << "Failed to open rtlsdr device #%d.\n";
        exit(1);
    }

    if (direct_sampling)
        verbose_direct_sampling(dev, 2);

    verbose_set_sample_rate(dev, samp_rate);

    verbose_set_frequency(dev, frequency);

    if (0 == gain) {
         /* Enable automatic gain */
        verbose_auto_gain(dev);
    } else {
        /* Enable manual gain */
    	gain= nearest_gain(dev, gain);
        verbose_gain_set(dev, gain);
    }

    verbose_ppm_set(dev, ppm_error);

    buffer = new uint8_t [out_block_size];
    if(buffer == NULL)
    {
    	std::cout << "Error memory" << std::endl;
    	exit(1);
    }
    std::cout << "Device activate" << std::endl;
    verbose_reset_buffer(dev);
}


//void RtlSdr::sync_read_in_file(const char * namefile, int bytes_to_read)
//{
//	bytes_to_read *= 2;
//	std::ofstream file;
//	file.open(namefile,std::ios::binary |std::ios::out| std::ios::trunc);
//	if(!file.is_open())
//	{
//		std::cout << "File don't open!" << std::endl;
//		exit(1);
//}
	//int r;
	//int counter = 0, n_read;/*todo:type*/
/*

	while(counter < bytes_to_read)
	{
		r = rtlsdr_read_sync(dev, buffer, out_block_size,&n_read);
		if(r < 0)
		{
			std::cout << "WARNING: sync read failed.\n";
			exit(1);
		}
		counter += n_read;
		convert_to_real_value(buffer, n_read);

		file.write((char *)in_file.data(),n_read * sizeof(float));
	}

	std::cout << "RECORD IN FILE : COMPLETE" << std::endl;

	file.close();
}
*/

std::vector<double> RtlSdr::sync_read_in_vector()
{
	std::vector<double> out_signal;
	int r, n_read;
	r = rtlsdr_read_sync(dev, buffer, out_block_size,&n_read);
	if(r < 0)
	{
		std::cout << "WARNING: sync read failed.\n";
		exit(1);
	}

	convert_to_real_value(out_signal,buffer, n_read);

	std::cout << "RECORD IN VECTOR : COMPLETE" << std::endl;
	return out_signal;
}


void RtlSdr::convert_to_real_value(std::vector<double> & out_signal, uint8_t * data, int size)
{

	for(int i = 0; i < size; ++i)
		out_signal.push_back(CONVERT_SIGNAL_ADC[data[i]]);

}

RtlSdr::~RtlSdr()
{
	delete [] buffer;
    rtlsdr_close(dev);
}

