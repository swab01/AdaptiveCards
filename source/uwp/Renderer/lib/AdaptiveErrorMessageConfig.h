// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "AdaptiveErrorMessageConfig.g.h"

namespace winrt::AdaptiveCards::Rendering::Uwp::implementation
{
    struct AdaptiveErrorMessageConfig : AdaptiveErrorMessageConfigT<AdaptiveErrorMessageConfig>
    {
        AdaptiveErrorMessageConfig(::AdaptiveCards::ErrorMessageConfig errorMessageConfig = {});

        property<ObjectModel::Uwp::TextSize> Size;
        property<ObjectModel::Uwp::Spacing> Spacing;
        property<ObjectModel::Uwp::TextWeight> Weight;
    };
}
namespace winrt::AdaptiveCards::Rendering::Uwp::factory_implementation
{
    struct AdaptiveErrorMessageConfig : AdaptiveErrorMessageConfigT<AdaptiveErrorMessageConfig, implementation::AdaptiveErrorMessageConfig>
    {
    };
}
