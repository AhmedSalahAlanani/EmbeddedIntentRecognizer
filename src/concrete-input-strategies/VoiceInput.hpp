//!
//! \file       VoiceInput.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class VoiceInput
//!

//---------------------------------------------------------------------------
#ifndef VOICE_INPUT_HPP
#define VOICE_INPUT_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include "interfaces/IInputStrategy.hpp"
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
    //! \class      VoiceInput
    //!
    //! \brief      Class implements input Strategy in case of Voice Input.
    //!             Its responsibility is to poll for new input via Voice input
    //!             and handle the received input so that it can be then forwarded
    //!             to the TextProcessor after that
    //!
    //! \note       The implementation to this class is not finished yet
    //!
    class VoiceInput : public IInputStrategy
    {
    private:
        //! IInputStrategy inherited method
        bool init(SupportedLanguages language) override;

        //! IInputStrategy inherited method
        void waitForInput(std::string &receivedInput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // VOICE_INPUT_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------