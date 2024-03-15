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
                        float votes[11] = { -0.004064584307 ,-0.041496520247 ,-0.004499930508 ,0.009883126757 ,-0.118279504981 ,0.001443721057 ,0.305234026699 ,0.028842232087 ,0.131847663852 ,-0.012598868247 ,-0.296311362162  };
                        votes[0] += dot(x,   1.304302812435  , -0.979517997715  , -0.388129825212 );
                        votes[1] += dot(x,   -0.684833006919  , 0.548628449456  , 1.005279344445 );
                        votes[2] += dot(x,   0.345144561986  , 0.881482298782  , -0.417461194006 );
                        votes[3] += dot(x,   0.145128086669  , -0.379138664196  , 0.975174097946 );
                        votes[4] += dot(x,   0.48431660181  , 0.672815488965  , -0.380126638562 );
                        votes[5] += dot(x,   -1.239432756143  , 0.577715838282  , 1.156170681668 );
                        votes[6] += dot(x,   -0.339291634221  , -0.995253329018  , -1.392198536841 );
                        votes[7] += dot(x,   0.37559979408  , 0.522724628378  , -0.048592270327 );
                        votes[8] += dot(x,   0.958865257325  , -0.170379250523  , -0.381087997021 );
                        votes[9] += dot(x,   0.329104040901  , 0.106163258992  , 0.400067992633 );
                        votes[10] += dot(x,   -1.678903757923  , -0.785240721404  , -0.529095654722 );
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