//
// Created by Srinath Kailasa on 2019-02-22.
//

#include <iostream>
#include <CLI11.hh>
#include "mphyLinearDataCreator.h"
#include "mphyFileLoaderDataCreator.h"
#include "mphyNormalEquationSolverStrategy.h"
#include "mphySVDSolverStrategy.h"


int main(int argc, char **argv) {

    std::string helpText;

    helpText = "================================================================ \n"
               "********************* Linear Regression App ******************** \n"
               "================================================================ \n"
               "Solve a 1D linear system using either the Normal Equations or \n"
               "Singular-Value Decomposition. All you have to do is specify a \n"
               "file containing your data in a two column format (X, y) separated \n"
               "by spaces. \n"
               "================================================================ \n"
               "***************************** Usage **************************** \n"
               "================================================================ \n"
               "./LinearRegression --file <filepath> --solver <svd/normal> \n"
               "e.g. \n"
               "./LinearRegression --file data.txt --solver normal \n"
               "================================================================ \n"
               "See -h or --help for further usage instructions \n";

    CLI::App app("Linear Regression App:");
    std::string file;
    std::string solver;

    CLI::Option *opt = app.add_option("-f,--file,file", file, "Filepath");

    app.add_option("-s,--solver, solver", solver, "Solver strategy ('svd' or "
                                                  "'normal')")->needs(opt);

    CLI11_PARSE(app, argc, argv);

    if (file == "" && solver=="") std::cout << helpText << std::endl;

    else if (file == "" | solver == "") std::cout << "You must specify a data "
                                                     "file AND solver method "
                                                     "see -h or --help for "
                                                     "usage instructions \n";

    else if (file!="" && solver!="") {

       try {
           auto data = mphy::FileLoaderDataCreator(file).GetData();

           if (solver == "svd") {
               auto res = mphy::SVDSolverStrategy().FitData(data);
               std::cout << "theta_0: "
                         << res.first
                         << " theta_1: "
                         << res.second << std::endl;
           }
           else if (solver == "normal") {
               auto res = mphy::NormalEquationSolverStrategy().FitData(data);
               std::cout << "theta_0: "
                         << res.first
                         << " theta_1: "
                         << res.second << std::endl;
           }

           else {
               std::cout << "You must choose a supported solver strategy!"
                         << std::endl;
           };
       } catch (std::exception const &e) {
           std::cerr << e.what() << '\n';
       }

    }

    return 0;
}