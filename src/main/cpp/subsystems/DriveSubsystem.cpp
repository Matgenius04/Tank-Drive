#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() 
{
    rearRightMotor.Follow(frontRightMotor);
    rearLeftMotor.Follow(frontLeftMotor);
}

void DriveSubsystem::Periodic() 
{
    // Do drive subsystem stuff
    // Called every time the Command Scheduler runs
}

void DriveSubsystem::Drive(double xSpeed, double rot, DriveType driveType)
{
    if (driveType == DriveType::Arcade) {
        m_drive.ArcadeDrive(xSpeed, rot, false);
    } else if (driveType == DriveType::Curvature) {
        m_drive.CurvatureDrive(xSpeed, rot, true);
    }
}