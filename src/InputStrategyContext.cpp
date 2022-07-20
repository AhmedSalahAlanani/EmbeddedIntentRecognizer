#include <iostream>

#include "InputStrategyContext.hpp"

namespace embeddedIntentRecognizer
{
    bool InputStrategyContext::init(SupportedLanguages language, SupportedInputs inputType) const
    {
        std::cout << "Initializing Input stratetgy..\n";

        // take the configuration and set the strategy
        // you might need to delegate some init stuff to the selected strategy as well

        if (m_inputStrategy != nullptr)
        {
            const bool state = m_inputStrategy->init();
            if (!state)
            {
                std::cout << "Error: Failed to initialize the selected Input strategy.\n";
                return false;
            }
        }

        return false;
    }

    void InputStrategyContext::waitForInput(std::string &receivedInput) const
    {
        m_inputStrategy->waitForInput(receivedInput);
    }

} // namespace embeddedIntentRecognizer