#pragma once

#include <SFML/Graphics.hpp>
#include "Input.h"
#include <string>
#include <iostream>

class BaseLevel
{
public:
	BaseLevel();
	~BaseLevel();

	virtual void handleInput(float dt) = 0;
	virtual void update(float dt) = 0;
	virtual void render() = 0;

protected:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	
};

