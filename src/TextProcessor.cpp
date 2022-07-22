#include <iostream>
#include <algorithm>

#include "intent-recognition-models/EnglishLanguageModel.hpp"
#include "TextProcessor.hpp"

namespace
{
    // supported commands
    static constexpr char g_exitCommand[] = "Exit";
    static constexpr char g_quitCommand[] = "Quit";

} // anonymous namespace

namespace embeddedIntentRecognizer
{
    bool TextProcessor::init(const ApplicationConfig &configuration)
    {
        std::cout << "[INFO]: Initializing Text Processor..\n";

        switch (configuration.language)
        {
        case SupportedLanguages::ENGLISH:
        {
            m_intentRecognitionModel = std::make_unique<EnglishLanguageModel>();
            break;
        }
        case SupportedLanguages::DEUTSCH:
        {
            std::cout << "[ERROR]: Model for Language Deutsch is currently not supported.\n";
            return false;
        }
        default:
        {
            std::cout << "[ERROR]: Received Unknown Input Language!.\n";
            return false;
        }
        }

        const bool state = m_intentRecognitionModel->loadDataSet();
        if (!state)
        {
            std::cout << "[ERROR]: Failed to load Data Set for the selected Model!.\n";
            return false;
        }

        std::cout << "[INFO]: Text Processor was initialized successfully.\n";
        return true;
    }

    void TextProcessor::attach(ITextProcessorOutputObserver *observer)
    {
        m_observers.emplace_back(observer);

        std::cout << "[DEBUG]: Current number of observers = " << m_observers.size() << "\n";
    }

    void TextProcessor::detach(ITextProcessorOutputObserver *observer)
    {
        const auto it = std::find(m_observers.begin(), m_observers.end(), observer);
        if (it == m_observers.end())
        {
            std::cout << "[WARNING]: This observer wasn't stored before, observers won't be modified..\n";
            return;
        }

        m_observers.erase(it);
    }

    void TextProcessor::processText(const std::string &text, InputTextType &inputType)
    {
        if (text == g_exitCommand || text == g_quitCommand)
        {
            inputType = InputTextType::EXIT_COMMAND;
            return;
        }

        inputType = InputTextType::NORMAL_TEXT;
        m_intentRecognitionModel->getIntent(text, m_lastProcessedOutput);
    }

    void TextProcessor::notifyOutputObservers() const
    {
        for (const auto &observer : m_observers)
        {
            observer->onNewOutputReady(m_lastProcessedOutput);
        }
    }

} // namespace embeddedIntentRecognizer