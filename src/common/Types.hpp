//!
//! \file       Types.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Common Types for Embedded Intent Recognizer Application
//!

//---------------------------------------------------------------------------
#ifndef TYPES_HPP
#define TYPES_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <cstdint>
#include <limits>
//---------------------------------------------------------------------------
// Forward Declarations
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//!
//! \namespace embeddedIntentRecognizer
//!
//! \brief Embedded Intent Recognizer namespace
//!
namespace embeddedIntentRecognizer
{
    //---------------------------------------------------------------------------
    //!
    //! \enum       mapper::SupportedInputs
    //!
    //! \brief      it holds all the currently supported input devices to the
    //!             application
    //!
    enum class SupportedInputs : uint8_t
    {
        CLI_INPUT = 0U,
        TOUCH_SCREEN_INPUT = 1U,
        VOICE_INPUT = 2U,
        // other supported input types can be added here
        UNKNOWN = std::numeric_limits<uint8_t>::max()
    };
    //---------------------------------------------------------------------------
    //!
    //! \enum       mapper::SupportedLanguages
    //!
    //! \brief      it holds all the currently supported input languages either by
    //!             input devices, output devices, or text processor itself
    //!
    enum class SupportedLanguages : uint8_t
    {
        ENGLISH = 0U,
        DEUTSCH = 1U,
        // other languages can be added here
        UNKNOWN = std::numeric_limits<uint8_t>::max()
    };
    //---------------------------------------------------------------------------
    //!
    //! \enum       mapper::SupportedLanguages
    //!
    //! \brief      it holds all the input text types classifications, where
    //!             currently the text processor can classify the input text
    //!             to either exit command or normal text
    //!
    enum class InputTextType : uint8_t
    {
        EXIT_COMMAND = 0U,
        NORMAL_TEXT = 1U,
        // other commands can be added here
        UNKNOWN = std::numeric_limits<uint8_t>::max()
    };
    //---------------------------------------------------------------------------
    //!
    //! \struct     ApplicationConfig
    //!
    //! \brief      it holds all the currently supported cofiguration
    //!
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

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------