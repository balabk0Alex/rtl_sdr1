
#include "SignalProcessing.hpp"
#include "RtlSdr.hpp"
#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	uint32_t size_b = 512, frec;

	std::cout << "Enter frequency:";std::cin >> frec;
	std::cout << std::endl;
	set_radio init_struct =
	{
			frec,/*frequency*/
			30,/*gain*/
			DEFAULT_SAMPLE_RATE,/*samp_rate*/
			0,/*ppm_error*/
			0,/*direct_sampling*/
			size_b /*out_block_size*/
	};

	RtlSdr device(&init_struct);

	std::vector<double> my_data1 = device.sync_read_in_vector();

	FFT process(my_data1);
	process.run();
	process.decide_spectral_dencity();

	std::vector<double> result = process.get_data();


	 std::ofstream file;
	 file.open("spectr",std::ios::binary |std::ios::out| std::ios::trunc);
	 if(!file.is_open())
	 {
			std::cout << "File don't open!" << std::endl;
	 	exit(1);
	 }

	 file.write((char *) result.data(),(int)size_b * sizeof(double));
	 file.close();

	 std::cout << "end";
}

