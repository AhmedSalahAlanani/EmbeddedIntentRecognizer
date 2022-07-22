#include <iostream>

#include "common/Types.hpp"
#include "TouchScreenOutput.hpp"

namespace embeddedIntentRecognizer
{
    bool TouchScreenOutput::init(SupportedLanguages language)
    {
        return false;
    }

    void TouchScreenOutput::onNewOutputReady(const std::string &textProcessorOutput) const
    {
        std::cout << "[WARNING]: Touch Screen Output was enabled, but not currently supported!\n";
    }
} // namespace embeddedIntentRecognizer