// Wild Magic Source Code
// David Eberly
// http://www.geometrictools.com
// Copyright (c) 1998-2007
//
// This library is free software; you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; either version 2.1 of the License, or (at
// your option) any later version.  The license is available for reading at
// either of the locations:
//     http://www.gnu.org/copyleft/lgpl.html
//     http://www.geometrictools.com/License/WildMagicLicense.pdf
//
// Version: 4.0.0 (2006/06/28)

#ifndef WM4COLORRGBAARRAY_H
#define WM4COLORRGBAARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4ColorRGBA.h"

namespace Wm4
{
typedef TSharedArray<ColorRGBA> ColorRGBAArray;
typedef Pointer<ColorRGBAArray> ColorRGBAArrayPtr;
WM4_REGISTER_STREAM(ColorRGBAArray);
}

#endif