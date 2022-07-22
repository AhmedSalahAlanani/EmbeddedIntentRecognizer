#include <iostream>

#include "CliEnglishInput.hpp"

namespace embeddedIntentRecognizer
{
    void CliEnglishInput::waitForInput(std::string &receivedInput) const
    {
        std::cout << "Please enter a new sentence or type: \"Exit\" or \"Quit\" to exit the application\n";

        // Input-specific operations for this language, should be handled
        // by this method. And similarly for all other inputs and languages.
        getline(std::cin, receivedInput);
    }

} // namespace embeddedIntentRecognizer