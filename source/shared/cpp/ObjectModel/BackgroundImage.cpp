#include "pch.h"
#include "BackgroundImage.h"
#include "ParseUtil.h"
#include "ParseContext.h"

using namespace AdaptiveSharedNamespace;

BackgroundImage::BackgroundImage()
{
}

std::shared_ptr<BackgroundImage> BackgroundImage::Deserialize(const Json::Value& value)
{
	std::shared_ptr<BackgroundImage> backgroundImage = std::make_shared<BackgroundImage>();
	backgroundImage->SetType(ParseUtil::GetString(value, AdaptiveCardSchemaKey::Type));
	backgroundImage->SetUrl(ParseUtil::GetString(value, AdaptiveCardSchemaKey::Url));
	backgroundImage->SetMode(ParseUtil::GetString(value, AdaptiveCardSchemaKey::Mode));
	backgroundImage->SetHorizontalAlignment(ParseUtil::GetEnumValue<HorizontalAlignment>(
		value, AdaptiveCardSchemaKey::HorizontalAlignment, HorizontalAlignment::Left, HorizontalAlignmentFromString));
	backgroundImage->SetVerticalAlignment(ParseUtil::GetEnumValue<VerticalAlignment>(
	 	value, AdaptiveCardSchemaKey::VerticalAlignment, VerticalAlignment::Top, VerticalAlignmentFromString));

    return backgroundImage;
}

void BackgroundImage::SetType(const std::string& value)
{
	m_type = value;
}

std::string BackgroundImage::GetType()
{
	return m_type;
}

void BackgroundImage::SetMode(const std::string& value)
{
	m_mode = value;
}

std::string BackgroundImage::GetMode()
{
	return m_mode;
}

void BackgroundImage::SetUrl(const std::string& value)
{
	m_url = value;
}

std::string BackgroundImage::GetUrl()
{
	return m_url;
}

void BackgroundImage::SetHorizontalAlignment(const HorizontalAlignment& value)
{
	m_horizontalAlignment = value;
}

HorizontalAlignment BackgroundImage::GetHorizontalAlignment()
{
	return m_horizontalAlignment;
}

void BackgroundImage::SetVerticalAlignment(const VerticalAlignment& value)
{
	m_verticalAlignment = value;
}

VerticalAlignment BackgroundImage::GetVerticalAlignment()
{
	return m_verticalAlignment;
}
