# 使用方法
本目录下项目目标实现stm32f103c8t6核心板的bringup，验证工具链的可用性。
预期现象是实现核心板上led的点亮与关闭。

## 编译
参考Makefile内容
```shell
make
```
## 清除编译产物
```shell
make clean
```

# 刷写
## 使用stlink-tools
```shell
st-flash erase
st-flash write blink.bin 0x08000000
```
也等价于直接
```shell
make stlink
```
## 使用openocd
开启openocd
```shell
sudo openocd -f /usr/share/openocd/scripts/interface/stlink.cfg -f /usr/share/openocd/scripts/target/stm32f1x.cfg
```
另一终端里开启telenet后输入控制命令
```shell
telnet localhost 4444
```
```shell
reset halt
flash write_image erase blink.bin 0x08000000
```

# 调试
开启openocd
```shell
sudo openocd -f /usr/share/openocd/scripts/interface/stlink.cfg -f /usr/share/openocd/scripts/target/stm32f1x.cfg
```
在另一终端开启gdb，后输入指令
```shell
gdb-multiarch blink.elf
```
```shell
target remote localhost:3333
list
```
