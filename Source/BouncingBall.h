#pragma once
#include <string>
#include <Engine/OGLGame.h>

/**
*  An OpenGL Game based on ASGE.
*/
class BouncingBall :
	public ASGE::OGLGame
{
public:
	BouncingBall();
	~BouncingBall();
	virtual bool init() override;

private:
	void keyHandler(const ASGE::SharedEventData data);
	void clickHandler(const ASGE::SharedEventData data);

	virtual void update(const ASGE::GameTime &) override;
	virtual void render(const ASGE::GameTime &) override;


	int  key_callback_id = -1;	        /**< Key Input Callback ID. */
	int  mouse_callback_id = -1;        /**< Mouse Input Callback ID. */
	ASGE::Sprite* background = nullptr; /**< Sprite Object. The background sprite. */
	ASGE::Sprite* ball = nullptr;  /**< Sprite Object. The ball sprite. */

	bool in_menu = true;
	int score = 0;
};