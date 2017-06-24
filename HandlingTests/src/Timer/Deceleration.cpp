#include "StdAfx.h"

#include <chrono>
#include <cmath>

#include "Keyboard.h"
#include "Timer/Deceleration.h"
#include "Utility.h"
#include "Vehicle.h"

namespace Timer {
	Deceleration::Deceleration(const int speedStart, const int speedStop, WPARAM key) : Timer(speedStart, speedStop, key) {}

	void Deceleration::update(Ped pedPlayer, Vehicle vehicle, const double speed) {
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

				if (std::floor(speed) == speedStart) {
					state = READY;
				}

				break;
			case READY:
				Veh::brake(pedPlayer, vehicle);

				if (speed < speedStart) {
					state = ON;
					timeStart = std::chrono::steady_clock::now();
				}

				break;
			case ON:
				Veh::brake(pedPlayer, vehicle);

				if (speed <= speedStop) {
					state = DONE;
				}

				timeElapsed = std::chrono::steady_clock::now() - timeStart;

				break;
			default:
				break;
		}
	}

	void Deceleration::draw(const float x, const float y) {
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

