# HW/SW integration specification example

## Prerequisites
* Build and flash an ATmega328p processor.
* Run the system, open a serial terminal.

## 1. Temperature measurement

### 1.1 Temperature button
* Press the temperature button (SW2).
* The temperature shall be printed in the terminal.

### 1.2 Temperature timer
* Ensure that the temperature is printed every 60 seconds, 
or 60 seconds after the last pressdown.

### 1.3 Temperature verification
* Verify that the temperature displayed in the terminal is correct
by comparing it with the room temperature when the button (SW2) is pressed.
* Increase the heat on the temperature sensor and confirm that the displayed 
temperature also increases when the button is pressed.

### 1.4 Temperature button debounce
* Ensure that the debounce works correctly by pressing the button (SW2) repetatly. 
* Buttons pressed between the interval of 300 ms should be ignored. 

## 2. Toggle button

### 2.1 Toggle button verification
* Ensure that the LED blinks when the toggle button (SW1) is pressed. 
* And stops blinking when the button is pressed again.

### 2.2 Toggle speed.
* Measure the frequency of the blinks.
* Compare the value to the expected frequency (5 Hz).

### 2.3 Toggle debounce
* Ensure that the debounce function works correctly pressing the button repetatly and watching the terminal.
* The debounce on the toggle button (SW1) should be 300 ms.

## 3 Watchdog

### 3.1 Watchdog verification
* If the system does not reset after 1024 ms, the watchdog works as expected.
* The default watchdog-timer should be set to 1024 ms. 

* When removing the watchdog timer, by removing the reset-function: 

```cpp
while (!stop) 
{ 
    // Regularly reset the watchdog to avoid system reset.
    myWatchdog.reset(); <-- THIS SHOULD BE REMOVED.
}
```

* You should expect the system to reset every 1024 ms. 
* By watching the terminal, you should see that the system restarts. 

### 3.2 Watchdog re-implementation
* When re-implementing the function. The system should work again. 

## 4 EEPROM-persistens

### 4.1 Toggle-timer verification. 
* Activate the toggle-function by pressing the toggle-button (SW1) and ensure that the led toggles. 
* Restart the system and make sure that the led still toggles. This ensures that the EEPROM works correctly. 
* Press the toggle-button once again, so that the led is off. 
* Restart the system once again and make sure that the LED is still off. 

## End-to-End Scenario
1. Start system from reset.
2. Press toggle --> LED blinks.
3. Press temperature button -> temperature printed in terminal.
4. Wait for automatic temperature print
5. Press toggle --> LED stops blinking.
6. Press toggle again --> LED blinks. 
7. Reset system --> LED should resume previous toggle state.
8. Press toggle --> LED stops blinking.
9. Reset system --> LED should remain off.

| Test ID | Description                      | Expected Result | Actual Result | Status (Pass/Fail) | Time spent |
|---------|----------------------------------|---------------------------------|---------------|------------------|-------|
| 1.1     | Temperature button (SW2) press   | Temperature is printed in terminal | 21.0°C printed after button pressed | Pass | 1 min |
| 1.2     | Temperature timer                | Temperature is printed every 60 s or 60 s after last press | Temperature printed 60 s after last pressdown | Pass | 2 min |
| 1.3     | Temperature verification         | Displayed temperature matches room temp; increases when sensor is heated | Temperature matched room temp and increased when heated | Pass | 2 min |
| 1.4     | Temperature button debounce      | Repeated presses within 300 ms are ignored | Only 1 reading printed when pressed rapidly 3 times within 300 ms | Pass | 1 min |
| 2.1     | Toggle button verification       | LED blinks when pressed and stops when pressed again | LED blinked at first press, stopped at the second press | Pass | 1 min |
| 2.2     | Toggle speed                     | LED blink frequency matches expected value (5 Hz) | Measured 5,1 Hz using stopwatch, ok results | Pass | 2 min |
| 2.3     | Toggle debounce                  | Repeated presses within 300 ms are ignored | Only 1 reading printed when pressed rapidly 3 times within 300 ms | Pass | 1 min |
| 3.1     | Watchdog verification            | System resets every 1024 ms when reset function removed | System reset occured 1 s after blocking loop | Pass | 2 min |
| 3.2     | Watchdog re-implementation       | System operates normally after restoring watchdog reset function | The system continued operating normally | Pass | 2 min |
| 4.1     | Toggle-timer EEPROM verification | LED state persists across power cycles; ON stays ON, OFF stays OFF | LED was on after restart, OFF after second restart --> EEPROM working | Pass | 2 min |





