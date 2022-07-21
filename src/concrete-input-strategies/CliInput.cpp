#include <iostream>

#include "concrete-input-language-strategies/CliEnglishInput.hpp"
#include "CliInput.hpp"

namespace embeddedIntentRecognizer
{
    bool CliInput::init(SupportedLanguages language)
    {
        switch (language)
        {
        case SupportedLanguages::ENGLISH:
        {
            m_inputLanguageStrategy = std::make_unique<CliEnglishInput>();
            break;
        }
        case SupportedLanguages::DEUTSCH:
        {
            std::cout << "[ERROR]: Input Language Deutsch is currently not supported.\n";
            return false;
        }
        default:
        {
            std::cout << "[ERROR]: Received Unknown Input Language!.\n";
            return false;
        }
        }

        if (m_inputLanguageStrategy == nullptr)
        {
            std::cout << "[ERROR]: Failed to set Input Language!.\n";
            return false;
        }

        std::cout << "Input Language was set successfully.\n";
        return true;
    }

    void CliInput::waitForInput(std::string &receivedInput) const
    {
        m_inputLanguageStrategy->waitForInput(receivedInput);
    }

} // namespace embeddedIntentRecognizer