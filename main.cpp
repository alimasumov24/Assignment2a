#include <iostream>
#include <fstream>
#include <filesystem>

int main(){
    std::string filename = "source.bin";
    std::string output_filename = "reversed.bin";

    std::ifstream infile(filename, std::ios::binary | std::ios::in);

    std::size_t filesize = std::filesystem::file_size(filename);
    char* buffer = new char[filesize];
    infile.read(buffer, filesize);
    infile.close();

    for (std::size_t i = 0; i < filesize / 2; ++i) {
        std::swap(buffer[i], buffer[filesize - i - 1]);
    }


    std::ofstream outfile(output_filename, std::ios::binary | std::ios::out);

    outfile.write(buffer, filesize);
    outfile.close();

    delete[] buffer;

    return 0;
}