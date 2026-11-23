#include <SDL3/SDL.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    const int win_w = 800;
    const int win_h = 600;
    const float cell_size = 40.0f;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    if (!SDL_CreateWindowAndRenderer("SDL3 Grid", win_w, win_h, 0, &window, &renderer)) {
        SDL_Log("SDL_CreateWindowAndRenderer failed: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        // Dark background
        SDL_SetRenderDrawColor(renderer, 20, 20, 24, 255);
        SDL_RenderClear(renderer);

        // Grid line color
        SDL_SetRenderDrawColor(renderer, 70, 75, 85, 255);

        // Vertical lines
        for (float x = 0.0f; x <= (float)win_w; x += cell_size) {
            SDL_RenderLine(renderer, x, 0.0f, x, (float)win_h);
        }

        // Horizontal lines
        for (float y = 0.0f; y <= (float)win_h; y += cell_size) {
            SDL_RenderLine(renderer, 0.0f, y, (float)win_w, y);
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
