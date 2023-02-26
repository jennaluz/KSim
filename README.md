# KSim
Uses Make and C++ to simulate the kernel of an operating system. "Processes" are moved between different states based on the Five State Process Model.

## Installation
<a href="docs/KSim.zip?raw=true" download>Click here</a> to download `KSim.zip`, otherwise found in [docs](docs).

Use `make` to build the executable.

Use `make run` to run the executable.

## Overview
### Five State Process Model
Processes can be of the state `New`, `Ready`, `Running`, `Blocked`, or `Exit`.

### Commands
The following commands shuffle processes between the different states. Each command consumes a certain amount of system ticks. Quotes "" are artifacts of the command definition. Do not include them when executing commands. See [](KSim User Manual) for more details about these commands.
- __add "process-name"__
  - Adds process of the name "process-name"
  - 32 ticks on success; 0 ticks on failure
- __exit__
  - Terminates simulation
- __io-event "io-dev-num"__
  - Unblocks all processes currently waiting on an I/O device with number "io-dev-num"
    - I/O device numbers on this system have a range [0, 3]
  - 1 tick
- __query "process-name"__
  - Prints the PID and state of process "process-name"
  - If "process-name"=="all", then the PID and state of all processes in the system are printed
  - 0 ticks
- __release__
  - Moves the currently running process into the `Exit` state
  - 32 ticks on success; 0 ticks on failure
- __step__
  - The following "house-keeping" duties are performed in this order
    1. Remove all processes in the `Exit` state from the system
    2. Moves at most one process from the `New` state to the `Ready` state
    3. Moves at most one process from each I/O device in the `Blocked` state to the `Ready` state
       - This only occurs if the blocked process has been waiting on the I/O device for at least `1,024` ticks
    4. Move the process currently in the `Running` state (if any) to the `Ready` state
    5. Dispatch the process that has been in the `Ready` state the longest (if any) to the `Running` state
  - 256 ticks
- __wait "io-dev-num"__
  - Blocks the currently running process on I/O device "io-dev-num"
  - 1 tick on success; 0 ticks on failure

## Improvements
### System Ticks
The current stystem tick is represented by a nine-digit integer. If the system goes over `999,999,999` ticks, the ticks will simply rollover to `000000000`.

### Process Priority
All processes are running at the same priority. Currently, a round-robin technique is used when dispatching the process.
