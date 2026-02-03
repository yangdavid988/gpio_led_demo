* [English Version](./README.md)

### Ameba RTL8721Dx GPIO 控制LED实现1s 流水显示示例（free_rtos）

🔹 这是一个基于 RTL8721Dx 系列 SoC 的“LED GPIO控制”示例。该程序展示通过GPIO  配置io输出让LED 灯闪烁的效果，因为EVB上面板载对应sRGB 灯的pin与GPIO对应IO相同，所以即使不连接外部LED 灯珠，从EVB板载LED上面也可以看到效果。

- 📎 开发板链接  [🛒 淘宝](https://item.taobao.com/item.htm?id=904981157046)   |[📦 Amazon](https://www.amazon.com/-/zh/dp/B0FB33DT2C/)
- 📄 [芯片详情](https://aiot.realmcu.com/cn/module/index.html)
- 📚 [GPIO Document](https://aiot.realmcu.com/cn/latest/rtos/peripherals/gpio/index.html)

### 功能特点
✅ 初始化GPIOs —— PA14/PA15/PA16/
✅ 初始化后，程序配置GPIO端口让LED以固定的时间间隔闪烁。   


### 搭建硬件环境

1️⃣ **所需组件**
   - 3个LED 
    ⚠️ 开发板上有内置LED，您可以直接观察效果。

2️⃣ **连接导线**
   - 将LED分别连接到 
      - `LED1_PIN(_PA_14)//绿色`   
      - `LED2_PIN(_PA_15)//红色` 
      - `LED3_PIN(_PA_16)//蓝色` 
      - 和 `GND`

### 快速开始

1️⃣ **初始化SDK环境**
   - 设定 `env.sh` (`env.bat`) 路径：`source {sdk}/env.sh`
   - 将 `{sdk}` 替换为[ameba-rtos SDK](https://github.com/Ameba-AIoT/ameba-rtos) 根目录下 `env.sh` 的绝对路径。SDK 路径不变时，该步骤仅需执行一次。

2️⃣ **编译**
   - 在当前example repository根目录下执行：
     ```bash
     source env.sh
     ameba.py build
     ```

3️⃣ **烧录 Flash**
   ```bash
   ameba.py flash --p COMx --image km4_boot_all.bin 0x08000000 0x8014000 --image km0_km4_app.bin 0x08014000 0x8200000
   ```
   **注意**：工程目录中提供了编译好的 bin 文件，直接烧录的方法如下：
   ```bash
   ameba.py flash --p COMx --image ../km4_boot_all.bin 0x08000000 0x8014000 --image ../km0_km4_app.bin 0x08014000 0x8200000
   ```

4️⃣ **打开串口监视**
   - `ameba.py monitor --port COMx --b 1500000`

5️⃣ **点击EVB RST按钮后，观察日志输出**


---
### 日志示例

 ```bash
 log：
14:02:16.036  ROM:[V1.1]
14:02:16.051  FLASH RATE:1, Pinmux:1
14:02:16.051  IMG1(OTA1) VALID, ret: 0
14:02:16.051  IMG1 ENTRY[f80078d:0]
14:02:16.051  [BOOT-I] KM4 BOOT REASON 0: Initial Power on
14:02:16.051  [BOOT-I] KM4 CPU CLK: 240000000 Hz
14:02:16.051  [BOOT-I] KM0 CPU CLK: 96000000 Hz
14:02:16.051  [BOOT-I] PSRAM Ctrl CLK: 240000000 Hz 
14:02:16.051  [BOOT-I] IMG1 ENTER MSP:[30009FDC]
14:02:16.051  [BOOT-I] Build Time: Jan 20 2026 14:01:20
14:02:16.051  [BOOT-I] IMG1 SECURE STATE: 1
14:02:16.051  [FLASH-I] FLASH CLK: 80000000 Hz
14:02:16.051  [FLASH-I] Flash ID: 85-20-16 (Capacity: 32M-bit)
14:02:16.051  [FLASH-I] Flash Read 4IO
14:02:16.051  [FLASH-I] FLASH HandShake[0x2 OK]
14:02:16.066  [BOOT-I] KM0 XIP IMG[0c000000:79e0]
14:02:16.066  [BOOT-I] KM0 SRAM[20068000:860]
14:02:16.066  [BOOT-I] KM0 PSRAM[0c008240:20]
14:02:16.066  [BOOT-I] KM0 ENTRY[20004d00:60]
14:02:16.066  [BOOT-I] KM4 XIP IMG[0e000000:17b20]
14:02:16.066  [BOOT-I] KM4 SRAM[2000b000:460]
14:02:16.071  [BOOT-I] KM4 PSRAM[0e017f80:20]
14:02:16.071  [BOOT-I] KM4 ENTRY[20004d80:40]
14:02:16.071  [BOOT-I] IMG2 BOOT from OTA 1, Version: 1.1 
14:02:16.071  [BOOT-I] Image2Entry @ 0xe0076b5 ...
14:02:16.071  [APP-I] [KM4 APP LOCKS-I]START 
14:02:16.071   KM0 ini[APP-I] t_retargVTOR: 30et_locks007000, VTOR_NS:
14:02:16.071  30007000
14:02:16.071  [APP-I] VTOR: 30007000, VTOR_NS:30007000
14:02:16.071  [APP-I] IMG2 [MAIN-I]SECURE S IWDG reTATE: 1
14:02:16.071  fresh on!
14:02:16.071  [MAIN-I] KM0 OS START 
14:02:16.071  [CLK-I] [CAL4M]: delta:1 target:320 PPM: 3125 PPM_Limit:30000 
14:02:16.072  [CLK-I] [CAL131K]: delta:11 target:2441 PPM: 4506 PPM_Limit:30000 
14:02:16.072  [LOCKS-I] KM4 init_retarget_locks
14:02:16.072  [APP-I] BOR arises when supply voltage decreases under 2.57V and recovers above 2.7V.
14:02:16.072  [MAIN-I] KM4 MAIN 
14:02:16.072  [VER-I] AMEBA-RTOS SDK VERSION: 1.2.0
14:02:16.087  [MAIN-I] File System Init Success 
14:02:16.087  [app_main-I] gpio_led_demo start!
14:02:16.087  gpio_led_setup ready!
14:02:19.077  [MAIN-I] KM4 START SCHEDULER 
14:02:22.082  ==> LED toggle count:1
14:02:25.080  ==> LED toggle count:2
14:02:28.083  ==> LED toggle count:3
14:02:31.086  ==> LED toggle count:4
14:02:34.088  ==> LED toggle count:5
14:02:37.093  ==> LED toggle count:6
14:02:40.094  ==> LED toggle count:7
14:02:43.093  ==> LED toggle count:8
14:02:46.098  ==> LED toggle count:9
14:02:49.100  ==> LED toggle count:10
14:02:52.102  ==> LED toggle count:11
14:02:55.106  ==> LED toggle count:12

 ```