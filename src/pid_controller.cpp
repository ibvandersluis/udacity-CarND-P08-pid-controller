#include "pid_controller/pid_controller.hpp"

namespace pid_controller
{

// TODO: Complete the PID class. You may add any additional desired functions.

PidController::PidController() {}

PidController::~PidController() {}

void PidController::init(double Kp, double Ki, double Kd)
{
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;

  p_error_ = 0.0;
  i_error_ = 0.0;
  d_error_ = 0.0;
}

void PidController::update_error(double cte)
{
  d_error_ = cte - p_error_;
  p_error_ = cte;
  i_error_ += cte;
}

double PidController::total_error() { return -Kp_ * p_error_ - Ki_ * i_error_ - Kd_ * d_error_; }

}  // namespace pid_controller
