#include <iostream>

#include "CliOutput.hpp"

namespace embeddedIntentRecognizer
{
    void CliOutput::onNewOutputReady(const std::string &textProcessorOutput) const
    {
        std::cout << textProcessorOutput << "\n";
    }

} // namespace embeddedIntentRecognizer