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
/*
double PID::UpdateError_speed(double cte) {
p_error_speed = cte;

std::cout << "Inside UpdateError p_error_speed is:" << p_error_speed << std::endl;

i_error_speed += cte;

//std::cout << "Inside UpdateError i_error is:" << i_error << std::endl;	

d_error_speed = cte - previous_in_d_error_speed;

std::cout << "Inside UpdateError d_error_speed is:" << d_error_speed << std::endl;

//std::cout << "Kp: " << Kp << " Ki: " << Ki << " Kd: " << Kd << std::endl;

previous_in_d_error_speed = cte;

return p_error_speed * Kp + d_error_speed * Kd + Ki * i_error_speed;



}*/


double PID::TotalError() {
		return p_error * Kp + i_error * Ki + d_error * Kd;
}

