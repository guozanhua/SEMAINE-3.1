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

// FaceLibraryViewerGlutWindow.h: interface for the FaceLibraryViewerGlutWindow class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FaceLibraryViewerGlutWindow_H__97B0F480_18A4_11D9_9C92_F2F8893FEB7F__INCLUDED_)
#define AFX_FaceLibraryViewerGlutWindow_H__97B0F480_18A4_11D9_9C92_F2F8893FEB7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <FL/Fl_Gl_Window.H>
#include "AgentAspect.h"

class FaceLibraryViewerGlutWindow : public Fl_Gl_Window  
{
public:
	int height;
	int width;
	int rot;
	void draw(void);
	int handle(int event);
	FaceLibraryViewerGlutWindow(int x, int y, int w, int h, const char *label);
	virtual ~FaceLibraryViewerGlutWindow();
	AgentAspect * agent;
	float camerapanx;
	float camerapany;
	float camerapanz;
	float camerarotx;
	float cameraroty;
	float camerarotz;
	int mousepressedx,mousepressedy;

	GLfloat light_ambient_0[4];
	GLfloat light_diffuse_0[4];
	GLfloat light_specular_0[4];
	GLfloat light_position_0[4];
};

#endif // !defined(AFX_FaceLibraryViewerGlutWindow_H__97B0F480_18A4_11D9_9C92_F2F8893FEB7F__INCLUDED_)