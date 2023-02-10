#ifndef PID_CONTROLLER__PID_CONTROLLER_HPP
#define PID_CONTROLLER__PID_CONTROLLER_HPP

namespace pid_controller
{

class PidController
{
public:
  PidController();
  virtual ~PidController();

  void init(double Kp, double Ki, double Kd);
  void update_error(double cte);
  double total_error();

private:
  double Kp_;
  double Ki_;
  double Kd_;

  double p_error_;
  double i_error_;
  double d_error_;
};

}  // namespace pid_controller

#endif  // PID_CONTROLLER__PID_CONTROLLER_HPP
