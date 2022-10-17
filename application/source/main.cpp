#include <switch.h>
#include <iostream>
#include <string>
#include <borealis.hpp>

#include "../include/ListItem.hpp"
#include "../include/MainActivity.hpp"
 
int main(int argc, char **argv)
{
    brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

    if (!brls::Application::init())
    {
        brls::Logger::error("Failed to init");
        return EXIT_FAILURE;
    }
    brls::Application::createWindow("BrewTails");
    brls::Application::setGlobalQuit(true);

    brls::Application::registerXMLView("ListItem", ListItem::create);

    brls::Application::pushActivity(new MainActivity());

    while (brls::Application::mainLoop());

    return 0;
}