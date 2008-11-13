//Copyright 1999-2008 Catherine Pelachaud - c.pelachaud@iut.univ-paris8.fr
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

// TorsoGestuary.h
//
//////////////////////////////////////////////////////////////////////
#include <string>
#include <map>
#include <vector>

#include "XMLGenericParser.h"
#include "TorsoGesture.h"
#include "TorsoMovementPoint.h"


namespace TorsoSpace {

	/**
	* class :TorsoGestuary
	*
	*/

	class TorsoGestuary 

	{

	public:


		/**
		* contructor 
		*
		*/

		TorsoGestuary();

		/**
		* destructor 
		*/

		virtual ~TorsoGestuary();


		/**
		*  
		*
		* @return 
		* @param  gestuaryfilename
		* @param  TorsoMovementPoint restposition
		*/

		int LoadGestuary(std::string gestuaryfilename, TorsoMovementPoint restposition);


		/**
		*  
		* 
		*
		* @return 
		*/

		std::map<std::string,TorsoGesture> getGestuary();

		std::map<std::string,TorsoGesture> gestuary;
		std::vector<TorsoGesture> gestures;

	};
}
