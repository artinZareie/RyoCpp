#include "../headers/choices.hpp"

using namespace Ryo::Terminal;

#ifdef __linux__ 

Choices::Choices(std::string prompt, std::vector<std::string> options): m_prompt(prompt), m_options(options) {}
Choices::Choices(std::string prompt, std::vector<char*> options): m_prompt(prompt) {
    m_options.reserve(options.size());
    for (const auto &option : options) {
        m_options.emplace_back(std::string(option));
    }
}

void Choices::clear_menu_section(unsigned int num_options) {
    std::cout << "\033[" << num_options << "A";
    std::cout << "\033[s";
    std::cout << "\033[J";
    std::cout << "\033[u";
}

void Choices::print_options(int choice) {
    for (size_t i = 0; i < m_options.size(); i++)
        {
            if (i == choice)
                std::cout << "[*] " << m_options[i] << std::endl;
            else 
                std::cout << "[ ] " << m_options[i] << std::endl;
        }
}

unsigned int Choices::fire() {
    set_noncanonical_mode();

    write_line(m_prompt);

    for (size_t i = 0; i < m_options.size(); i++)
    {
        newline();
    }

    int choice = 0;
    char key;

    while (true)
    {
        clear_menu_section(m_options.size());
        print_options(choice);
        
        key = getchar();
        if (key == 27) { // Escape key (27 is the escape sequence)
            key = getchar(); // Read the next character

            if (key == 91) { // '[' (91 is the '[' character)
                key = getchar(); // Read the actual arrow key code

                // Update the selected option based on arrow key
                switch (key) {
                    case 65: // Up arrow (65 is 'A')
                        choice = (choice - 1 + m_options.size()) % m_options.size();
                        break;
                    case 66: // Down arrow (66 is 'B')
                        choice = (choice + 1) % m_options.size();
                        break;
                }
            }
        } else if (key == 10) {
            clear_menu_section(m_options.size());
            break;
        }
        
    }
    
    restore_canonical_mode();

    return choice;
}


#endif