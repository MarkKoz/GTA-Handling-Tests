#pragma once

/**
 * Including SDKDDKVer.h defines the highest available Windows platform.
 *
 * If the project needs to be bult for a previous Windows platform, include
 * WinSDKVer.h and set the _WIN32_WINNT macro to the platform to be supported
 * before including SDKDDKVer.h.
 */
#include <WinSDKVer.h>
#define _WIN32_WINNT  0x0601 // Windows 7
#define NTDDI_VERSION 0x06010000
#include <SDKDDKVer.h>
