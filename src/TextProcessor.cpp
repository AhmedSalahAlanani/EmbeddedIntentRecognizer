#include <iostream>
#include <algorithm>

#include "TextProcessor.hpp"

namespace
{
    // supported commands
    static constexpr char g_exitCommand[] = "Exit";

} // anonymous namespace

namespace embeddedIntentRecognizer
{
    bool TextProcessor::init() const
    {
        std::cout << "[WARNING]: Text Processor Initialization was bypassed for now, should be handled later\n";
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
        if (text == g_exitCommand)
        {
            inputType = InputTextType::EXIT_COMMAND;
            return;
        }

        // text processing shall go here
        m_lastProcessedOutput = text;
    }

    void TextProcessor::notifyOutputObservers() const
    {
        for (const auto &observer : m_observers)
        {
            observer->onNewOutputReady(m_lastProcessedOutput);
        }
    }

    bool TextProcessor::loadDataSet() const
    {
        return false;
    }

} // namespace embeddedIntentRecognizer