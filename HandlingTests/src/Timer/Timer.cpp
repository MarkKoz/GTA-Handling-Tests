#include "StdAfx.h"

#include <chrono>

#include "Timer/Timer.h"

namespace Timer {
	Timer::Timer(const int speedStart, const int speedStop, WPARAM key) : state(OFF), speedStart(speedStart), speedStop(speedStop), key(key), result(nullptr) {}

	Timer::~Timer() {
		delete[] result;
	}

	void Timer::formatResult() {
		if (result != nullptr) {
			delete[] result;
		}

		result = new char[128];
		snprintf(result, 128, "%.3f seconds", static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(timeElapsed).count()) / 1000);
	}

	void Timer::start() {
		state = STANDBY;
	}

	void Timer::toggle() {
		if (state == OFF) {
			start();
		} else {
			stop();
		}
	}

	void Timer::stop() {
		state = OFF;
	}

	Timer::State Timer::getState() const {
		return state;
	}
}
