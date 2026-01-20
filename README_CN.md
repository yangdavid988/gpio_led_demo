# Ameba RTL8721Dx GPIO 控制LED实现1s 流水显示示例（free_rtos）
* [English Version](./README.md)


这是一个基于 RTL8721Dx 系列 SoC 的“LED GPIO控制”示例。该程序展示通过GPIO 配置io输出让LED 灯闪烁的效果，因为EVB上面板载对应sRGB 灯的pin与GPIO对应IO相同，所以即使不连接外部LED 灯珠，从EVB板载LED上面也可以看到效果。

* [EVB 链接](https://item.taobao.com/item.htm?id=904981157046)
* [IC](https://riot.realmcu.com/cn/module/index.html)

## 功能

- 程序初始化GPIO，PA14/PA15/PA16
- 初始化成功后GPIO拉高1s，3个LED 全亮，然后灭掉
- 每1s修改一次GPIO的输出，实现LED 流水闪烁


## 快速开始

1. **选择 SDK**
   - 设定 `env.sh` (`env.bat`) 路径：`source {sdk}/env.sh`
   - 将 `{sdk}` 替换为[ameba-rtos SDK](https://github.com/Ameba-AIoT/ameba-rtos) 根目录下 `env.sh` 的绝对路径。SDK 路径不变时，该步骤仅需执行一次。

2. **编译**
   - 在当前example repository根目录下执行：
     ```bash
     source env.sh
     ameba.py build
     ```

3. **烧录 Flash**
   ```bash
   ameba.py flash --p COMx --image km4_boot_all.bin 0x08000000 0x8014000 --image km0_km4_app.bin 0x08014000 0x8200000
   ```
   **注意**：工程目录中提供了编译好的 bin 文件，直接烧录的方法如下：
   ```bash
   ameba.py flash --p COMx --image ../km4_boot_all.bin 0x08000000 0x8014000 --image ../km0_km4_app.bin 0x08014000 0x8200000
   ```

4. **监控**
   - `ameba.py monitor --port COMx --b 1500000`

5. **连接 WiFi**
   - 使用 AT 指令连接 WiFi，具体参考 [AT+WLCONN](https://riot.realmcu.com/cn/latest/rtos/atcmd/at_command_wifi.html#at-wlconn)
   - 示例：`AT+WLCONN=ssid,Xiaomi_Pro_2G,pw,12345678`

6. **观察日志输出**

7. **AP 重新上下电，观察日志输出**

8. **点击开发板上的RESET按钮，观察 WiFi 自动重连**

---


 ```bash
 log：
2026-01-12 18:00:45.885 This is a "hello world" from app_main function!
2026-01-12 18:00:45.885 [app_main-A] (RTK_LOG_ALWAYS),hello world!
2026-01-12 18:00:45.885 [app_main-E] (RTK_LOG_ERROR),hello world!
2026-01-12 18:00:45.885 [app_main-W] (RTK_LOG_WARN),hello world!
2026-01-12 18:00:45.885 [app_main-I] (RTK_LOG_INFO),hello world!
2026-01-12 18:00:45.885 [MAIN-I] KM4 START SCHEDULER 
2026-01-12 18:00:45.885 interface 0 is initialized
2026-01-12 18:00:45.885 interface 1 is initialized
2026-01-12 18:00:45.885 [WLAN-I] LWIP consume heap 1312
2026-01-12 18:00:45.885 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:45.885 Wait for WiFi and DHCP Connect Success...
2026-01-12 18:00:45.885 Please use AT+WLCONN to connect AP first time
2026-01-12 18:00:45.885 [WLAN-A] Init WIFI
2026-01-12 18:00:45.895 [WLAN-A] Band=2.4G&5G
2026-01-12 18:00:45.925 [WLAN-I] NP consume heap 20336
2026-01-12 18:00:45.925 [WLAN-A] set ssid Xiaomi_Pro_2G
2026-01-12 18:00:46.096 [WLAN-A] start auth to 50:64:2b:34:88:9e
2026-01-12 18:00:46.137 [WLAN-A] auth success, start assoc
2026-01-12 18:00:46.177 [WLAN-A] assoc success(2)
2026-01-12 18:00:46.389 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:46.893 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:46.893 Wait for WiFi and DHCP Connect Success...
2026-01-12 18:00:46.893 Please use AT+WLCONN to connect AP first time
2026-01-12 18:00:47.386 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:47.890 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:47.890 Wait for WiFi and DHCP Connect Success...
2026-01-12 18:00:47.890 Please use AT+WLCONN to connect AP first time
2026-01-12 18:00:48.323 [WLAN-A] set pairwise key 4(WEP40-1 WEP104-5 TKIP-2 AES-4 GCMP-15)
2026-01-12 18:00:48.323 [WLAN-A] set group key 4 1
2026-01-12 18:00:48.323 [WLAN-I] set cam: gtk alg 4 0
2026-01-12 18:00:48.323 [$]wifi connected
2026-01-12 18:00:48.383 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:48.887 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:48.887 Wait for WiFi and DHCP Connect Success...
2026-01-12 18:00:48.887 Please use AT+WLCONN to connect AP first time
2026-01-12 18:00:49.401 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:49.401 [$]wifi got ip:"192.168.32.39"
2026-01-12 18:00:49.401 wtn dhcp success
2026-01-12 18:00:49.401 [WLAN-I] AP consume heap 11832
2026-01-12 18:00:49.401 [WLAN-I] Available heap after wifi init 321952
2026-01-12 18:00:49.904 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:50.408 [app_example-I] Hello world!
2026-01-12 18:00:51.424 [app_example-I] Hello world!
2026-01-12 18:00:52.421 [app_example-I] Hello world!
2026-01-12 18:00:53.427 [app_example-I] Hello world!
2026-01-12 18:00:54.413 [app_example-I] Hello world!
2026-01-12 18:00:55.430 [app_example-I] Hello world!
 ```