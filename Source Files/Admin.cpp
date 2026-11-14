#include "Admin.h"

bool Admin::login(std::string username, std::string password)
{

    return (username == this->username && password == this->password);
}