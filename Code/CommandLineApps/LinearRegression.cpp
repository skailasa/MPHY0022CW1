//
// Created by Srinath Kailasa on 2019-02-22.
//

#include <CLI11.hh>


int main(int charc, char** argv) {
    CLI::App app{"App description"};

    std::string filename = "default";
    app.add_option("-f,--file", filename, "A help string");

    CLI11_PARSE(app, charc, argv);
    return 0;
}