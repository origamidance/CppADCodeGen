#ifndef CPPAD_CG_TEST_PLUG_FLOW_INCLUDED
#define CPPAD_CG_TEST_PLUG_FLOW_INCLUDED
/* --------------------------------------------------------------------------
 *  CppADCodeGen: C++ Algorithmic Differentiation with Source Code Generation:
 *    Copyright (C) 2013 Ciengis
 *
 *  CppADCodeGen is distributed under multiple licenses:
 *
 *   - Eclipse Public License Version 1.0 (EPL1), and
 *   - GNU General Public License Version 3 (GPL3).
 *
 *  EPL1 terms and conditions can be found in the file "epl-v10.txt", while
 *  terms and conditions for the GPL3 can be found in the file "gpl3.txt".
 * ----------------------------------------------------------------------------
 * Author: Joao Leal
 */

#include <assert.h>

template<class T>
std::vector<CppAD::AD<T> > plugFlowFunc2(const std::vector<CppAD::AD<T> >& x) {
    using namespace CppAD;

    size_t j;

    // dependent variable vector 
    std::vector< AD<T> > y(6 * 4);

    // temporary variables
    std::vector< AD<T> > v(5);

    v[0] = 1.66666666666667e-05 * x[24];
    v[1] = 0.5 * 3.14159265358979 * x[25] * x[25];
    for (j = 0; j < 6; j++) {
        v[2] = 1000. * x[j];
        v[3] = 1000. * x[j + 6];
        v[4] = exp(35 - 83809.879272 / (8.31447215 * (x[j + 18] + 273.15))) * v[2] * v[3];
        y[j] = 0.001 * (1000. * x[(j < 2) ? j * -26 + 26 : j + -1] * v[0] - v[2] * v[0] + -1 * v[4] * v[1]) / v[1];
        y[j + 6] = 0.001 * (1000. * x[(j < 2) ? j * -21 + 27 : j + 5] * v[0] - v[3] * v[0] + -1 * v[4] * v[1]) / v[1];
        y[j + 12] = 0.001 * (1000. * x[(j < 2) ? j * -16 + 28 : j + 11] * v[0] - 1000. * x[j + 12] * v[0] + v[4] * v[1]) / v[1];
        y[j + 18] = 0;
    }

    return y;
}

template<class T>
std::vector<CppAD::AD<T> > plugFlowFunc(const std::vector<CppAD::AD<T> >& x) {
    using namespace CppAD;

    // dependent variable vector 
    std::vector< AD<T> > y(6 * 4);

    // temporary variables
    std::vector< AD<T> > v(58);

    v[0] = 1.66666666666667e-05 * x[24];
    v[1] = 1000. * x[0];
    v[2] = 1000. * x[26] * v[0];
    v[3] = v[1] * v[0];
    v[4] = x[18] - -273.15;
    v[5] = 1000. * x[6];
    v[6] = exp(34.0607405939677 - 83809.879272 / (8.31447215 * v[4])) * v[1] * v[5];
    v[7] = 3.14159265358979 * x[25] * x[25];
    v[8] = 0.5 * v[7];
    y[0] = 0.001 * (v[2] - v[3] + -1 * v[6] * v[8]) / v[8];
    v[9] = 1000. * x[1];
    v[10] = v[9] * v[0];
    v[11] = x[19] - -273.15;
    v[12] = 1000. * x[7];
    v[13] = exp(34.0607405939677 - 83809.879272 / (8.31447215 * v[11])) * v[9] * v[12];
    v[14] = 0.5 * v[7];
    y[1] = 0.001 * (v[3] - v[10] + -1 * v[13] * v[14]) / v[14];
    v[15] = 1000. * x[2];
    v[16] = v[15] * v[0];
    v[17] = x[20] - -273.15;
    v[18] = 1000. * x[8];
    v[19] = exp(34.0607405939677 - 83809.879272 / (8.31447215 * v[17])) * v[15] * v[18];
    v[20] = 0.5 * v[7];
    y[2] = 0.001 * (v[10] - v[16] + -1 * v[19] * v[20]) / v[20];
    v[21] = 1000. * x[3];
    v[22] = v[21] * v[0];
    v[23] = x[21] - -273.15;
    v[24] = 1000. * x[9];
    v[25] = exp(34.0607405939677 - 83809.879272 / (8.31447215 * v[23])) * v[21] * v[24];
    v[26] = 0.5 * v[7];
    y[3] = 0.001 * (v[16] - v[22] + -1 * v[25] * v[26]) / v[26];
    v[27] = 1000. * x[4];
    v[28] = v[27] * v[0];
    v[29] = x[22] - -273.15;
    v[30] = 1000. * x[10];
    v[31] = exp(34.0607405939677 - 83809.879272 / (8.31447215 * v[29])) * v[27] * v[30];
    v[32] = 0.5 * v[7];
    y[4] = 0.001 * (v[22] - v[28] + -1 * v[31] * v[32]) / v[32];
    v[33] = 1000. * x[5];
    v[34] = x[23] - -273.15;
    v[35] = 1000. * x[11];
    v[36] = exp(34.0607405939677 - 83809.879272 / (8.31447215 * v[34])) * v[33] * v[35];
    v[7] = 0.5 * v[7];
    y[5] = 0.001 * (v[28] - v[33] * v[0] + -1 * v[36] * v[7]) / v[7];
    v[37] = 1000. * x[27] * v[0];
    v[38] = v[5] * v[0];
    y[6] = 0.001 * (v[37] - v[38] + -1 * v[6] * v[8]) / v[8];
    v[39] = v[12] * v[0];
    y[7] = 0.001 * (v[38] - v[39] + -1 * v[13] * v[14]) / v[14];
    v[40] = v[18] * v[0];
    y[8] = 0.001 * (v[39] - v[40] + -1 * v[19] * v[20]) / v[20];
    v[41] = v[24] * v[0];
    y[9] = 0.001 * (v[40] - v[41] + -1 * v[25] * v[26]) / v[26];
    v[42] = v[30] * v[0];
    y[10] = 0.001 * (v[41] - v[42] + -1 * v[31] * v[32]) / v[32];
    y[11] = 0.001 * (v[42] - v[35] * v[0] + -1 * v[36] * v[7]) / v[7];
    v[43] = 1000. * x[12];
    v[44] = 1000. * x[28] * v[0];
    v[45] = v[43] * v[0];
    y[12] = 0.001 * (v[44] - v[45] + v[6] * v[8]) / v[8];
    v[46] = 1000. * x[13];
    v[47] = v[46] * v[0];
    y[13] = 0.001 * (v[45] - v[47] + v[13] * v[14]) / v[14];
    v[48] = 1000. * x[14];
    v[49] = v[48] * v[0];
    y[14] = 0.001 * (v[47] - v[49] + v[19] * v[20]) / v[20];
    v[50] = 1000. * x[15];
    v[51] = v[50] * v[0];
    y[15] = 0.001 * (v[49] - v[51] + v[25] * v[26]) / v[26];
    v[52] = 1000. * x[16];
    v[53] = v[52] * v[0];
    y[16] = 0.001 * (v[51] - v[53] + v[31] * v[32]) / v[32];
    v[54] = 1000. * x[17];
    y[17] = 0.001 * (v[53] - v[54] * v[0] + v[36] * v[7]) / v[7];
    
    v[55] = x[29] - -273.15;
    v[2] = 0.005 * v[2];
    v[37] = 0.007 * v[37];
    v[44] = 0.012 * v[44];
    v[56] = 1001.91585067007 * v[8];
    v[57] = ((v[56] - (0.005 * v[1] * v[8] + 0.007 * v[5] * v[8] + 0.012 * v[43] * v[8])) / 0.0180152833) / v[8];
    y[18] = (        v[2] * 1000. * (v[55] - v[4]) +         v[37] * 1000. * (v[55] - v[4]) +         v[44] * 2000. * (v[55] - v[4]) + (1001.91585067007 * v[0] - (v[2] + v[37] + v[44])) * 4189.68014953824 * (v[55] - v[4]) -    -33488. * v[6] * v[8]) / 
            (v[56] * (1000. * 0.005 * v[1] + 1000. * 0.007 * v[5] + 2000. * 0.012 * v[43] + 4189.68014953824 * 0.0180152833 * v[57]) / (0.005 * v[1] + 0.007 * v[5] + 0.012 * v[43] + 0.0180152833 * v[57]));
    
    v[56] = 1001.91585067007 * v[14];
    v[44] = ((v[56] - (0.005 * v[9] * v[14] + 0.007 * v[12] * v[14] + 0.012 * v[46] * v[14])) / 0.0180152833) / v[14];
    y[19] = (0.005 * v[3] * 1000. * (v[4] - v[11]) + 0.007 * v[38] * 1000. * (v[4] - v[11]) + 0.012 * v[45] * 2000. * (v[4] - v[11]) + 0.0180152833 * v[57] * v[0]                        * 4189.68014953824 * (v[4] - v[11]) -    -33488. * v[13] * v[14]) / 
            (v[56] * (1000. * 0.005 * v[9] + 1000. * 0.007 * v[12] + 2000. * 0.012 * v[46] + 4189.68014953824 * 0.0180152833 * v[44]) / (0.005 * v[9] + 0.007 * v[12] + 0.012 * v[46] + 0.0180152833 * v[44]));
    
    v[56] = 1001.91585067007 * v[20];
    v[57] = ((v[56] - (0.005 * v[15] * v[20] + 0.007 * v[18] * v[20] + 0.012 * v[48] * v[20])) / 0.0180152833) / v[20];
    y[20] = (0.005 * v[10] * 1000. * (v[11] - v[17]) + 0.007 * v[39] * 1000. * (v[11] - v[17]) + 0.012 * v[47] * 2000. * (v[11] - v[17]) + 0.0180152833 * v[44] * v[0] * 4189.68014953824 * (v[11] - v[17]) - -33488. * v[19] * v[20]) / (v[56] * (1000. * 0.005 * v[15] + 1000. * 0.007 * v[18] + 2000. * 0.012 * v[48] + 4189.68014953824 * 0.0180152833 * v[57]) / (0.005 * v[15] + 0.007 * v[18] + 0.012 * v[48] + 0.0180152833 * v[57]));
    v[56] = 1001.91585067007 * v[26];
    v[44] = ((v[56] - (0.005 * v[21] * v[26] + 0.007 * v[24] * v[26] + 0.012 * v[50] * v[26])) / 0.0180152833) / v[26];
    y[21] = (0.005 * v[16] * 1000. * (v[17] - v[23]) + 0.007 * v[40] * 1000. * (v[17] - v[23]) + 0.012 * v[49] * 2000. * (v[17] - v[23]) + 0.0180152833 * v[57] * v[0] * 4189.68014953824 * (v[17] - v[23]) - -33488. * v[25] * v[26]) / (v[56] * (1000. * 0.005 * v[21] + 1000. * 0.007 * v[24] + 2000. * 0.012 * v[50] + 4189.68014953824 * 0.0180152833 * v[44]) / (0.005 * v[21] + 0.007 * v[24] + 0.012 * v[50] + 0.0180152833 * v[44]));
    v[56] = 1001.91585067007 * v[32];
    v[57] = ((v[56] - (0.005 * v[27] * v[32] + 0.007 * v[30] * v[32] + 0.012 * v[52] * v[32])) / 0.0180152833) / v[32];
    y[22] = (0.005 * v[22] * 1000. * (v[23] - v[29]) + 0.007 * v[41] * 1000. * (v[23] - v[29]) + 0.012 * v[51] * 2000. * (v[23] - v[29]) + 0.0180152833 * v[44] * v[0] * 4189.68014953824 * (v[23] - v[29]) - -33488. * v[31] * v[32]) / (v[56] * (1000. * 0.005 * v[27] + 1000. * 0.007 * v[30] + 2000. * 0.012 * v[52] + 4189.68014953824 * 0.0180152833 * v[57]) / (0.005 * v[27] + 0.007 * v[30] + 0.012 * v[52] + 0.0180152833 * v[57]));
    v[56] = 1001.91585067007 * v[7];
    v[44] = ((v[56] - (0.005 * v[33] * v[7] + 0.007 * v[35] * v[7] + 0.012 * v[54] * v[7])) / 0.0180152833) / v[7];
    y[23] = (0.005 * v[28] * 1000. * (v[29] - v[34]) + 0.007 * v[42] * 1000. * (v[29] - v[34]) + 0.012 * v[53] * 2000. * (v[29] - v[34]) + 0.0180152833 * v[57] * v[0] * 4189.68014953824 * (v[29] - v[34]) - -33488. * v[36] * v[7]) / (v[56] * (1000. * 0.005 * v[33] + 1000. * 0.007 * v[35] + 2000. * 0.012 * v[54] + 4189.68014953824 * 0.0180152833 * v[44]) / (0.005 * v[33] + 0.007 * v[35] + 0.012 * v[54] + 0.0180152833 * v[44]));
    return y;
}

#endif
