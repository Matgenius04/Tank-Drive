#pragma once

#include "Constants.h"

#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <rev/CANSparkMax.h>

using namespace DriveConstants;

#include <frc2/command/SubsystemBase.h>

enum DriveType
{
    Arcade,
    Curvature
};

class DriveSubsystem : public frc2::SubsystemBase
{
    public:
        DriveSubsystem();
        void Periodic() override;
        void Drive(double xSpeed, double rot, DriveType driveType);
    private:
        rev::CANSparkMax frontRightMotor {frontRightMotorCANid, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax rearRightMotor {rearRightMotorCANid, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax frontLeftMotor {frontLeftMotorCANid, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax rearLeftMotor {rearLeftMotorCANid, rev::CANSparkMax::MotorType::kBrushless};

        frc::MotorControllerGroup leftGroup {frontLeftMotor, rearLeftMotor};
        frc::MotorControllerGroup rightGroup {frontRightMotor, rearRightMotor};

        frc::DifferentialDrive m_drive {leftGroup, rightGroup};
};