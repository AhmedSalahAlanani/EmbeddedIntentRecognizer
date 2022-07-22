#ifndef EMBEDDED_INTENT_RECOGNIZER_HPP
#define EMBEDDED_INTENT_RECOGNIZER_HPP

#include <vector>
#include <memory>

#include "ConfigManager.hpp"
#include "InputStrategyContext.hpp"
#include "TextProcessor.hpp"
#include "interfaces/IOutputDevice.hpp"

namespace embeddedIntentRecognizer
{
    class EmbeddedIntentRecognizer
    {
    public:
        bool init();
        bool run();

    private:
        ConfigManager m_configManager;
        InputStrategyContext m_inputStartegyContext;
        TextProcessor m_textProcessor;
        std::vector<std::unique_ptr<IOutputDevice>> m_outputDevices;

        void addOutputDevices(const ApplicationConfig &applicationConfig);
        static inline void clearScreen();
    };

} // namespace embeddedIntentRecognizer

#endif // EMBEDDED_INTENT_RECOGNIZER_HPP