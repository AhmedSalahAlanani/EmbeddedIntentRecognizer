#include <iostream>

#include "VoiceOutput.hpp"

namespace embeddedIntentRecognizer
{
    void VoiceOutput::onNewOutputReady(const std::string &textProcessorOutput) const
    {
        std::cout << "[WARNING]: Voice Output was enabled, but not currently supported!\n";
    }

} // namespace embeddedIntentRecognizer