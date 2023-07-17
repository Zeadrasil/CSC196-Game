#include "InputSystem.h"
#include "SDL2-2.28.0/include/SDL.h"
namespace JoeBidenWakeup
{
bool InputSystem::initialize()
{
    int numKeys;
    const uint8_t* newKeyboardState = SDL_GetKeyboardState(&numKeys);
    keyboardState.resize(numKeys);
    std::copy(newKeyboardState, newKeyboardState + numKeys, keyboardState.begin());
    previousKeyboardState = keyboardState;
    return true;
}

    InputSystem gInputSystem;

void InputSystem::shutdown()
{
}

void InputSystem::update()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    previousKeyboardState = keyboardState;
    const uint8_t* newKeyboardState = SDL_GetKeyboardState(nullptr);
    std::copy(newKeyboardState, newKeyboardState + keyboardState.size(), keyboardState.begin());

    int x, y;
    uint32_t buttons = SDL_GetMouseState(&x, &y);
    mousePosition = Vector2{ x , y };
    previousMouseButtonState = mouseButtonState;
    mouseButtonState[0] = buttons & SDL_BUTTON_LMASK;
    mouseButtonState[1] = buttons & SDL_BUTTON_MMASK;
    mouseButtonState[2] = buttons & SDL_BUTTON_RMASK;
}
}