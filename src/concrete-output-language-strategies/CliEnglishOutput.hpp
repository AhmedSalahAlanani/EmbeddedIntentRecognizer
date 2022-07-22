#ifndef CLI_ENGLISH_OUTPUT_HPP
#define CLI_ENGLISH_OUTPUT_HPP

#include "interfaces/IOutputLanguageStrategy.hpp"

namespace embeddedIntentRecognizer
{
    class CliEnglishOutput : public IOutputLanguageStrategy
    {
    private:
        void convertTextToOutput(const std::string &text) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // CLI_ENGLISH_OUTPUT_HPP