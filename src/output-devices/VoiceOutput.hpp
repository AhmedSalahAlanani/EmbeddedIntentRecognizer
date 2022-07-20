#ifndef VOICE_OUTPUT_HPP
#define VOICE_OUTPUT_HPP

#include "interfaces/ITextProcessorOutputObserver.hpp"

namespace embeddedIntentRecognizer
{
    class VoiceOutput : public ITextProcessorOutputObserver
    {
    private:
        void onNewOutputReady(const std::string &textProcessorOutput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // VOICE_OUTPUT_HPP