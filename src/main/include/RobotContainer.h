#pragma once

#include <frc/Joystick.h>
#include <frc2/command/Command.h>

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"

class RobotContainer 
{
    public:
        RobotContainer();

        frc2::Command* GetAutonomousCommand();
    private:
        frc::Joystick rightJoystick {IOConstants::rightJoystickId};
        frc::Joystick leftJoystick {IOConstants::leftJoystickId};

        DriveSubsystem drive;
};