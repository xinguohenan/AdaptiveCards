#include "pch.h"
#include "ParseUtil.h"
#include "PeoplePickerInput.h"

using namespace AdaptiveSharedNamespace;

PeoplePickerInput::PeoplePickerInput() :
    TextInput(CardElementType::PeoplePickerInput)
{
	PopulateKnownPropertiesSet();
}

std::shared_ptr<BaseCardElement> PeoplePickerInputParser::Deserialize(ParseContext& context, const Json::Value& json)
{
    ParseUtil::ExpectTypeString(json, CardElementType::PeoplePickerInput);

    std::shared_ptr<PeoplePickerInput> peoplePickerInput = BaseInputElement::Deserialize<PeoplePickerInput>(json);

    peoplePickerInput->SetPlaceholder(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Placeholder));
    peoplePickerInput->SetValue(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Value));
    peoplePickerInput->SetIsMultiline(ParseUtil::GetBool(json, AdaptiveCardSchemaKey::IsMultiline, false));
    peoplePickerInput->SetMaxLength(ParseUtil::GetUInt(json, AdaptiveCardSchemaKey::MaxLength, 0));
    peoplePickerInput->SetTextInputStyle(
        ParseUtil::GetEnumValue<TextInputStyle>(json, AdaptiveCardSchemaKey::Style, TextInputStyle::Text, TextInputStyleFromString));
    peoplePickerInput->SetInlineAction(ParseUtil::GetAction(context, json, AdaptiveCardSchemaKey::InlineAction, false));

    return peoplePickerInput;
}

std::shared_ptr<BaseCardElement> PeoplePickerInputParser::DeserializeFromString(ParseContext& context, const std::string& jsonString)
{
    return PeoplePickerInputParser::Deserialize(context, ParseUtil::GetJsonValueFromString(jsonString));
}

void PeoplePickerInput::PopulateKnownPropertiesSet()
{
    m_knownProperties.insert({AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Placeholder),
                              AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Value),
                              AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::IsMultiline),
                              AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::MaxLength),
                              AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::PeoplePickerInput)});
}