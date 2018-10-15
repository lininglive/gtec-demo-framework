#ifndef FSLGRAPHICS_RENDER_ATLASFONT_HPP
#define FSLGRAPHICS_RENDER_ATLASFONT_HPP
/****************************************************************************************************************************************************
 * Copyright (c) 2015 Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *    * Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *
 *    * Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *
 *    * Neither the name of the Freescale Semiconductor, Inc. nor the names of
 *      its contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************************************************************************************/

#include <FslBase/Noncopyable.hpp>
#include <FslGraphics/Render/Texture2D.hpp>
#include <FslGraphics/Font/TextureAtlasBitmapFont.hpp>

namespace Fsl
{
  class AtlasFont : private Noncopyable
  {
    const Texture2D m_atlasTexture;
    const TextureAtlasBitmapFont m_textureAtlasBitmapFont;

  public:
    AtlasFont(const Texture2D& atlasTexture, TextureAtlasBitmapFont textureAtlasBitmapFont);

    const Texture2D& GetAtlasTexture() const
    {
      return m_atlasTexture;
    }

    const TextureAtlasBitmapFont& GetAtlasBitmapFont() const
    {
      return m_textureAtlasBitmapFont;
    }

    Point2 MeasureString(const char* const psz) const
    {
      return m_textureAtlasBitmapFont.MeasureString(psz);
    }


    Point2 MeasureString(const char* const pStr, const int32_t startIndex, const int32_t length) const
    {
      return m_textureAtlasBitmapFont.MeasureString(pStr, startIndex, length);
    }
  };
}

#endif
