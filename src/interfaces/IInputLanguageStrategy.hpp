//!
//! \file       IInputLanguageStrategy.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Interface IInputLanguageStrategy
//!

//---------------------------------------------------------------------------
#ifndef I_INPUT_LANGUAGE_STRATEGY_HPP
#define I_INPUT_LANGUAGE_STRATEGY_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <string>
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
    //! \class      IInputLanguageStrategy
    //!
    //! \brief      The interface shall be responsible for the input language
    //!             strategy handling, where each input language strategy shall
    //!             inherit from this interface and implement the handling of
    //!             the input according to its language. Also support additional
    //!             user interface if needed (for example, language-scpecific
    //!             keyboard layout)
    //!
    //! \note       This way, the input language strategy can be set at runtime
    //!             upon modifying the configuration file and without touching
    //!             the other classes. Also on supporting a new input language
    //!             strategy, all needs to be done is inheriting from this interface
    //!             and making the configManager supports the new input language
    //!             so that the requests delegate to the new class implemented
    //!
    class IInputLanguageStrategy
    {
    public:
        //---------------------------------------------------------------------------
        //!
        //! \brief Destructor
        //!
        virtual ~IInputLanguageStrategy() = default;
        //---------------------------------------------------------------------------
        //!
        //! \brief This method shall poll for the input expected in the specified
        //!        language and convert it into textual format if needed, so that
        //!        it can be sent to the TextProcessor to recognize its Intent
        //!
        //! \param receivedInput [out] - the received input from the user
        //!
        virtual void waitForInput(std::string &receivedInput) const = 0;
    };

} // namespace embeddedIntentRecognizer

#endif // I_INPUT_LANGUAGE_STRATEGY_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------