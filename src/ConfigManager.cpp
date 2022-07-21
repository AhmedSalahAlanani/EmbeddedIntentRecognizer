#include <iostream>
#include <sstream>
#include <fstream>

#include "ConfigManager.hpp"

namespace
{
    // language support
    static constexpr char languageSupport[] = "Language Support";
    static constexpr char english[] = "English";
    static constexpr char deutsch[] = "Deutsch";

    // input devices
    static constexpr char inputDevice[] = "Input Device";
    static constexpr char cliInput[] = "CLI";
    static constexpr char touchScreenInput[] = "Touch Screen";
    static constexpr char voiceInput[] = "Voice Input";

    // output devices
    static constexpr char outputDevices[] = "Output Devices";
    static constexpr char cliOutput[] = "CLI";
    static constexpr char touchScreenOutput[] = "Touch Screen";
    static constexpr char voiceOutput[] = "Voice Output";

} // anonymous namespace

namespace embeddedIntentRecognizer
{
    bool ConfigManager::loadConfig(ApplicationConfig &configuration) const
    {
        std::cout << "Loading Application Configuration..\n";

        const bool state = readConfig(configuration);
        if (!state)
        {
            std::cout << "Failed to load Application Configuration.\n";
            return false;
        }

        std::cout << "Reading Application Configuration was successful.\n";
        return true;
    }

    bool ConfigManager::readConfig(ApplicationConfig &configuration) const
    {
        std::ostringstream documentBuffer;
        std::ifstream file{CONFIG_FILE_PATH};
        documentBuffer << file.rdbuf();

        rapidjson::Document configFile;
        configFile.Parse(documentBuffer.str().c_str());
        if (!configFile.IsObject())
        {
            std::cout << "[ERROR]: Failed to read Configuration File.\n";
            return false;
        }

        // set language support
        auto it = getMember(configFile, languageSupport);
        if (it != configFile.MemberEnd() && it->value.IsString())
        {
            if (!fillLanguageConfiguration(it->value.GetString(), configuration.language))
            {
                std::cout << "[ERROR]: Failed to set Language.\n";
                return false;
            }
            std::cout << "Language was set successfully." << std::endl;
        }

        // set input devices
        it = getMember(configFile, inputDevice);
        if (it != configFile.MemberEnd() && it->value.IsString())
        {
            if (!fillInputDeviceConfiguration(it->value.GetString(), configuration.inputType))
            {
                std::cout << "[ERROR]: Failed to set Input Device.\n";
                return false;
            }
            std::cout << "Input Device was set successfully." << std::endl;
        }

        // set output devices
        it = getMember(configFile, outputDevices);
        if (it != configFile.MemberEnd() && it->value.IsArray())
        {
            if (!fillOutputDeviceConfiguration(it->value.GetArray(), configuration))
            {
                std::cout << "[ERROR]: Failed to set Output Device.\n";
                return false;
            }
            std::cout << "Output Devices were set successfully." << std::endl;
        }

        return true;
    }

    bool ConfigManager::fillLanguageConfiguration(const std::string &inLanguage, SupportedLanguages &language) const
    {
        if (inLanguage == english)
        {
            language = SupportedLanguages::ENGLISH;
            return true;
        }

        if (inLanguage == deutsch)
        {
            language = SupportedLanguages::DEUTSCH;
            return true;
        }

        return false;
    }

    bool ConfigManager::fillInputDeviceConfiguration(const std::string &inInputDevice, SupportedInputs &inputDevice) const
    {
        if (inInputDevice == cliInput)
        {
            inputDevice = SupportedInputs::CLI_INPUT;
            return true;
        }

        if (inInputDevice == touchScreenInput)
        {
            inputDevice = SupportedInputs::TOUCH_SCREEN_INPUT;
            return true;
        }

        if (inInputDevice == voiceInput)
        {
            inputDevice = SupportedInputs::VOICE_INPUT;
            return true;
        }

        return false;
    }

    bool ConfigManager::fillOutputDeviceConfiguration(const rapidjson::Value::ConstArray &outDevices, ApplicationConfig &configuration) const
    {
        bool foundOutputDevice = false;
        for (auto it = outDevices.begin(); it != outDevices.end(); it++)
        {
            if (it->IsString())
            {
                const std::string &outDevice = it->GetString();
                if (outDevice == cliOutput)
                {
                    configuration.cliOutput = foundOutputDevice = true;
                    continue;
                }
                if (outDevice == touchScreenOutput)
                {
                    configuration.touchScreenOutput = foundOutputDevice = true;
                    continue;
                }
                if (outDevice == voiceOutput)
                {
                    configuration.voiceOutput = foundOutputDevice = true;
                    continue;
                }
            }
        }

        return foundOutputDevice;
    }

    inline rapidjson::Value::ConstMemberIterator ConfigManager::getMember(const rapidjson::Value &itrValue,
                                                                          const std::string &member) const
    {
        return itrValue.FindMember(member.c_str());
    }

} // namespace embeddedIntentRecognizer