# EARs-RobotWars

## BattleBot Project - Electronics and Radio Society

Welcome to the repository for the BattleBot Project! This repository contains all the code I am developing for a BattleBot as part of a team within the University Electronics and Radio Society. Our team of 7 members is designing and building this robot from scratch, working together to create a competitive and reliable bot to compete in robot wars events.

### Project Overview

The BattleBot will be a Featherweight (13.6kg) which features a 4-bar flipper weapon that is powered by a motor-driven screw mechanism. The flipper is designed for offensive capabilities, allowing the bot to effectively flip opponents in the arena. The weapon mechanism is controlled by the code in this repository, which manages the motor that drives the flipper forward and retracts it as needed.

### Team

The BattleBot team consists of 7 members from the Electronics and Radio Society, collaborating on various aspects including design, engineering, coding, and testing. Each team member contributes their skills to ensure a well-rounded and competitive robot.

### Key Features

    4-Bar Flipper Weapon: A powerful flipper designed to toss and disable opponents, controlled by a custom motor-driven screw system.
    Motor Control: The code here manages the motor responsible for the precise movements of the weapon, ensuring accurate and timely actions during a match.

### Repository Structure

The repository is organized as follows:

    /mainTest - Contains code for controlling the motor in the forward direction and stopping the motor when it reaches the end of it's range of travel (determined by a hall effect sensor)
    /testing - Scripts and tools used for testing the weapon functionality and overall bot performance.
    /libraries - Contains the libraries required to compile and run the code on the ESP32 C3 Supermini which we are using in out BattleBot.
    /media - Contains images and videos of our BattleBot build progress.

### How It Works

    Weapon Activation: The motor powers a threaded screw that drives the flipper forward.
    Flipper Retraction: When deactivated, the motor retracts the screw to reset the flipper position.
    Code Execution: The control code uses a combination of sensors (if available) and timing to manage the flipper's position and responsiveness.
