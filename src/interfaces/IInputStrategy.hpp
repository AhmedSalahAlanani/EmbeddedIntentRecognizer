#ifndef I_INPUT_STRATEGY_HPP
#define I_INPUT_STRATEGY_HPP

#include <string>

#include "common/Types.hpp"

namespace embeddedIntentRecognizer
{
    class IInputStrategy
    {
    public:
        virtual ~IInputStrategy() = default;
        virtual bool init(SupportedLanguages language) = 0;
        virtual void waitForInput(std::string &receivedInput) const = 0;
    };

} // namespace embeddedIntentRecognizer

#endif // I_INPUT_STRATEGY_HPP