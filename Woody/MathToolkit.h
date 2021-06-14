/**
* Author:gwang
* Date: 2021-06-14
* Description: provide common function for math 
*/

#pragma once

#include <SDL.h>
#include <math.h>
#include <random>
#include "Def.h"

template<typename T, typename P>
T LinearInterpolate(const T& x, const T& y, const P& t)
{
	return x + (y - x)*t;
}


template<typename T>
T Clamp(T x, T min, T max)
{
	return (x < min) ? min : (x > max) : max : x;
}
namespace Random
{

	static std::default_random_engine e;
	static std::uniform_int_distribution<UINT32>i(0, 0xFFFFFFFF);
	static std::uniform_real_distribution<float>r(0.f, 1.f);

	static UINT32 getRandomUint32() { return i(e); }
	static float getRandomFloat() { return r(e); }
}