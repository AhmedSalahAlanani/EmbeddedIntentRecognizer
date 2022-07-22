#include <iostream>

#include "CliEnglishOutput.hpp"

namespace embeddedIntentRecognizer
{
    void CliEnglishOutput::convertTextToOutput(const std::string &text) const
    {
        // Output-specific operations for this language, should be handled
        // by this method. So that the text received from the message
        // processor can be converted to the expected output format.
        // And similarly for all other output devices and languages.
        std::cout << text << "\n";
    }

} // namespace embeddedIntentRecognizer