#pragma once

#include "pch.h"
#include "Enums.h"
#include "BaseCardElement.h"
#include "BackgroundImage.h"

namespace AdaptiveSharedNamespace
{
    class BaseActionElement;

    class Container : public BaseCardElement
    {
        friend class ContainerParser;

    public:
        Container();

        Json::Value SerializeToJsonValue() const override;

        std::shared_ptr<BackgroundImage> GetBackgroundImage() const;
		void SetBackgroundImage(const std::shared_ptr<BackgroundImage> value);
		
        std::vector<std::shared_ptr<BaseCardElement>>& GetItems();
        const std::vector<std::shared_ptr<BaseCardElement>>& GetItems() const;

        ContainerStyle GetStyle() const;
        void SetStyle(const ContainerStyle value);

        std::shared_ptr<BaseActionElement> GetSelectAction() const;
        void SetSelectAction(const std::shared_ptr<BaseActionElement> action);

        void SetLanguage(const std::string& value);

        VerticalContentAlignment GetVerticalContentAlignment() const;
        void SetVerticalContentAlignment(const VerticalContentAlignment value);

        void GetResourceInformation(std::vector<RemoteResourceInformation>& resourceInfo) override;

    private:
        void PopulateKnownPropertiesSet() override;

        ContainerStyle m_style;
        VerticalContentAlignment m_verticalContentAlignment;
        std::vector<std::shared_ptr<AdaptiveSharedNamespace::BaseCardElement>> m_items;
        std::shared_ptr<BaseActionElement> m_selectAction;
		std::shared_ptr<BackgroundImage> m_backgroundImage;
    };

    class ContainerParser : public BaseCardElementParser
    {
    public:
        ContainerParser() = default;
        ContainerParser(const ContainerParser&) = default;
        ContainerParser(ContainerParser&&) = default;
        ContainerParser& operator=(const ContainerParser&) = default;
        ContainerParser& operator=(ContainerParser&&) = default;
        ~ContainerParser() = default;

        std::shared_ptr<BaseCardElement> Deserialize(ParseContext& context, const Json::Value& root) override;
        std::shared_ptr<BaseCardElement> DeserializeFromString(ParseContext& context, const std::string& jsonString) override;
    };
}
