#include <iostream>

#include "EmbeddedIntentRecognizer.hpp"

static constexpr auto SUCCESS = 0;
static constexpr auto GENERAL_ERROR = -1;

int main()
{
    embeddedIntentRecognizer::EmbeddedIntentRecognizer embeddedIntentRecognizer;

    bool state = embeddedIntentRecognizer.init();
    if (!state)
    {
        std::cout << "Error: Failed to initialize the application.\n";
        std::cout << "Terminating.." << std::endl;
        return GENERAL_ERROR;
    }

    state = embeddedIntentRecognizer.run();
    if (!state)
    {
        std::cout << "Error: Application terminated with error(s)." << std::endl;
        return GENERAL_ERROR;
    }

    std::cout << "Application finished successfully." << std::endl;
    return SUCCESS;
}