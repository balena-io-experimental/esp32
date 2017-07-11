# ESP32
edge-node-manager compatible firmware for the ESP32

### Getting started
 - Ensure you have [PlatformIO Core](http://docs.platformio.org/en/latest/installation.html) installed on your local machine
 - Sign up on [resin.io](https://dashboard.resin.io/signup)
 - Work through the [getting started guide](https://docs.resin.io/raspberrypi3/nodejs/getting-started/)
 - Create a dependent application called `esp32`
 - Set these variables in the `Fleet Configuration` dependent application side tab
    - `RESIN_SUPERVISOR_DELTA=1`
    - `RESIN_HOST_TYPE=esp32`
 - Clone this repository to your local workspace
 - Add the dependent application `resin remote` to your local workspace
 - Retrieve the dependent application ID from the Resin dashboard, for example: If your dependent application URL is
 `https://dashboard.staging.io/apps/13829/devices` the ID is `13829`
 - Change [line 4](https://github.com/resin-io-projects/esp32/blob/master/src/main.cpp#L4) in `src/main.cpp` `String applicationUUID = "1234567890";` to point to your dependent application ID e.g. `String applicationUUID = "13829";`
 - Connect the ESP32 to your computer using a USB cable
 - Run `platformio run --environment esp32dev --target upload` to compile the initial firmware and flash the ESP32 (replace `esp32dev` with a different board ID from the link below if you are not using the `esp32dev`)
 - Push code to resin as normal :)

### Note
You will need to ensure your gateway device has a spare WiFi interface

### Supported ESP32 boards
The supported boards can be found on the [platform.io](http://docs.platformio.org/en/latest/platforms/espressif32.html#over-the-air-ota-update) website, if you are not using the `esp32dev` you will need to change [line 9](https://github.com/resin-io-projects/esp32/blob/master/Dockerfile#L9) in the `Dockerfile` to the ID of the board you are using
