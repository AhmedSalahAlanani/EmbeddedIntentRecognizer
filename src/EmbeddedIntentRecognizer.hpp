//!
//! \file       EmbeddedIntentRecognizer.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class EmbeddedIntentRecognizer
//!

//---------------------------------------------------------------------------
#ifndef EMBEDDED_INTENT_RECOGNIZER_HPP
#define EMBEDDED_INTENT_RECOGNIZER_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <vector>
#include <memory>

#include "ConfigManager.hpp"
#include "InputStrategyContext.hpp"
#include "TextProcessor.hpp"
#include "interfaces/IOutputDevice.hpp"
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
    //! \class      EmbeddedIntentRecognizer
    //!
    //! \brief      Implementation of EmbeddedIntentRecognizer.
    //!
    class EmbeddedIntentRecognizer
    {
    public:
        //---------------------------------------------------------------------------
        //!
        //! \brief Initialize the Embedded Intent Recognizer Application
        //!
        //! \return true  - if initialization was successful,
        //!         false - otherwise
        //!
        bool init();
        //---------------------------------------------------------------------------
        //!
        //! \brief Run the Embedded Intent Recognizer Application
        //!
        //! \return true  - if initialization finished running successfully,
        //!         false - if error occurred causing the application to terminate
        //!                 unexpectedly
        //!
        bool run();

    private:
        //---------------------------------------------------------------------------
        //!
        //! \brief Configuration Manager resposible for loading the configuration
        //!        at startup, as well as providing other members with the needed
        //!        configuration to work properly.
        //!
        ConfigManager m_configManager;
        //---------------------------------------------------------------------------
        //!
        //! \brief Input Strategy Context is responsible to select the input strategy
        //!        according to the input config file.
        //!
        InputStrategyContext m_inputStartegyContext;
        //---------------------------------------------------------------------------
        //!
        //! \brief Text processor is responsible to process textual format only,
        //!        hence the input coming from the the selected input device must
        //!        convert the input into Text so that it can be processed.
        //!        For example, voice to text
        //!
        TextProcessor m_textProcessor;
        //---------------------------------------------------------------------------
        //!
        //! \brief Vector of output devices where it hold all the output devices
        //!        that shall be notified as soon as the text processor produces
        //!        a new textual output.
        //!
        std::vector<std::unique_ptr<IOutputDevice>> m_outputDevices;

        //---------------------------------------------------------------------------
        //!
        //! \brief method to add the enabled output devices in the config file
        //!        to the list of observers to the TextProcessor output
        //!
        //! \param applicationConfig [in] - the application configuration
        //!
        //!
        void addOutputDevices(const ApplicationConfig &applicationConfig);
        //---------------------------------------------------------------------------
        //!
        //! \brief This method clears the screen after initialization, to delete
        //!        log messages
        //!
        static inline void clearScreen();
    };

} // namespace embeddedIntentRecognizer

#endif // EMBEDDED_INTENT_RECOGNIZER_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------