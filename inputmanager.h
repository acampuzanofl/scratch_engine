#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

class InputManager
{
    public:

        enum Key
        {
            None,
            Left,
            Right,
            Up = 4,
            Down = 8,
            Esc = 0x10
        };

        void Update();

        bool IsKeyPressed(Key keycode);
        bool IsKeyDown(Key keycode);
        bool IsKeyUp(Key keycode);

    private:
        unsigned int thisFrameKeys;
        unsigned int lastFrameKeys;
};

#endif