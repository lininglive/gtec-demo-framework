#ifndef FSLSERVICE_IMPL_SERVICETYPE_ASYNC_ASYNCHRONOUSSERVICEFACTORY_HPP
#define FSLSERVICE_IMPL_SERVICETYPE_ASYNC_ASYNCHRONOUSSERVICEFACTORY_HPP
/****************************************************************************************************************************************************
 * Copyright 2017 NXP
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
 *    * Neither the name of the NXP. nor the names of
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

#include <FslService/Impl/Registry/IServiceFactoryInfo.hpp>
#include <memory>

namespace Fsl
{
  class IAsynchronousServiceProxyFactory;
  class IAsynchronousServiceImplFactory;

  class AsynchronousServiceFactory : public IServiceFactoryInfo
  {
    std::shared_ptr<IAsynchronousServiceProxyFactory> m_proxyFactory;
    std::shared_ptr<IAsynchronousServiceImplFactory> m_implFactory;

  public:
    AsynchronousServiceFactory();
    AsynchronousServiceFactory(const std::shared_ptr<IAsynchronousServiceProxyFactory>& proxyFactory,
                               const std::shared_ptr<IAsynchronousServiceImplFactory>& implFactory);
    ~AsynchronousServiceFactory() override;

    bool IsValid() const
    {
      return m_proxyFactory && m_implFactory;
    }

    std::shared_ptr<IAsynchronousServiceProxyFactory> GetProxyFactory() const;
    std::shared_ptr<IAsynchronousServiceImplFactory> GetImplFactory() const;

    // Inherited via IServiceFactoryInfo
    std::shared_ptr<AServiceOptionParser> GetOptionParser() const override;
    ServiceCaps::Flags GetFlags() const override;
    void FillInterfaceType(ServiceSupportedInterfaceDeque& rServiceInterfaceTypeDeque) const override;
  };
}

#endif
