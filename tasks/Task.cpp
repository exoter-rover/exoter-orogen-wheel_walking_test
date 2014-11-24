/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "Task.hpp"

using namespace wheel_walking_test;

Task::Task(std::string const& name)
    : TaskBase(name)
{
}

Task::Task(std::string const& name, RTT::ExecutionEngine* engine)
    : TaskBase(name, engine)
{
}

Task::~Task()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See Task.hpp for more detailed
// documentation about them.

bool Task::configureHook()
{
    if (! TaskBase::configureHook())
        return false;

    /** Read configuration **/
    canNodesNames = _canNodesNames.value();

    /** Initialize the joints variables **/
    joints_commands.resize(canNodesNames.size());
    joints_commands.names = canNodesNames;

    L=14.5;
    R=7.0;
    index=0;
    gait=1;
    loop=0;
    wheel_velocity_rad_s=3.14159/6.0;
    first_loop=true;
    return true;
}
bool Task::startHook()
{
    if (! TaskBase::startHook())
        return false;
    return true;
}
void Task::updateHook()
{
    TaskBase::updateHook();

    /** Reset joints commands **/
    for (size_t i=0; i<joints_commands.size(); ++i)
    {
        if (joints_commands[i].hasPosition())
            joints_commands[i].position = base::unset<double>();
        if (joints_commands[i].hasSpeed())
            joints_commands[i].speed = base::unset<float>();
        if (joints_commands[i].hasEffort())
            joints_commands[i].effort = base::unset<float>();
    }
    joints_commands.time = base::Time::now();


    if (gait==1){
    if (first_loop){
    switch(index)
    {
	case 1:
	    joints_commands[COMMAND_WHEEL_DRIVE_FL].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=-wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_FR].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=-wheel_velocity_rad_s*R/L;
	    break;
	case 2:
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_GROUP].speed=0;
	    break;
	case 3:
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_CL].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=-wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_CR].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=-wheel_velocity_rad_s*R/L;
	    break;
	case 4:
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_GROUP].speed=0;
	    break;
	case 5:
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_BL].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=-wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_BR].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=-wheel_velocity_rad_s*R/L;
	    break;
	case 6:
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_GROUP].speed=0;
	    break;
	case 7:
	    joints_commands[COMMAND_WHEEL_DRIVE_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_BR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=wheel_velocity_rad_s*R/L;
	    break;
	case 8:
	    break;
	case 9:
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=0;
	    first_loop=false;
            index=0;
	    break;
    }
    }else{
    switch(index)
    {
	case 1:
	    joints_commands[COMMAND_WHEEL_DRIVE_FL].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=-wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_FR].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=-wheel_velocity_rad_s*R/L;
	    break;
	case 2:
	    break;
	case 3:
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_GROUP].speed=0;
	    break;
	case 4:
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_CL].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=-wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_CR].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=-wheel_velocity_rad_s*R/L;
	    break;
	case 5:
	    break;
	case 6:
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_GROUP].speed=0;
	    break;
	case 7:
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_BL].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=-wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_BR].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=-wheel_velocity_rad_s*R/L;
	    break;
	case 8:
	    break;
	case 9:
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_GROUP].speed=0;
	    break;
	case 10:
	    joints_commands[COMMAND_WHEEL_DRIVE_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_BR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=wheel_velocity_rad_s*R/L;
	    break;
	case 11:
	    break;
	case 12:
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=0;
            index=0;
            loop++;
            if (loop==3){
                gait=2;
                loop=0;
            }
	    break;
    }
    }
_joints_commands.write(joints_commands);
}
if (gait==2){
    if (first_loop){
    switch(index)
    {
	case 1:
	    joints_commands[COMMAND_WHEEL_DRIVE_FL].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=-wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_CR].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=-wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_BL].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=-wheel_velocity_rad_s*R/L;
	    break;
	case 2: 
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_GROUP].speed=0;
	    break;
	case 3:
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_FR].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=-wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_CL].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=-wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_BR].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=-wheel_velocity_rad_s*R/L;
	    break;
	case 4:
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_GROUP].speed=0;
	    break;
	case 5:
	    joints_commands[COMMAND_WHEEL_DRIVE_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_BR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=wheel_velocity_rad_s*R/L;
	    break;
	case 6:
	    break;
	case 7:
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=0;
	    first_loop=false;
            index=0;
	    break;
    }
    }else
    {
    switch(index)
    {
	case 1:
	    joints_commands[COMMAND_WHEEL_DRIVE_FL].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=-wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_CR].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=-wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_BL].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=-wheel_velocity_rad_s*R/L;
	    break;
	case 2:
	    break;
	case 3: 
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_GROUP].speed=0;
	    break;
	case 4:
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_FR].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=-wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_CL].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=-wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_BR].speed=wheel_velocity_rad_s;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=-wheel_velocity_rad_s*R/L;
	    break;
	case 5:
	    break;
	case 6:
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=0;
	    joints_commands[COMMAND_WHEEL_DRIVE_GROUP].speed=0;
	    break;
	case 7:
	    joints_commands[COMMAND_WHEEL_DRIVE_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=wheel_velocity_rad_s*R/L;
	    joints_commands[COMMAND_WHEEL_DRIVE_BR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=wheel_velocity_rad_s*R/L;
	    break;
	case 8:
	    break;
	case 9:
	    joints_commands[COMMAND_WHEEL_WALK_FL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_FR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_CR].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BL].speed=0;
	    joints_commands[COMMAND_WHEEL_WALK_BR].speed=0;
	    first_loop=false;
            index=0;
	    loop++;
	    if (loop==3){
		gait=1;
                loop=0;
            }
	    break;
    }
    }
    _joints_commands.write(joints_commands);
}


}
void Task::errorHook()
{
    TaskBase::errorHook();
}
void Task::stopHook()
{
    TaskBase::stopHook();
}
void Task::cleanupHook()
{
    TaskBase::cleanupHook();
}
