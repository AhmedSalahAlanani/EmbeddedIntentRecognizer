#ifndef I_OUTPUT_DEVICE_HPP
#define I_OUTPUT_DEVICE_HPP

#include "ITextProcessorOutputObserver.hpp"

namespace embeddedIntentRecognizer
{
    class IOutputDevice : public ITextProcessorOutputObserver
    {
    public:
        virtual ~IOutputDevice() = default;
        virtual bool init(SupportedLanguages language) = 0;
    };

} // namespace embeddedIntentRecognizer

#endif // I_OUTPUT_DEVICE_HPP