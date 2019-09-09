#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  // init coefficients
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  // init errors
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;  

  // Previous cross track error.
  prev_cte = 0.0;

  // Counters.
  counter = 0;
  int_cte = 0.0;
  minError = 9999999999999999;
  maxError = -999999999999999;  
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  // Proportional error.
  p_error = cte;

  // Integral error.
  i_error += cte;

  // Diferential error.
  d_error = cte - prev_cte;
  prev_cte = cte;

  int_cte += cte;
  counter++;

  if ( cte > maxError ) {
    maxError = cte;
  }
  if ( cte < minError ) {
    minError = cte;
  }
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  // steer = -tau_p * cte - tau_d * diff_cte - tau_i * int_cte
  double p_err = p_error * Kp ;
  double i_err = i_error * Ki ;
  double d_err = d_error * Kd;
  
  return -1*(p_err + i_err + d_err); 
}