#pragma once
#include <cmath>
#include "TimeManager.h"
#include <iostream>

namespace CC_Graph
{
    enum class WaveFunctionType
    {
        NONE,
        SIN,
        COS,
        TAN
    };

    struct WaveFunction
    {
        WaveFunctionType funcType = WaveFunctionType::NONE;

        float amplitude;
        float frequency;
        float phase;
        float offset;

        inline float Draw(float x)
        {
            float elapsedTime = TimeManager::GetInstance().GetTotalTime();
            switch (funcType)
            {
            case WaveFunctionType::SIN:
                return amplitude * std::sin(frequency * x + phase + elapsedTime) + offset;
            case WaveFunctionType::COS:
                return amplitude * std::cos(frequency * x + phase + elapsedTime) + offset;
            case WaveFunctionType::TAN:
                return amplitude * std::tan(frequency * x + phase + elapsedTime) + offset;
            default:
                return 0.0f;
            }
        }
    };
}
