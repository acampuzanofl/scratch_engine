#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <SFML/Graphics.hpp>

struct FrameData
{
    int id; // Texture id (retrieved from our texture allocator).
    int x; // x position of sprite in the texture.
    int y; // y position of sprite in the texture.
    int width; // Width of sprite.
    int height; // Height of sprite.
    float displayTimeSeconds; // How long to display the frame.
};

class Animation
{
    public:
            // stores all frames of animation
        std::vector<FrameData> frames;
        
        Animation();

        void AddFrame(int textureID, int x, int y, int width, int height, float frameTime);

        const FrameData* GetCurrentFrame() const;

        bool UpdateFrame(float deltaTime);

        void Reset();
    
    private:
        void IncrementFrame();



        // current frame
        int currentFrameIndex;

        // amount of time that has passed on current frame
        float currentFrameTime;
};

#endif