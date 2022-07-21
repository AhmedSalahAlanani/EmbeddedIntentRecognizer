#include <iostream>

#include "TouchScreenInput.hpp"

namespace embeddedIntentRecognizer
{
    bool TouchScreenInput::init(SupportedLanguages language)
    {
        std::cout << "[ERROR]: Touch Screen Input is currently not supported.\n";
        return false;
    }

    void TouchScreenInput::waitForInput(std::string &receivedInput) const
    {
    }

} // namespace embeddedIntentRecognizer