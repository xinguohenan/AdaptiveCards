#pragma once

#include "pch.h"
#include "Enums.h"

namespace AdaptiveSharedNamespace
{
#pragma warning(push)
#pragma warning(disable: 26495)
// Disable incorrect warning about m_statusCode not being initialized (see
// AdaptiveCardParseException::AdaptiveCardParseException())

    class AdaptiveCardParseException : public std::exception
    {
    public:
        AdaptiveCardParseException(AdaptiveSharedNamespace::ErrorStatusCode statusCode, const std::string& message);

        virtual const char* what() const throw();
        AdaptiveSharedNamespace::ErrorStatusCode GetStatusCode() const;
        const std::string& GetReason() const;

    private:
        const AdaptiveSharedNamespace::ErrorStatusCode m_statusCode;
        const std::string m_message;
    };
#pragma warning(pop)
}
