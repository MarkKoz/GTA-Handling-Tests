#include "StdAfx.h"

#include <chrono>
#include <cmath>

#include "Keyboard.h"
#include "Timer/Acceleration.h"
#include "Utility.h"
#include "Vehicle.h"

namespace Timer {
	Acceleration::Acceleration(const int speedStart, const int speedStop, WPARAM key) : Timer(speedStart, speedStop, key) {}

	void Acceleration::update(Ped pedPlayer, Vehicle vehicle, const double speed) {
		if (isKeyJustUp(key)) {
			toggle();
		}

		switch (state) {
			case STANDBY:
				if (speed > speedStart) {
					Veh::brake(pedPlayer, vehicle);
				} else if (speed < speedStart) {
					Veh::throttle(pedPlayer, vehicle);
				}

				if (speed == speedStart) {
					state = READY;
				}

				break;
			case READY:
				Veh::throttle(pedPlayer, vehicle);

				if (speed > speedStart) {
					state = ON;
					timeStart = std::chrono::steady_clock::now();
				}

				break;
			case ON:
				Veh::throttle(pedPlayer, vehicle);

				if (speed >= speedStop) {
					state = DONE;
				}

				timeElapsed = std::chrono::steady_clock::now() - timeStart;

				break;
			case DONE:
				if (!VEHICLE::IS_VEHICLE_STOPPED(vehicle)) {
					Veh::brake(pedPlayer, vehicle);
				} else {
					state = RESULT;
				}

				break;
			default:
				break;
		}
	}

	void Acceleration::draw(const float x, const float y) {
		switch (state) {
			case STANDBY:
				Utility::drawMessage("Standby", x, y);

				break;
			case READY:
				Utility::drawMessage("Ready", x, y);

				break;
			case ON:
				formatResult();
				Utility::drawMessage(result, x, y);

				break;
			case DONE:
			case RESULT:
				Utility::drawMessage(result, x, y);

				break;
			default:
				break;
		}
	}
}

