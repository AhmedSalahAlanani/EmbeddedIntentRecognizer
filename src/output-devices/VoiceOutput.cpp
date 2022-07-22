#include <iostream>

#include "common/Types.hpp"
#include "VoiceOutput.hpp"

namespace embeddedIntentRecognizer
{
    bool VoiceOutput::init(SupportedLanguages language)
    {
        return false;
    }

    void VoiceOutput::onNewOutputReady(const std::string &textProcessorOutput)
    {
        std::cout << "[WARNING]: Voice Output was enabled, but not currently supported!\n";
    }

} // namespace embeddedIntentRecognizer