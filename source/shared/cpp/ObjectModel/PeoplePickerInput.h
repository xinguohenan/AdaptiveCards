#pragma once

#include "pch.h"
#include "BaseInputElement.h"
#include "Enums.h"
#include "ElementParserRegistration.h"
#include "TextInput.h"

namespace AdaptiveSharedNamespace
{
    class PeoplePickerInput : public TextInput
    {
    public:
        PeoplePickerInput();

	private:
        void PopulateKnownPropertiesSet() override;	
    };

    class PeoplePickerInputParser : public BaseCardElementParser
    {
    public:
        PeoplePickerInputParser() = default;
        PeoplePickerInputParser(const PeoplePickerInputParser&) = default;
        PeoplePickerInputParser(PeoplePickerInputParser&&) = default;
        PeoplePickerInputParser& operator=(const PeoplePickerInputParser&) = default;
        PeoplePickerInputParser& operator=(PeoplePickerInputParser&&) = default;
        ~PeoplePickerInputParser() = default;

        std::shared_ptr<BaseCardElement> Deserialize(ParseContext& context, const Json::Value& root) override;
        std::shared_ptr<BaseCardElement> DeserializeFromString(ParseContext& context, const std::string& jsonString) override;
    };
}
