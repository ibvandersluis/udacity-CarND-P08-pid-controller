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
}

void PidController::update_error(double cte)
{
  // TODO: Update PID errors based on cte.
}

double PidController::total_error()
{
  // TODO: Calculate and return the total error
  return 0.0;  // TODO: Add your total error calc here!
}

}  // namespace pid_controller
