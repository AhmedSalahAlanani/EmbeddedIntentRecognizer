#ifndef CLI_INPUT_HPP
#define CLI_INPUT_HPP

#include <memory>

#include "interfaces/IInputStrategy.hpp"
#include "interfaces/IInputLanguageStrategy.hpp"

namespace embeddedIntentRecognizer
{
    class CliInput : public IInputStrategy
    {
    private:
        std::unique_ptr<IInputLanguageStrategy> m_inputLanguageStrategy;

        bool init(SupportedLanguages language) override;
        void waitForInput(std::string &receivedInput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // CLI_INPUT_HPP