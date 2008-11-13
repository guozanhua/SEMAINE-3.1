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
// Version: 4.0.3 (2006/08/19)

#ifndef WM4GEOMETRY_H
#define WM4GEOMETRY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Spatial.h"
#include "Wm4VertexBuffer.h"
#include "Wm4IndexBuffer.h"
#include "Wm4LightingEffect.h"
#include "Wm4Matrix4.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Geometry : public Spatial
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // abstract base class
    virtual ~Geometry ();

    // member access
    VertexBufferPtr VBuffer;
    IndexBufferPtr IBuffer;
    BoundingVolumePtr ModelBound;

    // geometric updates
    virtual void UpdateMS (bool bUpdateNormals = true);

protected:
    Geometry ();
    Geometry (VertexBuffer* pkVBuffer, IndexBuffer* pkIBuffer);

    // geometric updates
    virtual void UpdateModelBound ();
    virtual void UpdateModelNormals ();
    virtual void UpdateWorldBound ();

    // render state updates
    virtual void UpdateState (std::vector<GlobalState*>* akGStack,
        std::vector<Light*>* pkLStack);

    // culling
    virtual void GetVisibleSet (Culler& rkCuller, bool bNoCull);

    // Dynamic lighting.  The effect is pushed onto the front of Spatial's
    // effect array so that lighting occurs before other shader effects.
    LightingEffectPtr m_spkLEffect;

// internal use
public:
    // Compute the homogeneous world matrix from the components of the World
    // transformation.
    virtual void UpdateWorldData (double dAppTime);

    // Render state and lights in path to this object.  An attached effect
    // provides additional render state, lights, and any other information
    // needed to draw the object.

    enum GeometryType
    {
        GT_POLYPOINT,
        GT_POLYLINE_SEGMENTS,
        GT_POLYLINE_OPEN,
        GT_POLYLINE_CLOSED,
        GT_TRIMESH,
        GT_TRISTRIP,
        GT_TRIFAN,
        GT_MAX_QUANTITY
    };

    GeometryType Type;
    GlobalStatePtr States[GlobalState::MAX_STATE_TYPE];
    Matrix4f HWorld;  // homogeneous world matrix
};

WM4_REGISTER_STREAM(Geometry);
typedef Pointer<Geometry> GeometryPtr;
#include "Wm4Geometry.inl"

}

#endif
