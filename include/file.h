#ifndef __FRACTAL_ENGINE_FILE_H__
#define __FRACTAL_ENGINE_FILE_H__

#include <filesystem>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <string>
#include <functional>

#include <window.h>
#include <renderer.h>

enum class E_FileStatus {modified, nothingChanged};

namespace Core
{
    class File
    {
    public:
        E_FileStatus                    status;

        std::string                     fragment_shader_path = "";

        std::filesystem::file_time_type fs_changed;

        int                             doOnce = 0;

        explicit File();
        ~File() noexcept;

        void UpdateFile(Graphics::Renderer& render, Window& window, float t);
        void CheckModification();
    };
}
#endif  //__FRACTAL_ENGINE_FILE_H__

