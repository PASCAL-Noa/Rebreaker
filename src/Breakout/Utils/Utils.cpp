#include "pch.h"
#include "Utils.h"

std::string Utils::getResourcesPath()
{
    #ifdef _DEBUG
    // Go back to the res directory from the ide path
    static std::string path = std::filesystem::current_path().parent_path().
    parent_path().parent_path().string() + "\\res\\";
    
    return path;
    
    #else

    // Go back to the res directory from the exe path
    static std::string path = std::filesystem::current_path().string() + "\\res\\";
    
    return path;
    
    #endif
}

float Utils::randomFloat(float min, float max)
{
    return (static_cast<float>(rand()) / RAND_MAX) * (max - min) + min;
}

void Utils::rotateVectorAroundPoint(sf::Vector2f& vector, const float angle)
{
    float px = vector.x;
    float py = vector.y;
    
    vector.x = px * cos(angle) - py* sin(angle);
    vector.y = px * sin(angle) + py * cos(angle);
}

float Utils::Lerp(float x, float y, float z) {
    return ((1.0f - z) * x) + (z * y);      
}


