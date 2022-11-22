/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "main.hpp"
#include "Components/SimpleComponent.hpp"
#include "IComponent.hpp"

void Core::handleInput(std::string str)
{
    if (str == "display")
        this->display();
    else if (str == "simulate") {
        this->simulate();/* 
        this->ticks += 1; */
    } else if (str == "exit")
        exit(0);
    else {
        std::regex words_regex("(^\\w+=([0-1]|U)$)");
        if (std::regex_match(str, words_regex) == false)
            throw Error("Invalid Input !");
        auto words_begin = std::sregex_iterator(str.begin(), str.end(), words_regex);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator x = words_begin; x != words_end; ++x) {
            std::string name;
            std::string nbr;
            std::smatch match = *x;
            std::string match_str = match.str();
            name = match_str.substr(0, match_str.find('='));
            nbr = match_str.substr(match_str.find('=') + 1, match_str.length());
            if (this->components[name] == nullptr || this->components[name]->getType() != "input")
                throw Error("Invalid Input, invalid component");
            if (nbr == "U")
                this->components[name]->setState(1, nts::UNDEFINED);
            else
                this->components[name]->setState(1, (nts::Tristate)atoi(nbr.c_str()));
        }
    }

}

Core::Error::Error(char const *msg)
{
    this->_msg = msg;
}

const char *Core::Error::what() const throw() {
    return _msg;
}

void Core::simulate() {
    for (int i = 0; !names[i].empty(); ++i) {
        if (this->components[names[i]]->getType() == "output") {
            this->components[names[i]]->simulate_pin(1);
        }
    }
    this->ticks += 1;
}

void Core::display() {
    std::cout << "tick: " << this->ticks << std::endl;
    std::cout << "input(s):" << std::endl;
    for (int i = 0; !names[i].empty(); ++i) {
        if (this->components[names[i]]->getType() == "input") {
            if (this->components[names[i]]->getState(1) == nts::UNDEFINED)
                std::cout << "  " << names[i] << ": U" << std::endl;
            else
                std::cout << "  " << names[i] << ": " << this->components[names[i]]->getState(1) << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (int i = 0; !names[i].empty(); ++i) {
        if (this->components[names[i]]->getType() == "output") {
            if (this->components[names[i]]->getState(1) == nts::UNDEFINED)
                std::cout << "  " << names[i] << ": U" << std::endl;
            else
                std::cout << "  " << names[i] << ": " << this->components[names[i]]->getState(1) << std::endl;
        }
    }
}


bool changeMode(int *mode, std::string str)
{
    const std::regex match3("^\\.(chipsets|links)+:$");
    if (std::regex_match(str, match3) == false) {
        return false;
    } else if (str == ".chipsets:") {
        if (*mode != -1)
            return false;
        *mode = 0;
    } else {
        if (*mode != 0)
            return false;
        *mode = 1;
    }
    return true;
}

bool checkLine(int *mode, std::string str)
{
    if (*mode == 0 && str[0] != '.') {
        const std::regex match1("(^[0-9]+\\s+\\w+\\s*$)|(^[A-Za-z]+\\s+\\w+\\s*$)");
        if (std::regex_match(str, match1) == false)
            return false;
    } else if (*mode == 1 && str[0] != '.') {
        const std::regex match2("^\\w+:[0-9]+\\s+\\w+:[0-9]+\\s*$");
        if (std::regex_match(str, match2) == false)
            return false;
    } else
        return changeMode(mode, str);
    return true;
}

void Core::verif_file(char **av)
{
    std::string str;
    int mode = -1;
    std::ifstream myfile (av[1]);
    int j = 0;
    int i = 0;
    //regex_search()
    if (myfile.is_open()) {
        while (getline(myfile, str)) {
            for (; str[0] == ' '; str = str.substr(1, str.length()));
            if (str[0] != '#' && str[0] != '\0') {
                str = str.substr(0, str.find('#'));;
                if (checkLine(&mode, str) == false)
                    throw Error("Incorect file, one line is not valid !");
                std::regex words_regex("(\\.[a-z]+)|(\\w+)");
                auto words_begin = std::sregex_iterator(str.begin(), str.end(), words_regex);
                auto words_end = std::sregex_iterator();
                j = 0;
                for (std::sregex_iterator x = words_begin; x != words_end; ++x, ++j) {
                    std::smatch match = *x;
                    std::string match_str = match.str();
                    if (match_str[0] == ' ')
                        match_str = match_str.substr(1, match_str.length());
                    this->instructions[i][j] = match_str;
                }
                i++;
            }
        }
    }
    else {
        throw Error("Unable to open file !");
        }
}

void Core::executeInstructions()
{
    int y = 0;
    int mode = 0;
    int nbr_names = 0;

    for (int i = 1; this->instructions[i][0].empty() == false; ++i) {
        if (this->instructions[i][0] == ".links") {
            mode = 1;
            ++i;
        }
        if (mode == 0) {
            if (this->components[this->instructions[i][1]] != nullptr)
                throw Error("Invalid file, two components have the same name !");
            this->components[this->instructions[i][1]] = nts::ComponentFactory::createComponent(this->instructions[i][0]);
            this->names[nbr_names] = this->instructions[i][1];
            ++nbr_names;
        } else {
            if (this->components[this->instructions[i][0]] == nullptr || this->components[this->instructions[i][2]] == nullptr)
                throw Error("Invalid components: doesn't exist");
            this->components[this->instructions[i][0]]->setLink(std::atoi(this->instructions[i][1].c_str()), *this->components[this->instructions[i][2]], std::atoi(this->instructions[i][3].c_str()));
        }
    }
}

int main(int ac, char **av)
{
    Core core;
    std::string str;

    try {
        core.verif_file(av);
        core.executeInstructions();
        //core.simulate();
        while(1) {
            printf("> ");
            std::getline (std::cin,str);
            if (std::cin.eof())
                return (0);
            core.handleInput(str);
        }
    } catch (std::exception &error) {
        std::cout << error.what() << std::endl;
        return 84;
    }

    // for (int i = 0; i < core.instructions.size(); ++i) {
    //     for (int j = 0; j < core.instructions[i].size(); ++j) {
    //         std::cout << core.instructions[i][j] << std::endl;
    //     }
    // }

    // std::cout << b << std::endl;
    // int ticks = 0;762

}