#ifndef VOICE_OUTPUT_HPP
#define VOICE_OUTPUT_HPP

#include "interfaces/IOutputDevice.hpp"

namespace embeddedIntentRecognizer
{
    class VoiceOutput : public IOutputDevice
    {
    private:
        bool init(SupportedLanguages language) override;
        void onNewOutputReady(const std::string &textProcessorOutput) override;
    };

} // namespace embeddedIntentRecognizer

#endif // VOICE_OUTPUT_HPP