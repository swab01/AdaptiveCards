// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveInputLabelConfig.g.h"

namespace winrt::AdaptiveCards::Rendering::Uwp::implementation
{
    struct AdaptiveInputLabelConfig : AdaptiveInputLabelConfigT < AdaptiveInputLabelConfig>
    {
        AdaptiveInputLabelConfig(::AdaptiveCards::InputLabelConfig inputLabelConfig = {});

        property<winrt::AdaptiveCards::ObjectModel::Uwp::ForegroundColor> Color;
        property<bool> IsSubtle;
        property<winrt::AdaptiveCards::ObjectModel::Uwp::TextSize> Size;
        property<hstring> Suffix;
        property<winrt::AdaptiveCards::ObjectModel::Uwp::TextWeight> Weight;
    };
}
namespace winrt::AdaptiveCards::Rendering::Uwp::factory_implementation
{
    struct AdaptiveInputLabelConfig : AdaptiveInputLabelConfigT<AdaptiveInputLabelConfig, implementation::AdaptiveInputLabelConfig>
    {
    };
}
