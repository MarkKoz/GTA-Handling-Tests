#pragma once

#include "StdAfx.h"

#include "Timer/Timer.h"

namespace Timer {
	class Deceleration : public Timer {
	public:
		Deceleration(const int speedStart, const int speedStop, WPARAM key);

		void update(Ped pedPlayer, Vehicle vehicle, const double speed) override;

		void draw(const float x, const float y) override;
	};
}
