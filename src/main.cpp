#include <math.h>
#include <uWS/uWS.h>

#include <iostream>
#include <string>

#include "nlohmann/json.hpp"
#include "pid_controller/pid_controller.hpp"
#include "udacity/uws.hpp"

// for convenience
using nlohmann::json;
using std::string;

int main()
{
  uWS::Hub h;

  pid_controller::PidController steer_pid;
  steer_pid.init(0.1, 0.0007, 1.0);

  h.onMessage(
    [&steer_pid](uWS::WebSocket<uWS::SERVER> ws, char * data, size_t length, uWS::OpCode opCode) {
      // "42" at the start of the message means there's a websocket message event.
      // The 4 signifies a websocket message
      // The 2 signifies a websocket event
      if (length && length > 2 && data[0] == '4' && data[1] == '2') {
        auto s = udacity::uws::has_data(string(data).substr(0, length));

        if (s != "") {
          auto j = json::parse(s);

          string event = j[0].get<string>();

          if (event == "telemetry") {
            // j[1] is the data JSON object
            double cte = std::stod(j[1]["cte"].get<string>());
            double speed = std::stod(j[1]["speed"].get<string>());
            double angle = std::stod(j[1]["steering_angle"].get<string>());
            steer_pid.update_error(cte);
            double steer_value = steer_pid.total_error();

            // DEBUG
            std::cout << "CTE: " << cte << " Steering Value: " << steer_value << std::endl;

            json msgJson;
            msgJson["steering_angle"] = steer_value;
            msgJson["throttle"] = 0.3;
            auto msg = "42[\"steer\"," + msgJson.dump() + "]";
            std::cout << msg << std::endl;
            ws.send(msg.data(), msg.length(), uWS::OpCode::TEXT);
          }  // end "telemetry" if
        } else {
          // Manual driving
          string msg = "42[\"manual\",{}]";
          ws.send(msg.data(), msg.length(), uWS::OpCode::TEXT);
        }
      }  // end websocket message if
    });  // end h.onMessage

  h.onConnection([&h](uWS::WebSocket<uWS::SERVER> ws, uWS::HttpRequest req) {
    std::cout << "Connected!!!" << std::endl;
  });

  h.onDisconnection([&h](uWS::WebSocket<uWS::SERVER> ws, int code, char * message, size_t length) {
    ws.close();
    std::cout << "Disconnected" << std::endl;
  });

  int port = 4567;
  if (h.listen(port)) {
    std::cout << "Listening to port " << port << std::endl;
  } else {
    std::cerr << "Failed to listen to port" << std::endl;
    return -1;
  }

  h.run();
}
