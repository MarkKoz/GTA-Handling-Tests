# GTA V Handling Tests
### Description
An assortment of tests for vehicle handling in GTA V. Includes:
* Speedometer in kilometres per hour.
* Acceleration timer (0 km/h to 100 km/h).
* Deceleration timer (100 km/h to 0 km/h).

### Instructions
Hotkeys:
* `F7` - Toggle Acceleration Timer
* `F8` - Toggle Deceleration Timer

Press one of the hotkeys listed above to activate the correponding timer. The
vehicle will automatically throttle/brake to reach the starting speed. The
result of the timer will appear in the centre of the screen. Once the target
speed is reached, the vehicle will automatically brake until stopped. The
result will remain displayed until the timer is toggled off.

### Requirements
* Grand Theft Auto V 1.0.1032.1
* [Script Hook V](http://www.dev-c.com/gtav/scripthookv/)

### Installation
Move `HandlingTests.asi` to game's root directory (i.e. where `GTAV.exe` is).

### Developing
Download the [Script Hook V SDK](http://www.dev-c.com/gtav/scripthookv/) and
move the archive's contents into `solution-root/libs/ScriptHookV/`.

### Credits
Alexander Blade - Script Hook V SDK