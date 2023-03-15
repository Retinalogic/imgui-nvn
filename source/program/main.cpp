#include "lib.hpp"
#include "imgui/imgui_nvn.h"

/* Example compressed font to load from memory. */
#include "imgui/tenacity_font.h"

/* This method shouldn't be edited */
ImGuiIO &nvnImguiGetIO(){
    return ImGui::GetIO();
}

/* This method shouldn't be edited */
void nvnImguiFontGetTexDataAsAlpha8(unsigned char **out_pixels, int *out_width, int *out_height, int *out_bytes_per_pixel){
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->GetTexDataAsAlpha8(out_pixels, out_width, out_height, out_bytes_per_pixel); // Make sure you have enough memory
}

/* This method is called during initialization. You can create your imgui context, add fonts etc. */
void nvnImguiInitialize(){
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.Fonts->AddFontFromMemoryCompressedTTF(tenacity_font_compressed, sizeof(tenacity_font_compressed), 16.0f);
}

/* 
    This method is called every frame and is where you do your rendering. 
    The method returns ImDrawData (you can return NULL if you dont want to draw anything right now) that will be drawn. 
*/
ImDrawData *nvnImguiCalc(){
    ImGuiIO &io = ImGui::GetIO();
    io.DeltaTime = 1 / 60.0f;
    ImGui::NewFrame();
    ImGui::ShowDemoWindow(NULL);
    ImGui::Render();
    return ImGui::GetDrawData();
}

extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking enviroment. */
    envSetOwnProcessHandle(exl::util::proc_handle::Get());
    exl::hook::Initialize();
    /*
    For sysmodules/applets, you have to call the entrypoint when ready
    exl::hook::CallTargetEntrypoint(x0, x1);
    */
}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}