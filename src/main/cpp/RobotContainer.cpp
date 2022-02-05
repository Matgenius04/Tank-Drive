#include "RobotContainer.h"

#include <frc2/command/InstantCommand.h>
#include <frc2/command/RunCommand.h>

RobotContainer::RobotContainer() 
{
    drive.SetDefaultCommand(frc2::RunCommand(
        [this] {
            drive.Drive(
                pow(rightJoystick.GetX(), 3) * 0.5,
                leftJoystick.GetY() / 5.0,
                DriveType::Curvature // can also switch to arcade
            );
        }, 
        {&drive}
    ));
};

frc2::Command* RobotContainer::GetAutonomousCommand() 
{
    return new frc2::InstantCommand(
        [this] {
            drive.Drive(0,0,DriveType::Arcade);
        },
        {&drive}
    );
}

