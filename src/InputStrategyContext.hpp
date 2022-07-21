#ifndef INPUT_STRATEGY_CONTEXT_HPP
#define INPUT_STRATEGY_CONTEXT_HPP

#include <memory>

#include "common/Types.hpp"
#include "interfaces/IInputStrategy.hpp"

namespace embeddedIntentRecognizer
{
    class InputStrategyContext
    {
    public:
        bool init(SupportedLanguages language, SupportedInputs inputType);
        void waitForInput(std::string &receivedInput) const;

    private:
        std::unique_ptr<IInputStrategy> m_inputStrategy;
    };

} // namespace embeddedIntentRecognizer

#endif // INPUT_STRATEGY_CONTEXT_HPP