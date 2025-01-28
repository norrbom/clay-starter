#define CLAY_IMPLEMENTATION
#include "../clay/clay.h"
#include "../clay/renderers/raylib/clay_renderer_raylib.c"
#include "../raylib/include/raylib.h"

void HandleClayErrors(Clay_ErrorData errorData) {
    printf("clay error: %s", errorData.errorText.chars);
}

int main(void) {
    Clay_Raylib_Initialize(1024, 768, "Introducing Clay Demo", FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);

    uint64_t clayRequiredMemory = Clay_MinMemorySize();
    Clay_Arena clayMemory = Clay_CreateArenaWithCapacityAndMemory(clayRequiredMemory, malloc(clayRequiredMemory));
    Clay_Dimensions dim = (Clay_Dimensions) {
        .width = GetScreenWidth(),
        .height = GetScreenHeight(),
    };
    Clay_Initialize(clayMemory, dim, (Clay_ErrorHandler) { HandleClayErrors });

    while (!WindowShouldClose())
    {
        Clay_SetLayoutDimensions((Clay_Dimensions) {
                .width = GetScreenWidth(),
                .height = GetScreenHeight()
        });
        Clay_BeginLayout();

        Clay_RenderCommandArray renderCommands = Clay_EndLayout();

        BeginDrawing();
        ClearBackground(BLACK);
        Clay_Raylib_Render(renderCommands);
        EndDrawing();
    }
}