#pragma once
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma comment(lib, "winmm.lib")
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<ctime>
#include "GameObject.h"
#include "Potato_Mine.h"
#include "Shooter.h"
#include "Sun.h"
#include "Wall.h"

extern void clear(char* canvas, int length);
extern void render(const char* canvas, int lastPosition);