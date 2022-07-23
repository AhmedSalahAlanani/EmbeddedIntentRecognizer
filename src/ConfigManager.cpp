//!
//! \file       ConfigManager.cpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class ConfigManager
//!

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <iostream>
#include <sstream>
#include <fstream>

#include "ConfigManager.hpp"

namespace embeddedIntentRecognizer
{
    //---------------------------------------------------------------------------
    // Defines and Macros
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // Typedefs
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // Constants
    //---------------------------------------------------------------------------
    namespace
    {
        // language support
        static constexpr char g_languageSupport[] = "Language Support";
        static constexpr char g_english[] = "English";
        static constexpr char g_deutsch[] = "Deutsch";

        // input devices
        static constexpr char g_inputDevice[] = "Input Device";
        static constexpr char g_cliInput[] = "CLI";
        static constexpr char g_touchScreenInput[] = "Touch Screen";
        static constexpr char g_voiceInput[] = "Voice Input";

        // output devices
        static constexpr char g_outputDevices[] = "Output Devices";
        static constexpr char g_cliOutput[] = "CLI";
        static constexpr char g_touchScreenOutput[] = "Touch Screen";
        static constexpr char g_voiceOutput[] = "Voice Output";

    } // anonymous namespace

    //---------------------------------------------------------------------------
    // Local function prototypes
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // Data
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // Functions
    //---------------------------------------------------------------------------
    bool ConfigManager::loadConfig(ApplicationConfig &configuration, const char configFilePath[]) const
    {
        std::cout << "[INFO]: Loading Application Configuration..\n";

        const bool state = readConfig(configuration, configFilePath);
        if (!state)
        {
            std::cout << "[ERROR]: Failed to load Application Configuration.\n";
            return false;
        }

        std::cout << "[VERBOSE]: Reading Application Configuration was successful.\n";
        return true;
    }
    //---------------------------------------------------------------------------
    bool ConfigManager::readConfig(ApplicationConfig &configuration, const char configFilePath[]) const
    {
        std::ostringstream documentBuffer;
        std::ifstream file{configFilePath};
        documentBuffer << file.rdbuf();

        rapidjson::Document configFile;
        configFile.Parse(documentBuffer.str().c_str());
        if (!configFile.IsObject())
        {
            std::cout << "[ERROR]: Failed to read Configuration File.\n";
            return false;
        }

        // set language support
        auto it = getMember(configFile, g_languageSupport);
        if (it != configFile.MemberEnd() && it->value.IsString())
        {
            if (!fillLanguageConfiguration(it->value.GetString(), configuration.language))
            {
                std::cout << "[ERROR]: Failed to set Language.\n";
                return false;
            }
            std::cout << "[VERBOSE]: Language was set successfully." << std::endl;
        }

        // set input devices
        it = getMember(configFile, g_inputDevice);
        if (it != configFile.MemberEnd() && it->value.IsString())
        {
            if (!fillInputDeviceConfiguration(it->value.GetString(), configuration.inputType))
            {
                std::cout << "[ERROR]: Failed to set Input Device.\n";
                return false;
            }
            std::cout << "[VERBOSE]: Input Device was set successfully." << std::endl;
        }

        // set output devices
        it = getMember(configFile, g_outputDevices);
        if (it != configFile.MemberEnd() && it->value.IsArray())
        {
            if (!fillOutputDeviceConfiguration(it->value.GetArray(), configuration))
            {
                std::cout << "[ERROR]: Failed to set Output Device.\n";
                return false;
            }
            std::cout << "[VERBOSE]: Output Devices were set successfully." << std::endl;
        }

        return true;
    }
    //---------------------------------------------------------------------------
    bool ConfigManager::fillLanguageConfiguration(const std::string &inLanguage, SupportedLanguages &language) const
    {
        if (inLanguage == g_english)
        {
            language = SupportedLanguages::ENGLISH;
            return true;
        }

        if (inLanguage == g_deutsch)
        {
            language = SupportedLanguages::DEUTSCH;
            return true;
        }

        return false;
    }
    //---------------------------------------------------------------------------
    bool ConfigManager::fillInputDeviceConfiguration(const std::string &inInputDevice, SupportedInputs &inputDevice) const
    {
        if (inInputDevice == g_cliInput)
        {
            inputDevice = SupportedInputs::CLI_INPUT;
            return true;
        }

        if (inInputDevice == g_touchScreenInput)
        {
            inputDevice = SupportedInputs::TOUCH_SCREEN_INPUT;
            return true;
        }

        if (inInputDevice == g_voiceInput)
        {
            inputDevice = SupportedInputs::VOICE_INPUT;
            return true;
        }

        return false;
    }
    //---------------------------------------------------------------------------
    bool ConfigManager::fillOutputDeviceConfiguration(const rapidjson::Value::ConstArray &outDevices, ApplicationConfig &configuration) const
    {
        bool foundOutputDevice = false;
        for (auto it = outDevices.begin(); it != outDevices.end(); it++)
        {
            if (it->IsString())
            {
                const std::string &outDevice = it->GetString();
                if (outDevice == g_cliOutput)
                {
                    configuration.cliOutput = foundOutputDevice = true;
                    continue;
                }
                if (outDevice == g_touchScreenOutput)
                {
                    configuration.touchScreenOutput = foundOutputDevice = true;
                    continue;
                }
                if (outDevice == g_voiceOutput)
                {
                    configuration.voiceOutput = foundOutputDevice = true;
                    continue;
                }
            }
        }

        return foundOutputDevice;
    }
    //---------------------------------------------------------------------------
    inline rapidjson::Value::ConstMemberIterator ConfigManager::getMember(const rapidjson::Value &itrValue,
                                                                          const std::string &member) const
    {
        return itrValue.FindMember(member.c_str());
    }

} // namespace embeddedIntentRecognizer

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------