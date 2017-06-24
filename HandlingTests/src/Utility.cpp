#include "StdAfx.h"

#include <cmath>
#include <cstdio>

#include "Utility.h"

namespace Utility {
	double getSpeed(const Vehicle vehicle) {
		// 1 m/s = 3.6 km/h
		const double speed = roundHund(ENTITY::GET_ENTITY_SPEED(vehicle) * 3.6);

		char buffer[16];
		snprintf(buffer, 16, "%.2f km/h", speed);
		drawMessage(buffer, 0.5f, 0.90f);

		return speed;
	}

	double roundHund(double operand) {
		return std::round(operand * 100) / 100;
	}

	void drawMessage(char* message, const float x, const float y) {
		UI::SET_TEXT_CENTRE(TRUE);
		UI::SET_TEXT_SCALE(0.5f, 0.5f);
		UI::_SET_TEXT_ENTRY("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(message);
		UI::_DRAW_TEXT(x, y);
	}
}
