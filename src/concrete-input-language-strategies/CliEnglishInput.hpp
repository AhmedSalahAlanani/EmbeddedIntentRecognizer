#ifndef CLI_ENGLISH_INPUT_HPP
#define CLI_ENGLISH_INPUT_HPP

#include "interfaces/IInputLanguageStrategy.hpp"

namespace embeddedIntentRecognizer
{
    class CliEnglishInput : public IInputLanguageStrategy
    {
    private:
        void waitForInput(std::string &receivedInput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // CLI_ENGLISH_INPUT_HPP