/*****************************************************************//**
 * @file   Main.cpp
 * @brief  Entry point of the app
 * 
 * @author codex
 * @date   January 2025
 *********************************************************************/
#pragma once

#include "raylib.h"

#include "../include/CapacityPlayerSingleAttack.hpp"
#include "../include/CapacityFactory.hpp"
#include "../include/DiceCapacity.hpp"

#include "../include/PlayerEntityGenerator.hpp"
#include "../include/Team.hpp"

#include <iostream>
#include <array>
#include <memory>



using namespace dice;
using namespace entity;
using namespace capacity;
using namespace group;

int main() {

	 SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	 InitWindow(800, 450, "Project Dice");

	 CapacityFactory capacity_factory;

	 PlayerEntityGenerator entity_generator;
	 BasePlayerEntity entity_1 = entity_generator.generateNewPlayerEntity();
	 //BasePlayerEntity entity_2 = entity_generator.generateNewPlayerEntity();
	 //BasePlayerEntity entity_3 = entity_generator.generateNewPlayerEntity();
	 //BasePlayerEntity entity_4 = entity_generator.generateNewPlayerEntity();
	 //BasePlayerEntity entity_5 = entity_generator.generateNewPlayerEntity();
	 //BasePlayerEntity entity_6 = entity_generator.generateNewPlayerEntity();
	 //entity_6.setCapacity(capacity_factory.attackRandom(entity_6), 3);

	 //Team team_1("Team 1");
	 //team_1.addEntity(std::make_unique<BasePlayerEntity>(entity_1), 0);
	 //team_1.addEntity(std::make_unique<BasePlayerEntity>(entity_2), 0);
	 //team_1.addEntity(std::make_unique<BasePlayerEntity>(entity_3), 0);
	 //team_1.addEntity(std::make_unique<BasePlayerEntity>(entity_4), 0);

	 //Team team_2("Team 2");
	 //team_2.addEntity(std::make_unique<BasePlayerEntity>(entity_5), 0);
	 //team_1.transferEntityTo(team_2, 1, 0);
	 //team_2.addEntity(std::make_unique<BasePlayerEntity>(entity_6), 0);

	 //team_1.printGroup();
	 //team_2.printGroup();

	 std::cout << "========================================================\n\n";
	 BaseCapacity capacity = capacity_factory.attackSingle(entity_1);
	 std::cout << "Before: " << entity_1.getCurrentLife() << '\n';
	 CapacityComponent capacity_modifier = capacity.getNextCapacityModifier();
	 entity_1.resolveCapacity(capacity_modifier, entity_1);
	 std::cout << "After:  " << entity_1.getCurrentLife() << '\n';

	 // Game loop
	 while (!WindowShouldClose()) {

		 BeginDrawing();
		 ClearBackground(RAYWHITE);

		 DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		 EndDrawing();
	 }

	 CloseWindow();
}




	
	


