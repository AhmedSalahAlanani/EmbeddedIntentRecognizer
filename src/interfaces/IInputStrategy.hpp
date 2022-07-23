//!
//! \file       IInputStrategy.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Interface IInputStrategy
//!

//---------------------------------------------------------------------------
#ifndef I_INPUT_STRATEGY_HPP
#define I_INPUT_STRATEGY_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <string>

#include "common/Types.hpp"
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
    //! \class      IInputStrategy
    //!
    //! \brief      The interface shall be responsible for the input strategy
    //!             handling (i.e input device), where each input strategy shall
    //!             inherit from this interface and implement the handling of
    //!             the input according to its format (for example: it could be
    //!             voice commands, touch screen keyboard, or simple command line
    //!             interface). Also the input language shall be configurable and
    //!             set at run time. Additionally, it shall provide user interface
    //!             if needed, according to the type of input supported.
    //!
    //! \note       For all input strategies, the input strategy shall be able to
    //!             convert the received input and convert it into textual format
    //!             (no matter its original format is), so that it can be processed
    //!             by the TextProcessor to recognize the intent of the input
    //!
    class IInputStrategy
    {
    public:
        //---------------------------------------------------------------------------
        //!
        //! \brief Destructor
        //!
        virtual ~IInputStrategy() = default;
        //---------------------------------------------------------------------------
        //!
        //! \brief This method is responsible for the initialization of the concrete
        //!        strategy including the setting of the input language so that
        //!        the language strategy can be set during initialization.
        //!
        //! \param language [in] - the configured input language which shall be supported
        //!                        by the input strategy
        //!
        virtual bool init(SupportedLanguages language) = 0;
        //---------------------------------------------------------------------------
        //!
        //! \brief This method polls for input and convert it into textual format
        //!        if needed and stores it into the string: receivedInput, so that
        //!        it can be read by the TextProcessor to recognize the intent of the
        //!        received input
        //!
        //! \param receivedInput [out] - the received input in Text format
        //!
        virtual void waitForInput(std::string &receivedInput) const = 0;
    };

} // namespace embeddedIntentRecognizer

#endif // I_INPUT_STRATEGY_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------