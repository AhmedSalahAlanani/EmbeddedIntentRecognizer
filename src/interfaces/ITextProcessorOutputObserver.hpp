//!
//! \file       ITextProcessorOutputObserver.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Interface ITextProcessorOutputObserver
//!

//---------------------------------------------------------------------------
#ifndef I_TEXT_PROCESSOR_OUTPUT_OBSERVER_HPP
#define I_TEXT_PROCESSOR_OUTPUT_OBSERVER_HPP
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
    //! \class      IOutputLanguageStrategy
    //!
    //! \brief      This interface for the classes that need to be notified by
    //!             the TextProcessor upon a new output is ready (for example:
    //!             Output Devices). So that they can be notified without the need
    //!             for polling whether a new output is ready or not yet
    //!
    class ITextProcessorOutputObserver
    {
    public:
        //---------------------------------------------------------------------------
        //!
        //! \brief Destructor
        //!
        virtual ~ITextProcessorOutputObserver() = default;
        //---------------------------------------------------------------------------
        //!
        //! \brief This is the callback method that will be called upon new output
        //!        is ready from the TextProcessor, hence it shall include all the logic
        //!        that shall be executed when new data is received
        //!        output format according to the configured language
        //!
        //! \param textProcessorOutput [in] - the new received output text from TexProcessor
        //!
        virtual void onNewOutputReady(const std::string &textProcessorOutput) = 0;
    };

} // namespace embeddedIntentRecognizer

#endif // I_TEXT_PROCESSOR_OUTPUT_OBSERVER_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------