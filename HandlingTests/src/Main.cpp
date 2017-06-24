#include "StdAfx.h"

#include "Keyboard.h"
#include "Timer/Acceleration.h"
#include "Utility.h"
#include "Timer/Deceleration.h"

void update(Timer::Acceleration& timerAccel, Timer::Deceleration& timerDecel) {
	Player player = PLAYER::PLAYER_ID();
	Ped pedPlayer = PLAYER::PLAYER_PED_ID();

	// Checks if the player ped exists and control is on (e.g. not in a cutscene).
	if (!ENTITY::DOES_ENTITY_EXIST(pedPlayer) ||
		!PLAYER::IS_PLAYER_CONTROL_ON(player)) {
		return;
	}

	// Checks for player ped death and player arrest.
	if (ENTITY::IS_ENTITY_DEAD(pedPlayer) ||
		PLAYER::IS_PLAYER_BEING_ARRESTED(player, TRUE)) {
		return;
	}

	Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(pedPlayer, false);

	// Checks if the player is in a vehicle.
	if (!ENTITY::DOES_ENTITY_EXIST(vehicle)) {
		return;
	}

	const double speed = Utility::getSpeed(vehicle);
	timerAccel.update(pedPlayer, vehicle, speed);
	timerAccel.draw(0.5f, 0.5f);
	timerDecel.update(pedPlayer, vehicle, speed);
	timerDecel.draw(0.5f, 0.6f);
}

void main() {
	Timer::Acceleration timerAccel(0, 100, VK_F7);
	Timer::Deceleration timerDecel(100, 0, VK_F8);

	while (true) {
		update(timerAccel, timerDecel);
		WAIT(0);
	}
}

void script() {
	main();
}

// Entry point for the DLL application.
BOOL APIENTRY DllMain(_In_ HMODULE hinstDLL,
					  _In_ DWORD fdwReason,
					  _In_ LPVOID lpvReserved) {
	switch (fdwReason) {
		case DLL_PROCESS_ATTACH:
			scriptRegister(hinstDLL, script);
			keyboardHandlerRegister(onKeyboardMessage);
			break;
		case DLL_PROCESS_DETACH:
			scriptUnregister(hinstDLL);
			keyboardHandlerUnregister(onKeyboardMessage);
			break;
		default:
			break;
	}

	return TRUE;
}
