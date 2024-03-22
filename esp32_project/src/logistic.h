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
                        float votes[6] = { 0.006686260878 ,-0.052242995263 ,0.01003504303 ,-0.003360033364 ,0.038883459719 ,-1.735001e-06  };
                        votes[0] += dot(x,   0.634990465695  , -0.604414451637  , -0.617328476966  , 0.6361083789 );
                        votes[1] += dot(x,   -0.255331560159  , 0.316789703749  , 0.169673459591  , -0.012363883217 );
                        votes[2] += dot(x,   -0.792226442727  , 0.9329561275  , 1.081572472545  , -1.017173836282 );
                        votes[3] += dot(x,   0.440809987592  , -0.392699973942  , -0.369896073492  , 0.457400963771 );
                        votes[4] += dot(x,   0.173834514177  , -0.049472102269  , -0.060593013827  , 0.138367065689 );
                        votes[5] += dot(x,   -0.202076964578  , -0.203159303402  , -0.203428367851  , -0.202338688861 );
                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 6; i++) {
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
                        va_start(w, 4);
                        float dot = 0.0;

                        for (uint16_t i = 0; i < 4; i++) {
                            const float wi = va_arg(w, double);
                            dot += x[i] * wi;
                        }

                        return dot;
                    }
                };
            }
        }
    }