#pragma once

#include "PengApp.h"



#define PENG_APPLICATION_START(T) \
\
int main()\
{\
	T game;\
	game.Run();\
}