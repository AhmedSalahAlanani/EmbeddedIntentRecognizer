#ifndef CONFIG_MANAGER_HPP
#define CONFIG_MANAGER_HPP

#include "common/Types.hpp"

namespace embeddedIntentRecognizer
{
    class ConfigManager
    {
    public:
        bool loadConfig(ApplicationConfig &configuration) const;
    };

} // namespace embeddedIntentRecognizer

#endif // CONFIG_MANAGER_HPP