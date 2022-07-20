#ifndef I_TEXT_PROCESSOR_OUTPUT_OBSERVER_HPP
#define I_TEXT_PROCESSOR_OUTPUT_OBSERVER_HPP

#include <string>

namespace embeddedIntentRecognizer
{
    class ITextProcessorOutputObserver
    {
    public:
        virtual ~ITextProcessorOutputObserver() = default;
        virtual void onNewOutputReady(const std::string &textProcessorOutput) const = 0;
    };

} // namespace embeddedIntentRecognizer

#endif // I_TEXT_PROCESSOR_OUTPUT_OBSERVER_HPP