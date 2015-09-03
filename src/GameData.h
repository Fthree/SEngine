#ifndef __GAMEDATA__
#define __GAMEDATA__

#include <SDL2/SDL.h>

#include <iostream>

class gameData
{
public:
	static gameData &instance()
	{
		static gameData *instance_ = new gameData();
		return *instance_;
	}

	void setData(SDL_Renderer *tempRenderer, SDL_Window *tempWindow, int tempX, int tempY, int tempWidth, int tempHeight, bool tempFullscrn)
	{
		_primaryRenderer = tempRenderer;
		_primaryWindow = tempWindow;
		_xWindowPos = tempX;
		_yWindowPos = tempY;
		_windowWidth = tempWidth;
		_windowHeight = tempHeight;
		_fullscreen = tempFullscrn;

		//Values pre-set as the game's dev size.
		gameScaleX = (double)tempWidth / 1920.0f;
		gameScaleY = (double)tempHeight / 1080.0f;
		scale = (gameScaleX + gameScaleY) / 2;

		_exit = true;
	}

	SDL_Renderer *getCurrRenderer() { return _primaryRenderer; }
	SDL_Window *getCurrWindow() { return _primaryWindow; }
	int getXPos() { return _xWindowPos; }
	int getYPos() { return _yWindowPos; }
	int getWidth() { return _windowWidth; }
	int getHeight() { return _windowHeight; }

	bool getFullScreenFlag() { return _fullscreen; }
	bool getExit() { return _exit; }
	void setExit(bool val) { _exit = val; }
	void setFPS(double FPS) { _FPS = FPS; }

	double getdt() { return 1/_FPS; }

	double getScale()
	{
		return scale;
	}

private:
	SDL_Renderer *_primaryRenderer;
	SDL_Window *_primaryWindow;


	int _xWindowPos;
	int _yWindowPos;
	int _windowWidth;
	int _windowHeight;
	bool _fullscreen;
	double _dt;
	double _FPS;
	bool _exit;
	double gameScaleX;
	double gameScaleY;
	double scale;

	gameData() {}
};

#endif