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
        // other supported input types can be added here
    };

    enum class SupportedLanguages : uint8_t
    {
        ENGLISH = 0U,
        DEUTSCH = 1U,
        // other languages can be added here
    };

    enum class InputTextType : uint8_t
    {
        TEXT = 0U,
        EXIT_COMMAND = 1U,
        // other commands can be added here
    };

    typedef struct ApplicationConfig
    {
        SupportedLanguages language;
        SupportedInputs inputType;
        bool cliOutput;
        bool touchScreenOutput;
        bool voiceOutput;
    } ApplicationConfig;

} // namespace embeddedIntentRecognizer

#endif // TYPES_HPP