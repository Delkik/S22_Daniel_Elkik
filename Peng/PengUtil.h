#pragma once

#include "pch.h"

#ifdef PENG_WINDOWS
	#ifdef PENG_LIB
		#define PENG_API __declspec(dllexport)
	#else
		#define PENG_API __declspec(dllimport)
	#endif
#else
	#define PENG_API 
#endif

#ifdef PENG_DEBUG
	#define PENG_LOG(x) std::cout<<x<<std::endl;
#else
	#define PENG_LOG(x) 
#endif