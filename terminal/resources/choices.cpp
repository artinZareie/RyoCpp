#include "../headers/choices.hpp"

using namespace Ryo::Terminal;

#ifdef __linux__ 

ChoicesConfig::ChoicesConfig(): selected_style(StyleBundle(ForeColor::GREEN)), other_style(StyleBundle()), selected_speciefier(u8"*") {}

Choices::Choices(std::string prompt, std::vector<std::string> options): menu_prompt(prompt), menu_options(options), config(ChoicesConfig()) {}

Choices::Choices(std::string prompt, std::vector<char*> options): menu_prompt(prompt), config() {
    menu_options.reserve(options.size());
    for (const auto &option : options) {
        menu_options.emplace_back(std::string(option));
    }
}

Choices::Choices(std::string prompt, std::vector<std::string> options, ChoicesConfig config): menu_prompt(prompt), menu_options(options), config(config) {}

Choices::Choices(std::string prompt, std::vector<char*> options, ChoicesConfig config): menu_prompt(prompt), config(config) {
    menu_options.reserve(options.size());
    for (const auto &option : options) {
        menu_options.emplace_back(std::string(option));
    }
}

void Choices::clear_menu_section(unsigned int numenu_options) {
    std::cout << "\033[" << numenu_options << "A";
    std::cout << "\033[s";
    std::cout << "\033[J";
    std::cout << "\033[u";
}

void Choices::print_options(int choice) {
    for (size_t i = 0; i < menu_options.size(); i++) {
            if (i == choice)
                std::cout << Stylize::apply(std::string("[") + config.selected_speciefier + std::string("] ") + menu_options[i], config.selected_style) << std::endl;
            else 
                std::cout << Stylize::apply(std::string("[ ] ") + menu_options[i], config.other_style) << std::endl;
        }
}

unsigned int Choices::fire() {
    set_noncanonical_mode();

    write_line(menu_prompt);

    for (size_t i = 0; i < menu_options.size(); i++)
    {
        newline();
    }

    int choice = 0;
    char key;

    while (true)
    {
        clear_menu_section(menu_options.size());
        print_options(choice);
        
        key = getchar();
        if (key == 27) { // Escape key (27 is the escape sequence)
            key = getchar(); // Read the next character

            if (key == 91) { // '[' (91 is the '[' character)
                key = getchar(); // Read the actual arrow key code

                // Update the selected option based on arrow key
                switch (key) {
                    case 65: // Up arrow (65 is 'A')
                        choice = (choice - 1 + menu_options.size()) % menu_options.size();
                        break;
                    case 66: // Down arrow (66 is 'B')
                        choice = (choice + 1) % menu_options.size();
                        break;
                }
            }
        } else if (key == 10) {
            clear_menu_section(menu_options.size());
            break;
        }
        
    }
    
    restore_canonical_mode();

    return choice;
}

void Choices::configure(ChoicesConfig configuration) {
    config = configuration;
}

#endif
