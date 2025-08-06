#include <gofpp.hpp>
#include <SDL2/SDL.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>
#include <SDL_opengl.h>

// Command: Undoable increment
struct IncrementCommand : gofpp::ICommand {
    int& target; int value;
    IncrementCommand(int& t, int v) : target(t), value(v) {}
    void execute() override { target += value; }
    void undo() override { target -= value; }
};

// State: UI modes
struct AppContext { int counter = 0; };

struct EditState : gofpp::State<AppContext> {
    void enter(AppContext&) override {}
    void update(AppContext& ctx) override {
        ImGui::Text("Edit Mode");
        if(ImGui::Button("Increment")) ctx.counter++;
    }
};

struct PlayState : gofpp::State<AppContext> {
    void update(AppContext& ctx) override {
        ImGui::Text("Play Mode - Counter: %d", ctx.counter);
    }
};

int main(int, char**) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_Window* window = SDL_CreateWindow("GoF++ Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init("#version 130");

    gofpp::CommandStack cmdStack;
    gofpp::StateMachine<AppContext> stateMachine;
    stateMachine.changeState(std::make_unique<EditState>());

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT) running = false;
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        auto io = ImGui::GetIO();
        // Create dockspace if needed
        if(io.ConfigFlags & ImGuiConfigFlags_DockingEnable){
            ImGui::DockSpaceOverViewport();
        }
        // Top menu to switch state
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::MenuItem("Edit Mode")) stateMachine.changeState(std::make_unique<EditState>());
            if (ImGui::MenuItem("Play Mode")) stateMachine.changeState(std::make_unique<PlayState>());
            ImGui::EndMainMenuBar();
        }

        stateMachine.update();

        ImGui::Render();
        glViewport(0, 0, 800, 600);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
