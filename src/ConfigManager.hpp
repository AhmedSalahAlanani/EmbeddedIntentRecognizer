//!
//! \file       ConfigManager.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class ConfigManager
//!

//---------------------------------------------------------------------------
#ifndef CONFIG_MANAGER_HPP
#define CONFIG_MANAGER_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include "rapidjson/include/rapidjson/document.h"
#include "common/Types.hpp"
//---------------------------------------------------------------------------
// Forward Declarations
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Constants
//---------------------------------------------------------------------------
namespace
{
    // configuration file path
    static constexpr char g_configFilePath[] = CONFIG_FILE_PATH;

} // anonymous namespace

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
    //! \class      ConfigManager
    //!
    //! \brief      Class responsible to parse and load the application configuration
    //!             file: "intent-recognizer.cfg". The loaded configuration is
    //!             then passed to other modules according to their needs.
    //!
    //! \note       The configuration file is configured in the CMakeLists.txt file,
    //!             you can modify, add, or remove entries through modifying
    //!             the input file "config/intent-recognizer.cfg.in", and
    //!             the generated file is currently saved under the binaries
    //!             directory. Also the syntax for the config file is same as
    //!             JSON format, so it's parsed as a JSON file.
    //!
    class ConfigManager
    {
    public:
        //---------------------------------------------------------------------------
        //!
        //! \brief Load the application configuration from the file:
        //!        "intent-recognizer.cfg", and store it in Applicationconfig object
        //!        to be passed to other modules that need to be configured at runtime
        //!
        //! \param configuration  [out] - the application configuration to be filled
        //!
        //! \param configFilePath [out] - the path where the config file is stored.
        //!                               (The path was set as a passed parameter
        //!                               for testability to try different configuration
        //!                               files, however, its default value is under
        //!                               the binaries directory where it's generated
        //!                               upon modifying the "intent-recognizer.cfg.in"
        //!                               input file)
        //!
        //! \return true  - in case loading the configuration was successful,
        //!         false - otherwise
        //!
        bool loadConfig(ApplicationConfig &configuration, const char configFilePath[] = g_configFilePath) const;

    private:
        //---------------------------------------------------------------------------
        //!
        //! \brief Read the configuration file received by the method: loadConfig
        //!        This method checks the JSON syntax first, then it starts calling
        //!        other methods to parse each field and fill its corresponding
        //!        attribute in the ApplicationConfiguration object to be sent back
        //!        to the caller
        //!
        //! \param configuration  [out] - the application configuration to be filled
        //!
        //! \param configFilePath [out] - the path where the config file is stored,
        //!                               where this path shall already be set by
        //!                               the method: loadConfig
        //!
        //! \return true  - in case reading and parsing the configuration was successful,
        //!         false - otherwise
        //!
        bool readConfig(ApplicationConfig &configuration, const char configFilePath[]) const;
        //---------------------------------------------------------------------------
        //!
        //! \brief This method is responsible for filling the language attribute
        //!        in the ApplicationConfiguration object received, where it expects
        //!        the language field to have one of the currently supported languages.
        //!
        //! \note  On adding a new language, the supported languages shall be updated
        //!        as well, so that the ConfigManager would accept it in this case
        //!        since it could be found in the supported languages
        //!
        //! \param inLanguage [in]  - the language read in the JSON file
        //!
        //! \param language   [out] - the language attribute to be set in case
        //!                           the language set in the configuration file
        //!                           is one of the currently supported languages
        //!
        //! \return true  - in case the language found was currently supported,
        //!                 and hence can be set in the ApplicationConfiguration
        //!                 object to be passed to other modules in the application
        //!         false - otherwise
        //!
        bool fillLanguageConfiguration(const std::string &inLanguage, SupportedLanguages &language) const;
        //---------------------------------------------------------------------------
        //!
        //! \brief This method is responsible for filling the input device attribute
        //!        in the ApplicationConfiguration object received, where it expects
        //!        the input device field to have one of the currently supported
        //!        input methods.
        //!
        //! \note  On adding a new input device, the supported devices shall be updated
        //!        as well, so that the ConfigManager would accept it in this case
        //!        since it could be found in the supported input devices
        //!
        //! \param inInputDevice [in]  - the input device read in the JSON file
        //!
        //! \param inputDevice   [out] - the input device attribute to be set in case
        //!                              the input method set in the configuration file
        //!                              is one of the currently supported input methods
        //!
        //! \return true  - in case the input device found was currently supported,
        //!                 and hence can be set in the ApplicationConfiguration
        //!                 object to be passed to other modules in the application
        //!         false - otherwise
        //!
        bool fillInputDeviceConfiguration(const std::string &inInputDevice, SupportedInputs &inputDevice) const;
        //---------------------------------------------------------------------------
        //!
        //! \brief This method is responsible for enabling and disabling the output
        //!        devices currently supported, where the application can support
        //!        multiple outputs at the same time. (example: voice and display
        //!        the recognized intent at the same time)
        //!
        //! \note  On adding a new output device, a new corresponding boolean attribute
        //!        shall be added to the ApplicationConfiguration struct, so that
        //!        when the ConfigManager finds it in the config file it can
        //!        recognize it and set its cooresponding attribute accordingly
        //!        to allow the output coming from the text processor to propagate
        //!        to this device as well.
        //!
        //! \param outDevices    [in]  - JSON array that contains the parsed array
        //!                              of output devices to be evaluated and hence
        //!                              the corresponding attributes can be set
        //!                              accordingly.
        //!
        //! \param configuration [out] - the application configuration to be filled,
        //!                              where this method sets multiple attributes
        //!                              in the ApplicationConfiguration object
        //!
        //! \return true  - in case at least one of the output devices listed is
        //!                 recognized and currently supported, and hence enabled
        //!                 in the application congiguration
        //!         false - otherwise
        //!
        bool fillOutputDeviceConfiguration(const rapidjson::Value::ConstArray &outDevices, ApplicationConfig &configuration) const;
        //---------------------------------------------------------------------------
        //!
        //! \brief This method wraps repetitve calls to rapidJson library, where it
        //!        it passes an iterator to an array or onbject and searches for
        //!        the passed string. where it returns an iterator pointing to the member
        //!        if found, otherwise the iterator is pointing to the end, indicating
        //!        the member wasn't found. This is very helpful when evaluating whether
        //!        the received input is currently supported or not
        //!
        //! \param itrValue [in]  - itr pointing to the array or object to be searched
        //!                         for the passed member
        //!
        //! \param member   [out] - the member to be searched for
        //!
        //! \return true  - iterator pointing to the member that was searched for
        //!                 in case it was found, otherwise the iterator is pointing
        //!                 to the end of the array or object to be searched for
        //!
        inline rapidjson::Value::ConstMemberIterator getMember(const rapidjson::Value &itrValue,
                                                               const std::string &member) const;
    };

} // namespace embeddedIntentRecognizer

#endif // CONFIG_MANAGER_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------