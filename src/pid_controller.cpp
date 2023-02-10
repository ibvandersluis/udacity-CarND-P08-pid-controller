#include "pid_controller/pid_controller.hpp"

namespace pid_controller
{

  /**
   * TODO: Complete the PID class. You may add any additional desired functions.
   */

  PidController::PidController() {}

  PidController::~PidController() {}

  void PidController::Init(double Kp_, double Ki_, double Kd_)
  {
    /**
     * TODO: Initialize PID coefficients (and errors, if needed)
     */
  }

  void PidController::UpdateError(double cte)
  {
    /**
     * TODO: Update PID errors based on cte.
     */
  }

  double PidController::TotalError()
  {
    /**
     * TODO: Calculate and return the total error
     */
    return 0.0; // TODO: Add your total error calc here!
  }

}
