// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveToggleVisibilityActionRenderer.g.h"

namespace winrt::AdaptiveCards::Rendering::Uwp::implementation
{
    struct AdaptiveToggleVisibilityActionRenderer : AdaptiveToggleVisibilityActionRendererT<AdaptiveToggleVisibilityActionRenderer>
    {
        AdaptiveToggleVisibilityActionRenderer() = default;

        winrt::Windows::UI::Xaml::UIElement Render(winrt::AdaptiveCards::ObjectModel::Uwp::IAdaptiveActionElement const& actionElement,
                                                   winrt::AdaptiveCards::Rendering::Uwp::AdaptiveRenderContext const& renderContext,
                                                   winrt::AdaptiveCards::Rendering::Uwp::AdaptiveRenderArgs const& renderArgs);
    };
}
namespace winrt::AdaptiveCards::Rendering::Uwp::factory_implementation
{
    struct AdaptiveToggleVisibilityActionRenderer
        : AdaptiveToggleVisibilityActionRendererT<AdaptiveToggleVisibilityActionRenderer, implementation::AdaptiveToggleVisibilityActionRenderer>
    {
    };
}
