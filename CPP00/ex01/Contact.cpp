#include "Contact.hpp"

void	Contact::setFirstName(std::string str) { this->first_name = str; }
void	Contact::setLastName(std::string str) { this->last_name = str; }
void	Contact::setNickName(std::string str) { this->nick_name = str; }
void	Contact::setPhoneNumber(std::string str) { this->phone_number = str; }
void	Contact::setDarkestSecret(std::string str) { this->darkest_secret = str; }
std::string	Contact::getFirstName() { return this->first_name; }
std::string	Contact::getLastName() { return this->last_name; }
std::string	Contact::getNickName() { return this->nick_name; }
std::string	Contact::getPhoneNumber() { return this->phone_number; }
std::string	Contact::getDarkestSecret() { return this->darkest_secret; }