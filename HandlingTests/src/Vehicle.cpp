#include "StdAfx.h"

#include "Vehicle.h"

namespace Veh {
	bool throttle(Ped pedPlayer, Vehicle vehicle) {
//		if (canMove(vehicle)) {
			// 23 - accelerate fast
			AI::TASK_VEHICLE_TEMP_ACTION(pedPlayer, vehicle, 32, -1);

			return true;
//		}
//
//		return false;
	}

	bool brake(Ped pedPlayer, Vehicle vehicle) {
//		if (canMove(vehicle)) {
			// 1  - brake
			// 6  - brake strong (handbrake?) until time ends
			// 24 - brake
			// 27 - brake until car stop or until time ends
			AI::TASK_VEHICLE_TEMP_ACTION(pedPlayer, vehicle, 24, -1);

			return true;
//		}
//
//		return false;
	}

	bool canMove(Vehicle vehicle) {
		return VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(vehicle) && !ENTITY::HAS_ENTITY_COLLIDED_WITH_ANYTHING(vehicle);
	}
}
