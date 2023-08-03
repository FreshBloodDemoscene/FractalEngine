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

class File
{
public:
    E_FileStatus status;

    std::string fragment_shader_path = "";
    std::string vertex_shader_path = "";

    std::filesystem::file_time_type fs_changed;
    std::filesystem::file_time_type vs_changed;

    int doOnce = 0;

    explicit File();
    ~File() noexcept;

    void UpdateFile         (Renderer& render, Window& window, float t);
    void CheckModification  ();
    void UpdateShader       (Renderer& render);
};

#endif  //__FRACTAL_ENGINE_FILE_H__

