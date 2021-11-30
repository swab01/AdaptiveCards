// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "RenderedAdaptiveCard.h"
#include "AdaptiveActionInvoker.g.h"

namespace winrt::AdaptiveCards::Rendering::Uwp::implementation
{
    struct AdaptiveActionInvoker : AdaptiveActionInvokerT < AdaptiveActionInvoker>
    {
        AdaptiveActionInvoker(Uwp::RenderedAdaptiveCard const& renderResult = nullptr) :
            m_weakRenderResult(renderResult)
        {
        }

        void SendActionEvent(ObjectModel::Uwp::IAdaptiveActionElement const& actionElement);

    private:
        winrt::weak_ref<Uwp::RenderedAdaptiveCard> m_weakRenderResult;
    };
}
namespace winrt::AdaptiveCards::Rendering::Uwp::factory_implementation
{
    struct AdaptiveActionInvoker : AdaptiveActionInvokerT<AdaptiveActionInvoker, implementation::AdaptiveActionInvoker>
    {
    };
}

