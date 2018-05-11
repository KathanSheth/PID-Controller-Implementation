#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double K_p, double K_i, double K_d) {
	Kp = K_p;
	Ki = K_i;
	Kd = K_d;
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
	previous_in_d_error = 0.0;
	p_error_speed = 0.0;
	i_error_speed = 0.0;
	d_error_speed = 0.0;
	previous_in_d_error_speed = 0.0;
}
/*
void PID::twiddle(double tol,double cte){

	std::vector<double> dp;
	std::vector<double> K;
	double best_err = std::numeric_limits<double>::max()
	double err;
	dp << 1.0,1.0,1.0;
	K << Kp,Ki,Kd;
	double sum_of_elems = 0.0;
	std::for_each(vector.begin(), vector.end(), [&] (double n) {
    sum_of_elems += n;
	});
	while(sum_of_elems > tol){
		for(int i=0;i<3;++i){
			K[i] = dp[i];

			p_error = cte;

	
			i_error += cte;

			
			d_error = cte - previous_in_d_error;

			
			previous_in_d_error = cte;

			err = p_error * Kp + i_error * Ki + d_error * Kd;

			if (err < best_err){
				best_err = err;
				dp[i] *= 1.1;

			}
			else{
				K[i] -= 2*dp[i];
				p_error = cte;

	
			i_error += cte;

			
			d_error = cte - previous_in_d_error;

			
			previous_in_d_error = cte;

			err = p_error * Kp + i_error * Ki + d_error * Kd;

				if (err < best_err){
                    best_err = err;
                    dp[i] *= 1.1;
                }
                else{
                    K[i] += dp[i];
                    dp[i] *= 0.9; 
                }


			}



		}

	}

}
*/
void PID::UpdateError(double cte) {
	p_error = cte;

	std::cout << "Inside UpdateError p_error is:" << p_error << std::endl;

	i_error += cte;

	std::cout << "Inside UpdateError i_error is:" << i_error << std::endl;	

	d_error = cte - previous_in_d_error;

	std::cout << "Inside UpdateError d_error is:" << d_error << std::endl;

	std::cout << "Kp: " << Kp << " Ki: " << Ki << " Kd: " << Kd << std::endl;

	previous_in_d_error = cte;

	//return p_error * Kp + i_error * Ki + d_error * Kd;



}

double PID::UpdateError_speed(double cte) {
p_error_speed = cte;

std::cout << "Inside UpdateError p_error_speed is:" << p_error_speed << std::endl;

i_error_speed += cte;

//std::cout << "Inside UpdateError i_error is:" << i_error << std::endl;	

d_error_speed = cte - previous_in_d_error_speed;

std::cout << "Inside UpdateError d_error_speed is:" << d_error_speed << std::endl;

std::cout << "Kp Speed: " << Kp << " Ki Speed: " << Ki << " Kd Speed: " << Kd << std::endl;

previous_in_d_error_speed = cte;

return p_error_speed * Kp + d_error_speed * Kd + Ki * i_error_speed;



}


double PID::TotalError() {
		return p_error * Kp + i_error * Ki + d_error * Kd;
}

