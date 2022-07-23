//!
//! \file       TouchScreenInput.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class TouchScreenInput
//!

//---------------------------------------------------------------------------
#ifndef TOUCH_SCREEN_INPUT_HPP
#define TOUCH_SCREEN_INPUT_HPP
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
    //! \class      TouchScreenInput
    //!
    //! \brief      Class implements input Strategy in case of Touch Screen.
    //!             Its responsibility is to poll for new input on Touch screen
    //!             and handle the received input so that it can be then forwarded
    //!             to the TextProcessor after that
    //!
    //! \note       The implementation to this class is not finished yet
    //!
    class TouchScreenInput : public IInputStrategy
    {
    private:
        //! IInputStrategy inherited method
        bool init(SupportedLanguages language) override;

        //! IInputStrategy inherited method
        void waitForInput(std::string &receivedInput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // TOUCH_SCREEN_INPUT_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------