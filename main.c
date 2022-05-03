#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>


int main(int argc, char *argv[]){
    // 初始化SDL
    SDL_Init(SDL_INIT_VIDEO);
    // 创建SDL窗口指针
    SDL_Window *window = SDL_CreateWindow(
            "SDL2Test",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            0
    );

    // 创建渲染器
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    // 设置渲染器
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    // 渲染
    SDL_RenderPresent(renderer);

    // 等待3000ms
    SDL_Delay(2000);

    // 销毁窗口&退出
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}