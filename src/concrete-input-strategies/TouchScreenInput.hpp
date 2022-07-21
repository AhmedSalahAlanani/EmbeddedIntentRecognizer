#ifndef TOUCH_SCREEN_INPUT_HPP
#define TOUCH_SCREEN_INPUT_HPP

#include "interfaces/IInputStrategy.hpp"

namespace embeddedIntentRecognizer
{
    class TouchScreenInput : public IInputStrategy
    {
    private:
        bool init(SupportedLanguages language) override;
        void waitForInput(std::string &receivedInput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // TOUCH_SCREEN_INPUT_HPP