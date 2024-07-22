/*
 * SignalProcessing.h
 *
 *  Created on: Jul 19, 2024
 *      Author: wow
 */

#ifndef SIGNALPROCESSING_HPP_
#define SIGNALPROCESSING_HPP_

#include <vector>
#include <fftw3.h>
#include <functional>
#include <cmath>

/*using declaration*/
using std::vector;
using std::reference_wrapper;
/*end using declaration*/

class SignalProcessing {
public:
	SignalProcessing(vector<double>& in_signal);

	virtual void updata(vector<double> new_signal) = 0;
	virtual void run() = 0;
	virtual vector<double> get_data() const = 0;

	virtual ~SignalProcessing();

protected:
	vector<double> result;
	reference_wrapper< vector<double>> actual_signal;
	int size;
};

class FFT : public SignalProcessing
{
public:
	FFT(vector<double>& in_signal);

	void decide_spectral_dencity();

	virtual void updata(vector<double> new_signal);
	virtual vector<double> get_data() const ;
	virtual void run();/*todo:check this*/

	~FFT()
	{

	}

private:
	fftw_plan planFFT;

};



#endif /* SIGNALPROCESSING_HPP_ */
