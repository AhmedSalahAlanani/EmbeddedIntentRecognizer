#include <iostream>

#include "common/Types.hpp"
#include "EmbeddedIntentRecognizer.hpp"

namespace embeddedIntentRecognizer
{
    bool EmbeddedIntentRecognizer::init() const
    {
        std::cout << "Starting Application..\n";

        ApplicationConfig applicationConfig;
        bool state = m_configManager.loadConfig(applicationConfig);
        if (!state)
        {
            std::cout << "Failed to load Configuration.\n";
            return false;
        }
        std::cout << "Configuration was loaded successfully.\n";

        state = m_inputStartegyContext.init(applicationConfig.inputType, applicationConfig.language);
        if (!state)
        {
            std::cout << "Failed to initialize Input strategy.\n";
            return false;
        }
        std::cout << "Initializing Input Strategy was successful.\n";

        state = m_textProcessor.init();
        if (!state)
        {
            std::cout << "Failed to initialize Input Text Processor.\n";
            return false;
        }
        std::cout << "Initializing Input Text Processor was successful.\n";

        // add output types  chosen from configuration as observers to text processor

        std::cout << "Initialization was successful.\n";
        return true;
    }

    bool EmbeddedIntentRecognizer::run() const
    {
        std::cout << "Embedded Intent Recognizer has started..\n";

        // application logic will go here
        while (true)
        {
            std::string receievdInput;
            m_inputStartegyContext.waitForInput(receievdInput);
        }

        return false;
    }

} // namespace embeddedIntentRecognizer