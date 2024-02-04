#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level : BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt)override;
	void render()override;

private:
	// Default functions for rendering to the screen.
	

	// Default variables for level class.
	
};