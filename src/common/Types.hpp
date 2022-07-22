#ifndef TYPES_HPP
#define TYPES_HPP

#include <cstdint>
#include <limits>

namespace embeddedIntentRecognizer
{
    enum class SupportedInputs : uint8_t
    {
        CLI_INPUT = 0U,
        TOUCH_SCREEN_INPUT = 1U,
        VOICE_INPUT = 2U,
        // other supported input types can be added here
        UNKNOWN = std::numeric_limits<uint8_t>::max()
    };

    enum class SupportedLanguages : uint8_t
    {
        ENGLISH = 0U,
        DEUTSCH = 1U,
        // other languages can be added here
        UNKNOWN = std::numeric_limits<uint8_t>::max()
    };

    enum class InputTextType : uint8_t
    {
        TEXT = 0U,
        EXIT_COMMAND = 1U,
        // other commands can be added here
        UNKNOWN = std::numeric_limits<uint8_t>::max()
    };

    typedef struct ApplicationConfig
    {
        SupportedLanguages language{SupportedLanguages::UNKNOWN};
        SupportedInputs inputType{SupportedInputs::UNKNOWN};
        bool cliOutput{false};
        bool touchScreenOutput{false};
        bool voiceOutput{false};
    } ApplicationConfig;

} // namespace embeddedIntentRecognizer

#endif // TYPES_HPP