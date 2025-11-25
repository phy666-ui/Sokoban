Sokoban
=======

跨平台3D推箱子游戏

## 项目简介
这是一个使用OpenGL开发的3D推箱子游戏，现在已适配为可在Windows和Linux平台运行。

## 构建依赖

### Linux依赖
- CMake 3.10或更高版本
- OpenGL
- GLFW3
- DevIL (Developer's Image Library)
- OpenAL
- ALUT

在Ubuntu/Debian上，可以使用以下命令安装依赖：
```bash
sudo apt-get install cmake libglfw3-dev libdevil-dev libopenal-dev libalut-dev
```

### Windows依赖
- Visual Studio
- CMake 3.10或更高版本
- 项目中包含的库文件（位于libraries目录）

## 构建步骤

### Linux构建
```bash
mkdir build
cd build
cmake ..
make
```

### Windows构建
可以使用CMake生成Visual Studio解决方案，或者直接使用Visual Studio打开现有的项目文件。

## 运行游戏
构建完成后，可以在build目录中找到可执行文件，直接运行即可。

## 注意事项
- 项目使用了混合的OpenGL风格（新旧混合）
- 游戏控制可能需要根据平台进行适当调整
- 在Linux上，全屏模式切换可能需要额外的配置


