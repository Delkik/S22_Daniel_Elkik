#pragma once

#include "PengApp.h"
#include "GameWindow.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "KeyCodes.h"
#include "Events.h"


#define PENG_APPLICATION_START(T) \
\
int main()\
{\
	T game;\
	game.Run();\
}