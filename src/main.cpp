#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>
#include <iostream>
#include <math.h>
#include <complex>
#include <cmath>
#include<vector>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

using namespace std;
double dft(int k, const std::vector<float> &p){
    int n=p.size();

    // complex multiplication in c++ is stupid
    // change int 2 to std::complex<double>(2,0) and also the same with M_PI and n+1
  
    const std::complex<double> C =std::exp((std::complex<double>(2,0)*sqrt(std::complex<double>(-1,0))*std::complex<double>(M_PI,0))/(std::complex<double>(n+1)));
   
   
    complex<double> result(0,0);

    for (int l = 0; l<n+1;l++){
        
        complex<double> re1=pow(C,-l*k);
       
        complex<double>re2(1,0);
        for (int m = 0;m<n;m++){
            re2*=(std::complex<double>(1,0)+(pow(C,l)-std::complex<double>(1,0))*std::complex<double>(p[m],0));
            
        }
        //result+=addComp(re1,re2);
        
        
        result+=re1*re2;
        //cout<<re1<<" "<<re2<<" "<<std::complex<double>(a,b)<<result<<" "<<"\n";
    }
    
    //cout<< ((std::complex<double>(1,0))/(std::complex<double>(1+n,0)))*result;
    //cout<<result;
    
    //cout<<std::real((1.0 / (1 + n)) * result);
    return std::real((1.0 / (1 + n)) * result);
    
}
namespace py = pybind11;

PYBIND11_MODULE(DFT_cpp, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: DFT_cpp

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

    m.def("dft", &dft, R"pbdoc(
        Add one value (k) and one list (p)
        Some other explanation about the add function.
    )pbdoc");

    

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
