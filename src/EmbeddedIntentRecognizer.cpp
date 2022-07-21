#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

#include "common/Types.hpp"
#include "output-devices/CliOutput.hpp"
#include "output-devices/TouchScreenOutput.hpp"
#include "output-devices/VoiceOutput.hpp"
#include "EmbeddedIntentRecognizer.hpp"

namespace embeddedIntentRecognizer
{
    bool EmbeddedIntentRecognizer::init()
    {
        std::cout << "Starting Application..\n";

        ApplicationConfig applicationConfig;
        bool state = m_configManager.loadConfig(applicationConfig);
        if (!state)
        {
            std::cout << "[ERROR]: Failed to load Configuration.\n";
            return false;
        }
        std::cout << "[INFO]: Configuration was loaded successfully.\n";

        state = m_inputStartegyContext.init(applicationConfig.language, applicationConfig.inputType);
        if (!state)
        {
            std::cout << "[ERROR]: Failed to initialize Input strategy.\n";
            return false;
        }
        std::cout << "[INFO]: Initializing Input Strategy was successful.\n";

        state = m_textProcessor.init();
        if (!state)
        {
            std::cout << "[ERROR]: Failed to initialize Input Text Processor.\n";
            return false;
        }
        std::cout << "[INFO]: Initializing Input Text Processor was successful.\n";

        // add output types  chosen from configuration as observers to text processor
        if (applicationConfig.cliOutput)
        {
            m_outputDevices.emplace_back(std::make_unique<CliOutput>());
        }
        if (applicationConfig.touchScreenOutput)
        {
            m_outputDevices.emplace_back(std::make_unique<TouchScreenOutput>());
        }
        if (applicationConfig.voiceOutput)
        {
            m_outputDevices.emplace_back(std::make_unique<VoiceOutput>());
        }

        // add output devices as observers to the Text Processor
        if (m_outputDevices.empty())
        {
            std::cout << "[WARNING]: None of the output devices were Enabled!\n";
        }
        else
        {
            for (const auto &outputDevice : m_outputDevices)
            {
                m_textProcessor.attach(outputDevice.get());
            }
        }

        std::cout << "[INFO]: Initialization was successful.\n";
        clearScreen();
        return true;
    }

    bool EmbeddedIntentRecognizer::run()
    {
        std::cout << "[INFO]: Embedded Intent Recognizer has started..\n";

        // application logic will go here
        while (true)
        {
            std::string input;
            InputTextType inputType;
            m_inputStartegyContext.waitForInput(input);

            m_textProcessor.processText(input, inputType);
            switch (inputType)
            {
            case InputTextType::TEXT:
            {
                m_textProcessor.notifyOutputObservers();
                break;
            }
            case InputTextType::EXIT_COMMAND:
            {
                std::cout << "[INFO]: Exit command was received.\n";
                return true;
            }
            default:
            {
                std::cout << "[ERROR]: Received unrecognized input.\n";
                return false;
            }
            }
        }

        return false;
    }

    inline void EmbeddedIntentRecognizer::clearScreen()
    {
        std::this_thread::sleep_for(std::chrono::seconds{2U});

#if (defined(unix) || defined(__unix) || defined(__unix__)) // Linux
        std::system("clear");
#elif (defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)) // Windows
        std::system("cls")
#endif
    }

} // namespace embeddedIntentRecognizer