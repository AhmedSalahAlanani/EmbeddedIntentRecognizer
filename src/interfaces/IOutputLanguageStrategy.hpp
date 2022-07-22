#ifndef I_OUTPUT_LANGUAGE_STRATEGY_HPP
#define I_OUTPUT_LANGUAGE_STRATEGY_HPP

#include <string>

namespace embeddedIntentRecognizer
{
    class IOutputLanguageStrategy
    {
    public:
        virtual ~IOutputLanguageStrategy() = default;
        virtual void convertTextToOutput(const std::string &text) const = 0;
    };

} // namespace embeddedIntentRecognizer

#endif // I_INPUT_LANGUAGE_STRATEGY_HPP