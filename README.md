# Dynamic Pawn System in Unreal Engine

## Overview
This project implements a dynamic pawn system in Unreal Engine using C++. Players can spawn and switch between different types of pawns based on input, utilizing a DataTable for managing pawn configurations. Additionally, each pawn type has unique attributes defined using DataAssets.

## Features
- **Default Pawn Creation**: AFirstPersonPawn class is implemented for first-person perspective with essential movement controls.
- **Configuring DataTable and Enum**: EPawnType enum and PawnDataTable DataTable are set up to manage pawn configurations.
- **Custom Player Controller**: ADynamicPawnController class allows players to spawn and possess pawns as defined in the DataTable. It tracks the current pawn type and ensures only one pawn is active at a time.
- **Pawn Attributes**: ABaseCharacter class serves as a base class for specific pawn classes. UPawnAttributeAsset is used to define unique attributes for each pawn type, such as speed, health, and jump height. These attributes are displayed using a Blueprint Implementable Event named DisplayAttributes.

## Setup
To use this project, follow these steps:
1. Clone or download the repository.
2. Open the project in Unreal Engine.
3. Compile the project to ensure all code is built correctly.
4. Play the project and test the dynamic pawn system by pressing the designated key to spawn and switch between pawns.

## Usage
- Use the designated key (e.g., "P") to spawn and switch between pawns.
- Check the console log or UI to see the attributes of the currently possessed pawn.

## Credits
This project is created as an assignment for [Course Name/Instructor Name/Institution Name].

## License
[License Name/Link]

