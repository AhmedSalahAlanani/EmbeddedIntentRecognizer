#include <iostream>

#include "common/Types.hpp"
#include "concrete-output-language-strategies/CliEnglishOutput.hpp"
#include "CliOutput.hpp"

namespace embeddedIntentRecognizer
{
    bool CliOutput::init(SupportedLanguages language)
    {
        switch (language)
        {
        case SupportedLanguages::ENGLISH:
        {
            m_outputLanguageStrategy = std::make_unique<CliEnglishOutput>();
            break;
        }
        case SupportedLanguages::DEUTSCH:
        {
            std::cout << "[ERROR]: Output Language Deutsch support is currently not implemented.\n";
            return false;
        }
        default:
        {
            std::cout << "[ERROR]: Received Unknown Output Language!.\n";
            return false;
        }
        }

        if (m_outputLanguageStrategy == nullptr)
        {
            std::cout << "[ERROR]: Failed to set Output Language!.\n";
            return false;
        }

        std::cout << "[VERBOSE]: Output Language was set successfully.\n";
        return true;
    }

    void CliOutput::onNewOutputReady(const std::string &textProcessorOutput) const
    {
        m_outputLanguageStrategy->convertTextToOutput(textProcessorOutput);
    }

} // namespace embeddedIntentRecognizer