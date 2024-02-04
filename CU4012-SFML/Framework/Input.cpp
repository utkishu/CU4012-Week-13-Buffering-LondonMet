#include "Input.h"

// Input Constructor, handles initial setup on input objects. Default positions, etc
Input::Input()
{
	// set default values
	mouse.left = MouseState::UP;
	mouse.right = MouseState::UP;
	mouse.x = 0;
	mouse.y = 0;
}

// Set a specific key state to true/down.
void Input::setKeyDown(int key)
{
	if (key >= 0)
	{
		keys[key] = true;
	}
}

// Set a specific key state to false/up.
void Input::setKeyUp(int key)
{
	if (key >= 0)
	{
		keys[key] = false;
	}
}

// Check if a key is currently down. Returns true if key is down.
bool Input::isKeyDown(int key)
{
	if (key >= 0)
	{
		return keys[key];
	}
	return false;
}

// Check if a key is pressed. Currently down, but will be automatically set up at the end of frame.
bool Input::isPressed(int key)
{
	bool cond = isKeyDown(key);
	if (cond)
	{
		pressed.push_back(key);
		return cond;
	}
	return false;
}

// Updates current state of keys. Focuses on pressed states. If pressed and processed, should be set to up.
void Input::update()
{
	for (int i = 0; i < pressed.size(); i++)
	{
		setKeyUp(pressed[i]);
	}
	pressed.clear();

	if (mouse.left == MouseState::PRESSED)
	{
		mouse.left = MouseState::UP;
	}
	if (mouse.right == MouseState::PRESSED)
	{
		mouse.right = MouseState::UP;
	}
}

// Stores current mouse x-coordinate
void Input::setMouseX(int lx)
{
	mouse.x = lx;
}

// Stores current mouse y-coordinate
void Input::setMouseY(int ly)
{
	mouse.y = ly;
}

// Stores both XY coordinate for mouse
void Input::setMousePosition(int lx, int ly)
{
	setMouseX(lx);
	setMouseY(ly);
}

// Returns mouse x-coordinate
int Input::getMouseX()
{
	return mouse.x;
}

// Returns mouse y-coordinate
int Input::getMouseY()
{
	return mouse.y;
}

// Set left mouse button state (UP, DOWN, PRESSED)
void Input::setLeftMouse(MouseState state)
{
	mouse.left = state;
}

// Checks if Left mouse button is down. Returning true if button is DOWN or PRESSED
bool Input::isLeftMouseDown()
{
	if (mouse.left == MouseState::DOWN || mouse.left == MouseState::PRESSED)
	{
		return true;
	}
	return false;
}

// Checks if left mouse button is pressed. If set to DOWN, is updated to PRESSED. Automatically updated in update().
bool Input::isLeftMousePressed()
{
	if (mouse.left == MouseState::DOWN || mouse.left == MouseState::PRESSED)
	{
		mouse.left = MouseState::PRESSED;
		return true;
	}
	return false;
}

// Set right mouse button state (UP, DOWN, PRESSED)
void Input::setRightMouse(MouseState state)
{
	mouse.right = state;
}

// Checks if right mouse button is down. Returning true if button is DOWN or PRESSED
bool Input::isRightMouseDown()
{
	if (mouse.right == MouseState::DOWN || mouse.right == MouseState::PRESSED)
	{
		return true;
	}
	return false;
}

// Checks if right mouse button is pressed. If set to DOWN, is updated to PRESSED. Automatically updated in update().
bool Input::isRightMousePressed()
{
	if (mouse.right == MouseState::DOWN || mouse.right == MouseState::PRESSED)
	{
		mouse.right = MouseState::PRESSED;
		return true;
	}
	return false;
}

