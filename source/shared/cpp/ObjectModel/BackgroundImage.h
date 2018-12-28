#pragma once

#include "pch.h"
#include "Enums.h"
#include "json/json.h"

namespace AdaptiveSharedNamespace
{
	class BackgroundImage
	{
	public:
		BackgroundImage();

		void SetType(const std::string& value);
		std::string GetType();
		
		void SetMode(const std::string& value);
		std::string GetMode();
		
		void SetUrl(const std::string& value);
		std::string GetUrl();
		
		void SetHorizontalAlignment(const HorizontalAlignment& value);
		HorizontalAlignment GetHorizontalAlignment();

		void SetVerticalAlignment(const VerticalAlignment& value);
		VerticalAlignment GetVerticalAlignment();

		static std::shared_ptr<BackgroundImage> Deserialize(const Json::Value& root);

	private:
		std::string m_type;
		std::string m_mode;
		std::string m_url;
		HorizontalAlignment m_horizontalAlignment;
		VerticalAlignment m_verticalAlignment;
	};
}