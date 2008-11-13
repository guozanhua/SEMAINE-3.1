//Copyright 1999-2008 Catherine Pelachaud - c.pelachaud@iut.univ-paris8.fr
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

//this is a simple class that holds 3D vectors. instead of using it
//it should be possible to use algebra3 vectors (see the next comment)
//but I started using it before using algebra3...

#ifndef INCLUDED_POINT3D
#define INCLUDED_POINT3D

/**
*
* class :point3d
*
*/

class point3d
{
public:
	float x,y,z;

	/**
	* contructor 
	*
	*/

	point3d();	
};

#endif