#ifndef FSLSIMPLEUI_BASE_SYSTEM_ITREENODELOCATOR_HPP
#define FSLSIMPLEUI_BASE_SYSTEM_ITREENODELOCATOR_HPP
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

#include <memory>

namespace Fsl
{
  namespace UI
  {
    class IWindowId;
    class TreeNode;

    class ITreeNodeLocator
    {
    public:
      virtual ~ITreeNodeLocator() = default;

      //! @brief Locate the node associated with the given window id
      //! @throws NotFoundException if the window can't be found
      virtual std::shared_ptr<TreeNode> Get(const IWindowId* const pWindowId) const = 0;

      //! @brief Locate the node associated with the given window id
      //! @throws NotFoundException if the window can't be found
      virtual std::shared_ptr<TreeNode> Get(const std::shared_ptr<IWindowId>& windowId) const = 0;

      //! @brief Try to Locate the node associated with the given window id
      //! @throws null if the window can not be found
      virtual std::shared_ptr<TreeNode> TryGet(const IWindowId* const pWindowId) const = 0;

      //! @brief Try to Locate the node associated with the given window id
      //! @throws null if the window can not be found
      virtual std::shared_ptr<TreeNode> TryGet(const std::shared_ptr<IWindowId>& windowId) const = 0;
    };
  }
}

#endif
