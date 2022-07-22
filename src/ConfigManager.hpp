#ifndef CONFIG_MANAGER_HPP
#define CONFIG_MANAGER_HPP

#include "rapidjson/include/rapidjson/document.h"
#include "common/Types.hpp"

namespace
{
    // configuration file path
    static constexpr char g_configFilePath[] = CONFIG_FILE_PATH;

} // anonymous namespace

namespace embeddedIntentRecognizer
{
    class ConfigManager
    {
    public:
        bool loadConfig(ApplicationConfig &configuration, const char configFilePath[] = g_configFilePath) const;

    private:
        bool readConfig(ApplicationConfig &configuration, const char configFilePath[]) const;
        bool fillLanguageConfiguration(const std::string &inLanguage, SupportedLanguages &language) const;
        bool fillInputDeviceConfiguration(const std::string &inInputDevice, SupportedInputs &inputDevice) const;
        bool fillOutputDeviceConfiguration(const rapidjson::Value::ConstArray &outDevices, ApplicationConfig &configuration) const;
        inline rapidjson::Value::ConstMemberIterator getMember(const rapidjson::Value &itrValue,
                                                               const std::string &member) const;
    };

} // namespace embeddedIntentRecognizer

#endif // CONFIG_MANAGER_HPP