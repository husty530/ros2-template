#ifndef CUSTOM_COMPONENT__VEHICLE_NODE_HPP_
#define CUSTOM_COMPONENT__VEHICLE_NODE_HPP_

#include <rclcpp/rclcpp.hpp>
#include "custom_msgs/msg/vehicle_status.hpp"
#include "custom_component/visibility_control.h"

namespace custom_component
{

class VehicleNode : public rclcpp::Node
{
private:
  rclcpp::Publisher<custom_msgs::msg::VehicleStatus>::SharedPtr pub_;
  rclcpp::Subscription<custom_msgs::msg::VehicleStatus>::SharedPtr sub_;
  rclcpp::TimerBase::SharedPtr timer_;
  float speed_;
  float steer_;
public:
  CUSTOM_COMPONENT_PUBLIC
  VehicleNode(
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  );
  CUSTOM_COMPONENT_PUBLIC
  VehicleNode(
    const std::string& name_space, 
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  );
};

}

#endif
