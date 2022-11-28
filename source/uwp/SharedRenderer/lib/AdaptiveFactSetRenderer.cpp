// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"

#include "AdaptiveFactSetRenderer.h"
#include "AdaptiveFactSetRenderer.g.cpp"
#include "TextHelpers.h"
#include "WholeItemsPanel.h"

namespace winrt::AdaptiveCards::Rendering::Xaml_Rendering::implementation
{
    winrt::xaml::UIElement AdaptiveFactSetRenderer::Render(winrt::IAdaptiveCardElement const& cardElement,
                                                           winrt::AdaptiveRenderContext const& renderContext,
                                                           winrt::AdaptiveRenderArgs const& renderArgs)
    {
        try
        {
            auto adaptiveFactSet = cardElement.as<winrt::AdaptiveFactSet>();

            winrt::xaml_controls::Grid xamlGrid{};

            winrt::xaml_controls::ColumnDefinition titleColumn{};
            winrt::xaml_controls::ColumnDefinition valueColumn{};

            winrt::xaml::GridLength factSetGridTitleLength{0, winrt::xaml::GridUnitType::Auto};
            winrt::xaml::GridLength factSetGridValueLength{1, winrt::xaml::GridUnitType::Star};

            titleColumn.Width(factSetGridTitleLength);
            valueColumn.Width(factSetGridValueLength);

            auto columnDefinitions = xamlGrid.ColumnDefinitions();
            columnDefinitions.Append(titleColumn);
            columnDefinitions.Append(valueColumn);

            winrt::xaml::GridLength factSetGridHeight{0, winrt::xaml::GridUnitType::Auto};

            auto heightType = cardElement.Height();

            if (heightType == winrt::HeightType::Stretch)
            {
                factSetGridHeight = {1, winrt::xaml::GridUnitType::Star};
            }

            auto facts = adaptiveFactSet.Facts();

            int currentFact = 0, validFacts = 0;

            for (auto fact : facts)
            {
                winrt::xaml_controls::RowDefinition factRow{};
                factRow.Height(factSetGridHeight);

                auto rowDefinitions = xamlGrid.RowDefinitions();
                rowDefinitions.Append(factRow);

                auto hostConfig = renderContext.HostConfig();
                auto factSetConfig = hostConfig.FactSet();

                // Get Language
                winrt::hstring language = fact.Language();

                // Create the title xaml textblock and style it from Host options
                auto titleTextConfig = factSetConfig.Title();
                winrt::xaml_controls::TextBlock titleTextBlock{};

                winrt::hstring factTitle = fact.Title();

                SetXamlInlinesWithFactSetTextConfig(renderContext, renderArgs, titleTextConfig, language, factTitle, titleTextBlock);

                // Create the value xaml textblock and style it from Host options
                auto valueTextConfig = factSetConfig.Value();
                winrt::xaml_controls::TextBlock valueTextBlock{};

                winrt::hstring factValue = fact.Value();

                SetXamlInlinesWithFactSetTextConfig(renderContext, renderArgs, valueTextConfig, language, factValue, valueTextBlock);

                if (!factTitle.empty() || !factValue.empty())
                {
                    // Mark the column container with the current column

                    auto spacing = factSetConfig.Spacing();
                    titleTextBlock.Margin({0, 0, (double)spacing, 0});

                    XamlHelpers::SetStyleFromResourceDictionary(renderContext, L"Adaptive.Fact.Title", titleTextBlock);

                    XamlHelpers::SetStyleFromResourceDictionary(renderContext, L"Adaptive.Fact.Value", valueTextBlock);

                    winrt::xaml_controls::Grid::SetColumn(titleTextBlock, 0);
                    winrt::xaml_controls::Grid::SetRow(titleTextBlock, currentFact);

                    winrt::xaml_controls::Grid::SetColumn(valueTextBlock, 1);
                    winrt::xaml_controls::Grid::SetRow(valueTextBlock, currentFact);

                    // Finally add the column container to the grid, and increment the column count

                    XamlHelpers::AppendXamlElementToPanel(titleTextBlock, xamlGrid);
                    XamlHelpers::AppendXamlElementToPanel(valueTextBlock, xamlGrid);
                    ++currentFact;
                    ++validFacts;
                }
            }

            if (validFacts == 0)
            {
                return nullptr;
            }

            XamlHelpers::SetStyleFromResourceDictionary(renderContext, L"Adaptive.FactSet", xamlGrid);

            return xamlGrid;
        }
        catch (winrt::hresult_error const& ex)
        {
            XamlHelpers::ErrForRenderFailedForElement(renderContext, cardElement.ElementTypeString(), ex.message());
            return nullptr;
        }
    }
}
