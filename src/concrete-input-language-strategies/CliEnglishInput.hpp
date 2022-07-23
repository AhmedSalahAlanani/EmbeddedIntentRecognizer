//!
//! \file       CliInput.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class CliInput
//!

//---------------------------------------------------------------------------
#ifndef CLI_ENGLISH_INPUT_HPP
#define CLI_ENGLISH_INPUT_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include "interfaces/IInputLanguageStrategy.hpp"
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
    //! \class      CliEnglishInput
    //!
    //! \brief      Class implements input Language Strategy. Its responsibility
    //!             is to poll for new input in English format and/or support
    //!             any needed user interface (example: keyboard layout), after
    //!             that the input is then forwarded to the TextProcessor
    //!
    class CliEnglishInput : public IInputLanguageStrategy
    {
    private:
        //! IInputLanguageStrategy inherited method
        void waitForInput(std::string &receivedInput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // CLI_ENGLISH_INPUT_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------