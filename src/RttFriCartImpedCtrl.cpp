/*
 * Author:  Pouya Mohammadi
 * Date:    August 25, 2017
 * License: 
 * Description: 
 * 
 */

#include "RttFriCartImpedCtrl.hpp"
#include <rtt/Component.hpp>

RttFriCartImpedCtrl::RttFriCartImpedCtrl(std::string const& name) : TaskContext(name){    
    _server_ip = "192.168.0.200";
    addProperty("server_ip", _server_ip).doc("IP of this machine");

    _host_ip = "192.168.0.21";
    addProperty("host_ip", _host_ip).doc("IP of robot");

    _port = 49938;
    addProperty("port", _port).doc("server port");

    initPorts();
}

void RttFriCartImpedCtrl::initPorts(){
    cartesian_pose_in_flow = RTT::NoData;
    cartesian_pose_in_port.setName("des_cart_pose");
    cartesian_pose_in_data = rstrt::geometry::Pose(0,0,0,1,0,0,0);
    ports()->addPort(cartesian_pose_in_port);

    stiff_damp_in_flow = RTT::NoData;
    stiff_damp_in_port.setName("des_stiff_damp");
    stiff_damp_in_data = rstrt::dynamics::JointImpedance(DOF_SIZE);
    ports()->addPort(stiff_damp_in_port);

    added_torques_in_flow = RTT::NoData;
    added_torques_in_port.setName("des_added_torques");
    added_torques_in_data = rstrt::dynamics::JointTorques(DOF_SIZE);
    ports()->addPort(added_torques_in_port);

    redundancy_resolution_in_flow = RTT::NoData;
    redundancy_resolution_in_port.setName("des_null_space");
    redundancy_resolution_in_data = rstrt::kinematics::JointAngles(DOF_SIZE);
    ports()->addPort(redundancy_resolution_in_port);
}

bool RttFriCartImpedCtrl::configureHook(){    
    // TODO check the fourth argument here
    _fri = friRemote(_port, _host_ip.c_str(), _server_ip.c_str(), this->getActivity()->thread()->getTask());
    // TODO make a sense of this:
    char str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(_fri.remote.krcAddr.sin_addr), str, INET_ADDRSTRLEN);
    RTT::log(RTT::Info) << "Opening FRI Version "
                        << FRI_MAJOR_VERSION << "."
                        << FRI_SUB_VERSION << "."
                        << FRI_DATAGRAM_ID_CMD << "."
                        << FRI_DATAGRAM_ID_MSR
                        << " Interface for LWR ROS server"
                        << RTT::endlog();
    RTT::log(RTT::Info) << "Checking if the robot is Stopped..." << RTT::endlog();
    if( this->_fri_inst->getState() == FRI_STATE_OFF ){
         RTT::log(RTT::Info) << "Please, start the KRL script now." << RTT::endlog();
    }
	return true;
}

bool RttFriCartImpedCtrl::startHook(){

	return true;
}

void RttFriCartImpedCtrl::updateHook(){
    sense();
}

void RttFriCartImpedCtrl::stopHook() {

}

void RttFriCartImpedCtrl::cleanupHook() {

}

void RttFriCartImpedCtrl::sense(){
    
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(RttFriCartImpedCtrl)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(RttFriCartImpedCtrl)
