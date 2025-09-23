/*****************************************************************//**
 * @file   Main.cpp
 * @brief  Entry point of the app
 * 
 * @author THUMELIN Jocelin
 * @date   January 2025
 *********************************************************************/
#pragma once

#include "raylib.h"

#include "../include/CapacityPlayerSingleAttack.hpp"
#include "../include/PassiveAugmentAttribute.hpp"
#include "../include/CapacityFactory.hpp"
#include "../include/ACapacitySystem.hpp"
#include "../include/DiceCapacitySystem.hpp"
#include "../include/CharacterGeneratorSystem.hpp"

#include <iostream>
#include <array>
#include <memory>


using namespace dice;
using namespace character;
using namespace capacity;
using namespace attribute;
//using namespace passive;

int main() {

	 SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	 InitWindow(800, 450, "Project Dice");

	 //CapacityFactory capacity_factory;

	 CharacterGeneratorSystem character_generator;
	 CharacterSystem character_1 = character_generator.generateNewPlayercharacter();
	 //CharacterSystem character_2 = character_generator.generateNewPlayercharacter();
	 //CharacterSystem character_3 = character_generator.generateNewPlayercharacter();
	 //CharacterSystem character_4 = character_generator.generateNewPlayercharacter();
	 //CharacterSystem character_5 = character_generator.generateNewPlayercharacter();
	 //CharacterSystem character_6 = character_generator.generateNewPlayercharacter();
	 //character_6.setCapacity(capacity_factory.attackRandom(character_6), 3);

	 //Team team_1("Team 1");
	 //team_1.addcharacter(std::make_unique<CharacterSystem>(character_1), 0);
	 //team_1.addcharacter(std::make_unique<CharacterSystem>(character_2), 0);
	 //team_1.addcharacter(std::make_unique<CharacterSystem>(character_3), 0);
	 //team_1.addcharacter(std::make_unique<CharacterSystem>(character_4), 0);

	 //Team team_2("Team 2");
	 //team_2.addcharacter(std::make_unique<CharacterSystem>(character_5), 0);
	 //team_1.transfercharacterTo(team_2, 1, 0);
	 //team_2.addcharacter(std::make_unique<CharacterSystem>(character_6), 0);

	 //team_1.printGroup();
	 //team_2.printGroup();

	 std::cout << "========================================================\n\n";
	 //ACapacitySystem capacity = capacity_factory.attackSingle(character_1);
	 //std::cout << "Before: " << character_1.getCurrentLife() << '\n';
	 //CapacityDTO capacity_modifier = capacity.getNextCapacityActionData();
	 //character_1.resolveCapacity(capacity_modifier, character_1);
	 //std::cout << "After:  " << character_1.getCurrentLife() << '\n';

	 std::cout << "========================================================\n\n";
	 //PassiveAugmentAttribute passive_strength(attribute::STRENGTH, 2);
	 //character_1.addPassive(passive_strength);
	 //character_1.executePassives();
	 character_1.printcharacter();





	 // Game loop
	 while (!WindowShouldClose()) {

		 BeginDrawing();
		 ClearBackground(RAYWHITE);

		 DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		 EndDrawing();
	 }

	 CloseWindow();
}




	
	


