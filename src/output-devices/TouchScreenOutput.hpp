#ifndef TOUCH_SCREEN_OUTPUT_HPP
#define TOUCH_SCREEN_OUTPUT_HPP

#include "interfaces/IOutputDevice.hpp"

namespace embeddedIntentRecognizer
{
    class TouchScreenOutput : public IOutputDevice
    {
    private:
        bool init(SupportedLanguages language) override;
        void onNewOutputReady(const std::string &textProcessorOutput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // TOUCH_SCREEN_OUTPUT_HPP