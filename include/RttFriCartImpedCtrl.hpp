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

class RttFriCartImpedCtrl : public RTT::TaskContext{
public:
	RttFriCartImpedCtrl(std::string const& name);
	bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
private:

protected:

};
#endif // RTTFRICARTIMPEDCTRL_HPP
