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

}

bool RttFriCartImpedCtrl::configureHook(){

	return true;
}

bool RttFriCartImpedCtrl::startHook(){

	return true;
}

void RttFriCartImpedCtrl::updateHook(){

}

void RttFriCartImpedCtrl::stopHook() {

}

void RttFriCartImpedCtrl::cleanupHook() {

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