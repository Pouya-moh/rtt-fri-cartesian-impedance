/*
 * Author:  Pouya Mohammadi
 * Date:    August 25, 2017
 * License: 
 * Description: 
 * 
 */

#ifndef RTTFRICARTIMPEDCTRL_HPP
#define RTTFRICARTIMPEDCTRL_HPP

#include <rtt/RTT.hpp>
#include <rst-rt/geometry/Pose.hpp>
#include <rst-rt/dynamics/JointImpedance.hpp>
#include <rst-rt/dynamics/JointTorques.hpp>
#include <rst-rt/kinematics/JointAngles.hpp>
#include "friremote_rt.h"

#define DOF_SIZE 7

class RttFriCartImpedCtrl : public RTT::TaskContext{
public:
	RttFriCartImpedCtrl(std::string const& name);
	bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();



private:
    friRemote _fri;
    std::string _host_ip, _server_ip;
    int _port;

    // input ports
    RTT::InputPort<rstrt::geometry::Pose> cartesian_pose_in_port;
    RTT::FlowStatus cartesian_pose_in_flow;
    rstrt::geometry::Pose cartesian_pose_in_data;

    RTT::InputPort<rstrt::dynamics::JointImpedance> stiff_damp_in_port;
    RTT::FlowStatus stiff_damp_in_flow;
    rstrt::dynamics::JointImpedance stiff_damp_in_data;

    RTT::InputPort<rstrt::dynamics::JointTorques> added_torques_in_port;
    RTT::FlowStatus added_torques_in_flow;
    rstrt::dynamics::JointTorques added_torques_in_data;

    RTT::InputPort<rstrt::kinematics::JointAngles> redundancy_resolution_in_port;
    RTT::FlowStatus redundancy_resolution_in_flow;
    rstrt::kinematics::JointAngles redundancy_resolution_in_data;

    // output ports
    RTT::OutputPort<rstrt::geometry::Pose> cartesian_pose_out_port;
    rstrt::geometry::Pose cartesian_pose_out_data;
    // maybe add stiffness and damping
    // deffinitly add the currenc conf and currecnt torques


    void initPorts();
    void sense();
    rstrt::geometry::Translation _ee_position;
    rstrt::geometry::Rotation _ee_orientation;
protected:

};
#endif // RTTFRICARTIMPEDCTRL_HPP
