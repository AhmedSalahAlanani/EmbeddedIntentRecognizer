#ifndef TOUCH_SCREEN_OUTPUT_HPP
#define TOUCH_SCREEN_OUTPUT_HPP

#include "interfaces/ITextProcessorOutputObserver.hpp"

namespace embeddedIntentRecognizer
{
    class TouchScreenOutput : public ITextProcessorOutputObserver
    {
    private:
        void onNewOutputReady(const std::string &textProcessorOutput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // TOUCH_SCREEN_OUTPUT_HPP