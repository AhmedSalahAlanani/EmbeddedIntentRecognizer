#ifndef CLI_OUTPUT_HPP
#define CLI_OUTPUT_HPP

#include <memory>

#include "interfaces/IOutputLanguageStrategy.hpp"
#include "interfaces/IOutputDevice.hpp"

namespace embeddedIntentRecognizer
{
    class CliOutput : public IOutputDevice
    {
    private:
        std::unique_ptr<IOutputLanguageStrategy> m_outputLanguageStrategy;

        bool init(SupportedLanguages language) override;
        void onNewOutputReady(const std::string &textProcessorOutput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // CLI_OUTPUT_HPP