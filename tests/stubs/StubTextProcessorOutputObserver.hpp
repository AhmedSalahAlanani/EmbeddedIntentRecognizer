//!
//! \file       StubTextProcessorOutputObserver.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      A stub implementing TextProcessorOutputObserver
//!

//---------------------------------------------------------------------------
#ifndef STUB_TEXT_PROCESSOR_OUTPUT_OBSERVER_HPP
#define STUB_TEXT_PROCESSOR_OUTPUT_OBSERVER_HPP

#include "interfaces/ITextProcessorOutputObserver.hpp"
#include <string>

#include <iostream>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------

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
    //! \class      StubTextProcessorOutputObserver
    //!
    //! \brief      A stub class that implements ITextProcessorOutputObserver
    //!             to be used in TextProcessor unit tests
    //!
    class StubTextProcessorOutputObserver : public ITextProcessorOutputObserver
    {
    public:
        void onNewOutputReady(const std::string &textProcessorOutput) override
        {
            std::cout << textProcessorOutput << std::endl;

            m_textProcessorOutput = textProcessorOutput;
        }

        const std::string &getLastTextProcessorOutput() const
        {
            return m_textProcessorOutput;
        }

    private:
        std::string m_textProcessorOutput;
    };

} // namespace embeddedIntentRecognizer

#endif // STUB_TEXT_PROCESSOR_OUTPUT_OBSERVER_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------