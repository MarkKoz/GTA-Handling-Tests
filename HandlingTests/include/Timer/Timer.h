#pragma once

#include "StdAfx.h"

#include <chrono>

namespace Timer {
	class Timer {
	public:
		typedef enum States {
			OFF,
			STANDBY,
			READY,
			ON,
			DONE,
			RESULT
		} State;

		virtual void update(Ped pedPlayer, Vehicle vehicle, const double speed) = 0;

		virtual void draw(const float x, const float y) = 0;

		void formatResult();

		void start();

		void toggle();

		void stop();

		State getState() const;

	protected:
		State state;
		int speedStart;
		int speedStop;
		WPARAM key;
		char* result;

		std::chrono::time_point<std::chrono::steady_clock> timeStart;
		std::chrono::nanoseconds timeElapsed;

		Timer(const int speedStart, const int speedStop, WPARAM key);

		virtual ~Timer();
	};
}
