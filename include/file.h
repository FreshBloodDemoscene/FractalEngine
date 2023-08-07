#ifndef __FRACTAL_ENGINE_FILE_H__
#define __FRACTAL_ENGINE_FILE_H__

#include <chrono>
#include <filesystem>
#include <functional>
#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>

#include <renderer.h>
#include <window.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

enum class E_FileStatus {modified, nothingChanged};

namespace Core
{
    class File
    {
    public:
        E_FileStatus                    status;

        std::string                     fragment_shader_path    = "";
        std::filesystem::file_time_type fs_changed;

        explicit File();
        ~File() noexcept;

        void                            File_Update             (Graphics::Renderer& render, Window& window, float t);
        void                            File_CheckModification  ();
    };
}
#endif  //__FRACTAL_ENGINE_FILE_H__

