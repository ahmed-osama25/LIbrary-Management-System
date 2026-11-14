#pragma once
#include <string>

class Admin
{
private:
    std::string username = "LibraryAdmin";

    std::string password = "Lib@2026";

public:
    bool login(std::string username, std::string password);
};