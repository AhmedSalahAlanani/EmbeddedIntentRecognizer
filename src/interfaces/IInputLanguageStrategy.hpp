#ifndef I_INPUT_LANGUAGE_STRATEGY_HPP
#define I_INPUT_LANGUAGE_STRATEGY_HPP

#include <string>

namespace embeddedIntentRecognizer
{
    class IInputLanguageStrategy
    {
    public:
        virtual ~IInputLanguageStrategy() = default;
        virtual void waitForInput(std::string &receivedInput) const = 0;
    };

} // namespace embeddedIntentRecognizer

#endif // I_INPUT_LANGUAGE_STRATEGY_HPP