#ifndef VOICE_INPUT_HPP
#define VOICE_INPUT_HPP

#include "interfaces/IInputStrategy.hpp"

namespace embeddedIntentRecognizer
{
    class VoiceInput : public IInputStrategy
    {
    private:
        bool init(SupportedLanguages language) override;
        void waitForInput(std::string &receivedInput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // VOICE_INPUT_HPP