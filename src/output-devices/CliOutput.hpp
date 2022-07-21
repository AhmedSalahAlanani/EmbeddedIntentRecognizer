#ifndef CLI_OUTPUT_HPP
#define CLI_OUTPUT_HPP

#include "interfaces/IOutputDevice.hpp"

namespace embeddedIntentRecognizer
{
    class CliOutput : public IOutputDevice
    {
    private:
        void onNewOutputReady(const std::string &textProcessorOutput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // CLI_OUTPUT_HPP