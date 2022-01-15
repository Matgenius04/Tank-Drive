#include "Robot.h"

#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit() {};

void Robot::RobotPeriodic() {
    frc2::CommandScheduler::GetInstance().Run();
};

void Robot::AutonomousInit() {
    autonomousCommand = container.GetAutonomousCommand();
    if (autonomousCommand != nullptr) {
        autonomousCommand -> Schedule();
    }
};
void Robot::AutonomousPeriodic() {};
void Robot::TeleopInit() {
    if (autonomousCommand != nullptr) {
        autonomousCommand -> Cancel();
        autonomousCommand = nullptr;
    }
};
void Robot::TeleopPeriodic() {};
void Robot::TestInit() {};
void Robot::TestPeriodic() {};

#ifndef RUNNING_FRC_TESTS
int main()
{
    return frc::StartRobot<Robot>();
}
#endif