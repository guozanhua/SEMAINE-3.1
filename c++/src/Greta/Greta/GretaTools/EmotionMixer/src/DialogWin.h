//Copyright 1999-2005 Catherine Pelachaud - c.pelachaud@iut.univ-paris8.fr
//
//This file is part of Greta.
//
//Greta is free software; you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 2 of the License, or
//(at your option) any later version.
//
//Greta is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with Greta; if not, write to the Free Software
//Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

// EmotionMixer.cpp: implementation of the EmotionMixer class.
//
//////////////////////////////////////////////////////////////////////


#pragma once

#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <fl/fl_counter.h>
#include <fl/fl_value_output.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <Windows.H>
#include <FL/Fl.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

using namespace std;


class DialogWin : public Fl_Window 
{

public:
	Fl_Input *nameEmotion;
	Fl_Button *ok;
	Fl_Button *cancel;

	DialogWin(void);
	~DialogWin(void);
	int DialogWin::handle(int event);
};