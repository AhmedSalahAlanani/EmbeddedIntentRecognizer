#ifndef VOICE_OUTPUT_HPP
#define VOICE_OUTPUT_HPP

#include "interfaces/IOutputDevice.hpp"

namespace embeddedIntentRecognizer
{
    class VoiceOutput : public IOutputDevice
    {
    private:
        void onNewOutputReady(const std::string &textProcessorOutput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // VOICE_OUTPUT_HPP