/*
 * SignalProcessing.cpp
 *
 *  Created on: Jul 19, 2024
 *      Author: wow
 */

#include "SignalProcessing.hpp"


SignalProcessing::SignalProcessing(vector<double>& in_signal):actual_signal(in_signal), size(in_signal.size())
{
}

SignalProcessing::~SignalProcessing()
{

}

FFT::FFT(vector<double>& in_signal):SignalProcessing(in_signal)
{
	result.resize(size);/*todo:check*/
	size = size / 2;

	run();
}

void FFT::run()
{
	double (*in)[2] = reinterpret_cast<double (*)[2]>( actual_signal.get().data());
	double (*out)[2] = reinterpret_cast<double (*)[2]>( result.data());

	planFFT = fftw_plan_dft_1d(size,in, out, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(planFFT);
}


void FFT::decide_spectral_dencity()
{
	/*norm*/
	vector<double> tmp_v;

	double size2_lg = log10f(1.0/(size*size));
	for(int i = 0 ,full_size = 2 * size; i < full_size; i +=2 )
		tmp_v.push_back(10.0 * ( size2_lg + 1.0*log10f(1.0*result[i]*result[i] + 1.0*result[i+ 1] * result[i + 1]))) ;
	result = tmp_v;/*todo:check speed*/

	/*FFT shift*/

	int d_lenpos = size / 2  + size % 2;
	int d_lenneg = size / 2;
	std::vector<double> buff_shift(d_lenpos);


	std::copy(result.begin(), result.begin() + d_lenpos, buff_shift.begin());
	std::copy(result.begin() + d_lenpos, result.end(), result.begin());
	std::copy(buff_shift.begin(), buff_shift.end(), result.begin() + d_lenneg);

}

void FFT::updata(vector<double> new_signal)
{
	actual_signal = new_signal;
	size = new_signal.size() / 2;

	fftw_destroy_plan(planFFT);
	result.clear();

	run();
}
vector<double> FFT::get_data() const
{
	return result;/*todo: maybe link?*/
}

