#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double previous_in_d_error;
  double p_error_speed;
  double i_error_speed;
  double d_error_speed;
  double previous_in_d_error_speed;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  double UpdateError_speed(double cte);

  /*
  * Calculate the total PID error.
  */

  double TotalError();
};

#endif /* PID_H */
