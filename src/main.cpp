/*****************************************************************//**
 * @file   Main.cpp
 * @brief  Entry point of the app
 * 
 * @author THUMELIN Jocelin
 * @date   January 2025
 *********************************************************************/
#pragma once

#include "raylib.h"

#include "CharacterManager.hpp"

#include <iostream>

using namespace dice;
using namespace character;
using namespace capacity;
using namespace attribute;
//using namespace passive;

int main() {

	 SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	 InitWindow(800, 450, "Project Dice");


	 CharacterManager character_manager;
	 CharacterSystem character_1 = character_manager.createNewPlayerCharacter();

	 std::cout << "========================================================\n\n";

	 character_1.setDiceCapacity(ATTACK_SINGLE, 1);
	 character_1.setDiceCapacity(ATTACK_RANDOM, 4);
	 character_1.setDiceCapacity(DEFEND_SELF, 6);
	 character_manager.printCharacter(character_1);

	 std::cout << "========================================================\n\n";
	 //PassiveAugmentAttribute passive_strength(attribute::STRENGTH, 2);
	 //character_1.addPassive(passive_strength);
	 //character_1.executePassives();
	 //character_1.printcharacter();




	 // Game loop
	 while (!WindowShouldClose()) {

		 BeginDrawing();
		 ClearBackground(RAYWHITE);

		 DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		 EndDrawing();
	 }

	 CloseWindow();
}




	
	


