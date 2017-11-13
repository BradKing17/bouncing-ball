#include <string>

#include <Engine/Keys.h>
#include <Engine/Input.h>
#include <Engine/InputEvents.h>
#include <Engine/Sprite.h>

#include "BouncingBall.h"

/**
*   @brief   Default Constructor.
*   @details Consider setting the game's width and height
             and even seeding the random number generator.
*/
BouncingBall::BouncingBall()
{
	game_width = 1024;
	game_height = 768;

	
}

/**
*   @brief   Destructor.
*   @details Remove any non-managed memory and callbacks.
*/
BouncingBall::~BouncingBall()
{
	this->inputs->unregisterCallback(key_callback_id);
	this->inputs->unregisterCallback(mouse_callback_id);

	if (background)
	{
		delete background;
		background = nullptr;
	}

	if (ball)
	{
		delete ball;
		ball = nullptr;
	}
}

/**
*   @brief   Initialises the game.
*   @details The game window is created and all assets required to
			 run the game are loaded. The keyHandler and clickHandler
			 callback should also be set in the initialise function.
*   @return  True if the game initialised correctly.
*/
bool BouncingBall::init()
{
	// initialises the graphics API, check to make sure it was a success
	if (!initAPI())
	{
		return false;
	}

	// disable sprite batching for simplicity 
	renderer->setSpriteMode(ASGE::SpriteSortMode::IMMEDIATE);
	renderer->setWindowTitle("Bouncing ball");
	
	toggleFPS();



	// load the ball



	std::srand(time(NULL));

	// input handling functions
	key_callback_id = inputs->addCallbackFnc(
		ASGE::E_KEY, &BouncingBall::keyHandler, this);
	
	mouse_callback_id =inputs->addCallbackFnc(
		ASGE::E_MOUSE_CLICK, &BouncingBall::clickHandler, this);

	return true;
}

/**
*   @brief   Processes any key inputs
*   @details This function is added as a callback to handle the game's
			 keyboard input. For this game, calls to this function
			 are thread safe, so you may alter the game's state as you
			 see fit.
*   @param   data The event data relating to key input.
*   @see     KeyEvent
*   @return  void
*/
void BouncingBall::keyHandler(const ASGE::SharedEventData data)
{
	auto key = static_cast<const ASGE::KeyEvent*>(data.get());

	if (key->key == ASGE::KEYS::KEY_ENTER &&
		key->action == ASGE::KEYS::KEY_RELEASED)
	{
			// set the in menu boolean to false
			
	}
	if (key->key == ASGE::KEYS::KEY_ESCAPE)
	{
		signalExit();
	}
}

/**
*   @brief   Processes any key inputs
*   @details This function is added as a callback to handle the game's
		     mouse button input. For this game, calls to this function
             are thread safe, so you may alter the game's state as you
             see fit.
*   @param   data The event data relating to key input.
*   @see     ClickEvent
*   @return  void
*/
void BouncingBall::clickHandler(const ASGE::SharedEventData data)
{
	auto click = static_cast<const ASGE::ClickEvent*>(data.get());

	double x_pos, y_pos;
	inputs->getCursorPos(x_pos, y_pos);

}



/**
*   @brief   Updates the scene
*   @details Prepares the renderer subsystem before drawing the
		     current frame. Once the current frame is has finished
		     the buffers are swapped accordingly and the image shown.
*   @return  void
*/
void BouncingBall::update(const ASGE::GameTime& us)
{
	if (!in_menu)
	{
		// grab the current position
		//auto y_pos = ball->yPos();   /***Uncomment this line once you have created the ball sprite!***/

		// move the ball in the upward direction, say 500pixels/sec? 
		// delta time is measured in milliseconds, so divide by 1000 and multiply


		// update the position of the ball

	}
}

/**
*   @brief   Renders the scene
*   @details Renders all the game objects to the current frame.
	         Once the current frame is has finished the buffers are
			 swapped accordingly and the image shown.
*   @return  void
*/
void BouncingBall::render(const ASGE::GameTime &)
{
	renderer->setFont(0);

	if (in_menu)
	{
		//render text to introduce the game
		//ask user to press enter to start the game


	}
	else
	{


		// creates a string with the score appended
		std::string score_str = "SCORE: " + std::to_string(score);

		// renders the string. a std string is not a c string so needs to be converted hence .c_str()
		renderer->renderText(score_str.c_str(), 850, 25, 1.0, ASGE::COLOURS::DARKORANGE);
	}
	
}
