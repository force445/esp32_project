#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class LogisticRegression {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        float votes[11] = { -0.005765614955 ,-0.008748193888 ,-0.001442001042 ,0.009296315617 ,0.002021152729 ,0.010656097241 ,0.004610735677 ,0.007725997549 ,-0.00481526396 ,-0.014668939426 ,0.001129714457  };
                        votes[0] += dot(x,   0.019242980797  , -0.040121044592  , 0.017954547089 );
                        votes[1] += dot(x,   -0.004093537159  , 0.000866928517  , 0.005473078126 );
                        votes[2] += dot(x,   -0.001178640616  , 0.016062247426  , -0.013505387442 );
                        votes[3] += dot(x,   0.007099462939  , -0.038142715488  , 0.028452689381 );
                        votes[4] += dot(x,   0.006943848502  , -0.01100312543  , 0.004510837076 );
                        votes[5] += dot(x,   -0.010245722371  , -0.001618777535  , 0.011937989985 );
                        votes[6] += dot(x,   -0.006393654773  , 0.024513050745  , -0.017544623893 );
                        votes[7] += dot(x,   -0.005424531852  , 0.013207475557  , -0.006421912852 );
                        votes[8] += dot(x,   0.000543574322  , -0.002043805628  , 0.003356539225 );
                        votes[9] += dot(x,   -0.017018208199  , 0.026005536278  , -0.007457351765 );
                        votes[10] += dot(x,   0.01052442841  , 0.01227423015  , -0.026756404932 );
                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 11; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                protected:
                    /**
                    * Compute dot product
                    */
                    float dot(float *x, ...) {
                        va_list w;
                        va_start(w, 3);
                        float dot = 0.0;

                        for (uint16_t i = 0; i < 3; i++) {
                            const float wi = va_arg(w, double);
                            dot += x[i] * wi;
                        }

                        return dot;
                    }
                };
            }
        }
    }
