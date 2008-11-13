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

#include <stdio.h>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/glut.H>
#include "DataContainer.h"
#include "BAPConverter.h"

#include "IniManager.h"
#include "FaceLibraryViewerWindow.h"

FaceLibraryViewerWindow *window;

IniManager inimanager;
std::string ini_filename;

DataContainer *datacontainer;
BAPConverter TorsoGlobalBAPconverter;

void idle()
{
	window->glutw->redraw();
}



int main(int argc, char **argv) 
{
		if(argc==2)
	{
		ini_filename=argv[1];
	} else {
		ini_filename="greta.ini";	
	}

		//datacontainer needs some data..
	inimanager.ReadIniFile(ini_filename);
	
	datacontainer = new DataContainer();

	//load faces, gestures etc
	int code=datacontainer->initBMLEngine();	
	if (code==0) {
		printf("Problem : out \n");
		exit(1);
	}

	window = new FaceLibraryViewerWindow();
	
	window->show();
	
	window->glutw->show();
	glutIdleFunc(idle);
  
  return Fl::run();
}