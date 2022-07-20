#ifndef I_INPUT_STRATEGY_HPP
#define I_INPUT_STRATEGY_HPP

#include <string>

namespace embeddedIntentRecognizer
{
    class IInputStrategy
    {
    public:
        virtual ~IInputStrategy() = default;
        virtual bool init() const = 0;
        virtual void waitForInput(std::string &receivedInput) const = 0;
    };

} // namespace embeddedIntentRecognizer

#endif // I_INPUT_STRATEGY_HPP