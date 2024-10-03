#ifndef CORELOGGER_H

#define CORELOGGER_H

#define SPDLOG_ACTIVE_LEVEL SDPLOG_DEBUG

#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include "spdlog/sinks/stdout_color_sinks.h"
#include <iostream>

class CoreLogger
{
public:
    CoreLogger();
    virtual ~CoreLogger();

    void SetupLogger(spdlog::level::level_enum logLevel);

private:

    // I will use one pool object for the logger instances, it should be the accessor for all the different sinks
    // like printing into console, file, or maybe into the qt-windows..
    std::shared_ptr<spdlog::async_logger> m_CoreLogger;
};


#endif // CORELOGGER_
