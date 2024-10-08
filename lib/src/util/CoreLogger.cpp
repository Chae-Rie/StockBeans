#include "CoreLogger.h"


CoreLogger::CoreLogger() {
}


CoreLogger::~CoreLogger() {
    // Make sure that the logger(s) will flush everything to the file
    // plus they should get closed gracefully
    spdlog::shutdown();
}

// This function should define all the needed sinks and all the settings for my loggers
void CoreLogger::SetupLogger(spdlog::level::level_enum logLevel) {
    try {
        // Defining the standard global thread pool with a capacity of 8192 items and one workerthread should be enough
        spdlog::init_thread_pool(8192, 1);
        auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

        // todo: add a basic file logger... I think this will be handy, soon are later

        // This vector makes it easy to combine all the different sinks into one async-logger
        std::vector<spdlog::sink_ptr> sinks{consoleSink};

        // blocking policy -> if the queue is full it will block until there is space to log again
        m_CoreLogger = std::make_shared<spdlog::async_logger>("StockBeans", sinks.begin(), sinks.end(),
                                                              spdlog::thread_pool(),
                                                              spdlog::async_overflow_policy::block);

        // I will be using the macros like SPDLOG_DEBUG more than spdlog::debug() because with the macro the formatting will be used properly
        // for that I need to make sure, my loggerobject is defined as default.
        spdlog::set_default_logger(m_CoreLogger);

        // this makes the change of visibility possible
        // on release DEBUG-calls shouldn't be made
        spdlog::set_level(logLevel);


        // make it flush on every call, trace is the lowest possible level
        spdlog::flush_on(spdlog::level::trace);
        SPDLOG_INFO("Logger got set up successfully.");
    } catch (const spdlog::spdlog_ex &ex) {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }
}
