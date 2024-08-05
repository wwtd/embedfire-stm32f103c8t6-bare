# STM32F103C8T6 核心板裸机代码，使用野火STM32F103C8T6核心板
## 简介
最近我对MCU上的裸机编程比较感兴趣。在中文网络上找到的资料使用Linux下GCC/Make系列工具链的比较少。在github上找到了一些比较类似的，但是仍不够符合我的口味。所以我尝试自己移植并启动一块STM32F103C8T6核心板。
## 目标
在linux平台下，从参考文档开始，完成STM32F103C8T6的点亮，并完成所有的外设的使用。
## 硬件环境
- 上位机环境，树莓派4B（实体的Linux环境均可）
- 野火STM32F103C8T6核心板（淘宝即可，十来块钱。同芯片的其它核心板类似，需要改一下引脚）
- st-link V2
使用中如需其它环境，会在各自子目录下的readme进行说明。
## 软件环境
Debian系列
```shell
sudo apt install make openocd telnet bear clangd gcc-arm-none-eabi stlink-tools clang-format gdb-multiarch
```
其它系列的Linux自行搜索。上述安装不一定包含所有软件依赖，如遇到软件缺失，自行安装即可。
