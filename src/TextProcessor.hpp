//!
//! \file       TextProcessor.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class TextProcessor
//!

//---------------------------------------------------------------------------
#ifndef TEXT_PROCESSOR_HPP
#define TEXT_PROCESSOR_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <vector>
#include <memory>

#include "common/Types.hpp"
#include "interfaces/ITextProcessorOutputObserver.hpp"
#include "interfaces/IIntentRecognitionModel.hpp"
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
    //! \class      TextProcessor
    //!
    //! \brief      Class responsible for input processing in textual format
    //!             only. The output as well is in textual format. However, it
    //!             shall support the processing text in different according to
    //!             the selected language Model
    //!
    //! \note       Since this class process text only, it is the responsibility
    //!             of input devices to collect the input and convert it
    //!             accordingly into textual form.
    //!             Same goes for output devices, where they are expected to
    //!             receive text and be able to convert it to their output format
    //!
    class TextProcessor
    {
    public:
        //---------------------------------------------------------------------------
        //!
        //! \brief Initialize the Text Processor Module
        //!
        //! \param configuration [in] - the application configuration
        //!
        //! \return true  - if initialization was successful,
        //!         false - otherwise
        //!
        bool init(const ApplicationConfig &configuration);
        //---------------------------------------------------------------------------
        //!
        //! \brief It adds a new Text Processor output observer to the list of
        //!        observers, so that it gets notified when the text processor finishes
        //!        processing and outputs the result.
        //!
        //! \param observer [in] - the observer to be added
        //!
        void attach(ITextProcessorOutputObserver *observer);
        //---------------------------------------------------------------------------
        //!
        //! \brief It removed this Text Processor output observer from the list of
        //!        observers, so it will no longer gets notified when the text
        //!        processor outputs a new result.
        //!
        //! \param observer [in] - the observer to be removed
        //!
        void detach(ITextProcessorOutputObserver *observer);
        //---------------------------------------------------------------------------
        //!
        //! \brief This is the main functionality of the Text Processor. It receives
        //!        input text. First it classifies the input text to either command
        //!        or text, and outputs this result. In case the received input was
        //!        text, it further process the text using the IntentRecognitionModel
        //!        to get the intent. The observers are notified then with the output
        //!        Intent.
        //!
        //! \param text      [in]  - the text to be processed
        //!
        //! \param inputType [out] - the input text type set by the text processor
        //!
        void processText(const std::string &text, InputTextType &inputType);

    private:
        //---------------------------------------------------------------------------
        //!
        //! \brief This is the Model responsible for the Intent Recognition,
        //!        its type is configurable and set at startup when the configuration
        //!        is loaded
        //!
        std::unique_ptr<IIntentRecognitionModel> m_intentRecognitionModel;
        //---------------------------------------------------------------------------
        //!
        //! \brief A string that holds the last output from the Model
        //!
        std::string m_lastProcessedOutput;
        //---------------------------------------------------------------------------
        //!
        //! \brief A Vector that holds the list of observers to be notified when
        //!        new output is ready
        //!
        std::vector<ITextProcessorOutputObserver *> m_observers;

        //---------------------------------------------------------------------------
        //!
        //! \brief This method simply iterates on the list of observer to notify them
        //!        with the new output
        //!
        inline void notifyOutputObservers() const;
    };

} // namespace embeddedIntentRecognizer

#endif // TEXT_PROCESSOR_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------