#ifndef EMBEDDED_INTENT_RECOGNIZER_HPP
#define EMBEDDED_INTENT_RECOGNIZER_HPP

#include "ConfigManager.hpp"
#include "InputStrategyContext.hpp"
#include "TextProcessor.hpp"

namespace embeddedIntentRecognizer
{
    class EmbeddedIntentRecognizer
    {
    public:
        bool init() const;
        bool run() const;

    private:
        ConfigManager m_configManager;
        InputStrategyContext m_inputStartegyContext;
        TextProcessor m_textProcessor;
    };

} // namespace embeddedIntentRecognizer

#endif // EMBEDDED_INTENT_RECOGNIZER_HPP