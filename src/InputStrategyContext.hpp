//!
//! \file       InputStrategyContext.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class InputStrategyContext
//!

//---------------------------------------------------------------------------
#ifndef INPUT_STRATEGY_CONTEXT_HPP
#define INPUT_STRATEGY_CONTEXT_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <memory>

#include "common/Types.hpp"
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
    //! \class      InputStrategyContext
    //!
    //! \brief      Class responsible to set the input strategy from the currently
    //!             supported strategies, where the external requests delegate
    //!             to the selected strategy to be handled
    //!
    class InputStrategyContext
    {
    public:
        //---------------------------------------------------------------------------
        //!
        //! \brief Initialize the Input Strategy context
        //!
        //! \param configuration [in] - the application configuration
        //!
        //! \return true  - in case initialization was successful,
        //!         false - otherwise
        //!
        bool init(const ApplicationConfig &configuration);
        //---------------------------------------------------------------------------
        //!
        //! \brief This method shall poll for any input received, where the input
        //!        context delegates to the selected strategy to handle the input
        //!        in its way
        //!
        //! \note  the selected input strategy is expected to be able to convert
        //!        the received input to textual format so that it can be processed
        //!
        //! \param receivedInput [out] - it holds the received input in textual
        //!                              format coming from the selected input
        //!                              strategy
        //!
        void waitForInput(std::string &receivedInput) const;

    private:
        //---------------------------------------------------------------------------
        //!
        //! \brief This is the input strategy that shall be set according to
        //!        the received configuration during initialization. Where all
        //         the client requests to the input strategy context shall delegate
        //!        to the selected strategy to be able to handle it on its way.
        //!
        std::unique_ptr<IInputStrategy> m_inputStrategy;
    };

} // namespace embeddedIntentRecognizer

#endif // INPUT_STRATEGY_CONTEXT_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------