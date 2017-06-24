/**
 * THIS FILE IS A PART OF GTA V SCRIPT HOOK SDK
 * http://dev-c.com
 * (C) Alexander Blade 2015
 */

#include "StdAfx.h"

#include "Keyboard.h"

const int KEYS_SIZE = 255;
const int NOW_PERIOD = 100; // ms
const int MAX_DOWN = 5000; // ms

struct {
	DWORD time;
	BOOL isWithAlt;
	BOOL wasDownBefore;
	BOOL isUpNow;
} keyStates[KEYS_SIZE];

void onKeyboardMessage(DWORD key,
					   WORD repeats,
					   BYTE scanCode,
					   BOOL isExtended,
					   BOOL isWithAlt,
					   BOOL wasDownBefore,
					   BOOL isUpNow) {
	if (key < KEYS_SIZE) {
		keyStates[key].time = GetTickCount();
		keyStates[key].isWithAlt = isWithAlt;
		keyStates[key].wasDownBefore = wasDownBefore;
		keyStates[key].isUpNow = isUpNow;
	}
}

bool isKeyDown(DWORD key) {
	return (key < KEYS_SIZE) ? ((GetTickCount() < keyStates[key].time + MAX_DOWN) && !keyStates[key].isUpNow) : false;
}

bool isKeyJustUp(DWORD key, bool exclusive) {
	bool b = (key < KEYS_SIZE) ? (GetTickCount() < keyStates[key].time + NOW_PERIOD && keyStates[key].isUpNow) : false;

	if (b && exclusive) {
		resetKeyState(key);
	}

	return b;
}

void resetKeyState(DWORD key) {
	if (key < KEYS_SIZE) {
		memset(&keyStates[key], 0, sizeof(keyStates[0]));
	}
}
