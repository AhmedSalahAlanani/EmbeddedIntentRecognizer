#ifndef TYPES_HPP
#define TYPES_HPP

#include <cstdint>

namespace embeddedIntentRecognizer
{
    enum class SupportedInputs : uint8_t
    {
        CLI_INPUT = 0U,
        TOUCH_SCREEN_INPUT = 1U,
        VOICE_INPUT = 2U,
    };

    enum class SupportedLanguages : uint8_t
    {
        ENGLISH = 0U,
        DEUTSCH = 1U,
    };

    typedef struct ApplicationConfig
    {
        SupportedInputs inputType;
        SupportedLanguages language;
        bool cliOutput;
        bool touchScreenOutput;
        bool voiceOutput;
    } ApplicationConfig;

} // namespace embeddedIntentRecognizer

#endif // TYPES_HPP