#include <iostream>
#include <fstream>
#include <sys/statvfs.h>


int main() {
        std::ifstream os_release;
        std::ifstream ascii_file;
        std::string distro;
        std::string color;
        std::string line;
        std::string ascii_text;
        int count_line = 0;

        os_release.open("/etc/os-release");
        os_release>>distro; distro.erase(0,5);
        os_release.close();
        
        if (distro == "\"Ubuntu\"") {
                ascii_file.open("ascii/ubuntu.txt");
                color = "\u001b[31m";
        } else if (distro == "\"Arch\"" || distro == "\"Arch Linux\"") {
                ascii_file.open("ascii/arch.txt");
                color = "\u001b[34m";
        } else {
                ascii_file.open("ascii/undefined.txt");
        }
        if (ascii_file.is_open()) {
                while ( getline (ascii_file,line) ) {
                        count_line += 1;
                        if (count_line == 3) {
                                std::cout << color << line << "\u001b[0m" << "                  Distro: " << distro << color << "\n";
                                } else {
                                        std::cout << color << line << "\n" << "\u001b[0m";
                                }
                        }
                }

        //std::cout << 'Distro: ' << distro << '\n';
}