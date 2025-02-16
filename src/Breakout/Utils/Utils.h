#pragma once

class Utils
{
public:
    static std::string getResourcesPath();
    static float randomFloat(float min, float max);
    static void rotateVectorAroundPoint(sf::Vector2f& vector, float angle);
    static float Lerp(float x, float y, float t);
};
