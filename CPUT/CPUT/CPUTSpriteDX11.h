/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _CPUTSPRITE_H
#define _CPUTSPRITE_H

#include "CPUT.h"
#include "d3d11.h"
#include "CPUTSprite.h"

class CPUTMaterial;
class CPUTRenderParameters;
class CPUTTexture;

class CPUTSpriteDX11 : public CPUTSprite
{
protected:

    ID3D11Buffer      *mpVertexBuffer;
    ID3D11InputLayout *mpInputLayout;

public:
    CPUTSpriteDX11()  : CPUTSprite(),
        mpInputLayout(NULL),
        mpVertexBuffer(NULL)
    {
    }
    ~CPUTSpriteDX11();
    static CPUTSpriteDX11* CreateSprite(
        float          spriteX,
        float          spriteY,
        float          spriteWidth,
        float          spriteHeight,
        const cString &materialName 
    );
    void DrawSprite( CPUTRenderParameters &renderParams ) { DrawSprite( renderParams, *mpMaterial ); }
    void DrawSprite( CPUTRenderParameters &renderParams, CPUTMaterial &material );
};

#endif // _CPUTSPRITE_H
