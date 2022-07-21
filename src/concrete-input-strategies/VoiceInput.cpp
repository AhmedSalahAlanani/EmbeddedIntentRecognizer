#include <iostream>

#include "VoiceInput.hpp"

namespace embeddedIntentRecognizer
{
    bool VoiceInput::init(SupportedLanguages language)
    {
        std::cout << "[ERROR]: Voice Input is currently not supported.\n";
        return false;
    }

    void VoiceInput::waitForInput(std::string &receivedInput) const
    {
    }

} // namespace embeddedIntentRecognizer