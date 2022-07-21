#include <iostream>

#include "TouchScreenOutput.hpp"

namespace embeddedIntentRecognizer
{
    void TouchScreenOutput::onNewOutputReady(const std::string &textProcessorOutput) const
    {
        std::cout << "[WARNING]: Touch Screen Output was enabled, but not currently supported!\n";
    }
} // namespace embeddedIntentRecognizer