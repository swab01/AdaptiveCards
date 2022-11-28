// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

namespace AdaptiveCards::Rendering::Xaml_Rendering::MediaHelpers
{
    winrt::xaml_controls::Image GetMediaPosterAsImage(winrt::AdaptiveRenderContext const& renderContext,
                                                      winrt::AdaptiveRenderArgs const& renderArgs,
                                                      winrt::AdaptiveMedia const& adaptiveMedia);

    winrt::xaml::UIElement CreatePosterContainerWithPlayButton(winrt::xaml_controls::Image const& posterImage,
                                                               winrt::AdaptiveRenderContext const& renderContext,
                                                               winrt::AdaptiveRenderArgs const& renderArgs);

    std::tuple<winrt::Uri, winrt::hstring> GetMediaSource(winrt::AdaptiveHostConfig const& hostConfig,
                                                          winrt::AdaptiveMedia const& adaptiveMedia);

    void HandleMediaClick(winrt::AdaptiveRenderContext const& renderContext,
                          winrt::AdaptiveMedia const& adaptiveMedia,
                          winrt::xaml_controls::MediaElement const& mediaElement,
                          winrt::xaml::UIElement const& posterContainer,
                          winrt::Uri const& mediaSourceUrl,
                          winrt::hstring const& mimeType,
                          winrt::AdaptiveMediaEventInvoker const& mediaInvoker);
}
