# 使用方法

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
另一终端里输入控制命令
```shell
reset halt
flash write_image erase blink.bin 0x08000000
```
