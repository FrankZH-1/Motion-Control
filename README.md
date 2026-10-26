# 柔性单轴精密运动控制项目

目标：研究系统辨识、快速定位与振动抑制，形成面向精密运动控制岗位的可复现实验作品。

**当前状态：设计阶段。现有代码仅验证 C++ 环境，尚未实现控制算法。**

- [完整项目设计](PROJECT.md)
- [跨电脑接续上下文](CONTEXT.md)
- [GitHub 与对话接续说明](SYNC.md)

本项目使用 C++17、CMake 和系统 Clang 编译器。

## 构建与运行

在本目录打开终端，首次构建执行：

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
./build/motion_control
```

Windows 多配置生成器可使用 `cmake --build build --config Debug`，随后运行 `build/Debug/motion_control.exe`。新电脑需先安装 CMake 和支持 C++17 的编译器。

正常输出：`C++17 environment is ready!`

修改 `src/main.cpp` 后，再执行后两条命令即可重新编译运行。
新增源文件时，将文件路径添加到 `CMakeLists.txt` 的 `add_executable` 中。

构建文件保存在 `build/`，其中 `compile_commands.json` 可供编辑器的 C++ 插件使用。
