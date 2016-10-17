# Latch

Arduino sketches to control automated latch mechanism for secret mirror door.

Uses a transistor-controlled solenoid to open the door. First button inside opens the door (normally open switch). Second button is a normally-closed magnetic switch hidden in a fake book next to the mirror door.

## latch3.ino

Production code for operating the latch.

## latch_debug_monitor.ino

Modified version of the code to print switch values to the serial monitor instead of triggering the latch.