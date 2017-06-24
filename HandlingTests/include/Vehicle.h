#pragma once

#include "StdAfx.h"

namespace Veh {
	typedef enum Tasks {
		Brake = 1,
		ReverseStraight = 3,
		HandBrakeLeft = 4,
		HandBrakeRight = 5,
		HandBrakeStraight = 6,
		GoForwardLeft = 7,
		GoForwardRight = 8,
		GoForwardStraightWeak = 9,
		SwerveRight = 10,
		SwerveLeft = 11,
		ReverseLeft = 13,
		ReverseRight = 14,
		SwerveAndBrakeLeft = 20,
		SwerveAndBrakeRight = 21,
		GoForwardWithCustomSteeringAngle = 23,
		GoForwardStraightBraking = 24,
		BrakeReverseFast = 28,
		BurnOut = 30,
		RevEngine = 31,
		GoForwardStraightFast = 32,
	} Task;

	bool throttle(Ped pedPlayer, Vehicle vehicle);

	bool brake(Ped pedPlayer, Vehicle vehicle);

	bool canMove(Vehicle vehicle);
}
